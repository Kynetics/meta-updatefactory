#!/bin/sh

source /etc/swupdate/swupdate.env
UBOOT_BOOTCMD="`fw_printenv -n bootcmd`"
case "${UBOOT_BOOTCMD}" in
	"run distro_bootcmd")
		echo 'U-Boot with distro_bootcmd support detected'
		echo 'Adding update mode support'
	        fw_setenv --script ${SWUPDATE_UBOOT_DIR}/distro_bootcmd_prepend.uenv
		;;
	*"6x_bootscript"*)
		echo 'Boundary Devices U-Boot pre-2017.07 detected'
		;;
	"run update_bootcmd; run distro_bootcmd")
		echo 'U-Boot with distro_bootcmd and update mode support detected'
		;;
	*)
		echo 'It looks like U-Boot environment has no distro_bootcmd support. Custom update mode support should be developed'
		exit 1
		;;
esac
fw_setenv --script ${SWUPDATE_UBOOT_DIR}/downloaded.uenv && reboot
