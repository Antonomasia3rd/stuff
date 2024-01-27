this is list of packages that i leave installed (not uninstalled)

make an Issue and i'll make the "uninstalled" list (if i'm not lazy heheh ><)

# The "Massive" Debloating

by "Massive" i mean the required system app needed to boot into homescreen

after rooting i still decided to mess with debloat thingy, so here you go ^^

remember that this breaks apps (obviously since this is massive), see the continuation on "Debloat" list or FAQ below if you have any questions

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

with no interactions = no connect / disconnect sound, meaning it was already stuck in starting zygote i guess, will auto-restart every 5 minutes and possibly auto-restart to recovery after several failed attempts

boot stuck = depends on the condition, you can still use ADB to restore it if you "always allow" it previously

# Debloat
this is list of system apps that i leave enabled (continuation of the "Massive" debloating list)

## Personal user

### package:com.android.bluetooth

hmmm i need this for bluetooth sharing (yes that is still common) and nearby sharing feature...

### package:com.android.externalstorage

i use SD card!

### package:com.android.hotwordenrollment.okgoogle

unironically i use the "Ok Google" thingy (guys pls don't judge me)

### package:com.android.inputdevices

i think it will be used for external keyboards ??? i do tend to use it on scrcpy --otg mode

### package:com.android.intentresolver

this breaks sharing feature

### package:com.android.internal.systemui.navbar.gestural
### package:com.android.internal.systemui.navbar.threebutton
### package:com.android.keychain
### package:com.android.managedprovisioning
### package:com.android.mms.service
### package:com.android.nfc
### package:com.android.phone
### package:com.android.printspooler
### package:com.android.providers.calendar
### package:com.android.providers.downloads
### package:com.android.providers.telephony
### package:com.android.server.telecom
### package:com.android.vending
### package:com.google.android.apps.maps
### package:com.google.android.captiveportallogin
### package:com.google.android.documentsui
### package:com.google.android.gm
### package:com.google.android.gms
### package:com.google.android.gms.location.history
### package:com.google.android.googlequicksearchbox
### package:com.google.android.gsf
### package:com.google.android.networkstack
### package:com.google.android.networkstack.tethering
### package:com.google.android.providers.media.module
### package:com.google.android.syncadapters.calendar
### package:com.google.android.webview
### package:com.google.android.youtube
### package:com.microsoft.skydrive
### package:com.osp.app.signin
### package:com.samsung.accessibility
### package:com.samsung.android.app.aodservice
### package:com.samsung.android.app.contacts
### package:com.samsung.android.app.dressroom
### package:com.samsung.android.app.routines
### package:com.samsung.android.app.smartcapture
### package:com.samsung.android.app.soundpicker
### package:com.samsung.android.app.telephonyui
### package:com.samsung.android.biometrics.app.setting
### package:com.samsung.android.bixby.agent
### package:com.samsung.android.bixby.wakeup
### package:com.samsung.android.da.daagent
### package:com.samsung.android.dialer
### package:com.samsung.android.dynamiclock
### package:com.samsung.android.forest
### package:com.samsung.android.game.gamehome
### package:com.samsung.android.game.gametools
### package:com.samsung.android.game.gos
### package:com.samsung.android.honeyboard
### package:com.samsung.android.incallui
### package:com.samsung.android.kgclient
### package:com.samsung.android.knox.zt.framework
### package:com.samsung.android.lool
### package:com.samsung.android.mdx
### package:com.samsung.android.mdx.quickboard
### package:com.samsung.android.messaging
### package:com.samsung.android.mtp
### package:com.samsung.android.networkstack
### package:com.samsung.android.peripheral.framework
### package:com.samsung.android.photoremasterservice
### package:com.samsung.android.provider.filterprovider
### package:com.samsung.android.providers.contacts
### package:com.samsung.android.providers.media
### package:com.samsung.android.providers.trash
### package:com.samsung.android.scloud
### package:com.samsung.android.secsoundpicker
### package:com.samsung.android.smartface
### package:com.samsung.android.smartmirroring
### package:com.samsung.android.sume.nn.service
### package:com.samsung.android.themecenter
### package:com.samsung.android.themestore
### package:com.samsung.android.vtcamerasettings
### package:com.samsung.app.newtrim
### package:com.samsung.cmfa.AuthTouch
### package:com.samsung.internal.systemui.navbar.gestural_no_hint
### package:com.samsung.internal.systemui.navbar.sec_gestural
### package:com.samsung.internal.systemui.navbar.sec_gestural_no_hint
### package:com.samsung.knox.securefolder
### package:com.sec.android.app.apex
### package:com.sec.android.app.billing
### package:com.sec.android.app.camera
### package:com.sec.android.app.myfiles
### package:com.sec.android.app.quicktool
### package:com.sec.android.app.samsungapps
### package:com.sec.android.app.soundalive
### package:com.sec.android.app.volumemonitorprovider
### package:com.sec.android.daemonapp
### package:com.sec.android.gallery3d
### package:com.sec.android.mimage.photoretouching
### package:com.sec.android.sdhms
### package:com.sec.hearingadjust
### package:com.sec.sve
### package:com.wssyncmldm

## rant

I'm NOT deleting com.samsung.android.mtp, deleting it will cause me not able to access files from computer, EVEN IF i reinstall it back

I mean- why is it so different than com.android.mtp, where that functionality is restored once i reinstall it?

com.android.mtp is basically useless on Samsung devices...

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

## based on Universal Android Debloater list, what is fully checked on the "massive debloat" list?

Recommended and Advanced!

## this setup cannot access SIM cards

please restore com.android.providers.telephony

## this setup spams Google Play Services not installed

please restore com.google.android.gms and com.google.android.gsf

## this setup cannot access storage (Downloaded apps)

please restore com.google.android.providers.media.module

## this setup cannot access storage (Samsung apps)

please restore com.samsung.android.providers.media
