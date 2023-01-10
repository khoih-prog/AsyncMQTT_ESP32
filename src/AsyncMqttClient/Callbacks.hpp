/****************************************************************************************************************************
  Callbacks.hpp
  
  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/

#pragma once

#ifndef CALLBACKS_HPP
#define CALLBACKS_HPP

#include <functional>

#include "DisconnectReasons.hpp"
#include "MessageProperties.hpp"
#include "Errors.hpp"

namespace AsyncMqttClientInternals 
{
  // user callbacks
  typedef std::function<void(bool sessionPresent)> OnConnectUserCallback;
  typedef std::function<void(AsyncMqttClientDisconnectReason reason)> OnDisconnectUserCallback;
  typedef std::function<void(uint16_t packetId, uint8_t qos)> OnSubscribeUserCallback;
  typedef std::function<void(uint16_t packetId)> OnUnsubscribeUserCallback;
  typedef std::function<void(char* topic, char* payload, AsyncMqttClientMessageProperties properties, size_t len, size_t index, size_t total)> OnMessageUserCallback;
  typedef std::function<void(uint16_t packetId)> OnPublishUserCallback;
  typedef std::function<void(uint16_t packetId, AsyncMqttClientError error)> OnErrorUserCallback;

  // internal callbacks
  typedef std::function<void(bool sessionPresent, uint8_t connectReturnCode)> OnConnAckInternalCallback;
  typedef std::function<void()> OnPingRespInternalCallback;
  typedef std::function<void(uint16_t packetId, char status)> OnSubAckInternalCallback;
  typedef std::function<void(uint16_t packetId)> OnUnsubAckInternalCallback;
  typedef std::function<void(char* topic, char* payload, uint8_t qos, bool dup, bool retain, size_t len, size_t index, size_t total, uint16_t packetId)> OnMessageInternalCallback;
  typedef std::function<void(uint16_t packetId, uint8_t qos)> OnPublishInternalCallback;
  typedef std::function<void(uint16_t packetId)> OnPubRelInternalCallback;
  typedef std::function<void(uint16_t packetId)> OnPubAckInternalCallback;
  typedef std::function<void(uint16_t packetId)> OnPubRecInternalCallback;
  typedef std::function<void(uint16_t packetId)> OnPubCompInternalCallback;
}  // namespace AsyncMqttClientInternals

#endif		// CALLBACKS_HPP
