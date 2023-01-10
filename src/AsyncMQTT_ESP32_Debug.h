/****************************************************************************************************************************
  AsyncMQTT_ESP32_Debug.h

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

#ifndef ASYNC_MQTT_ESP32_DEBUG_H
#define ASYNC_MQTT_ESP32_DEBUG_H

#ifdef ASYNC_MQTT_DEBUG_PORT
  #define DBG_PORT_AMQTT      ASYNC_MQTT_DEBUG_PORT
#else
  #define DBG_PORT_AMQTT      Serial
#endif

// Change _ASYNC_MQTT_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _ASYNC_MQTT_LOGLEVEL_
  #define _ASYNC_MQTT_LOGLEVEL_       1
#endif

/////////////////////////////////////////////////////////

#define AMQTT_PRINT_MARK      AMQTT_PRINT("[AMQTT] ")
#define AMQTT_PRINT_SP        DBG_PORT_AMQTT.print(" ")
#define AMQTT_PRINT_SP0X      DBG_PORT_AMQTT.print(" 0x")

#define AMQTT_PRINT           DBG_PORT_AMQTT.print
#define AMQTT_PRINTLN         DBG_PORT_AMQTT.println
#define AMQTT_PRINTF          DBG_PORT_AMQTT.printf

/////////////////////////////////////////////////////////

#define AMQTT_DEBUG(...)         if(_ASYNC_MQTT_LOGLEVEL_>3) { AMQTT_PRINTF(__VA_ARGS__); }
#define AMQTT_SSL_DEBUG(...)    if(_ASYNC_MQTT_LOGLEVEL_>3) { AMQTT_PRINTF(__VA_ARGS__); }

#define AMQTT_ASSERT( a )       do{ if(!(a)){AMQTT_PRINTF("ASSERT: %s %u \n", __FILE__, __LINE__);}}while(0)

/////////////////////////////////////////////////////////

#define AMQTT_LOGERROR(x)         if(_ASYNC_MQTT_LOGLEVEL_>0) { AMQTT_PRINT_MARK; AMQTT_PRINTLN(x); }
#define AMQTT_LOGERROR0(x)        if(_ASYNC_MQTT_LOGLEVEL_>0) { AMQTT_PRINT(x); }
#define AMQTT_LOGERROR1(x,y)      if(_ASYNC_MQTT_LOGLEVEL_>0) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP; AMQTT_PRINTLN(y); }
#define AMQTT_HEXLOGERROR1(x,y)   if(_ASYNC_MQTT_LOGLEVEL_>0) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP0X; AMQTT_PRINTLN(y, HEX); }
#define AMQTT_LOGERROR2(x,y,z)    if(_ASYNC_MQTT_LOGLEVEL_>0) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP; AMQTT_PRINT(y); AMQTT_PRINT_SP; AMQTT_PRINTLN(z); }
#define AMQTT_HEXLOGERROR2(x,y,z) if(_ASYNC_MQTT_LOGLEVEL_>0) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP0X; AMQTT_PRINT(y, HEX); AMQTT_PRINT_SP0X; AMQTT_PRINTLN(z, HEX); }
#define AMQTT_LOGERROR3(x,y,z,w)  if(_ASYNC_MQTT_LOGLEVEL_>0) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP; AMQTT_PRINT(y); AMQTT_PRINT_SP; AMQTT_PRINT(z); AMQTT_PRINT_SP; AMQTT_PRINTLN(w); }

/////////////////////////////////////////////////////////

#define AMQTT_LOGWARN(x)          if(_ASYNC_MQTT_LOGLEVEL_>1) { AMQTT_PRINT_MARK; AMQTT_PRINTLN(x); }
#define AMQTT_LOGWARN0(x)         if(_ASYNC_MQTT_LOGLEVEL_>1) { AMQTT_PRINT(x); }
#define AMQTT_LOGWARN1(x,y)       if(_ASYNC_MQTT_LOGLEVEL_>1) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP; AMQTT_PRINTLN(y); }
#define AMQTT_HEXLOGWARN1(x,y)    if(_ASYNC_MQTT_LOGLEVEL_>1) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP0X; AMQTT_PRINTLN(y, HEX); }
#define AMQTT_LOGWARN2(x,y,z)     if(_ASYNC_MQTT_LOGLEVEL_>1) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP; AMQTT_PRINT(y); AMQTT_PRINT_SP; AMQTT_PRINTLN(z); }
#define AMQTT_HEXLOGWARN2(x,y,z)  if(_ASYNC_MQTT_LOGLEVEL_>1) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP0X; AMQTT_PRINT(y, HEX); AMQTT_PRINT_SP0X; AMQTT_PRINTLN(z, HEX); }
#define AMQTT_LOGWARN3(x,y,z,w)   if(_ASYNC_MQTT_LOGLEVEL_>1) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP; AMQTT_PRINT(y); AMQTT_PRINT_SP; AMQTT_PRINT(z); AMQTT_PRINT_SP; AMQTT_PRINTLN(w); }

/////////////////////////////////////////////////////////

#define AMQTT_LOGINFO(x)          if(_ASYNC_MQTT_LOGLEVEL_>2) { AMQTT_PRINT_MARK; AMQTT_PRINTLN(x); }
#define AMQTT_LOGINFO0(x)         if(_ASYNC_MQTT_LOGLEVEL_>2) { AMQTT_PRINT(x); }
#define AMQTT_LOGINFO1(x,y)       if(_ASYNC_MQTT_LOGLEVEL_>2) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP; AMQTT_PRINTLN(y); }
#define AMQTT_HEXLOGINFO1(x,y)    if(_ASYNC_MQTT_LOGLEVEL_>2) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP0X; AMQTT_PRINTLN(y, HEX); }
#define AMQTT_LOGINFO2(x,y,z)     if(_ASYNC_MQTT_LOGLEVEL_>2) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP; AMQTT_PRINT(y); AMQTT_PRINT_SP; AMQTT_PRINTLN(z); }
#define AMQTT_HEXLOGINFO2(x,y,z)  if(_ASYNC_MQTT_LOGLEVEL_>2) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP0X; AMQTT_PRINT(y, HEX); AMQTT_PRINT_SP0X; AMQTT_PRINTLN(z, HEX); }
#define AMQTT_LOGINFO3(x,y,z,w)   if(_ASYNC_MQTT_LOGLEVEL_>2) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP; AMQTT_PRINT(y); AMQTT_PRINT_SP; AMQTT_PRINT(z); AMQTT_PRINT_SP; AMQTT_PRINTLN(w); }

/////////////////////////////////////////////////////////

#define AMQTT_LOGDEBUG(x)         if(_ASYNC_MQTT_LOGLEVEL_>3) { AMQTT_PRINT_MARK; AMQTT_PRINTLN(x); }
#define AMQTT_LOGDEBUG0(x)        if(_ASYNC_MQTT_LOGLEVEL_>3) { AMQTT_PRINT(x); }
#define AMQTT_LOGDEBUG1(x,y)      if(_ASYNC_MQTT_LOGLEVEL_>3) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP; AMQTT_PRINTLN(y); }
#define AMQTT_HEXLOGDEBUG1(x,y)   if(_ASYNC_MQTT_LOGLEVEL_>3) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP0X; AMQTT_PRINTLN(y, HEX); }
#define AMQTT_LOGDEBUG2(x,y,z)    if(_ASYNC_MQTT_LOGLEVEL_>3) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP; AMQTT_PRINT(y); AMQTT_PRINT_SP; AMQTT_PRINTLN(z); }
#define AMQTT_HEXLOGDEBUG2(x,y,z) if(_ASYNC_MQTT_LOGLEVEL_>3) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP0X; AMQTT_PRINT(y, HEX); AMQTT_PRINT_SP0X; AMQTT_PRINTLN(z, HEX); }
#define AMQTT_LOGDEBUG3(x,y,z,w)  if(_ASYNC_MQTT_LOGLEVEL_>3) { AMQTT_PRINT_MARK; AMQTT_PRINT(x); AMQTT_PRINT_SP; AMQTT_PRINT(y); AMQTT_PRINT_SP; AMQTT_PRINT(z); AMQTT_PRINT_SP; AMQTT_PRINTLN(w); }

/////////////////////////////////////////////////////////

#endif    //ASYNC_MQTT_ESP32_DEBUG_H
