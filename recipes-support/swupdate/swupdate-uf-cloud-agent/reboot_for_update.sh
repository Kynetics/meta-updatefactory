#!/bin/sh

source /etc/swupdate/swupdate.env
fw_setenv --script ${SWUPDATE_UBOOT_DIR}/update_setup.uenv && /sbin/reboot
