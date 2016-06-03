FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

PR := "${PR}.7"

COMPATIBLE_MACHINE_up-board = "up-board"


KERNEL_FEATURES_append_up-board += " cfg/smp.scc"

# aufs is needed for the live-boot feature
KERNEL_FEATURES_append_up-board += "${@bb.utils.contains('DISTRO_FEATURES', 'aufs', ' features/aufs/aufs-enable.scc', '', d)}"

SRC_URI += "file://up-board-standard.scc \
            file://up-board-user-config.scc \
            file://up-board-user-patches.scc \
            file://up-board-user-features.scc \
           "
