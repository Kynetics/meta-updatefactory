WKS_FILE = "sdimage-bootpart-recovery.wks"

IMAGE_FSTYPES = "wic.gz wic.bmap"

RECOVERY_IMAGE_FILES = " \
    ${IMAGE_BOOT_FILES} \
    swupdate-image-${MACHINE}.cpio.gz.u-boot;swupdate.img \
    updates/*;updates/ \
"

WICVARS += "RECOVERY_IMAGE_FILES"

do_image_wic[depends] += "swupdate-image:do_image_complete"

recovery_prepare() {
    # Create recovery mount point
    install -d ${IMAGE_ROOTFS}/recovery
}

ROOTFS_POSTPROCESS_COMMAND += "recovery_prepare; "

inherit deploy

addtask deploy after do_install before do_build

do_deploy() {
    # Create updates directory
    install -d ${DEPLOYDIR}/updates
    touch ${DEPLOYDIR}/updates/placeholder
}

# Install U-Boot fw-utils to manually check / set environment
IMAGE_INSTALL_append = "\
	u-boot-fw-utils \
"

# Install rng-tools to increase entropy at boot
IMAGE_INSTALL_append = "\
	rng-tools \
"

IMAGE_INSTALL_append = " \
	swupdate-uf-cloud-agent \
"
