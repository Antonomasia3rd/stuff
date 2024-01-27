# massive debloat

after rooting i still decided to mess with debloat thingy, so here you go ^^

remember that this breaks apps (obviously since this is massive), see the Debloat list or FAQ below if you have any questions

## Personal user

### package:android

obviously bootloop (with no interactions)

this is android's framework, deleting it for another user will also cause the personal user to soft-reboot every 5 minutes, better not mess with this

### package:com.android.location.fused

tested bootloop on Android 6, not sure about Android 14

based on google search, Samsung Galaxy A12 (which is Android 10 i think) will also bootloop with it uninstalled https://xdaforums.com/t/bootloop-after-removing-com-android-location-fused-solved.4444185/

also this list shows that Fused Location is on "Do not uninstall" list, but doesn't tell the exact reason https://gist.github.com/Zymlex/f0b58104dd2f9504a14ffd9bdc3799ac

### package:com.android.providers.settings

uninstalling on work profile will make it NOT start, probably will bootloop with no interactions

### package:com.android.settings

boot stuck - stuck on Logo

### package:com.android.settings.intelligence

since Android 14 samsung decided to merge Finder with Launcher, uninstalling it will crash launcher

### package:com.android.shell

yeah you will not debloat with this uninstalled, tested on Android 6, disconnects you from ADB with no way of reinstalling

### package:com.android.systemui

boot stuck - UI not showing

### package:com.android.uwb.resources

since i have trauma on deleting .resources on Android 11, this will probably bootloop

### package:com.android.wifi.resources

tested bootloop on Android 12, not sure about Android 14

### package:com.google.android.connectivity.resources

tested bootloop on Android 12, not sure about Android 14

### package:com.google.android.ext.services

tested, bootloop with no interactions

### package:com.google.android.modulemetadata

tested, bootloop

### package:com.google.android.packageinstaller

tested, bootloop with no interactions

### package:com.google.android.permissioncontroller

tested, bootloop with no interactions

### package:com.google.android.safetycenter.resources

since i have trauma on deleting .resources on Android 12, this will probably bootloop

### package:com.google.android.sdksandbox

tested, bootloop

### package:com.samsung.android.wifi.h2e.resources

since i have trauma on deleting .resources on Android 12, this will probably bootloop

### package:com.samsung.android.wifi.p2paware.resources

since i have trauma on deleting .resources on Android 12, this will probably bootloop

### package:com.samsung.android.wifi.resources

since i have trauma on deleting .resources on Android 12, this will probably bootloop

### package:com.samsung.android.wifi.softapwpathree.resources

since i have trauma on deleting .resources on Android 12, this will probably bootloop

### package:com.sec.android.app.launcher

boot stuck - Phone is starting...

## rant

Mediatek is weird, during boot you can NOT access ADB at all! so if you bootloop (not to be confused with boot stuck) you will have to factory reset

bootloop = zygote restarts several times, if you plug on your computer you can see it connects and disconnects until the battery is empty

with no interactions = no connect / disconnect sound, meaning it was already stuck in starting zygote i guess, will reboot to recovery after several failed attempts

boot stuck = depends on the condition, you can use ADB to restore it if you "always allow" it previously

# Debloat
this is list of system apps that i leave enabled

## Personal user

null

# FAQ

## how to reboot to recovery without waiting the battery to empty?

- Connect your phone to your computer (any cable as long as it connects)

- Hold volume down + Power button until the screen is off

- QUICKLY move your finger and press the volume down + volume up button until you see the Download mode

- Press volume up to continue

- Hold volume down FIRST + Power button until the screen is off

- QUICKLY release your finger, not releasing it quickly will result in restarting rather than powering off

- If you see the charging screen, congrats you just need to unplug it from your computer

- Enter recovery mode as usual (hold volume up first + power button)

## recommend me something?

you can open an Issue or Discussion on this repo!

## based on Universal Android Debloater list, what is fully checked?

Recommended and Advanced!

## this setup cannot access SIM cards

please restore com.android.providers.telephony

## this setup spams Google Play Services not installed

please restore com.google.android.gms and com.google.android.gsf

## this setup cannot access storage (Downloaded apps)

please restore com.google.android.providers.media.module

## this setup cannot access storage (Samsung apps)

please restore com.samsung.android.providers.media
