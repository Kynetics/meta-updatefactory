FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

include weston-background.inc

BACKGROUNDSETTINGS = "background-color=0xff002244\nbackground-type=scale-crop\nanimation=fade\nstartup-animation=fade\nbackground-image=${datadir}/backgrounds/${WESTON_BACKGROUND}"

do_install:append() {
    if [ -n "${WESTON_BACKGROUND}" ]; then
        sed -i "/^background-color\|^background-type\|^animation\|^startup-animation\|^background-image/d" ${D}${sysconfdir}/xdg/weston/weston.ini
        if ! grep -q '^\[shell\]' ${D}${sysconfdir}/xdg/weston/weston.ini ; then
            sed -i '$a [shell]' ${D}${sysconfdir}/xdg/weston/weston.ini
        fi
        sed -i "/^\[shell\]/a${BACKGROUNDSETTINGS}" ${D}${sysconfdir}/xdg/weston/weston.ini
fi

}
