swupdate_modify_rootfs() {
    # Create recovery mount point
    install -d ${IMAGE_ROOTFS}/recovery
    # Add recovery partition fstab entry
    grep -q -F 'LABEL=recovery' ${IMAGE_ROOTFS}/etc/fstab || echo 'LABEL=recovery       /recovery            ext4       defaults              0  0' >> ${IMAGE_ROOTFS}/etc/fstab
}

ROOTFS_POSTPROCESS_COMMAND += "swupdate_modify_rootfs; "

# Install U-Boot fw-utils to manually check / set environment
IMAGE_INSTALL_append = "\
	u-boot-fw-utils \
"

SWUPDATE_INIT = "tiny"

# Install installer agent
IMAGE_INSTALL_append = "\
        swupdate-uf-installer-agent \
"
