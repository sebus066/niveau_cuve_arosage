  // définition des pin pour les leds
  const int led_bleu = 9;
  const int led_verte = 10;
  const int led_orange = 11;
  const int led_rouge = 12;
  
  // definition des pin pour les floteurs 
  const int flot_1 = 5;
  const int flot_2 = 6;
  const int flot_3 = 7;
  
  // définition pin pour contact de pompe
  const int pompe = 8;

void setup() {
  //initialisation des pin en entrée ou en sortie
  pinMode (led_bleu, OUTPUT);
  pinMode (led_verte, OUTPUT);
  pinMode (led_orange, OUTPUT);
  pinMode (led_rouge, OUTPUT);
  pinMode (pompe, OUTPUT);
  pinMode (flot_1, INPUT);
  pinMode (flot_2, INPUT);
  pinMode (flot_3, INPUT);

//defini l'état des leds (allumées ou éteintes )
  digitalWrite(led_bleu, LOW);
  digitalWrite(led_verte,LOW);
  digitalWrite(led_orange, LOW);
  digitalWrite(led_rouge, LOW);
  digitalWrite(pompe, HIGH);
  
}
  

void loop() {
 
  if (digitalRead (flot_1)==LOW) //si le floteur niveau haut est pas activé 
  {
    digitalWrite(led_verte,LOW); // alors la led verte est éteinte
  }
      else 
      {
      digitalWrite(led_verte,HIGH); //sinon le led verte est allumée
      }




  if (digitalRead (flot_2)==LOW)  //si le floteur niveau moyen n'est pas activé 
  {
    digitalWrite(led_orange,LOW);// alors la led orange est eteinte
  }
      else 
      {
      digitalWrite(led_orange,HIGH); //sinon le led orange est allumée
      digitalWrite(led_bleu,LOW); // la led bleu s'éteint quand la cuve est à moitier pleine ce qui signifie que l'on peut a nouveau utiliser la pompe
      digitalWrite(pompe,HIGH); // ferme le relais pour l'utilisation de la pompe 
      }


  if (digitalRead (flot_3)==LOW) // si le floteur bas n'est pas activé alors on fait clignoter la led rouge " alerte niveau faible "
  {
    digitalWrite(led_rouge,LOW);
    delay(500);
    digitalWrite(led_rouge,HIGH);
    delay(500);
    digitalWrite(led_bleu,HIGH); // on allume la led bleu " indicateur de pompe non utilisable "
    digitalWrite(pompe,LOW); // et on coupe le relais de pompe  , on ne poura reutiliser la pompe que lorsque la cuve sera a moitié pleine 
  }
       else 
       {
        digitalWrite(led_rouge,HIGH); // sinon on allume  la led rouge cela indique que la cuve est entre le niveau bas et la moitier
       }
}
