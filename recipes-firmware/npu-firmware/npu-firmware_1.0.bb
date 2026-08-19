DESCRIPTION = "Intel NPU Firmware"
LICENSE = "CLOSED"
PR = "r0"
PN = "npu-firmware"
PV = "0.0"
S = "${UNPACKDIR}"

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
SRC_URI:append = " file://vpu_37xx_v0.0.bin "

do_install () {
   install -d ${D}${base_libdir}/firmware/intel/vpu/
   install -m 755 vpu_37xx_v0.0.bin ${D}${base_libdir}/firmware/intel/vpu/
}

FILES:${PN} += " ${base_libdir}/firmware/intel/vpu/* "
