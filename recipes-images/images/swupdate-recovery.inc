# Install U-Boot fw-utils to manually check / set environment
IMAGE_INSTALL:append = "\
	u-boot-fw-utils \
	u-boot-env \
"

SWUPDATE_INIT = "tiny"

# Install installer agent
IMAGE_INSTALL:append = "\
        swupdate-uf-installer-agent \
"
