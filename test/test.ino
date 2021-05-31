#include<ESP8266WiFi.h>
#include<MicroGear.h>

const char *ssid = "M";
const char *password = "milkkkkk";
int c = 0;
int count = 0;

#define APPID  "Theif"
#define KEY "QtAivZo62fMHEc1"
#define SECRET "Idx6JCEikKLRrBj2wozvnrlWW"

#define ALIAS "NodeMCU2"
#define TagetWeb "HTML_web"

WiFiClient client;

MicroGear microgear(client);

void onMsghandler(char *topec , uint8_t *msg ,unsigned int msglen){
  Serial.print("Incoming message -->");
  msg[msglen] = '\0';
  Serial.println((char *)msg);
}

void onConnected(char *attribute ,uint8_t *msg ,unsigned int msglen){
  Serial.println("Connected to Netpie...");
  microgear.setAlias(ALIAS);
}

void setup() {


  
  Serial.begin(115200);
  Serial.println("Starting....");
  microgear.on(MESSAGE,onMsghandler);
  microgear.on(CONNECTED,onConnected);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");


  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  microgear.init(KEY,SECRET,ALIAS);
  microgear.connect(APPID);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (microgear.connected()){

   // microgear.loop();
    Serial.println("connected");
    if(Serial.available())
    {
      //if (count == 0){
        Serial.println(Serial.read());
        c++;
        Serial.println(c);
       // count++;
      //}else{
      //  count = 0;
     // }
    }
   

    microgear.chat(TagetWeb,c);
    

   
  }else{
    Serial.println("connecion lost,reconnect...");
    microgear.connect(APPID);
  }
  delay(1500);

}
