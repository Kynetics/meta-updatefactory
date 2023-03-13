FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
	file://0001-fbmem.c-fix-formula-for-centered-logo-margins.patch \
"

inherit custom-kernel-logo
KERNEL_LOGO_PNG = "ufLogo_1024x146.png"
