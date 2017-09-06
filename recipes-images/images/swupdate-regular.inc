WKS_FILE = "sdimage-bootpart-recovery.wks"

IMAGE_FSTYPES = "wic.gz wic.bmap"

RECOVERY_IMAGE_FILES = " \
    ${IMAGE_BOOT_FILES} \
    boot-update.scr-${MACHINE};boot.scr \
    swupdate-image-${MACHINE}.cpio.gz.u-boot;swupdate.img \
    updates/*;updates/ \
"

RECOVERY_IMAGE_FILES_remove = "6x_bootscript-nitrogen6x;6x_bootscript"

WICVARS += "RECOVERY_IMAGE_FILES"

do_image_wic[depends] += "swupdate-image:do_image_complete"

recovery_prepare() {
    # Create recovery mount point
    install -d ${IMAGE_ROOTFS}/recovery
    # Add recovery partition fstab entry
    grep -q -F 'LABEL=recovery' ${IMAGE_ROOTFS}/etc/fstab || echo 'LABEL=recovery       /recovery            ext4       defaults              0  0' >> ${IMAGE_ROOTFS}/etc/fstab
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
