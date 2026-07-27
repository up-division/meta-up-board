SUMMARY = "Intel NPU (VPU) firmware"
DESCRIPTION = "Intel NPU firmware blobs, repackaged from firmware/bin/ in the \
intel/linux-npu-driver release tag used for the userspace NPU driver/compiler \
stack, so firmware and driver versions stay in sync. Ships all NPU generations \
(37xx/40xx/50xx) so any board using this package picks up the firmware its \
kernel driver actually requests."
HOMEPAGE = "https://github.com/intel/linux-npu-driver"
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = "file://COPYRIGHT;md5=fc2fbb5d2bb6781b1a2d90d302de9e7d"
PR = "r0"

# Matches the intel/linux-npu-driver v1.33.0 tag (pinned by commit sha, not
# the mutable tag, for a reproducible fetch).
SRCREV = "81a0ceb5e4c57ea6802174a070fbdd2738d0a235"

SRC_URI = " \
    https://raw.githubusercontent.com/intel/linux-npu-driver/${SRCREV}/firmware/bin/vpu_37xx_v1.bin;name=vpu37xx \
    https://raw.githubusercontent.com/intel/linux-npu-driver/${SRCREV}/firmware/bin/vpu_40xx_v1.bin;name=vpu40xx \
    https://raw.githubusercontent.com/intel/linux-npu-driver/${SRCREV}/firmware/bin/vpu_50xx_v1.bin;name=vpu50xx \
    https://raw.githubusercontent.com/intel/linux-npu-driver/${SRCREV}/firmware/bin/COPYRIGHT;name=copyright \
"
SRC_URI[vpu37xx.sha256sum] = "57333dd374188a904d0bb05ea879df1ce60babcebc581f06b2ca06203ac732a6"
SRC_URI[vpu40xx.sha256sum] = "c31424db102160c178c3779af29dbbcd4312273359da817114b7e14ca74b5e7a"
SRC_URI[vpu50xx.sha256sum] = "22702420b09e4a76208f0f7d08cf742753d0fda390b53212d58bb37194f0cae6"
SRC_URI[copyright.sha256sum] = "a16ec0f901f841db9badea5f1c23ca3d806a67028e751e7dfe3eab4131b8cb03"

S = "${UNPACKDIR}"

do_install () {
    install -d ${D}${base_libdir}/firmware/intel/vpu/
    install -m 644 ${UNPACKDIR}/vpu_37xx_v1.bin ${D}${base_libdir}/firmware/intel/vpu/vpu_37xx_v1.bin
    install -m 644 ${UNPACKDIR}/vpu_40xx_v1.bin ${D}${base_libdir}/firmware/intel/vpu/vpu_40xx_v1.bin
    install -m 644 ${UNPACKDIR}/vpu_50xx_v1.bin ${D}${base_libdir}/firmware/intel/vpu/vpu_50xx_v1.bin

    # Older kernel intel_vpu drivers probe for the legacy vN.0 / codename
    # filenames rather than the vN naming above. Reproduce the same alias
    # symlinks intel/linux-npu-driver ships in firmware/bin/, so whichever
    # name a given board's kernel requests resolves to the right blob.
    ln -sf vpu_37xx_v1.bin ${D}${base_libdir}/firmware/intel/vpu/vpu_37xx_v0.0.bin
    ln -sf vpu_40xx_v1.bin ${D}${base_libdir}/firmware/intel/vpu/vpu_40xx_v0.0.bin
    ln -sf vpu_37xx_v0.0.bin ${D}${base_libdir}/firmware/intel/vpu/mtl_vpu_v0.0.bin
}

FILES:${PN} += " ${base_libdir}/firmware/intel/vpu/* "
