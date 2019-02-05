int ledPin=5;
int inputPin=2;
int pinSpeaker=6;
int pinState=LOW;
int val=0;
bool led=true;
int nbMove = 0;
/*                       Hap  py  Birth Day  to  you,  Hap py   birth day  to
                         C4   C4   D4   C4   F4   E4   C4   C4   D4   C4   G4 */
unsigned int notes[] = { 262, 262, 294, 262, 349, 330, 262, 262, 294, 262, 392,
 
/*                       you, Hap py  Birth Day  dear  xxxx      Hap  py   birth
                         F4   C4   C4   C5   A4   F4   E4   D4   B4b  B4b  A4 */
                         349, 262, 262, 523, 440, 349, 330, 294, 466, 466, 440,
 
/*                       day  to  you
                         F4   G4   F4   */
                         349, 392, 349
                        };
                        
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
  pinMode(pinSpeaker, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inputPin);
  led = !led;
  if(led){
     digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
  
  if(val == HIGH){
    digitalWrite(ledPin, HIGH);
    //joueSon(300,160);
    nbMove += 1;
      
  }
  else{
    digitalWrite(ledPin,LOW);
    joueSon(0,0);
    nbMove = 0;
    delay(100);

    
  }
  if(nbMove==60){
    nbMove= 0;
    for(int i=0;i<25;i++){
      joueSon(200,notes[i]);
      joueSon(0,0);
      delay(40); 
    }
  }
  
  delay(100);  
}

void joueSon(long duree,int frequence){
  duree *= 1000;
  int periode =(1.0 /frequence)*1000000;
  long temps_passe=0;
  while(temps_passe <duree){
    digitalWrite(pinSpeaker, HIGH);
    delayMicroseconds(periode/2);
    digitalWrite(pinSpeaker, LOW);
    delayMicroseconds(periode/2);
    temps_passe += periode;
    
  }

}

