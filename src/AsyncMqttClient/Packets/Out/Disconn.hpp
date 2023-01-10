/****************************************************************************************************************************
  Disconn.hpp
  
  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/

#pragma once

#ifndef DISCONN_HPP
#define DISCONN_HPP

#include "OutPacket.hpp"
#include "../../Flags.hpp"
#include "../../Helpers.hpp"

namespace AsyncMqttClientInternals 
{
  class DisconnOutPacket : public OutPacket 
  {
    public:
    DisconnOutPacket();
    const uint8_t* data(size_t index = 0) const;
    size_t size() const;

    private:
    uint8_t _data[2];
  };
}  // namespace AsyncMqttClientInternals

#endif    // DISCONN_HPP
