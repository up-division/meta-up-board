Yocto BSP meta layer
======================================
**Note: This branch dunfell for Yocto 'dunfell' is for development purposes
only. Please refer to 'dunfell' branch in this repository for non-experimental
purposes.**

This README file contains information on building the meta-up-board BSP
layer.  Please see the corresponding sections below for details.

For more information on the UP board see:
http://up-board.org

Table of Contents
=================

1. Prerequisites
2. Downloading the meta-up-board BSP layer
3. Building your Yocto image for UP Xtreme
4. Booting the live USB image
5. Connectivity firmware
6. Enabling Secure Boot
7. Additional Resources


Prerequisites
================

Supported hardware versions for Yocto 3.1 (dunfell)
------------------------------------------------
* UP Board
* UP Squared/UP Squared Pro
* UP Core
* UP Core Plus
* UP Xtreme
* UP Xtreme i11
* UP Squared 6000

Downloading the meta-up-board BSP layer
========================================

[Yocto 3.1.7]

Commit ID:

Poky : 13f4ddf50eccaeed96a40a5f1a1d4173e677e98a

meta-intel : 4922e10c7b8169585ff9322b0d913dadc525c68e

meta-openembedded : f2d02cb71eaff8eb285a1997b30be52486c160ae

meta-virtualization : 92cd3467502bd27b98a76862ca6525ce425a8479

openembedded-core : 72431ee8de5e3a53d259cebf420a7713ac9e1f14


[Yocto 3.1.3]

Commit ID:

Poky : 012ad10a89a889c21e67c27dc37d22520212548f

meta-intel : d7134e86574172784f90117c03a012e0048d8bcb

Download the Dunfell release and enter the poky directory:
```
git clone -b dunfell git://git.yoctoproject.org/poky.git
cd poky
git checkout $[Commit ID]
```
Download the Intel BSP layer version for Dunfell:

```
git clone -b dunfell git://git.yoctoproject.org/meta-intel.git
cd meta-intel
git checkout $[Commit ID]
cd ..
```

Download the latest collection of layers for OE-core universe for Dunfell:
```
git clone -b dunfell git://git.openembedded.org/meta-openembedded
```
Download meta-virtualization and openembedded-core for Docker containers:
```
git clone -b dunfell git://git.yoctoproject.org/meta-virtualization
```

```
git clone -b dunfell git://git.openembedded.org/openembedded-core
```

Download this UP Board BSP layer for Dunfell:

```
git clone -b dunfell https://github.com/AaeonCM/meta-up-board.git
```


Building your Yocto image for each UP machine
=============================================
UP Board:
---------
From the poky directory:

```
TEMPLATECONF=meta-up-board/conf source oe-init-build-env
MACHINE=up-board bitbake upboard-image-sato
```

UP Squared Board:
-----------------
From the poky directory:

```
TEMPLATECONF=meta-up-board/conf source oe-init-build-env
MACHINE=up-squared bitbake upboard-image-sato
```

UP Core Board:
--------------
From the poky directory:

```
TEMPLATECONF=meta-up-board/conf source oe-init-build-env
MACHINE=up-core bitbake upboard-image-sato
```

UP Core  Plus Board:
--------------------
From the poky directory:

```
TEMPLATECONF=meta-up-board/conf source oe-init-build-env
MACHINE=up-core-plus bitbake upboard-image-sato
```

UP Xtreme:
--------------------
From the poky directory:

```
TEMPLATECONF=meta-up-board/conf source oe-init-build-env
MACHINE=up-xtreme bitbake upboard-image-sato
```

UP Xtreme i11:
--------------------
From the poky directory:

```
TEMPLATECONF=meta-up-board/conf source oe-init-build-env
MACHINE=up-xtreme-i11 bitbake upboard-image-sato
```

UP 4000 Board:
-----------------
From the poky directory:

```
TEMPLATECONF=meta-up-board/conf source oe-init-build-env
MACHINE=up-4000 bitbake upboard-image-sato
```

UP Squared 6000 Board:
-----------------
From the poky directory:

```
TEMPLATECONF=meta-up-board/conf source oe-init-build-env
MACHINE=up-squared-6000 bitbake upboard-image-sato
```
At the end of a successfull build, you should have a live image that
you can boot from a USB flash drive (see instructions on how to do
that below, in the section 'Booting the live USB image').


Booting the live USB image
==============================

This BSP creates bootable live images, which can be used to directly
boot Yocto off of a USB flash drive.  Upon completion of a successful
build, described in the previous section, the images are created in
a sub-folder named ./tmp/deploy/images/up-xtreme/ Replace up-xtreme with
the name used when building the image.

Under Linux, insert a USB flash drive.  Assuming the USB flash drive
takes device /dev/sdf, use dd to copy the live image to it.  For
example:

```
dd if=upboard-image-sato-up-xtreme.hddimg of=/dev/sdf
sync
eject /dev/sdf
```

