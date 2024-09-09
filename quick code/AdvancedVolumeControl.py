import tkinter as tk
from tkinter import messagebox
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
from ctypes import cast, POINTER
from comtypes import CLSCTX_ALL
import math

# Function to set volume
def set_volume(volume_level):
    devices = AudioUtilities.GetSpeakers()
    interface = devices.Activate(
        IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
    volume = cast(interface, POINTER(IAudioEndpointVolume))
    
    # Convert volume level to a range of 0.0 to 1.0
    volume_level_normalized = volume_level / 100.0
    volume.SetMasterVolumeLevelScalar(volume_level_normalized, None)

def get_current_volume():
    devices = AudioUtilities.GetSpeakers()
    interface = devices.Activate(
        IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
    volume = cast(interface, POINTER(IAudioEndpointVolume))
    
    # Get current volume in range of 0.0 to 1.0 and convert to 0-100
    current_volume = volume.GetMasterVolumeLevelScalar()
    return int(current_volume * 100)

def get_mute_status():
    devices = AudioUtilities.GetSpeakers()
    interface = devices.Activate(
        IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
    volume = cast(interface, POINTER(IAudioEndpointVolume))
    
    return volume.GetMute()

def mute_volume():
    devices = AudioUtilities.GetSpeakers()
    interface = devices.Activate(
        IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
    volume = cast(interface, POINTER(IAudioEndpointVolume))
    volume.SetMute(1, None)

def unmute_volume():
    devices = AudioUtilities.GetSpeakers()
    interface = devices.Activate(
        IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
    volume = cast(interface, POINTER(IAudioEndpointVolume))
    volume.SetMute(0, None)

# Create the main application window
root = tk.Tk()
root.title("Advanced Volume Control")

# Get current volume level and mute status
current_volume = get_current_volume()
is_muted = get_mute_status()

# Variable to hold the selected volume level
volume_level = tk.IntVar()
volume_level.set(current_volume)  # Set to current volume level

# Function to handle radio button selection
def on_volume_change():
    selected_volume = volume_level.get()
    set_volume(selected_volume)

# Function to handle mute checkbox
def on_mute_change():
    if mute_var.get() == 1:
        mute_volume()
    else:
        unmute_volume()

# Create radio buttons for volume levels
volume_frame = tk.LabelFrame(root, text="Volume Control")
volume_frame.pack(padx=10, pady=10)

for i in range(101):
    radio = tk.Radiobutton(volume_frame, text=str(i), variable=volume_level, value=i, command=on_volume_change)
    radio.grid(row=i//10, column=i%10)

# Create mute checkbox
mute_var = tk.IntVar()
mute_var.set(1 if is_muted else 0)
mute_checkbox = tk.Checkbutton(root, text="Mute", variable=mute_var, command=on_mute_change)
mute_checkbox.pack(pady=10)

# Start the main loop
root.mainloop()
