/****************************************************************************************************************************
  PubRelPacket.hpp
  
  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/
 
#pragma once

#ifndef PUB_REL_PACKET_HPP
#define PUB_REL_PACKET_HPP

#include "Arduino.h"
#include "Packet.hpp"
#include "../ParsingInformation.hpp"
#include "../Callbacks.hpp"

namespace AsyncMqttClientInternals 
{
  class PubRelPacket : public Packet 
  {
   public:
    explicit PubRelPacket(ParsingInformation* parsingInformation, OnPubRelInternalCallback callback);
    ~PubRelPacket();

    void parseVariableHeader(char* data, size_t len, size_t* currentBytePosition);
    void parsePayload(char* data, size_t len, size_t* currentBytePosition);

   private:
    ParsingInformation* _parsingInformation;
    OnPubRelInternalCallback _callback;

    uint8_t _bytePosition;
    char _packetIdMsb;
    uint16_t _packetId;
  };
}  // namespace AsyncMqttClientInternals

#endif    // PUB_REL_PACKET_HPP
