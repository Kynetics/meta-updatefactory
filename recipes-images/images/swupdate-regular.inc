UF_WKS_EXTRA_ARGS ?= ""
UF_UPDATES_PART_SIZE ?= "800"
WICVARS += "UF_UPDATES_PART_SIZE UF_WKS_EXTRA_ARGS"

WKS_FILE ?= "sdimage-bootpart-recovery-updates.wks"

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

updates_prepare() {
    # Create updates mount point
    install -d ${IMAGE_ROOTFS}/updates
}

ROOTFS_POSTPROCESS_COMMAND_append = " updates_prepare; "

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
