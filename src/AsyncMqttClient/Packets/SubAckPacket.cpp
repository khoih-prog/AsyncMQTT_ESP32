/****************************************************************************************************************************
  SubAckPacket.cpp

  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/

#include "SubAckPacket.hpp"

using AsyncMqttClientInternals::SubAckPacket;

SubAckPacket::SubAckPacket(ParsingInformation* parsingInformation, OnSubAckInternalCallback callback)
  : _parsingInformation(parsingInformation)
  , _callback(callback)
  , _bytePosition(0)
  , _packetIdMsb(0)
  , _packetId(0)
{
}

SubAckPacket::~SubAckPacket()
{
}

void SubAckPacket::parseVariableHeader(char* data, size_t len, size_t* currentBytePosition)
{
  (void)len;

  char currentByte = data[(*currentBytePosition)++];

  if (_bytePosition++ == 0)
  {
    _packetIdMsb = currentByte;
  }
  else
  {
    _packetId = currentByte | _packetIdMsb << 8;
    _parsingInformation->bufferState = BufferState::PAYLOAD;
  }
}

void SubAckPacket::parsePayload(char* data, size_t len, size_t* currentBytePosition)
{
  (void)len;
  char status = data[(*currentBytePosition)++];

  /* switch (status) {
    case 0:
      Serial.println("Success QoS 0");
      break;
    case 1:
      Serial.println("Success QoS 1");
      break;
    case 2:
      Serial.println("Success QoS 2");
      break;
    case 0x80:
      Serial.println("Failure");
      break;
    } */

  _parsingInformation->bufferState = BufferState::NONE;
  _callback(_packetId, status);
}
