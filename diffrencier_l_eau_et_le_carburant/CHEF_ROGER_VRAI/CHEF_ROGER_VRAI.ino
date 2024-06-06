const int BRS=5;
const int BGE=6;
const int BBAT=7;
const int BBAT2=8;
const int S=2;
const int G=3;
const int B=4;

// seuil de la batterie
int EBRS=0, EBGE=0, EBBAT=0, EBBAT2=0;
void setup() {
  // put your setup code here, to run once:
pinMode(BRS,INPUT);
pinMode(BGE,INPUT);
pinMode(BBAT,INPUT);
pinMode(BBAT2,INPUT);
pinMode(S,OUTPUT);
pinMode(G,OUTPUT);
pinMode(B,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
lecture();
if (EBRS==HIGH && EBBAT==LOW){
  delay(1000);
  
  lecture();
  
  //eteindre le groupe (instruction)
  while (EBRS==HIGH && EBBAT==LOW ){
        
    SNEL();
    lecture();
  }
}
else if (EBBAT==HIGH){
  while(EBBAT==HIGH){
    
  BATT();
  lecture();
  }
}
else if(EBBAT==LOW && EBGE==HIGH){
  // demarrage du groupe electrogene
  delay(1000);
  while(EBGE==HIGH){
    
    GE();
    lecture();
    }
  }
  else{
    DF();
 } 
 } 

void lecture(){
  EBRS=digitalRead(BRS);
  EBGE=digitalRead(BGE);
  EBBAT=digitalRead(BBAT);

}
void SNEL(){
 digitalWrite(S,LOW); // C
  digitalWrite(G,HIGH); // B
  digitalWrite(B,HIGH); // A
}
void BATT(){
   digitalWrite(S,LOW); //
  digitalWrite(G,HIGH); // B
  digitalWrite(B,LOW); // A
}
void GE(){
digitalWrite(S,LOW); // C
  digitalWrite(G,LOW); // B
  digitalWrite(B,HIGH); // A
  
}



void DF(){
  digitalWrite(S,LOW); // C
  digitalWrite(G,LOW); // B
  digitalWrite(B,LOW); // A
  }

