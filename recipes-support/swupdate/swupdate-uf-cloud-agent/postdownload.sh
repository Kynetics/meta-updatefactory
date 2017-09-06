#!/bin/sh

source /etc/swupdate/swupdate.env
UBOOT_BOOTCMD="`fw_printenv -n bootcmd`"
if [ "${UBOOT_BOOTCMD}" == "run distro_bootcmd" ]; then
        echo 'Adjusting U-Boot environment with distro_bootcmd to support update mode'
        fw_setenv --script ${SWUPDATE_UBOOT_DIR}/distro_bootcmd_prepend.uenv
elif [ "${UBOOT_BOOTCMD}" != "run update_bootcmd; run distro_bootcmd" ]; then
        echo 'It looks like U-Boot environment has no distro_bootcmd support. Custom update mode support should be developed'
        exit 1
fi
fw_setenv --script ${SWUPDATE_UBOOT_DIR}/downloaded.uenv && reboot
