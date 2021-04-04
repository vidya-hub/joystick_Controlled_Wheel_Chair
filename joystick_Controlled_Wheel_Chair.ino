int xpin=A0;
int ypin=A1;
int left_m=2;
int right_m=4;
int xval;
int yval;
int sval;

void setup() {
  Serial.begin(9600);
  pinMode(xpin,INPUT);
  pinMode(ypin,INPUT);
//  pinMode(spin,INPUT);
  pinMode(left_m,OUTPUT);
  pinMode(right_m,OUTPUT);
  digitalWrite(left_m,HIGH);
  digitalWrite(right_m,HIGH);

}

void loop() {
  
  xval=analogRead(xpin);
  yval=analogRead(ypin);
  sval=digitalRead(sval);
  delay(500);
  Serial.print(" xval is ");
  Serial.println(xval);
  Serial.print("   yval is ");
  Serial.println(yval);
  
  if (yval<250){                           // forward
    digitalWrite(left_m,LOW);
    digitalWrite(right_m,LOW);
    delay(100);
  }
  else if(xval<250){                       //LEFT
    digitalWrite(left_m,HIGH);
    digitalWrite(right_m,LOW);
    delay(100);
  }
  else if(xval>750){                       //RIGHT
    digitalWrite(left_m,LOW);
    digitalWrite(right_m,HIGH);
    delay(100);
  }
 
  else if(yval>750){                       // break
    digitalWrite(left_m,HIGH);
    digitalWrite(right_m,HIGH);
    delay(100);
  }
   else if(500<xval<510 || 515<yval<525){  //middle
    digitalWrite(left_m,HIGH);
    digitalWrite(right_m,HIGH);
    delay(100);
  }
}
