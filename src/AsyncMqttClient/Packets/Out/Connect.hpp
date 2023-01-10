/****************************************************************************************************************************
  Connect.hpp
  
  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/

#pragma once

#ifndef CONNECT_HPP
#define CONNECT_HPP

#include <vector>
#include <cstring>  // strlen

#include "OutPacket.hpp"
#include "../../Flags.hpp"
#include "../../Helpers.hpp"

namespace AsyncMqttClientInternals 
{
  class ConnectOutPacket : public OutPacket 
  {
    public:
    ConnectOutPacket(bool cleanSession,
                     const char* username,
                     const char* password,
                     const char* willTopic,
                     bool willRetain,
                     uint8_t willQos,
                     const char* willPayload,
                     uint16_t willPayloadLength,
                     uint16_t keepAlive,
                     const char* clientId);
    const uint8_t* data(size_t index = 0) const;
    size_t size() const;

    private:
    std::vector<uint8_t> _data;
  };
}  // namespace AsyncMqttClientInternals

#endif    // CONNECT_HPP
