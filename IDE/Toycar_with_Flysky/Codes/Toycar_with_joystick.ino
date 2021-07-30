
#define ip1 14        
#define ip2 15
const int Motor_L_F = 16;
const int Motor_L_B = 17;
const int Motor_R_F = 18;
const int Motor_R_B = 19;
int ch2,ch4;            

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
 ch2 = pulseIn(ip1, HIGH);
 ch4 = pulseIn(ip2, HIGH);

 if((ch2>1400 && ch2<1600) && (ch4>1400 && ch4<1600))
   Stop();
   
 if (ch2 > 1600) 
 {
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, HIGH);
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, HIGH);
  } 
  else
  {
    if(ch2<1400)
    {
     digitalWrite(Motor_L_F, HIGH);
     digitalWrite(Motor_L_B, LOW);
     digitalWrite(Motor_R_F, HIGH);
     digitalWrite(Motor_R_B, LOW);
     }
    else
     {
      if (ch4 >1600)
       {
         digitalWrite(Motor_L_F, LOW);
         digitalWrite(Motor_L_B, HIGH);
         digitalWrite(Motor_R_F, HIGH);
         digitalWrite(Motor_R_B, LOW);
         }
        else
        {
          if(ch4<1400)
          {
            digitalWrite(Motor_L_F, HIGH);
            digitalWrite(Motor_L_B, LOW);
            digitalWrite(Motor_R_F, LOW);
            digitalWrite(Motor_R_B, HIGH);
            } 
        }
    }
 
  }
}
void Stop(){
  
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);
  }
