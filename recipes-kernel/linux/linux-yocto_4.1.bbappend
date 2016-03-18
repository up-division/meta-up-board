FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

PR := "${PR}.7"

COMPATIBLE_MACHINE_up-board = "up-board"


KERNEL_FEATURES_append_up-board += " cfg/smp.scc"

SRC_URI += "file://up-board-standard.scc \
            file://up-board-user-config.scc \
            file://up-board-user-patches.scc \
            file://up-board-user-features.scc \
           "
