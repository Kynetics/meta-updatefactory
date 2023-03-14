inherit extra-rootfs-dirs

EXTRA_ROOTFS_DIRS:append:rpi = " boot/overlays"

WICVARS:append:rpi = " FILESCOPY_BOOT_IMAGE_FILES"

FILESCOPY_BOOT_IMAGE_FILES:rpi = " \
	boot.scr \
	${KERNEL_IMAGETYPE_UBOOT} \
	${@make_dtb_boot_files(d)} \
"

IMAGE_INSTALL:append:rpi = " kernel-devicetree"

