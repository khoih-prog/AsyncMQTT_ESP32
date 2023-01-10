/****************************************************************************************************************************
  AsyncMQTT_ESP32.hpp
  
  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32

  Version: 1.10.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.8.0    K Hoang     17/12/2022 Initial coding to port to ESP32 boards using WiFi or LwIP W5500, LAN8720 or ENC28J60
  1.9.0    K Hoang     21/12/2022 Add support to ESP32S2/C3 boards using LwIP W5500 or ENC28J60 Ethernet
  1.10.0   K Hoang     09/01/2023 Add support to ESP32 and ESP32S2/S3/C3 boards using LwIP W6100
 *****************************************************************************************************************************/

#pragma once

#ifndef ASYNC_MQTT_ESP32_HPP
#define ASYNC_MQTT_ESP32_HPP

#include <functional>
#include <vector>

#include "Arduino.h"

#ifndef MQTT_MIN_FREE_MEMORY
#define MQTT_MIN_FREE_MEMORY 4096
#endif

/////////////////////////////////////////////////////////

#define ASYNC_MQTT_ESP32_SHORT_VERSION        "AsyncMQTT_ESP32 v1.10.0" 

/////////////////////////////////////////////////////////

#define ASYNC_MQTT_ESP32_VERSION_MAJOR       1
#define ASYNC_MQTT_ESP32_VERSION_MINOR       10
#define ASYNC_MQTT_ESP32_VERSION_PATCH       0

#define ASYNC_MQTT_ESP32_VERSION_INT         1010000

/////////////////////////////////////////////////////////

#if defined(ESP32)

  #if ( ( defined(ESP_ARDUINO_VERSION_MAJOR) && (ESP_ARDUINO_VERSION_MAJOR >= 2) ) && ( ARDUINO_ESP32_GIT_VER != 0x46d5afb1 ) )
    #define USING_CORE_ESP32_CORE_V200_PLUS      true
    
    #if (_ASYNC_MQTT_LOGLEVEL_ > 3)
      #warning Using code for ESP32 core v2.0.0+ in AsyncMQTT_ESP32.hpp
    #endif
      
    #define ASYNC_MQTT_ESP32_VERSION        (ASYNC_MQTT_ESP32_SHORT_VERSION " for ESP32 core v2.0.0+")

  #else
    #if (_ASYNC_MQTT_LOGLEVEL_ > 3)
      #warning Using code for ESP32 core v1.0.6- in AsyncMQTT_ESP32.hpp
    #endif
    
    #define ASYNC_MQTT_ESP32_VERSION        (ASYNC_MQTT_ESP32_SHORT_VERSION " for ESP32 core v1.0.6-")
    
  #endif

  #if ASYNC_TCP_SSL_ENABLED
    #include <AsyncTCP_SSL.h>
    #warning ESP32 ASYNC_TCP_SSL_ENABLED
  #else
    #include <AsyncTCP.h>
  #endif
  
  #include <freertos/semphr.h>

/////////////////////////////////////////////////////////
         
#else
  #error This library is currently supporting only ESP32 using WiFi or LwIP Ethernet
#endif

/////////////////////////////////////////////////////////

#if ASYNC_TCP_SSL_ENABLED
  #include <tcp_mbedtls.h>
  
  #define SHA1_SIZE 20
#endif

/////////////////////////////////////////////////////////

#define SEMAPHORE_TAKE()      xSemaphoreTake(_xSemaphore, portMAX_DELAY)
#define SEMAPHORE_GIVE()      xSemaphoreGive(_xSemaphore)
#define GET_FREE_MEMORY()     ESP.getMaxAllocHeap()
#include <esp32-hal-log.h>

/////////////////////////////////////////////////////////

#include "AsyncMQTT_ESP32_Debug.h"

