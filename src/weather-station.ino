#include <DHT.h>
#include <LiquidCrystal_I2C.h>

/* ---------- Configuration ---------- */
#define DHT_PIN         11
#define DHT_TYPE        DHT11
#define LCD_ADDRESS     0x27
#define LCD_COLS        16
#define LCD_ROWS        2
#define SAMPLE_INTERVAL 3000   // milliseconds

/* ---------- Objects ---------- */
DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);

/* ---------- Global Variables ---------- */
float temperature = 0.0;
float humidity    = 0.0;

/* ---------- Function Prototypes ---------- */
void initializeSystem();
void readSensor();
bool isValidReading(float t, float h);
void printSerial(float t, float h);
void displayData(float t, float h);
void displayError();

void setup() {
  initializeSystem();
}

void loop() {

  readSensor();

  if (!isValidReading(temperature, humidity)) {
    displayError();
    Serial.println("Sensor read failed");
    delay(1000);
    return;
  }

  printSerial(temperature, humidity);
  displayData(temperature, humidity);

  delay(SAMPLE_INTERVAL);
}

/* ================================================= */
/* ---------------- Function Definitions ------------ */
/* ================================================= */

void initializeSystem() {
  Serial.begin(9600);
  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.clear();

  Serial.println("System Initialized");
}

void readSensor() {
  temperature = dht.readTemperature();
  humidity    = dht.readHumidity();
}

bool isValidReading(float t, float h) {
  return !(isnan(t) || isnan(h));
}

void printSerial(float t, float h) {
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print(" C | Hum: ");
  Serial.print(h);
  Serial.println(" %");
}

void displayData(float t, float h) {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t, 1);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(h, 1);
  lcd.print("%");
}

void displayError() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sensor Error");
}