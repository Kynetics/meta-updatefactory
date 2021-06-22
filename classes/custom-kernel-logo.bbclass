HOSTTOOLS += "pngtopnm ppmquant pnmnoraw"

KERNEL_LOGO_PNG ?= "custom_logo.png"
SRC_URI_append = " file://${KERNEL_LOGO_PNG}"
SRC_URI[vardeps] += "KERNEL_LOGO_PNG"

kernel_conf_variable() {
	CONF_SED_SCRIPT="$CONF_SED_SCRIPT /CONFIG_$1[ =]/d;"
	if test "$2" = "n"
	then
		echo "# CONFIG_$1 is not set" >> ${B}/.config
	else
		echo "CONFIG_$1=$2" >> ${B}/.config
	fi
}

do_configure_prepend() {
	if [ -e ${WORKDIR}/logo_linux_clut224.ppm ]; then
		bbdebug 1 "Custom kernel logo detected"
		install -m 0644 ${WORKDIR}/logo_linux_clut224.ppm ${S}/drivers/video/logo/logo_linux_clut224.ppm
		kernel_conf_variable LOGO y
		kernel_conf_variable LOGO_LINUX_CLUT224 y
	fi
}

do_png_to_ppm() {
	pngtopnm ${WORKDIR}/${KERNEL_LOGO_PNG} | ppmquant 224 | pnmnoraw > ${WORKDIR}/logo_linux_clut224.ppm
}

addtask png_to_ppm after do_patch before do_configure
