  // definition des pin pour les led
  const int led_bleu = 9;
  const int led_verte = 10;
  const int led_orange = 11;
  const int led_rouge = 12;
  
  // definition des pin pour les floteur 
  const int flot_1 = 5;
  const int flot_2 = 6;
  const int flot_3 = 7;
  
  // definition pin pour contadt de pompe
  const int pompe = 8;

void setup() {
  //initialisation des pin en entré ou en sortie
  pinMode (led_bleu, OUTPUT);
  pinMode (led_verte, OUTPUT);
  pinMode (led_orange, OUTPUT);
  pinMode (led_rouge, OUTPUT);
  pinMode (pompe, OUTPUT);
  pinMode (flot_1, INPUT);
  pinMode (flot_2, INPUT);
  pinMode (flot_3, INPUT);

//defini l'étas des led (alumé ou éteinte )
  digitalWrite(led_bleu, LOW);
  digitalWrite(led_verte,LOW);
  digitalWrite(led_orange, LOW);
  digitalWrite(led_rouge, LOW);
  digitalWrite(pompe, HIGH);
  
}
  

void loop() {
 
  if (digitalRead (flot_1)==LOW) //si le floteur niveau haut est pas activé 
  {
    digitalWrite(led_verte,LOW); // alors la led verte est eteinte
  }
      else 
      {
      digitalWrite(led_verte,HIGH); //sinon le led verte est allumé
      }




  if (digitalRead (flot_2)==LOW)  //si le floteur niveau moyen est pas activé 
  {
    digitalWrite(led_orange,LOW);// alors la led orange est eteint
  }
      else 
      {
      digitalWrite(led_orange,HIGH); //sinon le led orange est allumé
      digitalWrite(led_bleu,LOW); // la led bleu s'etein quand la uuve et a moitier pleine ce qui signifie que on peut a nouveau utilisé la pompe
      digitalWrite(pompe,HIGH); // ferme le relay pour l'utilisation de la pompe 
      }


  if (digitalRead (flot_3)==LOW) // si le floteur bas n'est pas activé on fait clignoté la led rouge " alerte niveau faible "
  {
    digitalWrite(led_rouge,LOW);
    delay(500);
    digitalWrite(led_rouge,HIGH);
    delay(500);
    digitalWrite(led_bleu,HIGH); // on allume la led bleu " indicateur de pompe non utilisable "
    digitalWrite(pompe,LOW); // et on coupe le relay de pompe  , on poura reutiliser la pompe que quand la cuve sera a moitier pleine 
  }
       else 
       {
        digitalWrite(led_rouge,HIGH); // sinon on allume juste la led rouge ui indique que la cuve est ntre le bas et la moitier
       }
}
