#!/bin/sh

source /etc/swupdate/swupdate.env
source ${SWUPDATE_CONF_DIR}/update.env

if ( ${UPDATE_FORCED} ); then
	reboot_for_update.sh &
fi
