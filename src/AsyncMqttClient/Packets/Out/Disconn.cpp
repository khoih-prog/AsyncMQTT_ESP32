/****************************************************************************************************************************
  Disconn.cpp

  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/

#include "Disconn.hpp"

using AsyncMqttClientInternals::DisconnOutPacket;

DisconnOutPacket::DisconnOutPacket()
{
  _data[0] = AsyncMqttClientInternals::PacketType.DISCONNECT;
  _data[0] = _data[0] << 4;
  _data[0] = _data[0] | AsyncMqttClientInternals::HeaderFlag.DISCONNECT_RESERVED;
  _data[1] = 0;
}

const uint8_t* DisconnOutPacket::data(size_t index) const
{
  return &_data[index];
}

size_t DisconnOutPacket::size() const
{
  return 2;
}
