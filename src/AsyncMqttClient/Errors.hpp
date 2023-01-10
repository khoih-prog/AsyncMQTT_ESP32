/****************************************************************************************************************************
  Errors.hpp
  
  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/

#pragma once

#ifndef ERRORS_HPP
#define ERRORS_HPP

enum class AsyncMqttClientError : uint8_t 
{
  MAX_RETRIES   = 0,
  OUT_OF_MEMORY = 1
};

#endif    // ERRORS_HPP
