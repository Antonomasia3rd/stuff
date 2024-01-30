you know that once removing kgclient you're locked by System UI with this message:

## Your phone is locked because Device services was uninstalled without authorization

# now how to uninstall it PROPERLY?

you know that you can replace the so-called "Device Owner" with 3rd party apps, such as Test DPC, Island / Insular, Dhizuku, etc. But unfortunately that does NOT work on unlocked bootloader

if you're ROOTED, you can bypass that with KnoxPatch, and then execute your dpm set-device-owner as usual
* by "as usual" i mean- you also have to follow the Android's original rules, which is removing all accounts and users (incl. secure folder and dual messenger) before attempting that, etc.

also some are asking if "Profile Owner" can be used, it can NOT, since kgclient will still exists on the file configuration (aka `.xml`, we'll talk about this later)

and also i have ALT way, which is changing the "`device_policies.xml`" in `/data/system/`, which works without installing KnoxPatch

(altho KP is recommended since it's easy, this method is STILL root only)

## if you don't mind using PC and ADB

1. enable dev options and usb debugging (you already know this since you're debloating anyways)
2. execute on the command prompt: `adb shell su`

   you should be kicked in to the root shell
3. do `cp /data/system/device_policies.xml /sdcard/`

   this copies that file into your internal storage
4. do `abx2xml -i /sdcard/device_policies.xml`

## WHY to do abx2xml?
at least on my device, it's "encrypted" with Android Binary XML (i knew with the "ABX" header and then googled it up), the benefit is that it speeds up booting, the side effect is it's not easily editable with a text editor, so we have to "decrypt" it first

## WHY to copy it first to internal storage
since it's "encrypted", i'm afraid i'll forgot that it's still decrypted XML format and it may bootloop (someone pls test this i'm playing safe okay-)

5. exit from adb shell (just type exit)
6. pull it to your PC's storage (i use desktop)

   e.g. `adb pull /sdcard/device_policies.xml D:\Desktop`
7. now open the `.xml` with your preferred text editor

![image](https://github.com/Antonomasia3/stuff/assets/89201774/47bdbcd7-7770-430a-a771-3f9345b015e7)

make sure the image looks like the same on the RIGHT side, if you got the left one you didn't execute `abx2xml` properly

8. delete the highlighted one

   make sure there are no line breaks

   (obviously LOOK at the right side)

   and then Save...

## if you prefer doing everything on phone
lmao video is too big, uploading later!

# some proof

![image](https://github.com/Antonomasia3/stuff/assets/89201774/9708415c-7626-4729-9323-009533dd4f66)

## what this means

i have currently 6 users (with the ID of 0, 10, 11, 12, 95, and 150), and then executes that to check whether Device services (aka. `kgclient`) is installed or not

the very below command (`pm list packages -u`...) means:

* `-u` is to show uninstalled packages
* `grep` is basically searching the string for the specified character (which in this case it's `kgclient`)
