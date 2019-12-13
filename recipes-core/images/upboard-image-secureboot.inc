WKS_FILE = "generic-bootdisk-up.wks.in"

inherit uefi-comboapp

IMAGE_FEATURES += "secureboot"

# Place secure-boot signing keys in the following directory, or set
# an alternative path for SECURE_BOOT_KEYS_DIR in local.conf
SECURE_BOOT_KEYS_DIR ?= "${TOPDIR}/secure-boot-keys"
SECURE_BOOT_SIGNING_KEY ?= "${SECURE_BOOT_KEYS_DIR}/DB.key"
SECURE_BOOT_SIGNING_CERT ?= "${SECURE_BOOT_KEYS_DIR}/DB.crt"
