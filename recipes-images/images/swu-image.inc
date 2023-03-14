inherit swupdate

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

SRC_URI += " \
	file://sw-description \
"

do_swuimage[depends] += "${UF_IMAGE}:do_image_complete"

SWUPDATE_SIGNING = "RSA"
SWUPDATE_IMAGES += "${UF_IMAGE}"
UF_SWUPDATE_IMAGES_FSTYPES ?= ".boot.img.zstd .root.img.zstd"

python() {
    flag = d.getVar('UF_IMAGE')
    value = d.getVar('UF_SWUPDATE_IMAGES_FSTYPES')
    d.setVarFlag("SWUPDATE_IMAGES_FSTYPES", flag, value)
}
