#include <ESP8266WiFi.h>
//************************************************************************//
// DEFINES                                                                //
//************************************************************************//
#define OFF 0
#define ON  1
//************************************************************************//
// VARIABLES                                                              //
//************************************************************************//
// WiFi AP features
const char* ssid = "Sunrise_Wi-Fi_42F4FBF";
const char* password = "w2ukrtFvzws4";
// SYSTEM LED
int systemLedPin = 2;
//************************************************************************//
// FUNCTIONS PROTOTYPES                                                   //
//************************************************************************//
void systemLed();
//************************************************************************//
// MAIN                                                                   //
//************************************************************************//
void setup() {
  // SERIAL CONSOLE INIT
  Serial.begin(115200);
  // WIFI AP CONNECTION INIT
  Serial.println("Booting...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  //SYSTEM LED INIT
  pinMode(systemLedPin, OUTPUT);
}
void loop() {
  systemLed();  // system Led blink
}
//************************************************************************//
// FUNCTIONS                                                              //
//************************************************************************//
// make led system Led blink
void systemLed(){
  static unsigned char state = 0;
  static int counter = 0;
  delay(1);
  if(counter <= 499){
    counter ++;
  }
  else{
    counter = 0;
    state = state ^ 0x01; // change state 0 <--> 1
  }
  if(state == 0){
    digitalWrite(systemLedPin, LOW);
  }
  else{
    digitalWrite(systemLedPin, HIGH);
  }
}
