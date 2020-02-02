#define botaovermelho 8
#define botaoamarelo 9
#define botaoverde 10
#define ledvermelho 7 // ok
#define ledamarelo 6
#define ledverde 5
#define led13 13

unsigned long timet;
unsigned long tempoativo1inicio;
unsigned long tempoativo2inicio;
unsigned long tempoativo3inicio;
unsigned long tempoativo1final;
unsigned long tempoativo2final;
unsigned long tempoativo3final;
unsigned long tempototal1;
unsigned long tempototal2;
unsigned long tempototal3;

unsigned long previousTime;
unsigned long previousTime2;
unsigned long previousTime3;
boolean enterFunction = true;
boolean enterFunction2 = true;
boolean enterFunction3 = true;
boolean statusled13;
boolean statusbotaovermelho;
boolean statusbotaoamarelo;
boolean statusbotaoverde;
int statusatual=0;


void setup() {
  // set the digital pin as output:
  pinMode(botaovermelho, INPUT);
  pinMode(botaoamarelo, INPUT);
  pinMode(botaoverde, INPUT);
  pinMode(ledvermelho, OUTPUT);
  pinMode(ledamarelo, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(led13, OUTPUT);
}

void loop() {
   timet = micros();
  if (enterFunction == true){
    previousTime= timet;
    //Serial.println(previousTime); // for debugging

    // Write your first code below 
    //-----------------------
    
    statusbotaovermelho= digitalRead(botaovermelho);
    statusbotaoamarelo= digitalRead(botaoamarelo);
    statusbotaoverde= digitalRead(botaoverde);

    if (statusbotaovermelho == HIGH){
      digitalWrite(ledamarelo, LOW);
      digitalWrite(ledverde, LOW);
      digitalWrite(ledvermelho, HIGH);
      statusatual= 1;
      
    } else if (statusbotaoamarelo == HIGH){
      digitalWrite(ledverde, LOW);
      digitalWrite(ledvermelho, LOW);
      digitalWrite(ledamarelo, HIGH);
      statusatual= 2;
      
    } else if (statusbotaoverde == HIGH){
      digitalWrite(ledamarelo, LOW);      
      digitalWrite(ledvermelho, LOW);
      digitalWrite(ledverde, HIGH);
      statusatual= 3;
      
    } else{
      if(statusatual== 1){
        digitalWrite(ledvermelho, HIGH);
      }
      if(statusatual== 2){
        digitalWrite(ledamarelo, HIGH);
      }
      if(statusatual== 3){
        digitalWrite(ledverde, HIGH);
      }
    }



    //-----------------------
    // End of your first code
  }  
   

  //------------------------
  // Your second code (different timing) starts here

  if (enterFunction2 == true){
    previousTime2= timet;
    //Serial.println(previousTime2); // for debugging

    // Write your second code below 
    //-----------------------
    
  
   //digitalWrite(led13, !digitalRead(led13));
   //Serial.println(statusbotaovermelho);


    //-----------------------
    // End of your second code    
    }   


//------------------------
  // Your third code (different timing) starts here

  if (enterFunction3 == true){
    previousTime3= timet;
       
    // Write your third code below 
    //-----------------------





    
    //-----------------------
   // End of your third code
   } 
  
  
  // The DELAY time is adjusted in the constant below >> 
  if (timet - previousTime < 10000){ // 1 million microsencods= 1 second delay
    /* I have actually used 0.999990 seconds, in a trial to compensate the time that
       this IF function takes to be executed. this is really a point that
       need improvement in my code */   
    enterFunction= false;
  } 
  else {
    enterFunction= true;
  }

  if (timet - previousTime2 < 999999){ 
      enterFunction2= false;
  } 
  else {
    enterFunction2= true;
  }
  
    // The DELAY time is adjusted in the constant below >> 
  if (timet - previousTime3 < 29990){ // 30,000 microsencods= 30 milisecond delay
      enterFunction3= false;
  } 
  else {
    enterFunction3= true;
  }
  
  
}
