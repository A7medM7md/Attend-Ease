void save_on_card()
{
  // Enables SD card chip select pin
  digitalWrite(CS_SD, LOW);
  // Open file
  String fileName = "lv_" + String(level) + "_G_" + String(group) + ".txt";
  Hertz = SD.open(fileName, FILE_WRITE);

  // If the file opened ok, write to it
  if (Hertz)
  {
    // Serial.println("File opened ");
    lcd.clear();
    lcd.print("File opened ");
    delay(1000);
    Hertz.print(UID);
    Hertz.print(", ");

    // Save time on SD card
    DateTime now = rtc.now();
    Hertz.print(now.year(), DEC);
    Hertz.print('/');
    Hertz.print(now.month(), DEC);
    Hertz.print('/');
    Hertz.print(now.day(), DEC);
    Hertz.print(',');
    Hertz.print(now.hour(), DEC);
    Hertz.print(':');
    Hertz.println(now.minute(), DEC);
    lcd.setCursor(0, 1);
    Hertz.close();
    lcd.print("You are Attended");
    delay(1100);
    i = i + 1;
  }
  else
  {
    // Serial.println("error opening data.txt");
    lcd.clear();
    lcd.print("error opening data.txt");
  }
  // Disables SD card chip select pin
  digitalWrite(CS_SD, HIGH);
}
