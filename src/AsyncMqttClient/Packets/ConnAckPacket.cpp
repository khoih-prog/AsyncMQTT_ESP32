/****************************************************************************************************************************
  ConnAckPacket.cpp

  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/

#include "ConnAckPacket.hpp"

using AsyncMqttClientInternals::ConnAckPacket;

ConnAckPacket::ConnAckPacket(ParsingInformation* parsingInformation, OnConnAckInternalCallback callback)
  : _parsingInformation(parsingInformation)
  , _callback(callback)
  , _bytePosition(0)
  , _sessionPresent(false)
  , _connectReturnCode(0)
{
}

ConnAckPacket::~ConnAckPacket()
{
}

void ConnAckPacket::parseVariableHeader(char* data, size_t len, size_t* currentBytePosition)
{
  (void)len;

  char currentByte = data[(*currentBytePosition)++];

  if (_bytePosition++ == 0)
  {
    _sessionPresent = (currentByte << 7) >> 7;
  }
  else
  {
    _connectReturnCode = currentByte;
    _parsingInformation->bufferState = BufferState::NONE;
    _callback(_sessionPresent, _connectReturnCode);
  }
}

void ConnAckPacket::parsePayload(char* data, size_t len, size_t* currentBytePosition)
{
  (void)data;
  (void)len;
  (void)currentBytePosition;
}
