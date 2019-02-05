#include <Servo.h>

Servo serv1;  //servo bas
Servo serv2;  //servo gauche

//bras en position a peu près droit
int posiMoteur1 = 90;
int posiMoteur2 = 45;

int leftPin=10;  //bouton pressoir gauche
int rightPin=8;  //bouton pressoir droit

int left;        //valeur en lecture du bouton gauche
int right;       //valeur en lecture du bouton droit

int moteur = 0;

void setup() {

  serv1.attach(2);
  serv2.attach(4);

  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);

  pinMode(LED_BUILTIN, OUTPUT); //Pour utiliser la LED sur la carte 

  //initialisation des moteurs en position initial
  serv1.write(posiMoteur1);
  serv2.write(posiMoteur2);
}

void loop() {

    //lecture des boutons
    left = digitalRead(leftPin);
    right= digitalRead(rightPin);

    //Lorsque l'on appuis sur les deux boutons on controle l'autre moteur
    if(left==HIGH && right==HIGH){ 
      moteur = (moteur +1) %2;
      if(moteur == 0)
      {
          digitalWrite(LED_BUILTIN, LOW);    //Led de la carte éteinte on contôle le moteur d'en bas             
      }
      else{
         digitalWrite(LED_BUILTIN, HIGH);    //Led de la carte allumé on contôle le moteur d'en bas
      }
      delay(1000);  
    }
    else{
      //cas du moteur du bas
      if(moteur==0){
          if(left==HIGH){
            posiMoteur1 -= 1;
          }
          if(right==HIGH){
            posiMoteur1 += 1;
          }
          
          if(posiMoteur1<0) posiMoteur1 =0;
          if(posiMoteur1>180) posiMoteur1 = 180;
      }
      //cas du moteur du haut
      //Attention le moteur est dans l'autre sens
      else{
         if(left==HIGH){
            posiMoteur2 += 1;
          }
          if(right==HIGH){
            posiMoteur2 -= 1;
          }
          
          if(posiMoteur2<0) posiMoteur2 =0;
          if(posiMoteur2>180) posiMoteur2 = 180;
      }
      
      //On bouge les moteurs lorsqu'il y a une pression
      if(left==HIGH || right==HIGH){
        serv1.write(posiMoteur1);
        serv2.write(posiMoteur2);
      }
      delay(15);
    }
  
}
