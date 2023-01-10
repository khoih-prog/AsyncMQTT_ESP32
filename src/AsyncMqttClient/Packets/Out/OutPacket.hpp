/****************************************************************************************************************************
  OutPacket.hpp
  
  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/

#pragma once

#ifndef OUT_PACKET_HPP
#define OUT_PACKET_HPP

#include <stdint.h>  // uint*_t
#include <stddef.h>  // size_t
#include <algorithm>  // std::min

#include "../../Flags.hpp"

namespace AsyncMqttClientInternals 
{
  class OutPacket 
  {
    public:
      OutPacket();
      virtual ~OutPacket();
      virtual const uint8_t* data(size_t index = 0) const = 0;
      virtual size_t size() const = 0;
      bool released() const;
      uint8_t packetType() const;
      uint16_t packetId() const;
      uint8_t qos() const;
      void release();

    public:
      OutPacket* next;
      uint32_t timeout;
      uint8_t noTries;

    protected:
      static uint16_t _getNextPacketId();
      bool _released;
      uint16_t _packetId;

    private:
      static uint16_t _nextPacketId;  
  };
}  // namespace AsyncMqttClientInternals

#endif    // OUT_PACKET_HPP