#include "AsyncMqttClient/Flags.hpp"
#include "AsyncMqttClient/ParsingInformation.hpp"
#include "AsyncMqttClient/MessageProperties.hpp"
#include "AsyncMqttClient/Helpers.hpp"
#include "AsyncMqttClient/Callbacks.hpp"
#include "AsyncMqttClient/DisconnectReasons.hpp"
#include "AsyncMqttClient/Storage.hpp"

#include "AsyncMqttClient/Packets/Packet.hpp"
#include "AsyncMqttClient/Packets/ConnAckPacket.hpp"
#include "AsyncMqttClient/Packets/PingRespPacket.hpp"
#include "AsyncMqttClient/Packets/SubAckPacket.hpp"
#include "AsyncMqttClient/Packets/UnsubAckPacket.hpp"
#include "AsyncMqttClient/Packets/PublishPacket.hpp"
#include "AsyncMqttClient/Packets/PubRelPacket.hpp"
#include "AsyncMqttClient/Packets/PubAckPacket.hpp"
#include "AsyncMqttClient/Packets/PubRecPacket.hpp"
#include "AsyncMqttClient/Packets/PubCompPacket.hpp"

#include "AsyncMqttClient/Packets/Out/Connect.hpp"
#include "AsyncMqttClient/Packets/Out/PingReq.hpp"
#include "AsyncMqttClient/Packets/Out/PubAck.hpp"
#include "AsyncMqttClient/Packets/Out/Disconn.hpp"
#include "AsyncMqttClient/Packets/Out/Subscribe.hpp"
#include "AsyncMqttClient/Packets/Out/Unsubscribe.hpp"
#include "AsyncMqttClient/Packets/Out/Publish.hpp"

/////////////////////////////////////////////////////////

class AsyncMqttClient 
{
 public:
  AsyncMqttClient();
  ~AsyncMqttClient();

  AsyncMqttClient& setKeepAlive(uint16_t keepAlive);
  AsyncMqttClient& setClientId(const char* clientId);
  AsyncMqttClient& setCleanSession(bool cleanSession);
  AsyncMqttClient& setMaxTopicLength(uint16_t maxTopicLength);
  AsyncMqttClient& setCredentials(const char* username, const char* password = nullptr);
  AsyncMqttClient& setWill(const char* topic, uint8_t qos, bool retain, const char* payload = nullptr, size_t length = 0);
  AsyncMqttClient& setServer(IPAddress ip, uint16_t port);
  AsyncMqttClient& setServer(const char* host, uint16_t port);
  
#if ASYNC_TCP_SSL_ENABLED
  AsyncMqttClient& setSecure(bool secure);
  AsyncMqttClient& addServerFingerprint(const uint8_t* fingerprint);
#endif

  AsyncMqttClient& onConnect(AsyncMqttClientInternals::OnConnectUserCallback callback);
  AsyncMqttClient& onDisconnect(AsyncMqttClientInternals::OnDisconnectUserCallback callback);
  AsyncMqttClient& onSubscribe(AsyncMqttClientInternals::OnSubscribeUserCallback callback);
  AsyncMqttClient& onUnsubscribe(AsyncMqttClientInternals::OnUnsubscribeUserCallback callback);
  AsyncMqttClient& onMessage(AsyncMqttClientInternals::OnMessageUserCallback callback);
  AsyncMqttClient& onPublish(AsyncMqttClientInternals::OnPublishUserCallback callback);

  bool connected() const;
  void connect();
  void disconnect(bool force = false);
  uint16_t subscribe(const char* topic, uint8_t qos);
  uint16_t unsubscribe(const char* topic);
  uint16_t publish(const char* topic, uint8_t qos, bool retain, const char* payload = nullptr, 
                   size_t length = 0, bool dup = false, uint16_t message_id = 0);
                   
  bool clearQueue();  // Not MQTT compliant!

  const char* getClientId() const;

 private:
 
#if ASYNC_TCP_SSL_ENABLED
  AsyncSSLClient _client;
#else
  AsyncClient _client;
#endif  
  
