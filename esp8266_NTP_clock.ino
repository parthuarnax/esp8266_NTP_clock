//***features***
//Updating the current time using the NTP protocol
//Keep time information until next update

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid     = "ijn7uhb_2";
const char *password = "11111111";

WiFiUDP udp;
NTPClient timeClient(udp);
NTPClient timeClient(udp, "kr.pool.ntp.org", 32400, 3600000); // set time as Korea
//NTPClient(UDP& udp, const char* poolServerName, int timeOffset, int updateInterval);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  //If you want to use a specific port to use UDP, 
  //provide the port number as an argument like timeClient.begin(port).
  //I'll just use the defaults with no arguments.
  //------------------------------------
  //timeClient.update()
  //timeClient.getHours()
  //timeClient.getMinutes()
  //timeClient.getSeconds()
  //timeClient.getFormattedTime()
  timeClient.begin(); //If connected, start the NTPClient object “timeClient” created in advance.
  timeClient.update();
  Serial.println(timeClient.getFormattedTime());
}

void loop() {
  delay(1000);
  Serial.println(timeClient.getFormattedTime());
  //1초마다 같은 양식으로 시간을 출력
  //셋업에서 한 번 시간 정보를 업데이트한 후
  //한 시간마다 업데이트(배터리 관리 및 자원 관리에 도움)
}
