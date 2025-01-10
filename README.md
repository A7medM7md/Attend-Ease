### **Attendance Tracking System**

**Purpose:** This system tracks attendance using RFID cards. Each time a card is scanned, the system records the card’s unique ID to monitor attendance.

**Components:**

* **RFID Reader (MFRC522):** Scans RFID cards to read their unique IDs.  
* **ESP8266 Microcontroller:** Handles communication and data processing.  
* **Wi-Fi Connection:** Connects to the internet to send data.  
* **Google Sheets:** Logs attendance data for record-keeping.  
* **Telegram Bot:** Sends notifications with the card’s ID.

**How It Works:**

1. **Initialize Components:** Sets up communication with the RFID reader and connects to Wi-Fi.  
2. **Read RFID Card:** Detects when a card is scanned and reads its unique ID.  
3. **Send Data:**  
   * **To Server:** Sends the card ID to a specified server.  
   * **To Google Sheets:** Logs the card ID in a Google Sheet for attendance records.  
   * **To Telegram:** Sends a message to a Telegram chat with the card ID for real-time monitoring.  
4. **Avoid Duplicate Processing:** Ensures the same card isn’t processed repeatedly within a short time.

This setup helps in managing and monitoring attendance efficiently by automatically logging and notifying the presence of individuals through RFID card scans.

Project Video link  
[0513 (2).mp4](https://drive.google.com/file/d/1xw2QHZ5W14H5ADoT60GJlzvjTAYX--zS/view?usp=sharing)