  AsyncMqttClientInternals::OutPacket* _head;
  AsyncMqttClientInternals::OutPacket* _tail;
  size_t _sent;
  
  enum 
  {
    CONNECTING,
    CONNECTED,
    DISCONNECTING,
    DISCONNECTED
  } _state;
  
  AsyncMqttClientDisconnectReason _disconnectReason;
  uint32_t _lastClientActivity;
  uint32_t _lastServerActivity;
  uint32_t _lastPingRequestTime;

  char _generatedClientId[18 + 1];  // esp8266-abc123, esp32-abcdef123456 or stm32-abcdef123456
  IPAddress _ip;
  const char* _host;
  bool _useIp;
  
#if ASYNC_TCP_SSL_ENABLED
  bool _secure;
#endif

  uint16_t _port;
  uint16_t _keepAlive;
  bool _cleanSession;
  const char* _clientId;
  const char* _username;
  const char* _password;
  const char* _willTopic;
  const char* _willPayload;
  uint16_t _willPayloadLength;
  uint8_t _willQos;
  bool _willRetain;

#if ASYNC_TCP_SSL_ENABLED
  std::vector<std::array<uint8_t, SHA1_SIZE>> _secureServerFingerprints;
#endif

  std::vector<AsyncMqttClientInternals::OnConnectUserCallback> _onConnectUserCallbacks;
  std::vector<AsyncMqttClientInternals::OnDisconnectUserCallback> _onDisconnectUserCallbacks;
  std::vector<AsyncMqttClientInternals::OnSubscribeUserCallback> _onSubscribeUserCallbacks;
  std::vector<AsyncMqttClientInternals::OnUnsubscribeUserCallback> _onUnsubscribeUserCallbacks;
  std::vector<AsyncMqttClientInternals::OnMessageUserCallback> _onMessageUserCallbacks;
  std::vector<AsyncMqttClientInternals::OnPublishUserCallback> _onPublishUserCallbacks;

  AsyncMqttClientInternals::ParsingInformation _parsingInformation;
  AsyncMqttClientInternals::Packet* _currentParsedPacket;
  uint8_t _remainingLengthBufferPosition;
  char _remainingLengthBuffer[4];

  std::vector<AsyncMqttClientInternals::PendingPubRel> _pendingPubRels;

  SemaphoreHandle_t _xSemaphore = nullptr;

  void _clear();
  void _freeCurrentParsedPacket();

  // TCP
  void _onConnect();
  void _onDisconnect();
  // void _onError(int8_t error);
  // void _onTimeout();
  void _onAck(size_t len);
  void _onData(char* data, size_t len);
  void _onPoll();

  // QUEUE
  void _insert(AsyncMqttClientInternals::OutPacket* packet);    // for PUBREL
  void _addFront(AsyncMqttClientInternals::OutPacket* packet);  // for CONNECT
  void _addBack(AsyncMqttClientInternals::OutPacket* packet);   // all the rest
  void _handleQueue();
  void _clearQueue(bool keepSessionData);

  // MQTT
  void _onPingResp();
  void _onConnAck(bool sessionPresent, uint8_t connectReturnCode);
  void _onSubAck(uint16_t packetId, char status);
  void _onUnsubAck(uint16_t packetId);
  void _onMessage(char* topic, char* payload, uint8_t qos, bool dup, bool retain, size_t len, 
                  size_t index, size_t total, uint16_t packetId);
  void _onPublish(uint16_t packetId, uint8_t qos);
  void _onPubRel(uint16_t packetId);
  void _onPubAck(uint16_t packetId);
  void _onPubRec(uint16_t packetId);
  void _onPubComp(uint16_t packetId);

  void _sendPing();
  
#if ASYNC_MQTT_USING_TEENSY41_QNETHERNET
  uint8_t* getTeensyMac(uint8_t* _macAddress);
#endif  
};

#endif    // ASYNC_MQTT_ESP32_HPP
