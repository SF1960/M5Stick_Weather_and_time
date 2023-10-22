#pragma once

/**************************************************************************************
* USER DEFINED PROGRAM INPUTS
*
* Please change your preferences below 
*
***************************************************************************************/

// OpenWeather API parameters
const String key = "0b2bf4473af8e57be78b80d38d61a6f4";      // OpenWeather API Key
#define TOWN "Crawley"                                      // check the OpenWeather website
#define COUNTRY "GB"                                        // for allowable towns and countries
#define GMT_OFFSET 3600                                     // hours offset from GMT in timezones as +/- 3600 steps
#define SUMMER_TIME_OFFSET 0                                // hours change to for summer time 3600
#define OW_INTERVAL_MINS 1                                  // schedule to update OpenWeather in minutes
#define IOT_INTERVAL_SECS 5                                 // schedule tp update IOT in seconds

// wifi credentials
const char* ssid       = "Pixel_7368";                      // PIXEL SSID
const char* password   = "hotspot1712";                     // PIXEL Password
const char* ssid2      = "TALKTALKB032AA";                  // VIRGIN SSID
const char* password2  = "6RGUAHGP";                        // VIRGIN Password
const char* ssid3      = "VM3988748";                       // HOME SSID
const char* password3  = "nr5jfPxrvxmw";                    // HOME Password

/******************************************************************************
* DO NOT CHANGE CODE BELOW
******************************************************************************/

#define CONN_ATTEMPTS 8                                      // the number of attempts to connect to WiFi
#define CONN_TIMEOUT 500                                     // connection time out ms
#define MESSAGE_DELAY 3500                                   // message delay time ms
#define RESET_DELAY 10000                                    // 10s reset device delay
#define CONNECTION_FAILED wifi::connectionFailed()           // code replacement for connection failed
#define CONNECT_TO_PIXEL  (wifi::connect(ssid, password))    // code replacement to connect to Pixel WiFi
#define CONNECT_TO_VIRGIN (wifi::connect(ssid2, password2))  // code replacement to connect to Kids WiFi
#define CONNECT_TO_HOME   (wifi::connect(ssid3, password3))  // code replacement to connect to Home WiFi

// ntp server credentials
const char* ntpServer = "europe.pool.ntp.org";                // Time server
const long  gmtOffset_sec = GMT_OFFSET;                       // hours +/- from GMT
const int   daylightOffset_sec = SUMMER_TIME_OFFSET;          // daylight saving
struct tm timeinfo;

// set up variables
// M5Stick parameters
float M5VBat, USBVin, M5BatTemp;                              // M5Stick performance
int intCharge;                                                // Charge rate
int hom=0; int rst=0;                                         // push button control variables
float batchargeCurrent = 0.0;                                 // battery actual charge rate

// network time variables
String strHrs, strMins, strSecs;                              // Strings to hold time elements
String strDate, strDay, strMonth, strYear;                    // Strings to hold date elements
float sensTemp, sensHum, sensPress;                           // Strings to hold sensor data

// OpenWeather variables
String townName = TOWN;                                       // OpenWeather variables
String Country = COUNTRY;                                     // GB
String payload = "";                                          // return OpenWeather string
String owTemp ="" ;                                           // temperature string
String owHum ="" ;                                            // humidity string
String owMaxTemp;                                             // maximum forecast temperature
String owMinTemp;                                             // minimum forecast temperature
String owForecast;                                            // overall forecast for the day
String owCurrentWeather = "";                                 // current conditions
String oWPressure ="";                                        // pressure string
String owWindSpeed = "";                                      // wind string
String owWindDirection = "";                                  // wind direction
String owWeatherIcon = "";                                    // icon for weather
String iconType = "";                                         // icon character

// screen definitions
#define colorDarkGrey 0x01EA
#define colOrange ORANGE
#define colYellow YELLOW
#define colGreen GREEN

// pushbutton definitions
#define PRESSED 0                                             // button pressed value

// weather
String displayIcon = "";

// menu
String strMenu[4] = {"Battery","Weather","Temp/Hum ","Time/Date "};
byte menuChosen = 1;                                         // default menu selection

// screen
byte brightness[5] = {15, 30, 45, 60, 85};                   // define brightness steps
byte chosenBrightness = 1;                                   // set to 2nd brightness level

// internet OpenWeather update schedule
unsigned long owPreviousMillis = 0;                          // used to periodically obtain weather data
const int owUpdateInterval = 1000 * 60 * OW_INTERVAL_MINS;   // OW_INTERVAL minutes between weather API calls

// Arduino IOT update schedule
unsigned long iotPreviousMillis = 0;
const int iotUpdateInterval = 1000 * IOT_INTERVAL_SECS;      // IOT_INTERVAL seconds update iot variables every 5 seconds

