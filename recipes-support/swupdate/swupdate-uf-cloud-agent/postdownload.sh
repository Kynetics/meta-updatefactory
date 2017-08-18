#!/bin/sh

source /etc/swupdate/swupdate.env 
fw_setenv --script ${SWUPDATE_UBOOT_DIR}/downloaded.uenv && reboot
