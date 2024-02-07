#include <ESP8266WiFi.h>
//************************************************************************//
// DEFINES                                                                //
//************************************************************************//
#define SYSTEMLEDPIN 2
#define GPIO00  0
#define GPIO02  2
#define GPIO04  4
#define GPIO05  5
#define GPIO12  12
#define GPIO13  13
#define GPIO14  14
#define GPIO15  15
#define GPIO16  16
#define OFF 0
#define ON  1
//************************************************************************//
// VARIABLES                                                              //
//************************************************************************//
// WiFi AP features
const char* ssid = "Sunrise_Wi-Fi_42F4FBF";
const char* password = "w2ukrtFvzws4";
//************************************************************************//
// FUNCTIONS PROTOTYPES                                                   //
//************************************************************************//
void systemLed();
void GPIOInit();
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
  // GPIOs Init
  GPIOInit();
}


unsigned char state12 = 0; 
unsigned char state14 = 0;
unsigned char state16 = 0;

void loop() {
  //systemLed();  // system Led blink
  state12 = digitalRead(GPIO12);
  state14 = digitalRead(GPIO14);
  state16 = digitalRead(GPIO16);
  if(state12 != 0 || state14 != 0 || state16 != 0){
    digitalWrite(SYSTEMLEDPIN, HIGH);
  }
  else{
    systemLed();
  }
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
    digitalWrite(SYSTEMLEDPIN, LOW);
  }
  else{
    digitalWrite(SYSTEMLEDPIN, HIGH);
  }
}

// Init all GPIOs
void GPIOInit(){
  //SYSTEM LED INIT
  pinMode(SYSTEMLEDPIN, OUTPUT);
  // GPIOs init
  pinMode(GPIO12, INPUT);
  pinMode(GPIO14, INPUT);
  pinMode(GPIO16, INPUT);
}
