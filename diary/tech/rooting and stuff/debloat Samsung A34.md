# Debloat
this is list of system apps that i have enabled

# massive debloat

after rooting i still decided to mess with debloat thingy, so here you go ^^

remember that this breaks apps (obviously since this is massive), see FAQ below if you have any questions

## Personal user

### package:android

obviously bootloop (with no interactions) this is android's framework, deleting it for another user will also cause the personal user to soft-reboot every 5 minutes, better not mess with this

package:com.android.location.fused // tested bootloop on Android 6, not sure about Android 14

package:com.android.providers.settings // uninstalling on work profile will make it NOT start, probably will bootloop with no interactions

package:com.android.settings // boot stuck - stuck on Logo

package:com.android.settings.intelligence // since Android 14 samsung decided to merge Finder with Launcher, uninstalling it will crash launcher

package:com.android.shell // yeah you will not debloat with this uninstalled

package:com.android.systemui // boot stuck - UI not showing

package:com.android.uwb.resources // since i have trauma on deleting .resources on Android 11, this will probably bootloop

package:com.android.wifi.resources // tested bootloop on Android 12, not sure about Android 14

package:com.google.android.connectivity.resources // tested bootloop on Android 12, not sure about Android 14

package:com.google.android.ext.services // tested, bootloop with no interactions

package:com.google.android.modulemetadata // tested, bootloop

package:com.google.android.packageinstaller // tested, bootloop with no interactions

package:com.google.android.permissioncontroller // tested, bootloop with no interactions

package:com.google.android.safetycenter.resources // since i have trauma on deleting .resources on Android 12, this will probably bootloop

package:com.google.android.sdksandbox // tested, bootloop

package:com.samsung.android.wifi.h2e.resources // since i have trauma on deleting .resources on Android 12, this will probably bootloop

package:com.samsung.android.wifi.p2paware.resources // since i have trauma on deleting .resources on Android 12, this will probably bootloop

package:com.samsung.android.wifi.resources // since i have trauma on deleting .resources on Android 12, this will probably bootloop

package:com.samsung.android.wifi.softapwpathree.resources // since i have trauma on deleting .resources on Android 12, this will probably bootloop

package:com.sec.android.app.launcher // boot stuck - Phone is starting...

## rant

Mediatek is weird, during boot you can NOT access ADB at all! so if you bootloop (not to be confused with boot stuck) you will have to factory reset

bootloop = zygote restarts several times, if you plug on your computer you can see it connects and disconnects until the battery is empty

with no interactions = no connect / disconnect sound, meaning it was already stuck in starting zygote i guess

boot stuck = depends on the condition, you can use ADB to restore it if you "always allow" it previously

## FAQ

* recommend me something? you can open an Issue or Discussion on this repo!

* based on Universal Android Debloater list, what is fully checked? Recommended and Advanced!

* this setup cannot access SIM cards, please restore com.android.providers.telephony

* this setup spams Google Play Services not installed, please restore com.google.android.gms and com.google.android.gsf

* this setup cannot access storage (Downloaded apps), please restore com.google.android.providers.media.module

* this setup cannot access storage (Samsung apps), please restore com.samsung.android.providers.media
