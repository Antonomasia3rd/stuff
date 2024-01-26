# title
package:android
package:com.android.location.fused // tested bootloop on Android 6, not sure about Android 14
package:com.android.providers.settings // tested bootloop on work profile so it WILL be sure bootloop on personal user
package:com.android.settings // boot stuck - stuck on Logo, you can still use ADB to restore if you check the always trust thingy
package:com.android.settings.intelligence // needed for Launcher
package:com.android.shell // yeah you will not debloat with this uninstalled
package:com.android.systemui // boot stuck - UI not showing
package:com.android.uwb.resources // since i have trauma on deleting .resources on Android 11, this will probably bootloop
package:com.android.wifi.resources // tested bootloop on Android 12, not sure about Android 14
package:com.google.android.connectivity.resources // tested bootloop on Android 12, not sure about Android 14
package:com.google.android.ext.services // tested, bootloop with no interactions
package:com.google.android.modulemetadata
package:com.google.android.packageinstaller
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
boot stuck = depends on the condition

# FAQ
* this setup cannot access SIM cards, please restore com.android.providers.telephony
* this setup cannot access storage (Downloaded apps), please restore com.google.android.providers.media.module
* this setup cannot access storage (Samsung apps), please restore com.samsung.android.providers.media
