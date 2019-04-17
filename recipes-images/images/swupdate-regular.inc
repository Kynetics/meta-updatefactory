python () {
    if d.getVar("UF_PARTITIONING_MODE", True) == None:
        bb.fatal("UF_PARTITIONING_MODE is not set in your local.conf or distro.conf")
}

WKS_FILE ?= "sdimage-bootpart-${@d.getVar("UF_PARTITIONING_MODE", True)}.wks"

IMAGE_FSTYPES ?= "wic.gz wic.bmap"

IMAGE_BOOT_FILES_BASE = "${IMAGE_BOOT_FILES}"

IMAGE_BOOT_FILES += "\
    boot-regular.scr-${MACHINE};boot.scr \
"

RECOVERY_IMAGE_FILES = " \
    ${IMAGE_BOOT_FILES_BASE} \
    boot-update.scr-${MACHINE};boot.scr \
    swupdate-image-${MACHINE}.cpio.gz.u-boot;swupdate.img \
    updates/*;updates/ \
"

RECOVERY_IMAGE_FILES_remove = "6x_bootscript-${MACHINE};6x_bootscript"

WICVARS += "RECOVERY_IMAGE_FILES"

do_image_wic[depends] += "swupdate-image:do_image_complete u-boot-script-regular:do_deploy u-boot-script-update:do_deploy"

recovery_prepare() {
    # Create recovery mount point
    install -d ${IMAGE_ROOTFS}/recovery
    # Add recovery partition fstab entry
    grep -q -F 'LABEL=recovery' ${IMAGE_ROOTFS}/etc/fstab || echo 'LABEL=recovery       /recovery            ext4       defaults              0  0' >> ${IMAGE_ROOTFS}/etc/fstab
}

updates_prepare() {
    # Create updates mount point
    install -d ${IMAGE_ROOTFS}/recovery/updates
    # Add updates partition fstab entry
    grep -q -F 'LABEL=updates' ${IMAGE_ROOTFS}/etc/fstab || echo 'LABEL=updates       /recovery/updates            ext4       defaults              0  0' >> ${IMAGE_ROOTFS}/etc/fstab
}

def choose_partitioning_mode(d):
    partitioning_mode = d.getVar("UF_PARTITIONING_MODE", True)
    if  partitioning_mode == "recovery-updates":
        return "updates_prepare"
    elif (partitioning_mode == "recovery"):
        return "recovery_prepare"

ROOTFS_POSTPROCESS_COMMAND += "${@choose_partitioning_mode(d)}; "

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

python __anonymous () {
	if d.getVar('DISTRO_UFCLOUDAGENT_SUPPORT', True) != "notinstalled":
		d.appendVar('IMAGE_INSTALL', ' swupdate-uf-cloud-agent')
}
