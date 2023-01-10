/****************************************************************************************************************************
  Packet.hpp
  
  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/
 
#ifndef PACKET_HPP
#define PACKET_HPP

namespace AsyncMqttClientInternals 
{
  class Packet 
  {
   public:
    virtual ~Packet() {}

    virtual void parseVariableHeader(char* data, size_t len, size_t* currentBytePosition) = 0;
    virtual void parsePayload(char* data, size_t len, size_t* currentBytePosition) = 0;
  };
}  // namespace AsyncMqttClientInternals

#endif    // PACKET_HPP
