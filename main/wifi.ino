#define WIFI_SSID "GAVR"
#define WIFI_PSK  "129asdfg3667"


ESP8266WiFiMulti setupWifi() {
  ESP8266WiFiMulti WiFiMulti;
  
  // We start by connecting to a WiFi network
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(WIFI_SSID, WIFI_PSK);

  Serial.println();
  Serial.print("Wait for WiFi... ");
  Serial.print(WIFI_SSID);
  Serial.print(" ");
  Serial.print(WIFI_PSK);

  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  return WiFiMulti;
}
