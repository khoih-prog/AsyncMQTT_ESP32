/****************************************************************************************************************************
  PublishPacket.hpp
  
  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/
 
#pragma once

#ifndef PUBLISH_PACKET_HPP
#define PUBLISH_PACKET_HPP

#include "Arduino.h"
#include "Packet.hpp"
#include "../Flags.hpp"
#include "../ParsingInformation.hpp"
#include "../Callbacks.hpp"

namespace AsyncMqttClientInternals 
{
  class PublishPacket : public Packet 
  {
   public:
    explicit PublishPacket(ParsingInformation* parsingInformation, OnMessageInternalCallback dataCallback, OnPublishInternalCallback completeCallback);
    ~PublishPacket();

    void parseVariableHeader(char* data, size_t len, size_t* currentBytePosition);
    void parsePayload(char* data, size_t len, size_t* currentBytePosition);

   private:
    ParsingInformation* _parsingInformation;
    OnMessageInternalCallback _dataCallback;
    OnPublishInternalCallback _completeCallback;

    void _preparePayloadHandling(uint32_t payloadLength);

    bool _dup;
    uint8_t _qos;
    bool _retain;

    uint8_t _bytePosition;
    char _topicLengthMsb;
    uint16_t _topicLength;
    bool _ignore;
    char _packetIdMsb;
    uint16_t _packetId;
    uint32_t _payloadLength;
    uint32_t _payloadBytesRead;
  };
}  // namespace AsyncMqttClientInternals

#endif    // PUBLISH_PACKET_HPP
