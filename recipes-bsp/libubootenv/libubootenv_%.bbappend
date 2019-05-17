FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
        file://libubootenv-v3-fw_printenv-set-u-boot-initial-env-file-as-default.patch \
"

