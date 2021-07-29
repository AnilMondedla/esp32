
#define ip1 14        
#define ip2 15
const int Motor_L_F = 16;
const int Motor_L_B = 17;
const int Motor_R_F = 18;
const int Motor_R_B = 19;

 void Back_Left();
 void Back_Right();
 void Back();
 void Right();
 void Forward();
void Left();
       

int ch1,ch2;            
int val1,val2;

void setup()
{
  Serial.begin(9600);
  pinMode(ip1, INPUT);
  pinMode(ip2, INPUT);
  pinMode(Motor_L_F, OUTPUT);
  pinMode(Motor_L_B, OUTPUT);
  pinMode(Motor_R_F, OUTPUT);
  pinMode(Motor_R_B, OUTPUT);
}

void loop()
{
 ch1 = pulseIn(ip1, HIGH);
 ch2 = pulseIn(ip2, HIGH);
 if (ch1 < 1400) 
 {
   val1=map(ch1, 1400, 1003, 40, 75);
  if (ch2 <1400)
  {
    Back_Right();
  }
  else if (ch2>1600)
  {
    Back_Left();
  }
  else{
      Back();
  }
 }     
 else if (ch1 > 1500)
 {
   val1=map(ch1, 1550, 1990, 30, 75);
   if (ch2 <1400)
   {
    Right();
   }
  else if (ch2>1600)
  {
    Left();
  }
  else
  { 
  Forward();
  }
  }   
else
  Stop();
  delay(80); 
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
  
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);
  
  }

void Left(){
  
  digitalWrite(Motor_L_F, LOW);
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
  void Back_Right()
  {
    digitalWrite(Motor_L_F, HIGH);
    digitalWrite(Motor_L_B, LOW);

    digitalWrite(Motor_R_F, LOW);
    digitalWrite(Motor_R_B, LOW);
    
    }

    void Back_Left()
  {
    digitalWrite(Motor_L_F, LOW);
    digitalWrite(Motor_L_B, LOW);

    digitalWrite(Motor_R_F, HIGH);
    digitalWrite(Motor_R_B, LOW);
    
    }
  
