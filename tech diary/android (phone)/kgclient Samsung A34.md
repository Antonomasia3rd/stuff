you know that once removing kgclient you're locked by System UI with this message:

## Your phone is locked because Device services was uninstalled without authorization

# now how to uninstall it PROPERLY?

you know that you can replace the so-called "Device Owner" with 3rd party apps, such as Test DPC, Island / Insular, Dhizuku, etc. But unfortunately that does NOT work on unlocked bootloader
* WHY "Device Owner"? `kgclient` uses that to trigger the warning and preventing uninstallation

if you're ROOTED, you can bypass the bootloader detection with KnoxPatch, and then execute your dpm set-device-owner as usual
* by "as usual" i mean- you also have to follow the Android's original rules, which is removing all accounts and users (incl. secure folder and dual messenger) before attempting that, etc.

also some are asking if `set-profile-owner` can be used
* it can NOT
* since kgclient will still exists on the file configuration (aka `device_policies.xml`)
* just try it with `pm suspend`, it will always return `false` (aka. will still trigger when uninstalled)

and also i have ALT way, which is changing the "`device_policies.xml`" in `/data/system/`, which works without installing KnoxPatch

the benefit is that you don't have to do much hassle by removing ALL accounts and users,

# SIDE EFFECTS !!
* it's not for everyone, it's not easy...
* if you somehow enters safe mode you HAVE to restore the package because it still locks, so make sure your ADB is "always allow"ed

you need to install 3 more apps on this method, VS the "Device Owner" replacement, which only requires 2 apps (e.g. Island + KnoxPatch)

i'll be explaining this ALT method

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
here is the video tutorial: https://youtu.be/r_7Vo8U6YMY

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

## still images that i'll sort later
![VideoCapture_20240130-213334](https://github.com/Antonomasia3/stuff/assets/89201774/ed3019ef-f212-4af0-a7fa-99c97b310583)
![VideoCapture_20240130-213350](https://github.com/Antonomasia3/stuff/assets/89201774/eeb6eacb-5155-4d1f-8dcc-16c1d44c3136)
![VideoCapture_20240130-213355](https://github.com/Antonomasia3/stuff/assets/89201774/6d4628e7-f85b-4df5-8027-bc63e9c72faf)
![VideoCapture_20240130-213430](https://github.com/Antonomasia3/stuff/assets/89201774/e5840ac9-f4f8-44a8-b937-03313f0b03b2)
![VideoCapture_20240130-213445](https://github.com/Antonomasia3/stuff/assets/89201774/d0f3adf7-434c-4721-8038-b5e53375c86e)
![VideoCapture_20240130-213450](https://github.com/Antonomasia3/stuff/assets/89201774/b3c04fde-5d52-45a7-a104-812ef574efd7)
![VideoCapture_20240130-213514](https://github.com/Antonomasia3/stuff/assets/89201774/7f631911-d89f-4b92-bd0e-e17a6fdb7458)
![VideoCapture_20240130-213640](https://github.com/Antonomasia3/stuff/assets/89201774/da08ddf0-77d4-4b29-a8c6-e499ff74eab9)
![VideoCapture_20240130-213657](https://github.com/Antonomasia3/stuff/assets/89201774/2f595251-4c6c-469f-a2b2-7b1844703e14)
![VideoCapture_20240130-213802](https://github.com/Antonomasia3/stuff/assets/89201774/a2b9eee7-6b85-4124-a655-cdfd82616597)
![VideoCapture_20240130-213836](https://github.com/Antonomasia3/stuff/assets/89201774/581de0c8-a7ed-4e74-ac91-747699f8c4e3)
![VideoCapture_20240130-213923](https://github.com/Antonomasia3/stuff/assets/89201774/12b3f161-9b5b-440c-81b4-ab8eb9b7d158)
![VideoCapture_20240130-213932](https://github.com/Antonomasia3/stuff/assets/89201774/9687b784-245a-4219-aecf-cb705d7aa077)
![VideoCapture_20240130-214041](https://github.com/Antonomasia3/stuff/assets/89201774/e326e309-22f2-4c7e-8a2a-abc33ad18f4f)
![VideoCapture_20240130-214101](https://github.com/Antonomasia3/stuff/assets/89201774/5e9b7249-9abe-41d7-8ed9-83b22dbc14c8)
![VideoCapture_20240130-214108](https://github.com/Antonomasia3/stuff/assets/89201774/94a7314a-29fd-40a8-a687-ff9e96aec9d3)
![VideoCapture_20240130-214123](https://github.com/Antonomasia3/stuff/assets/89201774/3412949f-5492-41ba-837e-8569baace56c)
![VideoCapture_20240130-214132](https://github.com/Antonomasia3/stuff/assets/89201774/ffe5fe02-295f-463e-b7ce-49d83163181b)


# some proof

![image](https://github.com/Antonomasia3/stuff/assets/89201774/9708415c-7626-4729-9323-009533dd4f66)

## what this means

i have currently 6 users (with the ID of 0, 10, 11, 12, 95, and 150), and then executes that to check whether Device services (aka. `kgclient`) is installed or not

the very below command (`pm list packages`...) means:

* `-u` is to show uninstalled packages
* `grep` is basically searching the string for the specified character (which in this case it's `kgclient`)

  if the `package:`... thingy appears, it means that it's totally uninstalled before with `pm uninstall`..., aka. i have that package before, so i can proof myself