This should give you a bootable USB flash device.  Insert the device
into a bootable USB socket on the target, and power on.  At the
initial BIOS splash screen, press F7 to display a menu of boot options
and select the USB device.  This should result in a system booted to
the Sato graphical desktop.

If you want a terminal, use the arrows at the top of the UI to move to
different pages of available applications, one of which is named
'Terminal'.  Clicking that should give you a root terminal.

If you want to ssh into the system, you can use the root terminal to
ifconfig the IP address and use that to ssh in.  The root password is
empty, so to log in type 'root' for the user name and hit 'Enter' at
the Password prompt: and you should be in.

If you find you're getting corrupt images on the USB (it doesn't show
the syslinux boot: prompt, or the boot: prompt contains strange
characters), try doing this first:

```
dd if=/dev/zero of=/dev/sdf bs=1M count=512
```

Connectivity firmware
======================
Ampak connectivity firmware is included to enable WiFi and Bluetooth
for UPCorePlus boards.

Firmware will be included by defaults for building your image. If you
don't want to include it, just edit conf/machine/up-core.conf or
conf/machine/up-core-plus.con file and disable "Ampak-firmware, SystemD
and network tools" parameters.

a. WiFi
--------
Scan your available WiFi networks:

```
iwlist wlan0 scan
```
You will see all the WiFi interfaces in your area.

a. Bluetooth
-------------
Check your Bluetooth devices in your area:

```
systemctl restart firmware-ampak-ap6355.service

rfkill unblock bluetooth

hciconfig hci0

hcitool scan
```

Enabling Secure Boot
====================
From the poky directory:

```
TEMPLATECONF=meta-up-board/conf source oe-init-build-env
```

Edit build/conf/local.conf file to enable Secure Boot

```
UP_SECURE_BOOT = "1"
```

Before building the image, signing keys need to be available so that the
image can be signed. To generate the signing key material, execute the
following commands on a PC running Ubuntu 16.04 or similar:

```
openssl req -new -x509 -newkey rsa:2048 -subj "/CN=UP-BOARD Platform Key/" -keyout PK.key -out PK.crt -days 3650 -nodes -sha256
openssl req -new -x509 -newkey rsa:2048 -subj "/CN=UP-BOARD Key-Exchange Key/" -keyout KEK.key -out KEK.crt -days 3650 -nodes -sha256
openssl req -new -x509 -newkey rsa:2048 -subj "/CN=UP-BOARD Kernel-Signing Key/" -keyout DB.key -out DB.crt -days 3650 -nodes -sha256

chmod -v 400 DB.key KEK.key PK.key
```

The key files are the private keys and should be kept secret. They will be
used internally for signing different components. In the build folder create
a new directory called **secure-boot-keys**. You should now have:

```
poky/build/secure-boot-keys
```

Copy the DB.key and DB.crt to the **secure-boot-keys** folder. The signed image
can now be built using the standard bitbake commands in **Building your Yocto image
for each UP machine**. Copy the signed image to a USB pen drive.

Under Linux, insert a USB flash drive.  Assuming the USB flash drive
takes device /dev/sdf, use dd to copy the live image to it.  For
example:

```
dd if=core-image-sato-up-board.wic of=/dev/sdf
sync
eject /dev/sdf
```

Before booting the signed image a few steps are required to configure the BIOS
for secure booting. The UP BIOS reads the certificates in a .DER format, the
.crt files created above need to be converted to this format.

```
openssl x509 -outform DER -in PK.crt -out PK.cer
openssl x509 -outform DER -in KEK.crt -out KEK.cer
openssl x509 -outform DER -in DB.crt -out DB.cer
```

Copy PK.cer KEK.cer and DB.cer to a FAT formatted USB pen drive. Plug this pen
drive into an UP Board and boot into the BIOS menu. Navigate to the Secure Boot
Menu.

Highlight **Secure Boot** and select **Enable**. Then select **Key Management**
and press **enter**. This menu provides a method to load the certificates from
the pen drive onto the BIOS. The 3 entries we are concerned with are:

--Platform Key (PK)
--Key Exchange (KEK)
--Authorised Signatures

The 3 certificate files correspond to each entry as follows:
--PK.cer for Platform Key (PK)
--KEK.cer for Key Exchange Key (KEK)
--DB.cer for Authroised Signatures

Remove any existing keys from here. To delete a key, select the entry and press
**enter**. Highlight **Delete Key** press enter and enter again to confirm.

To add a new key, select the entry and press **enter**. Highight **Set new
Key**, select **No** (to load key from pen drive) and press enter. In the
navigation window locate your files on the pen drive. Highlight the file
appropriate to the entry you are updating. Press **enter**  and **enter** again
to confirm **Public Key Certificate**. **Save and Reset**.

Insert the USB pen drive that contains the signed image and power up the UP
board. The board should now boot the signed image.

Additional Resources
=======================
In addition to this README, please see the following URLs for details
and additional documentation:

* http://up-board.org
* https://up-community.org
* https://wiki.up-community.org/
