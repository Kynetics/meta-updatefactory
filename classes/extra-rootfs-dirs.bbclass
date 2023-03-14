# Install the extra directories listed in bitbake variable
# EXTRA_ROOTFS_DIRS for example to add required mountpoints

do_rootfs:append () {
    import os
    rootfs_path = d.getVar('IMAGE_ROOTFS',True)
    directories = d.getVar('EXTRA_ROOTFS_DIRS',True).split()
    for dir in directories:
        if dir[0] == os.sep:
            dir = dir[1:]
        path = os.path.join(rootfs_path,dir)
        if not os.path.exists(path):
            bb.utils.mkdirhier(path)
}

FILES:${PN} += "${EXTRA_ROOTFS_DIRS}"

