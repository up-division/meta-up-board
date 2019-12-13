DESCRIPTION = "Linux image for UP family boards based on core-image-base"

LICENSE = "GPLv2"

require recipes-core/images/core-image-base.bb
require ${@bb.utils.contains('UP_SECURE_BOOT', '1', 'upboard-image-secureboot.inc', '', d)}
require upboard-image-base.inc

