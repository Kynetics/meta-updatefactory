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

To integrate Update Factory support in your image just include the following
snippet in your image recipe:  
```require <relative-path-to>/recipes-images/images/swupdate-regular.inc```

Currently support has been tested with Boundary Devices boards, but more will come with time.

## Contributing
To contribute to this layer you should open a GitHub pull request for review.

Please refer to:  
http://openembedded.org/wiki/Commit_Patch_Message_Guidelines  
for some useful guidelines to be followed when submitting patches.

## License

All metadata is EPL-2.0 licensed (see COPYING.EPL-2.0) unless otherwise stated.
Source code included in tree for individual recipes is under the LICENSE stated
in the associated recipe (.bb file) unless otherwise stated.
