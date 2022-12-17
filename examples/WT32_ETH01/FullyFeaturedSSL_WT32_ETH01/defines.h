/****************************************************************************************************************************
  defines.h
  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500, LAN8720 or ENC28J60

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) async-mqtt-client (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 ***************************************************************************************************************************************/

#ifndef defines_h
#define defines_h

// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       1
#define _ASYNC_MQTT_LOGLEVEL_               4

#include <WebServer_WT32_ETH01.h>

// Select the IP address according to your local network
IPAddress myIP(192, 168, 2, 232);
IPAddress myGW(192, 168, 2, 1);
IPAddress mySN(255, 255, 255, 0);

// Google DNS Server IP
IPAddress myDNS(8, 8, 8, 8);

#endif    //defines_h
