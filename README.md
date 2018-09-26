# Azure IoT Edge OpenVino #
Using this module, developers can build Azure IoT Edge solutions with Intel OpenVino toolkit.

## Target Device Setup ##

### Platform Compatibility ###
Azure IoT Edge is designed to be used with a broad range of operating system platforms. OpenVino module has been tested on the following platforms:

- UP2 board with Linux x64 operating system

### Device Setup ###
- [Linux](https://docs.microsoft.com/en-us/azure/iot-edge/quickstart-linux)

## Build Environment Setup ##
OpenVino module is a C++ application, which is developed and built based on the guidelines in Azure IoT Edge document.
Please follow [this link](https://docs.microsoft.com/en-us/azure/iot-edge/tutorial-c-module) to setup the build environment. 

Basic requirement:
- Docker CE

## HowTo Run ##

### Run as an IoT Edge module ###
Please follow the [link](https://docs.microsoft.com/en-us/azure/iot-edge/tutorial-c-module) to deploy the module as an IoT Edge module.


In the **Container Create Option section**, enter the following.
```json
{
    "NetworkingConfig":
    {
        "EndpointsConfig":{
            "host":{}
        }
    },
    "Env":["DISPLAY=:0","DEVICE=GPU"],
    "HostConfig":
    {
        "NetworkMode":"host",
        "IpcMode":"host",
        "Devices":
        [
            {
                "PathOnHost":"/dev/dri",
                "PathInContainer":"/dev/dri",
                "CgroupPermissions":"rwm"
            },
            {
                "PathOnHost":"/dev/video0",
                "PathInContainer":"/dev/video0",
                "CgroupPermissions":"rwm"
            }
        ],
        "Binds":["/tmp.X11-unix:/tmp/.X11-unix"]
    }
}
```

### See result on Device Explorer ###

```log
9/26/2018 3:25:59 PM> Device: [OpenVinoDev01], Data:[1 faces detected!]
9/26/2018 3:26:09 PM> Device: [OpenVinoDev01], Data:[1 faces detected!]
```

# Contributing

This project welcomes contributions and suggestions.  Most contributions require you to agree to a
Contributor License Agreement (CLA) declaring that you have the right to, and actually do, grant us
the rights to use your contribution. For details, visit https://cla.microsoft.com.

When you submit a pull request, a CLA-bot will automatically determine whether you need to provide
a CLA and decorate the PR appropriately (e.g., label, comment). Simply follow the instructions
provided by the bot. You will only need to do this once across all repos using our CLA.

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or
contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

