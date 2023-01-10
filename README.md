# AsyncMQTT_ESP32 Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncMQTT_ESP32.svg?)](https://www.ardu-badge.com/AsyncMQTT_ESP32)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/AsyncMQTT_ESP32.svg)](https://github.com/khoih-prog/AsyncMQTT_ESP32/releases)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/AsyncMQTT_ESP32.svg)](http://github.com/khoih-prog/AsyncMQTT_ESP32/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>

---
---

## Table of Contents

* [Why do we need this AsyncMQTT_ESP32 library](#why-do-we-need-this-AsyncMQTT_ESP32-library)
  * [Features](#features)
  * [Why Async is better](#why-async-is-better)
  * [Currently supported Boards](#currently-supported-boards)
  * [To-be-supported Boards](#To-be-supported-Boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)](#howto-use-analogread-with-esp32-running-wifi-andor-bluetooth-btble)
  * [1. ESP32 has 2 ADCs, named ADC1 and ADC2](#1--esp32-has-2-adcs-named-adc1-and-adc2)
  * [2. ESP32 ADCs functions](#2-esp32-adcs-functions)
  * [3. ESP32 WiFi uses ADC2 for WiFi functions](#3-esp32-wifi-uses-adc2-for-wifi-functions)
* [Basic Usage](#Basic-Usage)
* [How to connect W5500, W6100 or ENC28J60 to ESP32_S2/S3/C3](#How-to-connect-W5500-W6100-or-ENC28J60-to-ESP32_S2S3C3)
* [Examples](#examples)
  * [1. For ESP32](#1-for-ESP32)
    * [1. FullyFeatured_ESP32](examples/ESP32/FullyFeatured_ESP32)
    * [2. FullyFeaturedSSL_ESP32](examples/ESP32/FullyFeaturedSSL_ESP32)
  * [2. For WT32_ETH01](#2-for-WT32_ETH01)
    * [1. FullyFeatured_WT32_ETH01](examples/WT32_ETH01/FullyFeatured_WT32_ETH01)
    * [2. FullyFeaturedSSL_WT32_ETH01](examples/WT32_ETH01/FullyFeaturedSSL_WT32_ETH01)
  * [3. For ESP32_ENC](#3-for-ESP32_ENC)
    * [1. FullyFeatured_ESP32_ENC](examples/ESP32_ENC/FullyFeatured_ESP32_ENC)
    * [2. FullyFeaturedSSL_ESP32_ENC](examples/ESP32_ENC/FullyFeaturedSSL_ESP32_ENC)
  * [4. For ESP32_W5500](#4-for-ESP32_W5500)
    * [1. FullyFeatured_ESP32_W5500](examples/ESP32_W5500/FullyFeatured_ESP32_W5500)
    * [2. FullyFeaturedSSL_ESP32_W5500](examples/ESP32_W5500/FullyFeaturedSSL_ESP32_W5500)
  * [5. For ESP32_SC_ENC](#5-for-ESP32_SC_ENC)
    * [1. FullyFeatured_ESP32_SC_ENC](examples/ESP32_SC_ENC/FullyFeatured_ESP32_SC_ENC)
    * [2. FullyFeaturedSSL_ESP32_SC_ENC](examples/ESP32_SC_ENC/FullyFeaturedSSL_ESP32_SC_ENC)
  * [6. For ESP32_SC_W5500](#6-for-ESP32_SC_W5500)
    * [1. FullyFeatured_ESP32_SC_W5500](examples/ESP32_SC_W5500/FullyFeatured_ESP32_SC_W5500)
    * [2. FullyFeaturedSSL_ESP32_SC_W5500](examples/ESP32_SC_W5500/FullyFeaturedSSL_ESP32_SC_W5500)
  * [7. For ESP32_W6100](#7-for-ESP32_W6100)
    * [1. FullyFeatured_ESP32_W6100](examples/ESP32_W6100/FullyFeatured_ESP32_W6100)
    * [2. FullyFeaturedSSL_ESP32_W6100](examples/ESP32_W6100/FullyFeaturedSSL_ESP32_W6100)
  * [8. For ESP32_SC_W6100](#8-for-ESP32_SC_W6100)
    * [1. FullyFeatured_ESP32_SC_W6100](examples/ESP32_SC_W6100/FullyFeatured_ESP32_SC_W6100)
    * [2. FullyFeaturedSSL_ESP32_SC_W6100](examples/ESP32_SC_W6100/FullyFeaturedSSL_ESP32_SC_W6100)
* [Example FullyFeaturedSSL_ESP32_SC_W5500](#example-FullyFeaturedSSL_ESP32_SC_W5500)
  * [1. File FullyFeaturedSSL_ESP32_SC_W5500.ino](#1-file-FullyFeaturedSSL_ESP32_SC_W5500ino)
  * [2. File defines.h](#2-file-definesh)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [ 1. FullyFeature_ESP32_SC_W5500 on ESP32S3_DEV with ESP32_S3_W5500](#1-FullyFeature_ESP32_SC_W5500-on-ESP32S3_DEV-with-ESP32_S3_W5500)
  * [ 2. FullyFeatureSSL_ESP32_SC_W5500 on ESP32S3_DEV with ESP32_S3_W5500](#2-FullyFeatureSSL_ESP32_SC_W5500-on-ESP32S3_DEV-with-ESP32_S3_W5500)
  * [ 3. FullyFeature_ESP32_SC_ENC on ESP32S3_DEV with ESP32_S3_ENC28J60](#3-FullyFeature_ESP32_SC_ENC-on-ESP32S3_DEV-with-ESP32_S3_ENC28J60)
  * [ 4. FullyFeatureSSL_ESP32_SC_ENC on ESP32S3_DEV with ESP32_S3_ENC28J60](#4-FullyFeatureSSL_ESP32_SC_ENC-on-ESP32S3_DEV-with-ESP32_S3_ENC28J60)
  * [ 5. FullyFeatureSSL_WT32_ETH01 on WT32-ETH01 with ETH_PHY_LAN8720](#5-FullyFeatureSSL_WT32_ETH01-on-WT32-ETH01-with-ETH_PHY_LAN8720)
  * [ 6. FullyFeatureSSL_ESP32_SC_W5500 on ESP32S2_DEV with ESP32_S2_W5500](#6-FullyFeatureSSL_ESP32_SC_W5500-on-ESP32S2_DEV-with-ESP32_S2_W5500)
  * [ 7. FullyFeatureSSL_ESP32_SC_W5500 on ESP32C3_DEV with ESP32_C3_W5500](#7-FullyFeatureSSL_ESP32_SC_W5500-on-ESP32C3_DEV-with-ESP32_C3_W5500)
  * [ 8. FullyFeatureSSL_ESP32_SC_ENC on ESP32C3_DEV with ESP32_C3_ENC28J60](#8-FullyFeatureSSL_ESP32_SC_ENC-on-ESP32C3_DEV-with-ESP32_C3_ENC28J60)
  * [ 9. FullyFeature_ESP32_W6100 on ESP32_DEV with ESP32_W6100](#9-FullyFeature_ESP32_W6100-on-ESP32_DEV-with-ESP32_W6100)
  * [10. FullyFeatureSSL_ESP32_SC_W6100 on ESP32S3_DEV with ESP32_S3_W6100](#10-FullyFeatureSSL_ESP32_SC_W6100-on-ESP32S3_DEV-with-ESP32_S3_W6100)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [AsyncMQTT_ESP32 library](https://github.com/khoih-prog/AsyncMQTT_ESP32)

#### Features

This [**AsyncMQTT_ESP32 library**](https://github.com/khoih-prog/AsyncMQTT_ESP32) is based on and modified from [**Marvin Roger's async-mqtt-client Library**](https://github.com/marvinroger/async-mqtt-client), to provide support to `ESP32/S2/S3/C3` boards using WiFi or `LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet`

#### Why Async is better

- Using asynchronous network means that you can handle **more than one connection at the same time**
- **You are called once the request is ready and parsed**
- When you send the response, you are **immediately ready** to handle other connections while the server is taking care of sending the response in the background
- **Speed is OMG**
- **Easy to use API, HTTP Basic and Digest MD5 Authentication (default), ChunkedResponse**
- Easily extensible to handle **any type of content**
- Supports Continue 100
- **Async WebSocket plugin offering different locations without extra servers or ports**
- Async EventSource (Server-Sent Events) plugin to send events to the browser
- URL Rewrite plugin for conditional and permanent url rewrites
- ServeStatic plugin that supports cache, Last-Modified, default index and more
- Simple template processing engine to handle templates


---

### Currently Supported Boards

#### 1. ESP32/S2/S3/C3 using WiFi

1. **ESP32 (ESP32-DEV, etc.)**

#### 2. ESP32 using LwIP ENC28J60, W5500, W6100 or LAN8720

1. **ESP32 (ESP32-DEV, etc.)**

#### 3. **WT32_ETH01** using ESP32-based boards and LAN8720 Ethernet

#### 4. ESP32S3 using LwIP W5500, W6100 or ENC28J60

1. **ESP32-S3 (ESP32S3_DEV, ESP32_S3_BOX, UM TINYS3, UM PROS3, UM FEATHERS3, etc.)**

#### 5. ESP32S2 using LwIP W5500, W6100 or ENC28J60

1. **ESP32-S2 (ESP32S2_DEV, etc.)**

#### 6. ESP32C3 using LwIP W5500, W6100 or ENC28J60

1. **ESP32-C3 (ESP32C3_DEV, etc.)**


--- 

#### ESP32S3_DEV

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncMQTT_ESP32/raw/main/Images/ESP32S3_DEV.png">
</p>

#### ESP32S2_DEV

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncMQTT_ESP32/raw/main/Images/ESP32S2_DEV.png">
</p> 


#### ESP32C3_DEV

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncMQTT_ESP32/raw/main/Images/ESP32_C3_DevKitC_02.png">
</p> 


---

##### W6100

`FULL_DUPLEX, 100Mbps`

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncMQTT_ESP32/raw/main/Images/W6100.png">
</p>


---

##### W5500

`FULL_DUPLEX, 100Mbps`

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncMQTT_ESP32/raw/main/Images/W5500.png">
</p>

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncMQTT_ESP32/raw/main/Images/W5500_small.png">
</p> 

---

##### ENC28J60

`FULL_DUPLEX, 10Mbps`

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncMQTT_ESP32/raw/main/Images/ENC28J60.png">
</p>
 
 
 
---

### To-be Supported Boards

#### 1. New ESP32 using LwIP W5500, W6100 or ENC28J60


---
---
 
## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`ESP32 Core 2.0.6+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
 3. [`AsyncTCP v1.1.1+`](https://github.com/me-no-dev/AsyncTCP) for ESP32. To install manually for Arduno IDE
 4. [`AsyncTCP_SSL v1.3.1+`](https://github.com/khoih-prog/AsyncTCP_SSL) for ESP32. [![GitHub release](https://img.shields.io/github/release/khoih-prog/AsyncTCP_SSL.svg)](https://github.com/khoih-prog/AsyncTCP_SSL/releases)
 5. [`WebServer_WT32_ETH01 v1.5.1+`](https://github.com/khoih-prog/WebServer_WT32_ETH01) for ESP32-based WT32_ETH01 using **either ESP32 core v2.0.0+ or v1.0.6-**. [![GitHub release](https://img.shields.io/github/release/khoih-prog/WebServer_WT32_ETH01.svg)](https://github.com/khoih-prog/WebServer_WT32_ETH01/releases)
 6. [`WebServer_ESP32_ENC library v1.5.1+`](https://github.com/khoih-prog/WebServer_ESP32_ENC) if necessary to use ESP32 boards using `LwIP ENC28J60` Ethernet. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_ESP32_ENC.svg?)](https://www.ardu-badge.com/WebServer_ESP32_ENC)
 7. [`WebServer_ESP32_W5500 library v1.5.2+`](https://github.com/khoih-prog/WebServer_ESP32_W5500) if necessary to use ESP32 boards using `LwIP W5500` Ethernet. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_ESP32_W5500.svg?)](https://www.ardu-badge.com/WebServer_ESP32_W5500)
 8. [`WebServer_ESP32_SC_ENC library v1.2.0+`](https://github.com/khoih-prog/WebServer_ESP32_SC_ENC) if necessary to use `ESP32_S2/S3/C3` boards using `LwIP ENC28J60` Ethernet. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_ESP32_SC_ENC.svg?)](https://www.ardu-badge.com/WebServer_ESP32_SC_ENC)
 9. [`WebServer_ESP32_SC_W5500 library v1.2.1+`](https://github.com/khoih-prog/WebServer_ESP32_SC_W5500) if necessary to use `ESP32_S2/S3/C3` boards using `LwIP W5500` Ethernet. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_ESP32_SC_W5500.svg?)](https://www.ardu-badge.com/WebServer_ESP32_SC_W5500)
10. [`WebServer_ESP32_W6100 library v1.5.2+`](https://github.com/khoih-prog/WebServer_ESP32_W6100) if necessary to use ESP32 boards using `LwIP W6100` Ethernet. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_ESP32_W6100.svg?)](https://www.ardu-badge.com/WebServer_ESP32_W6100)
11. [`WebServer_ESP32_SC_W6100 library v1.2.1+`](https://github.com/khoih-prog/WebServer_ESP32_SC_W6100) if necessary to use `ESP32_S2/S3/C3` boards using `LwIP W6100` Ethernet. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_ESP32_SC_W6100.svg?)](https://www.ardu-badge.com/WebServer_ESP32_SC_W6100)

---
---

## Installation

### Use Arduino Library Manager
The best and easiest way is to use `Arduino Library Manager`. Search for `AsyncMQTT_ESP32`, then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncMQTT_ESP32.svg?)](https://www.ardu-badge.com/AsyncMQTT_ESP32) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [**AsyncMQTT_ESP32**](https://github.com/khoih-prog/AsyncMQTT_ESP32) page.
2. Download the latest release `AsyncMQTT_ESP32-main.zip`.
3. Extract the zip file to `AsyncMQTT_ESP32-main` directory 
4. Copy whole `AsyncMQTT_ESP32-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**AsyncMQTT_ESP32** library](https://registry.platformio.org/libraries/khoih-prog/AsyncMQTT_ESP32) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/AsyncMQTT_ESP32/installation). Search for **AsyncMQTT_ESP32** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---


### HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)

Please have a look at [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to have more detailed description and solution of the issue.

#### 1.  ESP32 has 2 ADCs, named ADC1 and ADC2

#### 2. ESP32 ADCs functions

- `ADC1` controls `ADC` function for pins **GPIO32-GPIO39**
- `ADC2` controls `ADC` function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/master/components/driver/adc_common.c#L61)

> In ADC2, there're two locks used for different cases:
> 1. lock shared with app and Wi-Fi:
>    ESP32:
>         When Wi-Fi using the ADC2, we assume it will never stop, so app checks the lock and returns immediately if failed.
>    ESP32S2:
>         The controller's control over the ADC is determined by the arbiter. There is no need to control by lock.
> 
> 2. lock shared between tasks:
>    when several tasks sharing the ADC2, we want to guarantee
>    all the requests will be handled.
>    Since conversions are short (about 31us), app returns the lock very soon,
>    we use a spinlock to stand there waiting to do conversions one by one.
> 
> adc2_spinlock should be acquired first, then adc2_wifi_lock or rtc_spinlock.


- In order to use `ADC2` for other functions, we have to **acquire complicated firmware locks and very difficult to do**
- So, it's not advisable to use `ADC2` with WiFi/BlueTooth (BT/BLE).
- Use `ADC1`, and pins **GPIO32-GPIO39**
- If somehow it's a must to use those pins serviced by `ADC2` (**GPIO0, 2, 4, 12, 13, 14, 15, 25, 26 and 27**), use the **fix mentioned at the end** of [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to work with ESP32 WiFi/BlueTooth (BT/BLE).

    
---
---

## Basic Usage

Please check [API documentation](https://github.com/khoih-prog/AsyncMQTT_ESP32/blob/main/docs/2.-API-reference.md).


---
---


### How to connect W5500, W6100 or ENC28J60 to ESP32_S2/S3/C3

##### W6100

`FULL_DUPLEX, 100Mbps`

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncMQTT_ESP32/raw/main/Images/W6100.png">
</p>

---


#### W5500

`FULL_DUPLEX, 100Mbps`

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncMQTT_ESP32/raw/main/Images/W5500.png">
</p>

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncMQTT_ESP32/raw/main/Images/W5500_small.png">
</p> 

---

#### ENC28J60

`FULL_DUPLEX, 10Mbps`

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncMQTT_ESP32/raw/main/Images/ENC28J60.png">
</p>
 
 
---

#### ESP32S3_DEV


<p align="center">
    <img src="https://github.com/khoih-prog/AsyncMQTT_ESP32/raw/main/Images/ESP32S3_DEV.png">
</p> 


You can change the `INT` pin to another one. Default is `GPIO4`

```cpp
// Must connect INT to GPIOxx or not working
#define INT_GPIO            4
```

|W5500, W6100 or ENC28J60|<--->|ESP32_S3|
|:-:|:-:|:-:|
|MOSI|<--->|GPIO11|
|MISO|<--->|GPIO13|
|SCK|<--->|GPIO12|
|CS/SS|<--->|GPIO10|
|INT|<--->|GPIO4|
|RST|<--->|RST|
|GND|<--->|GND|
|3.3V|<--->|3.3V|

---

#### ESP32S2_DEV


<p align="center">
    <img src="https://github.com/khoih-prog/AsyncMQTT_ESP32/raw/main/Images/ESP32S2_DEV.png">
</p> 


You can change the `INT` pin to another one. Default is `GPIO4`

```cpp
// Must connect INT to GPIOxx or not working
#define INT_GPIO            4
```

|W5500, W6100 or ENC28J60|<--->|ESP32_S2|
|:-:|:-:|:-:|
|MOSI|<--->|GPIO35|
|MISO|<--->|GPIO37|
|SCK|<--->|GPIO36|
|CS/SS|<--->|GPIO34|
|INT|<--->|GPIO4|
|RST|<--->|RST|
|GND|<--->|GND|
|3.3V|<--->|3.3V|


---

#### ESP32C3_DEV

<p align="center">
    <img src="https://github.com/khoih-prog/AsyncMQTT_ESP32/raw/main/Images/ESP32_C3_DevKitC_02.png">
</p> 


You can change the `INT` pin to another one. Default is `GPIO4`

```cpp
// Must connect INT to GPIOxx or not working
#define INT_GPIO            10
```

|W5500, W6100 or ENC28J60|<--->|ESP32_C3|
|:-:|:-:|:-:|
|MOSI|<--->|GPIO6|
|MISO|<--->|GPIO5|
|SCK|<--->|GPIO4|
|CS/SS|<--->|GPIO7|
|INT|<--->|GPIO10|
|RST|<--->|RST|
|GND|<--->|GND|
|3.3V|<--->|3.3V|

---
---

### Examples

#### 1. For ESP32

 1. [FullyFeatured_ESP32](examples/ESP32/FullyFeatured_ESP32)
 2. [FullyFeaturedSSL_ESP32](examples/ESP32/FullyFeaturedSSL_ESP32)

#### 2. For WT32_ETH01

 1. [FullyFeatured_WT32_ETH01](examples/WT32_ETH01/FullyFeatured_WT32_ETH01)
 2. [FullyFeaturedSSL_WT32_ETH01](examples/WT32_ETH01/FullyFeaturedSSL_WT32_ETH01)
 
#### 3. For ESP32_ENC

 1. [FullyFeatured_ESP32_ENC](examples/ESP32_ENC/FullyFeatured_ESP32_ENC)
 2. [FullyFeaturedSSL_ESP32_ENC](examples/ESP32_ENC/FullyFeaturedSSL_ESP32_ENC)
 
#### 4. For ESP32_W5500

 1. [FullyFeatured_ESP32_W5500](examples/ESP32_W5500/FullyFeatured_ESP32_W5500)
 2. [FullyFeaturedSSL_ESP32_W5500](examples/ESP32_W5500/FullyFeaturedSSL_ESP32_W5500)
 
#### 5. For ESP32_SC_ENC

 1. [FullyFeatured_ESP32_SC_ENC](examples/ESP32_SC_ENC/FullyFeatured_ESP32_SC_ENC)
 2. [FullyFeaturedSSL_ESP32_SC_ENC](examples/ESP32_SC_ENC/FullyFeaturedSSL_ESP32_SC_ENC)
 
#### 6. For ESP32_SC_W5500

 1. [FullyFeatured_ESP32_SC_W5500](examples/ESP32_SC_W5500/FullyFeatured_ESP32_SC_W5500)
 2. [FullyFeaturedSSL_ESP32_SC_W5500](examples/ESP32_SC_W5500/FullyFeaturedSSL_ESP32_SC_W5500)

#### 7. For ESP32_W6100

 1. [FullyFeatured_ESP32_W6100](examples/ESP32_W6100/FullyFeatured_ESP32_W6100)
 2. [FullyFeaturedSSL_ESP32_W6100](examples/ESP32_W6100/FullyFeaturedSSL_ESP32_W6100)
 
#### 8. For ESP32_SC_W6100

 1. [FullyFeatured_ESP32_SC_W6100](examples/ESP32_SC_W6100/FullyFeatured_ESP32_SC_W6100)
 2. [FullyFeaturedSSL_ESP32_SC_W6100](examples/ESP32_SC_W6100/FullyFeaturedSSL_ESP32_SC_W6100)  
      
---
---

### Example [FullyFeaturedSSL_ESP32_SC_W5500](examples/ESP32_SC_W5500/FullyFeaturedSSL_ESP32_SC_W5500)

#### 1. File [FullyFeaturedSSL_ESP32_SC_W5500.ino](examples/ESP32_SC_W5500/FullyFeaturedSSL_ESP32_SC_W5500/FullyFeaturedSSL_ESP32_SC_W5500.ino)

https://github.com/khoih-prog/AsyncMQTT_ESP32/blob/4a9f8bcdb04e6c0c329bda40896afd4d7d8e31c7/examples/ESP32_SC_W5500/FullyFeaturedSSL_ESP32_SC_W5500/FullyFeaturedSSL_ESP32_SC_W5500.ino#L14-L283



#### 2. File [defines.h](examples/ESP32_SC_W5500/FullyFeaturedSSL_ESP32_SC_W5500/defines.h)

https://github.com/khoih-prog/AsyncMQTT_ESP32/blob/4a9f8bcdb04e6c0c329bda40896afd4d7d8e31c7/examples/ESP32_SC_W5500/FullyFeaturedSSL_ESP32_SC_W5500/defines.h#L13-L90


---
---

### Debug Terminal Output Samples

#### 1. FullyFeature_ESP32_SC_W5500 on ESP32S3_DEV with ESP32_S3_W5500

This is terminal debug output when running [FullyFeatured_ESP32_SC_W5500](examples/ESP32_SC_W5500/FullyFeatured_ESP32_SC_W5500) on **ESP32S3_DEV** with `LwIP W5500`, connecting to `broker.emqx.io` MQTT server.

```cpp
Starting FullyFeature_ESP32_SC_W5500 on ESP32S3_DEV with ESP32_S3_W5500
WebServer_ESP32_SC_W5500 v1.2.1 for core v2.0.0+
AsyncMQTT_ESP32 v1.10.0 for ESP32 core v2.0.0+
ETH starting
ETH connected
ETH got IP
IP address: 192.168.2.108
Connecting to MQTT...
Connected to MQTT broker: broker.emqx.io, port: 1883
PubTopic: async-mqtt/ESP32_SC_W5500_Pub
************************************************
Session present: 0
Subscribing at QoS 2, packetId: 1
Publishing at QoS 0
Publishing at QoS 1, packetId: 2
Publishing at QoS 2, packetId: 3
************************************************
Subscribe acknowledged.
  packetId: 1
  qos: 2
Publish received.
  topic: async-mqtt/ESP32_SC_W5500_Pub
  qos: 0
  dup: 0
  retain: 0
  len: 16
  index: 0
  total: 16
Publish acknowledged.
  packetId: 2
Publish received.
  topic: async-mqtt/ESP32_SC_W5500_Pub
  qos: 1
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish received.
  topic: async-mqtt/ESP32_SC_W5500_Pub
  qos: 2
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish acknowledged.
  packetId: 3
```

---

#### 2. FullyFeatureSSL_ESP32_SC_W5500 on ESP32S3_DEV with ESP32_S3_W5500

This is terminal debug output when running [FullyFeaturedSSL_ESP32_SC_W5500](examples/ESP32_SC_W5500/FullyFeaturedSSL_ESP32_SC_W5500) on **ESP32S3_DEV** with `LwIP W5500`, connecting to `broker.emqx.io` secured MQTTS server (port 8883)


```cpp
Starting FullyFeatureSSL_ESP32_SC_W5500 on ESP32S3_DEV with ESP32_S3_W5500
WebServer_ESP32_SC_W5500 v1.2.1 for core v2.0.0+
AsyncMQTT_ESP32 v1.10.0 for ESP32 core v2.0.0+
ETH starting
ETH connected
ETH got IP
IP address: 192.168.2.125
Connecting to MQTT...
Connected to MQTT broker: broker.emqx.io, port: 8883
PubTopic: async-mqtt/ESP32_W5500_SSL_Pub
************************************************
Session present: 0
Subscribing at QoS 2, packetId: 1
Publishing at QoS 0
Publishing at QoS 1, packetId: 2
Publishing at QoS 2, packetId: 3
************************************************
Subscribe acknowledged.
  packetId: 1
  qos: 2
Publish received.
  topic: async-mqtt/ESP32_W5500_SSL_Pub
  qos: 0
  dup: 0
  retain: 0
  len: 16
  index: 0
  total: 16
Publish acknowledged
  packetId: 2
Publish received.
  topic: async-mqtt/ESP32_W5500_SSL_Pub
  qos: 1
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish received.
  topic: async-mqtt/ESP32_W5500_SSL_Pub
  qos: 2
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish acknowledged
  packetId: 3
```

---

#### 3. FullyFeature_ESP32_SC_ENC on ESP32S3_DEV with ESP32_S3_ENC28J60

This is terminal debug output when running [FullyFeatured_ESP32_SC_ENC](examples/ESP32_SC_ENC/FullyFeatured_ESP32_SC_ENC) on **ESP32S3_DEV** with `LwIP ENC28J60`, connecting to `broker.emqx.io` MQTT server.

```cpp
Starting FullyFeature_ESP32_SC_ENC on ESP32S3_DEV with ESP32_S3_ENC28J60
WebServer_ESP32_SC_ENC v1.2.0 for core v2.0.0+
AsyncMQTT_ESP32 v1.10.0 for ESP32 core v2.0.0+
ETH starting
ETH connected
ETH got IP
IP address: 192.168.2.88
Connecting to MQTT...
Connected to MQTT broker: broker.emqx.io, port: 1883
PubTopic: async-mqtt/ESP32_SC_ENC_Pub
************************************************
Session present: 0
Subscribing at QoS 2, packetId: 1
Publishing at QoS 0
Publishing at QoS 1, packetId: 2
Publishing at QoS 2, packetId: 3
************************************************
Subscribe acknowledged.
  packetId: 1
  qos: 2
Publish received.
  topic: async-mqtt/ESP32_SC_ENC_Pub
  qos: 0
  dup: 0
  retain: 0
  len: 14
  index: 0
  total: 14
Publish acknowledged.
  packetId: 2
Publish received.
  topic: async-mqtt/ESP32_SC_ENC_Pub
  qos: 1
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish received.
  topic: async-mqtt/ESP32_SC_ENC_Pub
  qos: 2
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish acknowledged.
  packetId: 3
```

---

#### 4. FullyFeatureSSL_ESP32_SC_ENC on ESP32S3_DEV with ESP32_S3_ENC28J60

This is terminal debug output when running [FullyFeaturedSSL_ESP32_SC_ENC](examples/ESP32_SC_ENC/FullyFeaturedSSL_ESP32_SC_ENC) on **ESP32S3_DEV** with `LwIP ENC28J60`, connecting to `broker.emqx.io` secured MQTTS server (port 8883)


```cpp
Starting FullyFeatureSSL_ESP32_SC_ENC on ESP32S3_DEV with ESP32_S3_ENC28J60
WebServer_ESP32_SC_ENC v1.2.0 for core v2.0.0+
AsyncMQTT_ESP32 v1.10.0 for ESP32 core v2.0.0+
ETH starting
ETH connected
ETH got IP
IP address: 192.168.2.109
Connecting to MQTT...
Connected to MQTT broker: broker.emqx.io, port: 8883
PubTopic: async-mqtt/ESP32_SC_ENC_SSL_Pub
************************************************
Session present: 0
Subscribing at QoS 2, packetId: 1
Publishing at QoS 0
Publishing at QoS 1, packetId: 2
Publishing at QoS 2, packetId: 3
************************************************
Subscribe acknowledged.
  packetId: 1
  qos: 2
Publish received.
  topic: async-mqtt/ESP32_SC_ENC_SSL_Pub
  qos: 0
  dup: 0
  retain: 0
  len: 17
  index: 0
  total: 17
Publish acknowledged
  packetId: 2
Publish received.
  topic: async-mqtt/ESP32_SC_ENC_SSL_Pub
  qos: 1
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish received.
  topic: async-mqtt/ESP32_SC_ENC_SSL_Pub
  qos: 2
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish acknowledged
  packetId: 3
```

---

#### 5. FullyFeatureSSL_WT32_ETH01 on WT32-ETH01 with ETH_PHY_LAN8720

This is terminal debug output when running [FullyFeaturedSSL_WT32_ETH01](examples/WT32_ETH01/FullyFeaturedSSL_WT32_ETH01) on **WT32-ETH01** connecting to `broker.emqx.io` secured MQTT server (port 8883)


```cpp
Starting FullyFeatureSSL_WT32_ETH01 on WT32-ETH01 with ETH_PHY_LAN8720
WebServer_WT32_ETH01 v1.5.1 for core v2.0.0+
AsyncMQTT_ESP32 v1.10.0 for ESP32 core v2.0.0+
ETH starting
ETH connected
ETH got IP
IP address: 192.168.2.97
Connecting to MQTT...
Connected to MQTT broker: broker.emqx.io, port: 8883
PubTopic: async-mqtt/WT32_ETH01_SSL_Pub
************************************************
Session present: 0
Subscribing at QoS 2, packetId: 1
Publishing at QoS 0
Publishing at QoS 1, packetId: 2
Publishing at QoS 2, packetId: 3
************************************************
Subscribe acknowledged.
  packetId: 1
  qos: 2
Publish received.
  topic: async-mqtt/WT32_ETH01_SSL_Pub
  qos: 0
  dup: 0
  retain: 0
  len: 15
  index: 0
  total: 15
Publish acknowledged
  packetId: 2
Publish received.
  topic: async-mqtt/WT32_ETH01_SSL_Pub
  qos: 1
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish received.
  topic: async-mqtt/WT32_ETH01_SSL_Pub
  qos: 2
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish acknowledged
  packetId: 3
```


---

#### 6. FullyFeatureSSL_ESP32_SC_W5500 on ESP32S2_DEV with ESP32_S2_W5500

This is terminal debug output when running [FullyFeaturedSSL_ESP32_SC_W5500](examples/ESP32_SC_W5500/FullyFeaturedSSL_ESP32_SC_W5500) on **ESP32S2_DEV** connecting to `broker.emqx.io` secured MQTT server (port 8883)


```cpp
Starting FullyFeatureSSL_ESP32_SC_W5500 on ESP32S2_DEV with ESP32_S2_W5500
WebServer_ESP32_SC_W5500 v1.2.1 for core v2.0.0+
AsyncMQTT_ESP32 v1.10.0 for ESP32 core v2.0.0+
Using built-in mac_eth = 7E:DF:A1:08:32:C9
ETH starting
ETH connected
ETH got IP
IP address: 192.168.2.133
Connecting to MQTT...
Connected to MQTT broker: broker.emqx.io, port: 8883
PubTopic: async-mqtt/ESP32_W5500_SSL_Pub
************************************************
Session present: 0
Subscribing at QoS 2, packetId: 1
Publishing at QoS 0
Publishing at QoS 1, packetId: 2
Publishing at QoS 2, packetId: 3
************************************************
Subscribe acknowledged.
  packetId: 1
  qos: 2
Publish received.
  topic: async-mqtt/ESP32_W5500_SSL_Pub
  qos: 2
  dup: 0
  retain: 1
  len: 6
  index: 0
  total: 6
Publish received.
  topic: async-mqtt/ESP32_W5500_SSL_Pub
  qos: 0
  dup: 0
  retain: 0
  len: 16
  index: 0
  total: 16
Publish acknowledged
  packetId: 2
Publish received.
  topic: async-mqtt/ESP32_W5500_SSL_Pub
  qos: 1
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish received.
  topic: async-mqtt/ESP32_W5500_SSL_Pub
  qos: 2
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish acknowledged
  packetId: 3
```


---

#### 7. FullyFeatureSSL_ESP32_SC_W5500 on ESP32C3_DEV with ESP32_C3_W5500

This is terminal debug output when running [FullyFeaturedSSL_ESP32_SC_W5500](examples/ESP32_SC_W5500/FullyFeaturedSSL_ESP32_SC_W5500) on **ESP32C3_DEV** connecting to `broker.emqx.io` secured MQTT server (port 8883)


```cpp
Starting FullyFeatureSSL_ESP32_SC_W5500 on ESP32C3_DEV with ESP32_C3_W5500
WebServer_ESP32_SC_W5500 v1.2.1 for core v2.0.0+
AsyncMQTT_ESP32 v1.10.0 for ESP32 core v2.0.0+
Using built-in mac_eth = 7C:DF:A1:BC:BC:53
ETH starting
ETH connected
ETH got IP
IP address: 192.168.2.135
Connecting to MQTT...
Connected to MQTT broker: broker.emqx.io, port: 8883
PubTopic: async-mqtt/ESP32_W5500_SSL_Pub
************************************************
Session present: 0
Subscribing at QoS 2, packetId: 1
Publishing at QoS 0
Publishing at QoS 1, packetId: 2
Publishing at QoS 2, packetId: 3
************************************************
Subscribe acknowledged.
  packetId: 1
  qos: 2
Publish received.
  topic: async-mqtt/ESP32_W5500_SSL_Pub
  qos: 2
  dup: 0
  retain: 1
  len: 6
  index: 0
  total: 6
Publish received.
  topic: async-mqtt/ESP32_W5500_SSL_Pub
  qos: 0
  dup: 0
  retain: 0
  len: 16
  index: 0
  total: 16
Publish acknowledged
  packetId: 2
Publish received.
  topic: async-mqtt/ESP32_W5500_SSL_Pub
  qos: 1
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish received.
  topic: async-mqtt/ESP32_W5500_SSL_Pub
  qos: 2
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish acknowledged
  packetId: 3
```


---

#### 8. FullyFeatureSSL_ESP32_SC_ENC on ESP32C3_DEV with ESP32_C3_ENC28J60

This is terminal debug output when running [FullyFeaturedSSL_ESP32_SC_ENC](examples/ESP32_SC_ENC/FullyFeaturedSSL_ESP32_SC_ENC) on **ESP32C3_DEV** connecting to `broker.emqx.io` secured MQTT server (port 8883)


```cpp
Starting FullyFeatureSSL_ESP32_SC_ENC on ESP32C3_DEV with ESP32_C3_ENC28J60
WebServer_ESP32_SC_ENC v1.2.0 for core v2.0.0+
AsyncMQTT_ESP32 v1.10.0 for ESP32 core v2.0.0+
Using built-in mac_eth = 7C:DF:A1:DA:66:87
ETH starting
ETH connected
ETH got IP
IP address: 192.168.2.136
Connecting to MQTT...
Connected to MQTT broker: broker.emqx.io, port: 8883
PubTopic: async-mqtt/ESP32_SC_ENC_SSL_Pub
************************************************
Session present: 0
Subscribing at QoS 2, packetId: 1
Publishing at QoS 0
Publishing at QoS 1, packetId: 2
Publishing at QoS 2, packetId: 3
************************************************
Subscribe acknowledged.
  packetId: 1
  qos: 2
Publish received.
  topic: async-mqtt/ESP32_SC_ENC_SSL_Pub
  qos: 2
  dup: 0
  retain: 1
  len: 6
  index: 0
  total: 6
Publish received.
  topic: async-mqtt/ESP32_SC_ENC_SSL_Pub
  qos: 0
  dup: 0
  retain: 0
  len: 17
  index: 0
  total: 17
Publish acknowledged
  packetId: 2
Publish received.
  topic: async-mqtt/ESP32_SC_ENC_SSL_Pub
  qos: 1
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish received.
  topic: async-mqtt/ESP32_SC_ENC_SSL_Pub
  qos: 2
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish acknowledged
  packetId: 3
```


---

#### 9. FullyFeature_ESP32_W6100 on ESP32_DEV with ESP32_W6100

This is terminal debug output when running [FullyFeatured_ESP32_W6100](examples/ESP32_W6100/FullyFeatured_ESP32_W6100) on **ESP32_DEV** connecting to `broker.emqx.io` secured MQTT server (port 1883)


```cpp
Starting FullyFeature_ESP32_W6100 on ESP32_DEV with ESP32_W6100
WebServer_ESP32_W6100 v1.5.2 for core v2.0.0+
AsyncMQTT_ESP32 v1.10.0 for ESP32 core v2.0.0+
ETH starting
ETH connected
ETH got IP
IP address: 192.168.2.158
Connecting to MQTT...
Connected to MQTT broker: broker.emqx.io, port: 1883
PubTopic: async-mqtt/ESP32_W6100_Pub
************************************************
Session present: 0
Subscribing at QoS 2, packetId: 1
Publishing at QoS 0
Publishing at QoS 1, packetId: 2
Publishing at QoS 2, packetId: 3
************************************************
Subscribe acknowledged.
  packetId: 1
  qos: 2
Publish received.
  topic: async-mqtt/ESP32_W6100_Pub
  qos: 0
  dup: 0
  retain: 0
  len: 16
  index: 0
  total: 16
Publish acknowledged.
  packetId: 2
Publish received.
  topic: async-mqtt/ESP32_W6100_Pub
  qos: 1
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish received.
  topic: async-mqtt/ESP32_W6100_Pub
  qos: 2
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish acknowledged.
  packetId: 3
```


---

#### 10. FullyFeatureSSL_ESP32_SC_W6100 on ESP32S3_DEV with ESP32_S3_W6100

This is terminal debug output when running [FullyFeaturedSSL_ESP32_SC_W6100](examples/ESP32_SC_W6100/FullyFeaturedSSL_ESP32_SC_W6100) on **ESP32S3_DEV** connecting to `broker.emqx.io` secured MQTT server (port 8883)


```cpp
Starting FullyFeatureSSL_ESP32_SC_W6100 on ESP32S3_DEV with ESP32_S3_W6100
WebServer_ESP32_SC_W6100 v1.2.1 for core v2.0.0+
AsyncMQTT_ESP32 v1.10.0 for ESP32 core v2.0.0+
ETH starting
ETH connected
ETH got IP
IP address: 192.168.2.92
Connecting to MQTT...
Connected to MQTT broker: broker.emqx.io, port: 8883
PubTopic: async-mqtt/ESP32_W6100_SSL_Pub
************************************************
Session present: 0
Subscribing at QoS 2, packetId: 1
Publishing at QoS 0
Publishing at QoS 1, packetId: 2
Publishing at QoS 2, packetId: 3
************************************************
Subscribe acknowledged.
  packetId: 1
  qos: 2
Publish received.
  topic: async-mqtt/ESP32_W6100_SSL_Pub
  qos: 2
  dup: 0
  retain: 1
  len: 6
  index: 0
  total: 6
Publish received.
  topic: async-mqtt/ESP32_W6100_SSL_Pub
  qos: 0
  dup: 0
  retain: 0
  len: 16
  index: 0
  total: 16
Publish acknowledged
  packetId: 2
Publish received.
  topic: async-mqtt/ESP32_W6100_SSL_Pub
  qos: 1
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish received.
  topic: async-mqtt/ESP32_W6100_SSL_Pub
  qos: 2
  dup: 0
  retain: 0
  len: 6
  index: 0
  total: 6
Publish acknowledged
  packetId: 3
```


---
---

### Debug

Debug is enabled by default on Serial. Debug Level from 0 to 4. To disable, change the _MYSQL_LOGLEVEL_ to 0

```cpp
#define ASYNC_MQTT_DEBUG_PORT               Serial

// Debug Level from 0 to 4
#define _ASYNC_MQTT_LOGLEVEL_               1
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.


---
---


### Issues ###

Submit issues to: [AsyncMQTT_ESP32 issues](https://github.com/khoih-prog/AsyncMQTT_ESP32/issues)

---
---

### TO DO

 1. Bug fixing.

---

### DONE

 1. Add support to any `ESP32/S2/S3/C3` boards using WiFi with `SSL/TLS`
 2. Add support to `ESP32` boards using `LwIP W5500 / ENC28J60 / LAN8720 Ethernet` with `SSL/TLS`
 3. Add support to `ESP32S3` boards using `LwIP W5500 / ENC28J60 / LAN8720 Ethernet` with `SSL/TLS`
 4. Add support to `ESP32S2` boards using `LwIP W5500 / ENC28J60 / LAN8720 Ethernet` with `SSL/TLS`
 5. Add support to `ESP32C3` boards using `LwIP W5500 / ENC28J60 / LAN8720 Ethernet` with `SSL/TLS`
 6. Add support to `ESP32` and `ESP32S2/S3/C3` boards using `LwIP W6100 Ethernet` with `SSL/TLS`
 
 
---
---

### Contributions and Thanks

1. Based on and modified from [**Marvin Roger's async-mqtt-client Library**](https://github.com/marvinroger/async-mqtt-client)


<table>
  <tr>
    <td align="center"><a href="https://github.com/marvinroger"><img src="https://github.com/marvinroger.png" width="100px;" alt="marvinroger"/><br /><sub><b>⭐️ Marvin Roger</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- Many of the credits go to original author [Marvin Roger](https://github.com/marvinroger)

- The library is licensed under [MIT](https://github.com/khoih-prog/AsyncMQTT_ESP32/blob/main/LICENSE)

---

## Copyright

1. Copyright (c) 2017- Marvin Roger
2. Copyright (c) 2022- Khoi Hoang

