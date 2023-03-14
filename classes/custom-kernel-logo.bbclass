
KERNEL_LOGO_PPM ?= "custom_logo.ppm"
SRC_URI:append = " file://${KERNEL_LOGO_PPM}"
KERNEL_LOGO_PPM[vardeps] += "SRC_URI"

kernel_conf_variable() {
	CONF_SED_SCRIPT="$CONF_SED_SCRIPT /CONFIG_$1[ =]/d;"
	if test "$2" = "n"
	then
		echo "# CONFIG_$1 is not set" >> ${B}/.config
	else
		echo "CONFIG_$1=$2" >> ${B}/.config
	fi
}

do_configure:prepend() {
	if [ -e ${WORKDIR}/${KERNEL_LOGO_PPM} ]; then
		bbdebug 1 "Custom kernel logo detected"
		install -m 0644 ${WORKDIR}/${KERNEL_LOGO_PPM} ${S}/drivers/video/logo/logo_linux_clut224.ppm
		kernel_conf_variable LOGO y
		kernel_conf_variable LOGO_LINUX_CLUT224 y
	fi
}
