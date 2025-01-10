#include <MFRC522.h> // for the RFID
#include <SPI.h>     // for the RFID and SD card module
#include <SD.h>      // for the SD card
#include "RTClib.h"  // for the RTC
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

//-------------------------------------------
// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;
int i = 0;
String UID, level, group, uid;

//-------------------------------------------
// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
//--------------------------------------------
// define pins for RFID
#define CS_RFID 10
#define RST_RFID 9
// define select pin for SD card module
#define CS_SD 8
#define buzz A0
//---------------------------------------------
// Create a file to store the data
File Hertz;
//---------------------------------------------
// Instance of the class for RFID
MFRC522 rfid(CS_RFID, RST_RFID);
//--------------------------------------------
// Instance of the class for RTC
RTC_DS3231 rtc;
//---------------------------------------------
// keypad ---------------------------------------------
const int ROWS = 4;
const int COLS = 4;

char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {3, 2, A1, A2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//-------------------------------------------
void setup()
{
  //-------------------------------------------------
  // initialize LCD
  lcd.init();
  // turn on LCD backlight
  lcd.backlight();
  // Init Serial port
  Serial.begin(115200);
  tone(buzz, 5000, 200);
  delay(100);
  lcd.setCursor(1, 0);
  lcd.print("    Welcome");

  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("   Hertz Team");
  delay(1000);
  lcd.clear();
  // Init SPI bus------------------------
  SPI.begin();
  // Init MFRC522 -------------------------
  rfid.PCD_Init();
  //------------------------------------------------------
  // Setup for the SD card
  // Serial.print("Initializing SD card...");
  lcd.print("Initializing SD card...");
  lcd.setCursor(0, 1);
  lcd.print("SD card Wait...");
  delay(2500);
  lcd.clear();
  if (!SD.begin(CS_SD))
  {
    // Serial.println("initialization failed!");
    lcd.print("Initializing ");
    lcd.setCursor(0, 1);
    lcd.print("failed!");
    return;
  }
  // Serial.println("initialization done.");
  lcd.print("Initialization ");
  lcd.setCursor(0, 1);
  lcd.print("Done...");
  delay(2000);
  //--------------------------------------------------------------
  // Setup for the RTC
  if (!rtc.begin())
  {
    lcd.setCursor(1, 0);
    lcd.print(" Couldn't find ");
    lcd.setCursor(0, 1);
    lcd.print("  RTC ");
    Serial.flush();
    while (1)
      delay(10);
  }

  if (rtc.lostPower())
  {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  //-----------------------------------------
  keypadd();
}

void loop()
{
  // look for new cards
  if (rfid.PICC_IsNewCardPresent())
  {
    readRFID();
    idcheck();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Put ID to Scan");
    lcd.setCursor(0, 1);
    lcd.print("Attendees Num:");
    lcd.setCursor(14, 1);
    lcd.print(i);
    delay(10);
  }
  else if (keypad.getKey() == '#')
  {
    tone(buzz, 5000, 200);
    delay(100);
    i = 0;
    keypadd();
  }
}
