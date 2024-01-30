you know that once removing kgclient you're locked by System UI with this message:

## Your phone is locked because Device services was uninstalled without authorization

# now how to uninstall it PROPERLY?

you know that you can replace the so-called "Device Owner" with 3rd party apps, such as Test DPC, Island / Insular, Dhizuku, etc. But unfortunately that does NOT work on unlocked bootloader

if you're ROOTED, you can bypass that with KnoxPatch, and then execute your dpm set-device-owner as usual

and also i have ALT way, which is changing the "device_policies.xml" in /data/system/, which works without installing KnoxPatch

(altho KP is recommended since it's easy, this method is STILL root only)

## If you don't mind using PC and ADB

1. enable dev options and usb debugging (you already know this since you're debloating anyways)
2. execute on the command prompt: `adb shell su`

   you should be kicked in to the root shell
4. do `cp /data/system/device_policies.xml /sdcard/`
5. do `abx2xml -i /sdcard/device_policies.xml`

## WHY to do abx2xml?
at least on my device, it's "encrypted" with Android Binary XML (i knew with the "ABX" header and then googled it up), the benefit is that it speeds up booting, the side effect is it's not easily editable with a text editor, so we have to "decrypt" it first

## WHY to copy it first to internal storage
since it's "encrypted", i'm afraid i'll forgot that it's still decrypted XML format and it may bootloop (someone pls test this i'm playing safe okay-)

6. exit from adb shell (just type exit)
7. pull it to your PC's storage (i use desktop)

   e.g. `adb pull /sdcard/device_policies.xml D:\Desktop`
8. now open the .xml with your preferred text editor

![image](https://github.com/Antonomasia3/stuff/assets/89201774/9708415c-7626-4729-9323-009533dd4f66)
