void keypadd()
{

  //  Serial.println("Enter level");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter level : ");
findkey:
  char key = keypad.getKey();

  while (!key)
  {

    goto findkey;
  }
  if (key)
  {
    tone(buzz, 5000, 200);
    delay(100);
  }
  level = String(key);
  // Serial.println(level);
  // Serial.println("Enter group");
  lcd.setCursor(14, 0);
  lcd.print(level);
  lcd.setCursor(0, 1);
  lcd.print("Enter Group : ");
findkeyy:
  char keyy = keypad.getKey();

  while (!keyy)
  {
    goto findkeyy;
  }
  if (key)
  {
    tone(buzz, 5000, 200);
    delay(100);
  }
  group = String(keyy);
  lcd.setCursor(14, 1);
  lcd.print(group);
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Put ID to Scan");
  lcd.setCursor(0, 1);
  lcd.print("Attendees Num:");
  lcd.setCursor(14, 1);
  lcd.print(i);
  String fileName = "Lv_" + String(level) + "_G_" + String(group);
  Serial.print(fileName);
  delay(400);
}
