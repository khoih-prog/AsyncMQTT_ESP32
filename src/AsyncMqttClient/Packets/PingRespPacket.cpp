/****************************************************************************************************************************
  PingRespPacket.cpp

  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/

#include "PingRespPacket.hpp"

using AsyncMqttClientInternals::PingRespPacket;

PingRespPacket::PingRespPacket(ParsingInformation* parsingInformation, OnPingRespInternalCallback callback)
  : _parsingInformation(parsingInformation)
  , _callback(callback)
{
}

PingRespPacket::~PingRespPacket()
{
}

void PingRespPacket::parseVariableHeader(char* data, size_t len, size_t* currentBytePosition)
{
  (void)data;
  (void)len;
  (void)currentBytePosition;
}

void PingRespPacket::parsePayload(char* data, size_t len, size_t* currentBytePosition)
{
  (void)data;
  (void)len;
  (void)currentBytePosition;
}
