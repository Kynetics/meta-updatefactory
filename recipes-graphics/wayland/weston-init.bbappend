FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

include weston-background.inc

do_install:append() {
    if [ -n "${WESTON_BACKGROUND}" ]; then
        sed -i "s|#background-image|background-image=${datadir}/backgrounds/${WESTON_BACKGROUND}|g" ${D}${sysconfdir}/xdg/weston/weston.ini
    fi
}
