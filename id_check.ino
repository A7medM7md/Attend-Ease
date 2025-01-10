void idcheck()
{

  if (uid != UID)
  {
    uid = UID;
    save_on_card();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Put ID to Scan");
    lcd.setCursor(0, 1);
    lcd.print("Attendees Num:");
    lcd.setCursor(14, 1);
    lcd.print(i);
    delay(10);
  }
  else
  {
    lcd.clear();
    lcd.print("Attended Before");
    delay(1000);
  }
}
