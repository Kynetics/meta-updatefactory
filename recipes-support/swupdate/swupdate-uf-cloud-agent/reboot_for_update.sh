#!/bin/sh

source /etc/swupdate/swupdate.env

/usr/bin/patch_uenv_with_recovery

fw_setenv --script ${SWUPDATE_UBOOT_DIR}/update_setup.uenv && /sbin/reboot
