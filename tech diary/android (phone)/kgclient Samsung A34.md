you know that once removing kgclient you're locked by System UI with this message:

## Your phone is locked because Device services was uninstalled without authorization

# now how to uninstall it PROPERLY?

you know that you can replace the so-called "Device Owner" with 3rd party apps, such as Test DPC, Island / Insular, Dhizuku, etc. But unfortunately that does NOT work on unlocked bootloader

if you're ROOTED, you can bypass that with KnoxPatch, and then execute your dpm set-device-owner as usual
* by "as usual" i mean- you also have to follow the Android's original rules, which is removing all accounts and users (incl. secure folder and dual messenger) before attempting that, etc.

also some are asking if "Profile Owner" can be used, it can NOT, since kgclient will still exists on the file configuration (aka `device_policies.xml`)

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

   e.g. `adb pull /sdcard/device_policies.xml D:\Desktop\`
7. now open the `.xml` with your preferred text editor

![image](https://github.com/Antonomasia3/stuff/assets/89201774/47bdbcd7-7770-430a-a771-3f9345b015e7)

make sure the image looks like the same on the RIGHT side, if you got the left one you didn't execute `abx2xml` properly

8. delete the highlighted one

   make sure there are no line breaks

   (obviously LOOK at the right side)

   and then Save...

9. do the opposite (which is moving it back to your phone)
   `adb push D:\Desktop\device_policies.xml /sdcard/`
   `adb shell su`
   `xml2abx -i /sdcard/device_policies.xml`
   `cp /sdcard/device_policies.xml /data/system/`

## overwrite confirmation? just press `y` and then Enter

10. do NOT forget to change the owner and group to `system` since based on my observation it's still on `root` (playing safe, avoiding bootloops)

    for your information, the original permission is (o) system (g) system with octal 0600, aka.:
    * owner: system (read allowed, write allowed, execute denied)
    * group: system (ALL denied)
    * global (ALL denied)
   
    everyone who is tech savvy please make an Issue because i change this with FX File Explorer, not sure about doing that on ADB shell

## if you prefer doing everything on phone
lmao video is too big, uploading still images later!

you need:
* FX File Explorer
* Remote ADB Shell
* an app that can enable wireless ADB so you can communicate with Remote ADB Shell (i use WADB)

1. open `FX File Explorer`
2. make sure `Root access is enabled`
   * (top-left) hamburger menu
   * `Settings`
   * `Upgrade FX`
   * swipe left until you see the `Developer/Root` tab
   * click the `Enable` button, confirm the warning
3. you should see the `System (Root)` now, confirm the warning
4. go to `data` folder, and then `system`
5. scroll until you see `device_policies.xml`, copy to internal storage
   * long press the `.xml` file
   * (top-right) the rectangle button is copy
   * (top-left) home button
   * `Main Storage`
   * (top-right) click the `1 copied` thingy
   * (bottom-right) `Paste`

## WHY?
same reason as the pc tutorial above...

6. open `Remote ADB Shell`
7. if you didn't change anything in `WADB`, the default settings should do, just press `Connect`
8. confirm the confirmation
9. do `abx2xml -i /sdcard/device_policies.xml`
10. go back to `FX`, open that mentioned `.xml` file
11. click the pencil button on the top-right to edit the file
12. scroll until you see the `kgclient` thingy, delete the string from its <admin> to </admin>
13. make sure there are no line breaks, and then Save
    * three-dots menu
    * Save
14. go back to `Remote ADB Shell`, now do `xml2abx -i /sdcard/device_policies.xml`
15. go back to `FX`, move that file back to `/data/system/` (aka. previous folder)
    * same tutorial as the `Step 5` but this time you press the scissors button aka. `Cut`
16. confirm to `Overwrite / Merge`
17. (IMPORTANT!) check if it's ABX or not
    * click the `.xml` file on `/data/system/`
    * make sure it's garbled (lmao) and have the "ABX" header
    * if it is then you can just close the file
19. (IMPORTANT!) fix the permission
    * long press the `.xml` file
    * click the (i) button near the file you just long-pressed
    * you should now see the 3x3 table, press it
    * make sure the `owner` and `group` is `system`, if not then you can click it to change, `system` is top-right on my device
    * make sure the `owner` has the `Read` and `Write` checked, everything else should not be set (`-`)
    * confirm the confirmation
20. done, reboot device before uninstalling with ADB

# some proof

![image](https://github.com/Antonomasia3/stuff/assets/89201774/9708415c-7626-4729-9323-009533dd4f66)

## what this means

i have currently 6 users (with the ID of 0, 10, 11, 12, 95, and 150), and then executes that to check whether Device services (aka. `kgclient`) is installed or not

the very below command (`pm list packages`...) means:

* `-u` is to show uninstalled packages
* `grep` is basically searching the string for the specified character (which in this case it's `kgclient`)

  if the `package:`... thingy appears, it means that it's totally uninstalled before with `pm uninstall`..., aka. i have that package before, so i can proof myself
