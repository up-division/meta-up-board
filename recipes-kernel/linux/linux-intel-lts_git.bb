KBRANCH = "5.10/yocto"
KMETA_BRANCH = "yocto-5.10"
SRCREV_meta = "a58f4e7cca3973e04d3f9a40356ef9c2c0bb10a5"
SRCREV_machine ?= "2dafc777a64181d42982628c7f5907a03da5f070"
LINUX_VERSION ?= "5.10.90"
LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

KERNEL_SRC_URI ?= "git://github.com/intel/linux-intel-lts.git;protocol=https;branch=${KBRANCH};name=machine"
SRC_URI = "${KERNEL_SRC_URI}"

LINUX_KERNEL_TYPE = "lts"
KERNEL_PACKAGE_NAME = "${PN}-kernel"

require recipes-kernel/linux/linux-intel-ese.inc
require recipes-kernel/linux/upboard.inc

#LTS2020 Specific feature configuration
SRC_URI:append = " file://bsp/${BSP_SUBTYPE}/ipmi.scc"

#Enable Audio for ADL-S/P on kernel 5.10
SRC_URI:append = " file://bsp/${BSP_SUBTYPE}/audio-adl.scc"
