#include <WiFi.h>
#include <WiFiClient.h> 
#include <WebServer.h>

const int Motor_L_F = 16;
const int Motor_L_B = 17;
const int Motor_R_F = 18;
const int Motor_R_B = 19;

WebServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(Motor_L_F, OUTPUT);
  pinMode(Motor_L_B, OUTPUT);
  pinMode(Motor_R_F, OUTPUT);
  pinMode(Motor_R_B, OUTPUT);
  
  Serial.println("START");
  WiFi.begin("Anil","anil1234");
// Connecting WiFi
 while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }

  //WiFi.mode(WIFI_AP);
  //WiFi.softAP(ssid);
// Starting WEB-server
 Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));
    
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
     
}

void loop() {
  server.handleClient();
   delay(50);
}

void HTTP_handleRoot(void) {
String ani;
//if( server.hasArg("State") ){
       ani=server.arg("State");
     //  Serial.print(ani);
 // }
//  server.send ( 200, "text/html", "" );
if (ani == "forward")
 {
  Forward();
  Serial.print("Forward");
 }
 else
 {
  if (ani == "back")
  {
     Serial.print("back");
     Back();
  }
  else
  {
    if (ani== "right")
    {
       Serial.print("right");
      Right();
    }
    else
    {
      if (ani=="left")
      {
         Serial.print("left");
         Left();
      }
      else {
         Serial.print("stop");
         Stop();
      }
      }
    }
  }
 }
 void Forward(){
 
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, HIGH);

 
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, HIGH);
  
  }

void Right(){
 
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, HIGH);
  
  digitalWrite(Motor_R_F, HIGH);
  digitalWrite(Motor_R_B, LOW);
  
  }

void Left(){
  
  digitalWrite(Motor_L_F, HIGH);
  digitalWrite(Motor_L_B, LOW);

  
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, HIGH);
  
  }

void Back(){
 
  digitalWrite(Motor_L_F, HIGH);
  digitalWrite(Motor_L_B, LOW);

  
  digitalWrite(Motor_R_F, HIGH);
  digitalWrite(Motor_R_B, LOW);
  
  }

void Stop(){
  // Run Left Motor In Forward Direction
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);

 
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);
  
  }
  
