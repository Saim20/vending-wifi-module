#include <Arduino.h>
#include <WiFi.h>
// #include <Firebase_ESP_Client.h>

#define RXp2 16
#define TXp2 17

// Insert your network credentials
#define WIFI_SSID "Computer Lab"
#define WIFI_PASSWORD "2020_2024"

// // Insert Firebase project API Key
// #define API_KEY "AIzaSyDg4s787iggM3YUxvnrdDpkh1f_4fEpWPs"

// // Insert RTDB URLefine the RTDB URL */
// #define DATABASE_URL "https://canteenvending-d71be-default-rtdb.asia-southeast1.firebasedatabase.app/"

// // Define Firebase Data object
// FirebaseData fbdo;

// FirebaseAuth auth;
// FirebaseConfig config;

String connection_status;
void connect_wifi()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial2.println("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial2.print(".");
    delay(300);
  }
  Serial2.print("Connected with IP: ");
  Serial2.println(WiFi.localIP());

  connection_status = "connected";
}

int string_to_int(String str)
{
  int num = 0;
  for (int i = 0; i < str.length(); i++)
  {
    num = num * 10 + (str.charAt(i) - '0');
  }
  return num;
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);

  connect_wifi();
}
void loop()
{
  delay(100);
  connection_status = WiFi.status();
  String msg = Serial2.readString();

  if (msg.length() > 0)
  {
    Serial.println(msg);

    if (msg == "connection_status")
    {
      Serial2.print(connection_status);
    }
    else if (msg == "get_balance")
    {
      // Do something
      delay(1000 / 2);
      while (!((int)msg[0] >= 49 && msg[0] <= 58))
        msg = Serial2.readString();
    }
    
  }
}