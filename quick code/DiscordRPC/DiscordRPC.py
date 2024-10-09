import time
import psutil
import configparser
from ctypes import windll, create_unicode_buffer
from pypresence import Presence
from win10toast import ToastNotifier

# i call this massive update since i don't know anything abt configparser XD
config = configparser.ConfigParser()
config.read('config.ini')

# don't forget to install the dependencies! >.>
# open https://discord.com/developers dulu, create new app, then copy the Application ID
client_id = config['general']['client_id']
RPC = Presence(client_id)
toaster = ToastNotifier()

# replace / censor words (good way to prevent your IRL name from showing, if that's what u want)
# oe, change the config ini file, you are not looking for anything here >.>
CENSOR_MAP = dict(config['censor_map'])

# push notif on Windows 10 if succeed
def connect_rpc():
    is_shown = False
    while True:
        try:
            RPC.connect()
            toaster.show_toast("Discord", "Rich Presence has been restarted (report a bug if it loops)")
            return True
        except Exception as e:
            if not is_shown:
                toaster.show_toast("Discord", f"{e}")
                is_shown = True
            time.sleep(10)

connect_rpc()

# detect opened programs
def get_focused_window_title():
    hwnd = windll.user32.GetForegroundWindow()
    buffer = create_unicode_buffer(128)
    windll.user32.GetWindowTextW(hwnd, buffer, len(buffer))
    window_title = buffer.value or "staring at the void >.> (Taskbar)"
    for keyword, replacement in CENSOR_MAP.items():
        if keyword.lower() in window_title.lower():
            window_title = replacement
    # discord doesn't accept 1 char title (though arRPC bypasses this!)
    # often happens on the X app humph D:
    if len(window_title) == 1:
        window_title += " "
    return window_title

# CPU + RAM usage
def get_system_info():
    cpu_percent = psutil.cpu_percent()
    ram_percent = psutil.virtual_memory().percent
    total_ram_gb = round(psutil.virtual_memory().total / (1024 ** 3), 1)
    return cpu_percent, ram_percent, total_ram_gb

# 1st button: clock + battery
def get_time_and_battery():
    now = time.localtime()
    time_str = time.strftime("%I:%M %p", now)
    
    # Check if battery exists
    battery_info = psutil.sensors_battery()
    if battery_info is None:
        return f"{time_str}, 🖥️"

    battery_percent = battery_info.percent
    plugged = battery_info.power_plugged
    plugged_str = "🔋" if not plugged else "🔌"
    
    time_remaining_str = ""
    if not plugged:
        remaining_secs = battery_info.secsleft
        if remaining_secs > 0:
            hours = remaining_secs // 3600
            if hours <= 24:
                minutes = (remaining_secs % 3600) // 60
                time_remaining_str = f" ({hours}h {minutes}m)"
    
    return f"{time_str}, {battery_percent}% {plugged_str}{time_remaining_str}"

# large picture
def get_large_image_and_text():
    now = time.localtime()
    hour = now.tm_hour
    
    # time-based implementation - be creative! (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧
    if 5 <= hour < 12:
        return config['time_based_images']['morning_image'], config['time_based_images']['morning_text']
    elif 12 <= hour < 16:
        return config['time_based_images']['afternoon_image'], config['time_based_images']['afternoon_text']
    elif 16 <= hour < 22:
        return config['time_based_images']['evening_image'], config['time_based_images']['evening_text']
    else:
        return config['time_based_images']['night_image'], config['time_based_images']['night_text']

# small picture - i also made it react if AFK more than 2 minutes
def get_small_image_and_text(idle_time):
    # Check if the user is AFK for more than the configured idle threshold
    idle_threshold = int(config['afk']['idle_threshold'])  # In seconds
    afk_message = config['afk']['afk_message']  # Configurable AFK message
    show_idle_time = config.getboolean('afk', 'show_idle_time')  # On/off switch for idle time

    if idle_time >= idle_threshold or last_window_title == "Windows Default Lock Screen":
        # Convert idle time into hours, minutes, seconds if enabled
        idle_str = ""
        if show_idle_time:
            hours_idle = int(idle_time // 3600)
            minutes_idle = int((idle_time % 3600) // 60)
            seconds_idle = int(idle_time % 60)
            idle_str = f" since {hours_idle}h {minutes_idle}m {seconds_idle}s"
        
        # Return AFK image and text with optional idle time
        return 'zzz', f"{afk_message}{idle_str}"

    now = time.localtime()
    hour = now.tm_hour
    
    # Return normal status based on the time of day
    if 5 <= hour < 12:
        return 'online', config['small_text']['morning_text']
    elif 12 <= hour < 16:
        return 'online', config['small_text']['afternoon_text']
    elif 16 <= hour < 22:
        return 'idle', config['small_text']['evening_text']
    else:
        return 'idle', config['small_text']['night_text']

# elapsed time, this is your system's uptime
def get_system_uptime_start():
    return int(psutil.boot_time())

# main logic - don't change anything!
def update_presence():
    global last_window_title, idle_start_time
    
    window_title = get_focused_window_title()
    
    if window_title == last_window_title:
        idle_time = time.time() - idle_start_time
    else:
        idle_time = 0 if last_window_title != "Windows Default Lock Screen" else time.time() - idle_start_time
        idle_start_time = time.time() if last_window_title != "Windows Default Lock Screen" else idle_start_time
        last_window_title = window_title
    
    cpu_percent, ram_percent, total_ram_gb = get_system_info()
    time_and_battery = get_time_and_battery()  # Dynamic label for button 1
    large_image, large_text = get_large_image_and_text()
    small_image, small_text = get_small_image_and_text(idle_time)
    system_uptime_start = get_system_uptime_start()

    # Fetch layout configurations
    show_large_image = config.getboolean('layout', 'show_large_image')
    show_small_image = config.getboolean('layout', 'show_small_image')
    show_buttons = config.getboolean('layout', 'show_buttons')
    show_details = config.getboolean('layout', 'details_field')
    show_state = config.getboolean('layout', 'state_field')
    
    # Button 2 label and URL from .ini file
    button_2_label = config['buttons']['button_2_label']
    button_2_url = config['buttons']['button_2_url']

    # Set up dynamic presence components
    buttons = []
    if show_buttons:
        buttons = [
            {"label": time_and_battery, "url": config['buttons']['button_1_url']},  # Dynamic time and battery
            {"label": button_2_label, "url": button_2_url}
        ]
    
    # Assembling the presence data dynamically based on the layout
    presence_data = {}
    
    if show_details:
        presence_data['details'] = window_title
    
    if show_state:
        presence_data['state'] = f"CPU: {cpu_percent}%, RAM: {ram_percent}% (of {total_ram_gb}GB)"
    
    presence_data['start'] = system_uptime_start
    
    if show_large_image:
        presence_data['large_image'] = large_image
        presence_data['large_text'] = large_text
    
    if show_small_image:
        presence_data['small_image'] = small_image
        presence_data['small_text'] = small_text
    
    if show_buttons:
        presence_data['buttons'] = buttons
    
    # Updating Discord RPC
    try:
        RPC.update(**presence_data)
    except Exception as e:
        toaster.show_toast("Discord", f"{e}")
        RPC.close()
        connect_rpc()

# AFK indicator logic
last_window_title = ""
idle_start_time = time.time()

# updates every 5 seconds, i don't recommend to change it lower than that!
# (if your laptop / PC can't handle it, it will probably lag the entire system, yk windows xD)
while True:
    update_presence()
    time.sleep(5)
