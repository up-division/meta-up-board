# meta-up-board
Yocto BSP meta layer for UP Board

## Supported Yocto versions
* Yocto 2.0.1 (jethro)

## Supported hardware versions
* UP Board V0.1 (EVT1)
* UP Board V0.2 (EVT2)
* UP Board V0.3 (EVT3)

## Usage Instructions
Download the Poky base ("jethro" release branch)
```
git clone -b jethro git://git.yoctoproject.org/poky.git
cd poky
```
Download the Intel BSP meta layer ("jethro" release branch)
```
git clone -b jethro git://git.yoctoproject.org/meta-intel
```
Download this UP Board BSP meta layer ("jethro" release branch)
```
git clone -b jethro https://github.com/emutex/meta-up-board
```
Set up the bitbake build environment
```
source oe-init-build-env
```
Edit 'conf/bblayers.conf' to include the meta-intel and meta-up-board layers:
```
...
BBLAYERS ?= " \
  /path/to/yocto/meta \
  /path/to/yocto/meta-yocto \
  /path/to/yocto/meta-yocto-bsp \
  /path/to/yocto/meta-intel \
  /path/to/yocto/meta-up-board \
  "
...
```
Edit 'conf/local.conf' to set the target MACHINE as "up-board":
```
...
# You need to select a specific machine to target the build with. There are a selection
# of emulated machines available which can boot and run in the QEMU emulator:
#
MACHINE = "up-board"
#MACHINE ?= "qemuarm"
...
```
Build a live USB bootable image for the UP board:
```
bitbake core-image-sato
```
Following a successful build, the images will be created in:
```
./tmp/deploy/images/up-board/
```

Please refer to ../meta-up-board/README for further information.
