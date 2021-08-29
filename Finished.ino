#include "DHT.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"

//PIN DEF'S
#define DHTPIN 4     // Digital pin connected to the DHT sensor
#define ONE_WIRE_BUS 3
#define echoPin 16 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 34 //attach pin D3 Arduino to pin Trig of HC-SR04
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin #
#define analogInput 35
#define relayPin 25
//Modules DEF'S
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

extern const unsigned char precelerator[];
extern const unsigned char tempWater[];
extern const unsigned char airTemp[];
extern const unsigned char waterFull[];
extern const unsigned char waterHalf[];
extern const unsigned char waterEmpty[];
extern const unsigned char waterHum[];
extern const unsigned char batterie[];


//INITIALISATION'S
DHT dht(DHTPIN, DHTTYPE);
OneWire oneWire(ONE_WIRE_BUS);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
RTC_DS3231 rtc;
DallasTemperature sensors(&oneWire);


//Variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
long messIntLuft = 10000;
long messIntWasser = 10000;
long messIntWasserStand = 10000;
long millisOldTemp = 0;
long millisOldWasser = 0;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int batterieVolt = 0;
int batterieVoltCalc = 0;
float h = 0;
float t = 0;
float w = 0;
long displayPrint = 4000;
long displayAusgabeOld = 0;
long batMesInt = 5000;
long batMesIntOld = 0;
long wateringInt = 120000;
long wateringIntOld = 0;

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  delay(200);
  digitalWrite(relayPin, HIGH);
  delay(200);
  digitalWrite(relayPin, LOW);
  delay(200);
  digitalWrite(relayPin, HIGH);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(100);
  display.clearDisplay();
  display.drawBitmap(1, 10, precelerator, 126, 13, WHITE);
  display.setCursor(0, 27);
  display.setTextColor(WHITE, BLACK);
  display.setTextSize(1);
  display.println("Community Space for");
  display.println("Enterpreneurship &");
  display.println("Prototyping");
  display.display();
  



  // Start up the library's
  sensors.begin();  //DS18B20 Wasser Sensor
  dht.begin();      //Luft Sensor
  rtc.begin();
  //rtc.adjust(DateTime(2021, 8, 12, 10, 31, 30));
}

void loop() {
  
  // Wait a few seconds between measurements.
  if ((millis() - millisOldTemp) >= messIntLuft) {
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    t = dht.readTemperature();
    // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
    sensors.requestTemperatures();
    w = sensors.getTempCByIndex(0);
    Serial.print("  Wasser Temperatur: ");
    // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
    Serial.print(sensors.getTempCByIndex(0));
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Luft Temperatur: "));
    Serial.print(t);
    Serial.print(" °C  ");
    millisOldTemp = millis();
    printTimeSerial();
  }

  if ((millis() - millisOldWasser) >= messIntWasserStand) {
    //Ultraschall Sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor
    Serial.print("  Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    millisOldWasser = millis();
  }
  if ((millis() - batMesIntOld) >= batMesInt) {
    batterieVolt = analogRead(analogInput);
    Serial.print("ANALOG WERT:");
    Serial.println(batterieVolt);
    batterieVoltCalc = map(batterieVolt, 3000, 4100, 10, 100);
    batMesIntOld = millis();
  }
  if ((millis() - wateringIntOld) >= wateringInt){
    digitalWrite(relayPin, LOW);
    delay(30000);
    digitalWrite(relayPin, HIGH);
  }

  if ((millis() - displayAusgabeOld) >= displayPrint) {
    displayAusgabe(h, t, w, distance, batterieVoltCalc);
    displayAusgabeOld = millis();
  }
  
 
  
}

void displayAusgabe(float h, float t, float w, int distance, int voltage ) {
  display.clearDisplay();
  /*
    display.setCursor(2, 2);
    display.setTextSize(1);
    display.setTextColor(WHITE, BLACK);
    display.print("Luftfeuchte: ");
    display.print(h);
    display.print(" %");

    display.setCursor(2, 12);
    display.setTextSize(1);
    display.setTextColor(WHITE, BLACK);
    display.print("Lufttemp:    ");
    display.print(t);
    display.print((char)247);
    display.print("C");

    display.setCursor(2, 22);
    display.setTextSize(1);
    display.setTextColor(WHITE, BLACK);
    display.print("Wassertemp:  ");
    display.print(w);
    display.print((char)247);
    display.print("C");

    display.setCursor(2, 32);
    display.setTextSize(1);
    display.setTextColor(WHITE, BLACK);
    display.print("Wasserstand: ");
    display.print(distance);

    display.print(" cm");
  */
  display.drawBitmap(4, 2, tempWater, 15, 20, WHITE);
  display.setCursor(19, 10);
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.print(" ");
  display.print(w, 1);
  display.print((char)247);
  //Tank
  //display.drawLine(80, 2, 80, 25, WHITE);

  display.drawBitmap(77, 2, waterFull, 15, 20, WHITE);

  display.drawBitmap(4, 24, airTemp, 15, 20, WHITE);
  display.setCursor(19, 32);
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.print(" ");
  display.print(t, 1);
  display.print((char)247);

  display.drawBitmap(77, 24, waterHum, 15, 20, WHITE);
  display.setCursor(92, 32);
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.print(" ");
  display.print(h, 0);
  display.print("%");

  display.drawBitmap(4, 46, batterie, 15, 20, WHITE);
  display.setCursor(19, 54);
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.print(" ");
  display.print(voltage);
  display.print("%");

  
  display.display();
}

void printTimeSerial() {
  DateTime now = rtc.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
}




// Check if any reads failed and exit early (to try again).
/*if (isnan(h) || isnan(t)) {
  Serial.println(F("Failed to read from DHT sensor!"));
  return;
  }*/
/*
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
*/
