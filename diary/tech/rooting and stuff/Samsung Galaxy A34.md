# Hello! 🙌
this is my personal experience on rooting and setting up my own device, Samsung Galaxy A34

# first things first, BACK UP all your data !!
* if you have Samsung account, just back it up through their cloud (recommended)
* you can optionally back up through your Google account, that all is on Settings > Accounts and backup
* back up internal storage to sd card / another computer / another phone / etc.

## why Samsung cloud?
it also backs up apps + games installed outside play store, i found it very convenient

## my backup suggestions
* for WhatsApp, do NOT forget to back up through WA settings, then copy/move everything from Android/data/com.whatsapp, that includes downloaded medias
* for LINE, i guess just back up through google drive thingy etc., my phone number is banned from registration because i repeatedly reset phone lmoai i forgot
* i back up my internal storage with FX File Explorer, selecting all folders on there, and then make it .zip, i store without compressing just to be safe if in case my data got corrupted there, and then moving it to my laptop

# now to the rooting stuff
to do so, you need to:
- know how to enable developer options (hin: just spam tap ~7 times on build number)
- enable OEM unlock which is located on developer options
- obviously know your lockscreen password, biometrics will not work
- choose what rooting solution that you will use

## Before proceeding
i use magisk to root my device, if you prefer another rooting solution then this might be of no use here, sorry 🙏

for magisk, you can also LOOK at this samsung-specific tutorial on official Magisk https://topjohnwu.github.io/Magisk/install.html#samsung-devices

## 1. unlock the "bootloader" - phone
- remember, RESET is required to unlock bootloader
  (yes samsung requires this to protect your privacy smh)
- use cable that can connect to your computer
BUT, always use the OFFICIAL cable if you are that afraid of breaking your phone during flashing (i will explain later)
- turn off your phone, long press both volume button, and then connect the cable to your phone (KEEP both the volume button pressed)
- after cyan colored warning appears, just follow the on-screen instructions
- you can also search the tutorial on Google, i think there are many videos explaining how, if you still don't understand then make an Issue and i'll (hopefully) make one

## 2. download the "firmware" - PC
* firmware is well, the software that is on your phone, which is Android OS (+ other samsung stuff = OneUI)
* i use Frija to download, but there are other softwares that can be used to download firmware, the principle should be same (entering model number, CSC, IMEI, etc.)
![image](https://github.com/Antonomasia3/stuff/assets/89201774/9c528ecd-1b99-43e7-8c00-7d691d4b9d90)
* after downloading, don't forget to extract the zip file you just downloaded (i extracted it to Desktop)

## 3. download Odin3 - PC
just download it from here https://dl2018.sammobile.com/Odin.zip, i pulled it from magisk tutorial lmao

after downloading, don't forget to extract the zip file you just downloaded (i extracted it to Desktop\Odin3)

also for some computers the required "drivers" might not load automatically, you can download from here https://developer.samsung.com/android-usb-driver (also pulled from magisk tutorial)

## 4. flashing with Odin3
- Open Odin3, if warning appears just press "OK"
![image](https://github.com/Antonomasia3/stuff/assets/89201774/7eee006b-b415-4e2f-ad5b-db98e6d45371)
- 
