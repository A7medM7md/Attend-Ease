void readRFID()
{
  rfid.PICC_ReadCardSerial();
  lcd.clear();
  UID = ""; // if write strig error
  for (byte i = 0; i < rfid.uid.size; i++)
  {
    //  Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");// E8 07 C7 D2
    // Serial.print(rfid.uid.uidByte[i], HEX);
    UID.concat(String(rfid.uid.uidByte[i] < 0x10 ? "0" : "")); // 0E c2 12
    UID.concat(String(rfid.uid.uidByte[i], HEX));
    // Serial.println();
  }
  rfid.PICC_HaltA();
  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
  lcd.print(" Your Id : ");
  UID.toUpperCase();
  // E8 07 C7 D2
  Serial.print(UID);
  Serial.print("  ");
  lcd.setCursor(4, 1);
  lcd.print(UID);

  delay(1500);
}
