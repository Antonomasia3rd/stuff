import time
import psutil
from ctypes import windll, create_unicode_buffer
from pypresence import Presence
from win10toast import ToastNotifier

# don't forget to install the dependencies! >.>
# open https://discord.com/developers dulu, create new app, then copy the Application ID
client_id = '1234567891011121314'
RPC = Presence(client_id)
toaster = ToastNotifier()

# replace / censor words (good way to prevent your IRL name from showing, if that's what u want >.>)
# just copy one of the lines, and then paste below (don't forget the comma on the previous line!)
CENSOR_MAP = {
    "Amiya": "irl stuff u don't wanna know~",
    "Program Manager": "Desktop (Home screen / Program Manager)"
}
# for clarification Amiya is not my real name, don't stalk! ><

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
    battery_info = psutil.sensors_battery()
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
        return 'bailu', "reminder to stay hydrated (><)/"
    elif 12 <= hour < 16:
        return 'qingque', "a round of celestial jade i'm in! :O"
    elif 16 <= hour < 22:
        return 'lynx_3', "spring shining evening~"
    else:
        return 'jing_yuan_2', "i'm a sleepy person ;^;"

# small picture - i also made it react if AFK more than 2 minutes
def get_small_image_and_text(idle_time):
    if idle_time >= 120 or last_window_title == "Windows Default Lock Screen":  # change this, on seconds
        hours_idle = int(idle_time // 3600)
        minutes_idle = int((idle_time % 3600) // 60)
        seconds_idle = int(idle_time % 60)
        idle_str = f"{hours_idle}h {minutes_idle}m {seconds_idle}s"
        return 'zzz', f"this user is suspected to be AFK since {idle_str}"

    now = time.localtime()
    hour = now.tm_hour
    
    # the same, time-based implementation
    if 5 <= hour < 12:
        return 'online', "IRL status: Starting the day!"
    elif 12 <= hour < 16:
        return 'online', "IRL status: Productive afternoon!"
    elif 16 <= hour < 22:
        return 'idle', "IRL status: Relaxing evening!"
    else:
        return 'idle', "IRL status: Time to rest!"

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
    time_and_battery = get_time_and_battery()
    large_image, large_text = get_large_image_and_text()
    small_image, small_text = get_small_image_and_text(idle_time)
    system_uptime_start = get_system_uptime_start()

# you can mess with this if you want (change position, etc.) ^^
    try:
        RPC.update(
            details=window_title,
            state=f"CPU: {cpu_percent}%, RAM: {ram_percent}% (of {total_ram_gb}GB)",
            start=system_uptime_start,
            buttons=[
                {"label": time_and_battery, "url": "https://time.is/GMT+7"},
                {"label": "don't know what to put here T_T", "url": "https://google.com"}
            ],
            large_image=large_image,
            large_text=large_text,
            small_image=small_image,
            small_text=small_text
        )
    # if error happens, restart the rich presence, without this code it will just force close
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
