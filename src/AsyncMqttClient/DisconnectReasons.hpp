/****************************************************************************************************************************
  DisconnectReasons.hpp
  
  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/

#pragma once

#ifndef DISCONNECT_REASONS_HPP
#define DISCONNECT_REASONS_HPP

enum class AsyncMqttClientDisconnectReason : uint8_t 
{
  TCP_DISCONNECTED                    = 0,

  MQTT_UNACCEPTABLE_PROTOCOL_VERSION  = 1,
  MQTT_IDENTIFIER_REJECTED            = 2,
  MQTT_SERVER_UNAVAILABLE             = 3,
  MQTT_MALFORMED_CREDENTIALS          = 4,
  MQTT_NOT_AUTHORIZED                 = 5,

  ESP8266_NOT_ENOUGH_SPACE            = 6,

  TLS_BAD_FINGERPRINT                 = 7
};

#endif    // DISCONNECT_REASONS_HPP
