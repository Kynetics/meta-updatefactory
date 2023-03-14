include partition-images.inc
UF_COMPRESSED_PARTITIONS ?= ""boot 1" "root 2" "recovery 3""

UF_WKS_EXTRA_ARGS ?= " "
UF_BOOT_PART_SIZE ?= "100"
UF_ROOT_PART_SIZE ?= "1000"
UF_UPDATES_PART_SIZE ?= "800"
WICVARS += "UF_ROOT_PART_SIZE UF_BOOT_PART_SIZE UF_UPDATES_PART_SIZE UF_WKS_EXTRA_ARGS"

WKS_FILE ?= "uf-boot-root-recovery-updates.wks"
WKS_FILE:rpi ?= "uf-rpi-boot-root-recovery-updates.wks"

IMAGE_FSTYPES ?= "wic.gz wic.bmap"

IMAGE_BOOT_FILES_BASE = "${IMAGE_BOOT_FILES}"

IMAGE_BOOT_FILES += "\
    boot-regular.scr-${MACHINE};boot.scr \
"

RECOVERY_IMAGE_FILES = " \
    ${IMAGE_BOOT_FILES_BASE} \
    boot-update.scr-${MACHINE};boot.scr \
    swupdate-image-${MACHINE}.cpio.gz.u-boot;swupdate.img \
"

RECOVERY_IMAGE_FILES:remove = "6x_bootscript-${MACHINE};6x_bootscript"

WICVARS += "RECOVERY_IMAGE_FILES"

do_image_wic[depends] += "swupdate-image:do_image_complete u-boot-script-regular:do_deploy u-boot-script-update:do_deploy"

# Install U-Boot fw-utils to manually check / set environment
IMAGE_INSTALL:append = "\
	u-boot-fw-utils \
	u-boot-env \
"

# Install rng-tools to increase entropy at boot
IMAGE_INSTALL:append = "\
	rng-tools \
"

python __anonymous () {
    if d.getVar('DISTRO_UFCLOUDAGENT_SUPPORT', True) != "notinstalled":
        d.appendVar('IMAGE_INSTALL', ' swupdate-uf-cloud-agent')
}
