#ifndef WifiManager_h
#define WifiManager_h

#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <ESP8266mDNS.h>
#include <FS.h>
extern "C" {
#include "user_interface.h"
}

#define WIFI_MODE_OFF 0
#define WIFI_MODE_AP 1
#define WIFI_MODE_STATION 2

/*
   This file contains all necessary functions for hosting and connecting to an access point.
   For compatibility and simplicity, all those functions are global.
 */

// Important strings
const char W_DEAUTHER[] PROGMEM = "deauth.me"; // captive portal domain (alternative to 192.168.4.1)
const char W_WEBINTERFACE[] PROGMEM = "/web";  // default folder containing the web files
const char W_ERROR_PASSWORD[] PROGMEM = "ERROR: Password must have at least 8 characters!";
const char W_DEFAULT_LANG[] PROGMEM = "/lang/default.lang";

const char W_HTML[] PROGMEM = "text/html";
const char W_CSS[] PROGMEM = "text/css";
const char W_JS[] PROGMEM = "application/javascript";
const char W_PNG[] PROGMEM = "image/png";
const char W_GIF[] PROGMEM = "image/gif";
const char W_JPG[] PROGMEM = "image/jpeg";
const char W_ICON[] PROGMEM = "image/x-icon";
const char W_XML[] PROGMEM = "text/xml";
const char W_XPDF[] PROGMEM = "application/x-pdf";
const char W_XZIP[] PROGMEM = "application/x-zip";
const char W_GZIP[] PROGMEM = "application/x-gzip";
const char W_JSON[] PROGMEM = "application/json";
const char W_TXT[] PROGMEM = "text/plain";

const char W_DOT_HTM[] PROGMEM = ".htm";
const char W_DOT_HTML[] PROGMEM = ".html";
const char W_DOT_CSS[] PROGMEM = ".css";
const char W_DOT_JS[] PROGMEM = ".js";
const char W_DOT_PNG[] PROGMEM = ".png";
const char W_DOT_GIF[] PROGMEM = ".gif";
const char W_DOT_JPG[] PROGMEM = ".jpg";
const char W_DOT_ICON[] PROGMEM = ".ico";
const char W_DOT_XML[] PROGMEM = ".xml";
const char W_DOT_PDF[] PROGMEM = ".pdf";
const char W_DOT_ZIP[] PROGMEM = ".zip";
const char W_DOT_GZIP[] PROGMEM = ".gz";
const char W_DOT_JSON[] PROGMEM = ".json";

// Server and other global objects
ESP8266WebServer server(80);
DNSServer dnsServer;
IPAddress apIP(192, 168, 4, 1);
IPAddress netMsk(255, 255, 255, 0);
File fsUploadFile;