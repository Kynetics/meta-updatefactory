include partition-images.inc

UF_COMPRESSED_PARTITIONS:rpi ?= ""boot 2" "root 4""
UF_COMPRESSED_PARTITIONS ?= ""boot 1" "root 3""

BOOT_ALIGN_KB:rpi ?= "30"
UF_WKS_EXTRA_ARGS ?= " "
UF_BOOT_PART_SIZE ?= "100"
UF_ROOT_PART_SIZE ?= "1000"
UF_UPDATES_PART_SIZE ?= "800"
WICVARS += "UF_ROOT_PART_SIZE UF_BOOT_PART_SIZE UF_UPDATES_PART_SIZE UF_WKS_EXTRA_ARGS"
WICVARS:append:rpi = " BOOT_ALIGN_KB"

WKS_FILE ?= "uf-doublecopy-boot-root.wks"
WKS_FILE:rpi ?= "uf-doublecopy-rpi-boot-root.wks"

IMAGE_FSTYPES ?= "wic.gz wic.bmap"

IMAGE_BOOT_FILES_BASE = "${IMAGE_BOOT_FILES}"

IMAGE_BOOT_FILES += "\
    boot.scr-${MACHINE};boot.scr \
"
IMAGE_BOOT_FILES:rpi = "${BOOTFILES_DIR_NAME}/* u-boot.bin;${SDIMG_KERNELIMAGE} bcm2711-rpi-4-b.dtb bcm2711-rpi-400.dtb bcm2711-rpi-cm4.dtb"

do_image_wic[depends] += "u-boot-default-script:do_deploy"

# Install U-Boot fw-utils to manually check / set environment
IMAGE_INSTALL:append = "\
	u-boot-fw-utils \
	u-boot-env \
"

# Install rng-tools to increase entropy at boot
IMAGE_INSTALL:append = "\
	rng-tools \
"
#Install swupdate
IMAGE_INSTALL:append=" swupdate"

#Install findmnt to support double update
# TODO: move to swupdate RDEPENDS
IMAGE_INSTALL:append=" util-linux-findmnt"
