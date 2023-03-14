FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
	file://0001-fbmem.c-fix-formula-for-centered-logo-margins.patch \
        file://0001-cma-overlay.dts-remove-option-to-pass-overlay-paramt.patch \
"

inherit custom-kernel-logo
KERNEL_LOGO_PPM = "ufLogo_1024x146.ppm"
