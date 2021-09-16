#include <WiFi.h>
#include "analogWrite.h"

void Stop();
void rightTurn();
void leftTurn();
int maxof(int a,int b,int c);
int check_RSSI();
void Back();
void Right();
void Left();
void Forward();

String  ClientRequest;
WiFiServer server(80);

WiFiClient client;

String myresultat;

String ReadIncomingRequest(){
while(client.available()) {
ClientRequest = (client.readStringUntil('\r'));
 if ((ClientRequest.indexOf("HTTP/1.1")>0)&&(ClientRequest.indexOf("/favicon.ico")<0)){
myresultat = ClientRequest;
}
}
return myresultat;
}

const int Motor_L_F = 16;
const int Motor_L_B = 17;
const int Motor_R_F = 18;
const int Motor_R_B = 19;
void setup()
{
ClientRequest = "";
Serial.begin(115200);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
  WiFi.begin("Anil","anil1234");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));
  server.begin();
   pinMode(14, OUTPUT);
    pinMode(15, OUTPUT);
  pinMode(Motor_L_F, OUTPUT);
  pinMode(Motor_L_B, OUTPUT);
  pinMode(Motor_R_F, OUTPUT);
  pinMode(Motor_R_B, OUTPUT);
 
}


void loop()
{
  analogWrite(14,170);
  analogWrite(15,170);
  int Frssi = check_RSSI();
  while (Frssi>114)
  {
    int Frssi = check_RSSI();
  }
  rightTurn();
  int Rrssi = check_RSSI();
  leftTurn();
  leftTurn();
  int Lrssi = check_RSSI();
  int mxOf=maxof(Frssi,Rrssi,Lrssi);
  Serial.print("max = ");
  Serial.println(mxOf);
  for (int i=0;i<mxOf;i++)
  {
    rightTurn();
    
  }
  Back();
  delay(700);
  Stop();
  delay(300);
}
void rightTurn()
{
  Right();
  delay(300);
  Stop();
  delay(400);
}

void leftTurn()
{
  Left();
  delay(300);
  Stop();
  delay(400);
}
int maxof(int a,int b,int c)
{
  int mx = 1;
  if (b>a)
  {
    mx = 2;
    if (c>=b)
    {
      mx = 0;   
    }
  }
 else if (c>=a)
 {
  mx=0;
 }
 return mx;
}

int check_RSSI(){
  int rssi=0;
  int x;
  for(int j=0;j<20;j++)
  {
   x=WiFi.RSSI();
  rssi = rssi + x;
  }
  rssi = rssi / 40;
  Serial2.write(rssi);
  Serial.println(rssi);
  return rssi;
}


void Back(){
  // Run Left Motor In Forward Direction
  digitalWrite(Motor_L_F, HIGH);
  digitalWrite(Motor_L_B, LOW);

  //Run Right Motor in Forward Direction
  digitalWrite(Motor_R_F, HIGH);
  digitalWrite(Motor_R_B, LOW);
  
  }

void Right(){
  //Stop Right Motor
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);

  //Run Left Motor in Forward Direction
  digitalWrite(Motor_L_F, HIGH);
  digitalWrite(Motor_L_B, LOW);
  
  }

void Left(){
  //Stop Left Motor
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);

  //Run Right Motor in Forward Direction
  digitalWrite(Motor_R_F, HIGH);
  digitalWrite(Motor_R_B, LOW);
  
  }

void Forward(){
  // Run Left Motor In Forward Direction
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, HIGH);

  //Run Right Motor in Forward Direction
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, HIGH);
  
  }

void Stop(){
  // Run Left Motor In Forward Direction
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);

  //Run Right Motor in Forward Direction
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);
  
  }
