/****************************************************************************************************************************
  OutPacket.cpp

  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/

#include "OutPacket.hpp"

using AsyncMqttClientInternals::OutPacket;

OutPacket::OutPacket()
  : next(nullptr)
  , timeout(0)
  , noTries(0)
  , _released(true)
  , _packetId(0) {}

OutPacket::~OutPacket() {}

bool OutPacket::released() const
{
  return _released;
}

uint8_t OutPacket::packetType() const
{
  return data(0)[0] >> 4;
}

uint16_t OutPacket::packetId() const
{
  return _packetId;
}

uint8_t OutPacket::qos() const
{
  if (packetType() == AsyncMqttClientInternals::PacketType.PUBLISH)
  {
    return (data()[1] & 0x06) >> 1;
  }

  return 0;
}

void OutPacket::release()
{
  _released = true;
}

uint16_t OutPacket::_nextPacketId = 0;

uint16_t OutPacket::_getNextPacketId()
{
  if (++_nextPacketId == 0)
  {
    ++_nextPacketId;
  }

  return _nextPacketId;
}
