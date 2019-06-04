#define En_right 2
#define En_left 3

#define Rm_p 4         // assign motor pins to arduino
#define Rm_n 5
#define Lm_p 6
#define Lm_n 7

//int in_40=LOW;
//int in_38=LOW;
//int in_36=LOW;




void setup() {


  pinMode(Rm_p,OUTPUT);
  pinMode(Rm_n,OUTPUT);
  pinMode(Lm_p,OUTPUT);
  pinMode(Lm_n,OUTPUT);
  pinMode(En_right,OUTPUT);
  pinMode(En_left,OUTPUT);
  
  digitalWrite(En_right,LOW);
  digitalWrite(En_left,LOW);
 
  Serial.begin(9600);
  Serial.println("Motor test!");

}

void loop() {
  // put your main code here, to run repeatedly:

        //RIGHT   //001
     
      Serial.print("right");
      digitalWrite(En_right,LOW);
      digitalWrite(En_left,HIGH);
      
      digitalWrite(Lm_p,HIGH);
      digitalWrite(Lm_n,LOW);

      delay(2000);
      
 
                            //LEFT   //100
      Serial.print("Left");
      digitalWrite(En_right,HIGH);
      digitalWrite(En_left,LOW);
      
      digitalWrite(Rm_p,HIGH);
      digitalWrite(Rm_n,LOW);
      delay(2000);
      
  
            //FORWARD    //101
    
      Serial.print("front");
      
      digitalWrite(En_right,HIGH);
      digitalWrite(En_left,HIGH);
      
      digitalWrite(Rm_p,HIGH);
      digitalWrite(Rm_n,LOW);
      
      digitalWrite(Lm_p,HIGH);
      digitalWrite(Lm_n,LOW);      
      
       delay(2000);
   
        //BACKWARD   //010
     
      
      Serial.print("back");
      digitalWrite(En_right,HIGH);
      digitalWrite(En_left,HIGH);
      
      digitalWrite(Rm_p,LOW);
      digitalWrite(Rm_n,HIGH);
      
      digitalWrite(Lm_p,LOW);
      digitalWrite(Lm_n,HIGH);      
      
     delay(2000);

                             //STOP
      Serial.print("back");
      digitalWrite(En_right,LOW);
      digitalWrite(En_left,LOW);
        
  delay(2000);
  
}

