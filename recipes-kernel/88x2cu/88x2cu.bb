SUMMARY = "Realtek 88x2cu WiFi Driver"
LICENSE = "CLOSED"

inherit module

SRC_URI = "file://88x2cu/"

S = "${WORKDIR}/88x2cu"

KERNELDIR = "${STAGING_KERNEL_DIR}"

do_compile() {
    oe_runmake -C ${S} \
    KERNEL_SOURCE=${KERNELDIR} \
    KSRC=${KERNELDIR} \
    KBUILD_BUILD_USER='' \
    KBUILD_BUILD_HOST='' \
    KBUILD_BUILD_VERSION='' \
    KBUILD_SRC='' \
    KCFLAGS="-fmacro-prefix-map=${S}=. -fdebug-prefix-map=${S}=."
}

do_install() {
    install -d ${D}/lib/modules/${KERNEL_VERSION}/kernel/drivers/net/wireless/88x2cu
    install -m 0644 ${S}/*.ko ${D}/lib/modules/${KERNEL_VERSION}/kernel/drivers/net/wireless/88x2cu/
}

do_install_post() {
    ${STRIP} --strip-debug ${D}/lib/modules/${KERNEL_VERSION}/kernel/drivers/net/wireless/88x2cu/*.ko || true
}

FILES_${PN} += "/lib/modules/${KERNEL_VERSION}/kernel/drivers/net/wireless/88x2cu/88x2cu.ko"

INHIBIT_PACKAGE_DEBUG_SPLIT = "1"

