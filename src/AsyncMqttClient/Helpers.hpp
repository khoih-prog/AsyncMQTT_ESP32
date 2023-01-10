/****************************************************************************************************************************
  Helpers.hpp
  
  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/

#pragma once

#ifndef HELPERS_HPP
#define HELPERS_HPP

namespace AsyncMqttClientInternals
{
class Helpers
{
  public:
    static uint32_t decodeRemainingLength(char* bytes)
    {
      uint32_t multiplier = 1;
      uint32_t value = 0;
      uint8_t currentByte = 0;
      uint8_t encodedByte;

      do
      {
        encodedByte = bytes[currentByte++];
        value += (encodedByte & 127) * multiplier;
        multiplier *= 128;
      } while ((encodedByte & 128) != 0);

      return value;
    }

    static uint8_t encodeRemainingLength(uint32_t remainingLength, char* destination)
    {
      uint8_t currentByte = 0;
      uint8_t bytesNeeded = 0;

      do
      {
        uint8_t encodedByte = remainingLength % 128;
        remainingLength /= 128;

        if (remainingLength > 0)
        {
          encodedByte = encodedByte | 128;
        }

        destination[currentByte++] = encodedByte;
        bytesNeeded++;
      } while (remainingLength > 0);

      return bytesNeeded;
    }
};

}  // namespace AsyncMqttClientInternals

#endif    // HELPERS_HPP
