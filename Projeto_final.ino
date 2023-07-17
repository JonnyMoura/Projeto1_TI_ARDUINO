int buttonPin=5;
bool trueReading=false;
bool lastState=false;
long deBounceDelay=50;
long bounce;
int contaprime=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
  


}

void loop() {
  // put your main code here, to run repeatedly:
unsigned long timer = millis();
int numero_aleatorio=random(1,32);
for(int i=0; i<=4; i++){
digitalWrite(6+i, (numero_aleatorio >> i) & 1);
}
Serial.println("TENS 15 SEGUNDOS FORÇA:");
while((millis()-timer)<15000){
bool  buttonState=!digitalRead(buttonPin);
    if (buttonState!=lastState){
     bounce=millis(); 
   
  }
  if(millis()-bounce>1000 && buttonState==HIGH){
    while(digitalRead(buttonPin)==LOW){
      
    }
  loop();
  }
  
  if(millis()-bounce>deBounceDelay){
    if (buttonState!=trueReading){
      trueReading=buttonState;
      if (trueReading==true){
        contaprime=contaprime+1;
        Serial.println(contaprime);
          if (contaprime==32){
              contaprime=0;
            
}
}}}
lastState=buttonState;
}





  if (numero_aleatorio==contaprime){
Serial.println("Parabéns acertou o numero");
contaprime=0;
for(int led=6;led<=10;led++){
 digitalWrite(led,LOW);
  
}

for(int led=6;led<=10;led++){
  digitalWrite(led,HIGH);
  delay(500);  
}  
  }else{ 
  Serial.println("Bem erraste, o número certo:");
  Serial.println(numero_aleatorio,DEC);
  contaprime=0;
}
 




}
