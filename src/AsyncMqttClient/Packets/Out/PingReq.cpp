/****************************************************************************************************************************
  PingReq.cpp

  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/

#include "PingReq.hpp"

using AsyncMqttClientInternals::PingReqOutPacket;

PingReqOutPacket::PingReqOutPacket()
{
  _data[0] = AsyncMqttClientInternals::PacketType.PINGREQ;
  _data[0] = _data[0] << 4;
  _data[0] = _data[0] | AsyncMqttClientInternals::HeaderFlag.PINGREQ_RESERVED;
  _data[1] = 0;
}

const uint8_t* PingReqOutPacket::data(size_t index) const
{
  return &_data[index];;
}

size_t PingReqOutPacket::size() const
{
  return 2;
}
