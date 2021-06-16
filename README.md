# Yocto layer for Update Factory support

## About Update Factory
**Update Factory is an artifact content and software update delivery IoT Platform**. To learn more, please visit:  
http://www.kynetics.com/update-factory

For Update Factory documentation visit:  
http://docs.updatefactory.io/

## meta-updatefactory integration
This layer provides Yocto support on the device side for Update Factory platform.

This layer depends on:

 - meta-swupdate
   URI: https://github.com/sbabic/meta-swupdate.git

To integrate Update Factory support in your image you need to:

1. include the following snippet in your image recipe:\
 ```require <relative-path-to>/recipes-images/images/swupdate-regular.inc```\
 (see for example `recipes-core/images/core-image-minimal.bbappend` and `recipes-images/images/core-image-x11.bbappend` in this layer)

A dedicated partition as storage space for `.swu` update files is mounted by default in /updates.

Currently support has been tested with boards by:

1. [Raspberry Pi](https://www.raspberrypi.org/) (RPi 4B)
1. [Boundary Devices](https://boundarydevices.com/) (Nitrogen6x, Nitrogen8M)
1. [Toradex](https://www.toradex.com/) (Apalis iMX6)
1. [Variscite](https://www.variscite.com/) (VAR-SOM-MX7)

The layer is designed to make it as easy as possible to add support for new hardware.

## Contributing
To contribute to this layer you should open a GitHub pull request for review.

Please refer to:
http://openembedded.org/wiki/Commit_Patch_Message_Guidelines
for some useful guidelines to be followed when submitting patches.

## License

All metadata is EPL-2.0 licensed (see COPYING.EPL-2.0) unless otherwise stated.
Source code included in tree for individual recipes is under the LICENSE stated in the associated recipe (.bb file) unless otherwise stated.
