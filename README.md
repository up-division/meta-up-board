Yocto BSP meta layer for the UP Board
======================================

This README file contains information on building the meta-up-board BSP
layer.  Please see the corresponding sections below for details.

For more information on the UP board see:
http://up-board.org

Table of Contents
=================

1. Prerequisites
2. Downloading the Intel Yocto BSP MR4 repository
3. Building your Intel Yocto image for each UP machine
4. Booting the live USB image
5. Connecitvity firmware
7. Additional Resources


Prerequisites
================

Supported hardware versions for Yocto 2.5 (sumo_mr4)
----------------------------------------------------
* UP Squared
* UP Core Plus

Downloading the meta-up-board BSP layer
========================================

Download the latest Intel Yocto BSP MR4 repository following the official instructions:

https://github.com/intel/iotg-yocto-bsp-public/tree/E3900-MR4#getting-started-with-yocto-bsp-for-intel-atom-e3900-soc

Now, we need to edit the layer configuration file to add our meta-up-board layer to be included during compilation:

```
sudo nano iotg-yocto-bsp-public/setup/combolayer.conf
```

Add the next lines:
```
[meta-up-board]

src_uri = git://github.com/emutex/meta-up-board

local_repo_dir = repo-ext/meta-up-board

dest_dir = meta-up-board

branch = sumo_mr4

last_revision = fd55044103c763f7f03fe5fd27c79af3c8ef258e
```

Also, we have to edit the bblayer file to add our layer in the setup:
```
sudo nano iotg-yocto-bsp-public/setup/bsp-conf/bblayers.conf.sample
```
Add our layer:
```
##OEROOT##/meta-up-board \
```

After execute the setup.sh script, you would find a new directory called yocto_build.

There you will find the meta layers integrated.

Building your Intel Yocto image for each UP machine
===================================================

To include Docker containers into your Yocto image, you have to download
meta-virtualization and openembedded-core in yocto_build directory:
```
git clone -b sumo git://git.yoctoproject.org/meta-virtualization
```

```
git clone -b sumo git://git.openembedded.org/openembedded-core
```

UP Squared Board:
-----------------
From the yocto_build directory:
```
TEMPLATECONF=meta-up-board/conf source oe-init-build-env
```
And again from yocto_build dir, for your specific machine:
```
MACHINE=up-squared bitbake upboard-image-sato
```


UP Core  Plus Board:
--------------------
From the yocto_build directory:
```
TEMPLATECONF=meta-up-board/conf source oe-init-build-env
```
And again from yocto_build dir, for your specific machine:
```
MACHINE=up-core-plus bitbake upboard-image-sato
```

At the end of a successfull build, you should have a live image that
you can boot from a USB flash drive (see instructions on how to do
that below, in the section 'Booting the live USB image').


Booting the live USB image
==============================

This BSP creates bootable live images, which can be used to directly
boot Yocto off of a USB flash drive.  Upon completion of a successful
build, described in the previous section, the images are created in
a sub-folder named ./tmp/deploy/images/up-board/

Under Linux, insert a USB flash drive.  Assuming the USB flash drive
takes device /dev/sdf, use dd to copy the live image to it.  For
example:

```
dd if=core-image-sato-up-board.hddimg of=/dev/sdf
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
don't want to include it, just edit conf/machine/up-board.conf file
and disable "Ampak-firmware, SystemD and network tools" parameters.

a. WiFi
--------
Scan your available WiFi networks:

```
rfkill unblock wlan
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

Additional Resources
=======================
In addition to this README, please see the following URLs for details
and additional documentation:

* http://up-board.org
* https://up-community.org
* https://wiki.up-community.org/

Please submit any patches against this BSP to the maintainer:
Maintainer: Ubilinux Team <ubilinux@emutex.com>
