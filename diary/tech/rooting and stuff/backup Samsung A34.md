# Hello! 🙌
this is my personal experience on backing up before rooting my own device, Samsung Galaxy A34

# backing up data
* if you have Samsung account, just back it up through their cloud (recommended)
* you can optionally back up through your Google account, that all is on Settings > Accounts and backup
* back up internal storage to sd card / another computer / another phone / etc.

## why Samsung cloud?
it also backs up apps + games installed outside play store, i found it very convenient

## my backup suggestions
* for WhatsApp, do NOT forget to back up through WA settings, then copy/move everything from Android/data/com.whatsapp, that includes downloaded medias
* for LINE, i guess just back up through google drive thingy etc., my phone number is banned from registration because i repeatedly reset phone lmoai i forgot
* i back up my internal storage with FX File Explorer, selecting all folders on there, and then make it .zip, i store without compressing just to be safe if in case my data got corrupted there, and then moving it to my laptop
* i love stacked widgets, so i also made a backup of it (+ i back up my debloat list)

![image](https://github.com/Antonomasia3/stuff/assets/89201774/160b39c3-8127-4ce7-97d9-3621c2aa6741)

# if you're planning to root
i wrote this because i initially wanted to write a tutorial on "how to root samsung galaxy a34", but i guess magisk's official tutorial should already be enough for everyone to understand-

## the warning
- rooting will void warranty
- i use magisk to root my device, if you prefer another rooting solution then this might be of no use here, sorry 🙏

for magisk, you can also look at this samsung-specific tutorial on official Magisk https://topjohnwu.github.io/Magisk/install.html#samsung-devices

## resetting from rooted device?

### also back up your magisk modules!

here is my example:

* ADB & Fastboot for Android NDK
* Busybox for Android NDK
* GMS Doze
* Hex-Installer-Module
* KnoxPatch Enhancer
* Magisk Bootloop Protector
* None Display Cutout
* Play Integrity NEXT
* Remove /proc/stat restriction
* Small Battery
* YouTube ReVanced Extended
* Zygisk - LSPosed

### also back up your lsposed modules!

this is where samsung cloud kicks in, i don't need to memorize this
