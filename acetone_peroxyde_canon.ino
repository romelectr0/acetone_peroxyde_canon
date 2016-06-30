#include <IRremote.h>
const int RECV_PIN = A0;
IRrecv irrecv(RECV_PIN);
int n = 0;
int a  = 2;
int b = 5;
int c  = 6;
int d  = 4;
int e = 7;
int f = 8;
int g = 3;
int dizaine = A1;
int unite = A2;
int directshoot = A3;
int timer = 60;
int up = 9;
int down = 10;
int set = 11;
int shoot = 12;
int whiletime = 0;
bool upval = false;
bool downval =  false;
int lastir[2];
bool setval[2] = {false,false};
decode_results results;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for(int i = 0;i<7;i++) {
    pinMode(i+2,OUTPUT);
  }
  pinMode(dizaine,OUTPUT);
  pinMode(unite,OUTPUT);
  pinMode(up,INPUT);
  pinMode(down,INPUT);
  pinMode(set,INPUT);
  pinMode(shoot,OUTPUT);
  pinMode(directshoot,INPUT);
  /*for(int i=0;i<100;i++){
    displaynumber(i,5,10);
  }*/
    irrecv.enableIRIn();
      irrecv.blink13(true);
 }
void loop() {
  
  if ((irrecv.decode(&results)) || ((digitalRead(up) || digitalRead(down) || digitalRead(set) || digitalRead(directshoot)) == HIGH)) {
    if ((results.value == 0x938F2CCF) || (results.value == 0xD03780EA) || (digitalRead(set) == HIGH)) {
      setval[0] = true;
      irrecv.resume();
    }    
    else if ((results.value == 0x2A0) || (results.value == 0xAA0) || (digitalRead(up) == HIGH)) {
      upval = true;
      downval = false;
      lastir[0] = 0;      
      if ((results.value == 0x2A0) || (results.value == 0xAA0)) {
        lastir[0] = 1;
        lastir[1] = millis();
      }
        irrecv.resume();      
    }
    else if ((results.value == 0x2A1) || (results.value == 0xAA1) || (digitalRead(down) == HIGH)) {
      upval = false;
      downval = true;
      lastir[0] = 0;      
      if ((results.value == 0x2A1) || (results.value == 0xAA1)) {
        lastir[0] = 2;
        lastir[1] = millis();
      }
      irrecv.resume();      
    }
    else if ((results.value == 0xF21169DD) || (results.value == 0xC5F4A8B0) || (digitalRead(directshoot) == HIGH)) {
      setval[1] = true;
      irrecv.resume();
      }
      else if (((results.value >= 0xA80) && (results.value <= 0xA89)) || ((results.value >= 0x280) && (results.value <= 0x289))) {
        timer = timerdecide();
      }
    else {
      irrecv.resume();
    }
  }
  if (upval || downval) {
  timer = timerr();
  }
  else {
    whiletime = 0;
    displaynumber(timer,5,5);
  }
  if (setval[0]) {
    setval[0] = shooter(setval[0],setval[1]);
  }
  else if (setval[1]) {
    setval[1] = shooter(setval[0],setval[1]);
  }
}

void offnumber() {
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
void zero() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
}
void un() {
 digitalWrite(b,HIGH);
 digitalWrite(c,HIGH); 
}
void deux() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(d,HIGH);
}
void trois() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
}
void quatre() {
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
}
void cinq() {
  digitalWrite(a,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
}
void six() {
  digitalWrite(a,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
}
void sept() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
}
void huit() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void neuf() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void displaydigit(int number) {
  if (number == 0) {
    zero();
  }
  if (number == 1) {
    un();
  }
  if (number == 2) {
    deux();
  }
  if (number == 3) {
    trois();
  }
  if (number == 4) {
    quatre();
  }
  if (number == 5) {
    cinq();
  }
  if (number == 6) {
    six();
  }
  if (number == 7) {
    sept();
  }
  if (number == 8) {
    huit();
  }
  if (number == 9) {
    neuf();
  }
}
void displaynumber(int value,int timenumber,int timetotal) {
  int dizainedisplay = (value-(value%10))/10;
  int unitedisplay = value%10;
  for(int i = 0;i < timetotal/timenumber;i++) {
  digitalWrite(unite,HIGH);
  displaydigit(unitedisplay);
  delay(timenumber);
  offnumber();
  digitalWrite(unite,LOW);
  digitalWrite(dizaine,HIGH);
  displaydigit(dizainedisplay);
  delay(timenumber);
  offnumber();
  digitalWrite(dizaine,LOW);
  }
  }
 int timerr() {
  while(true) {
    int add;
    if (upval) {
      add = 1;
      whiletime = whiletime+1;
    }
    else if (downval) {
      add = -1;
      whiletime = whiletime+1;
    }
     if (timer < 100) {     
      timer = timer+add;
      timer = constrain(timer,0,99); 
      
     if (whiletime < 6) {
      displaynumber(timer,5,100);
     }
     else {
      displaynumber(timer,5,50);
     }
     }
if (irrecv.decode(&results)) {
    lastir[1] = millis();
    if (lastir[0] == 1) {
      upval = true;
      downval = false;
      irrecv.resume();        
    }
    else if (lastir[0] == 2) {
      upval = false;
      downval = true;
      irrecv.resume();      
    }
    else {
      irrecv.resume();
    }
}
else {
     if (digitalRead(up) == HIGH) {
      upval = true;
    }
    else {
      upval = false;
    }
    if (digitalRead(down) == HIGH) {
      downval = true;
    }
    else {
      downval = false;
    }
}
   if ((upval || downval) == false) {
    timer = constrain(timer,0,99);
    return(timer);
   }
  }
  timer = constrain(timer,0,99);  
  return(timer);
 }
bool shooter(bool shootval0,bool shootval1) {
  bool shootvalue = true;
  if(shootval0) {
    for(int i = 0;i < timer;i++) {
     if (irrecv.decode(&results)) {
      if ((results.value == 0x28C) || (results.value == 0xA8C)) {
        irrecv.resume();
        return(false);
      }
      else {
        irrecv.resume();
      }
     }
     displaynumber(timer-i,5,30);
  }
  shootvalue = shooting(3000);
  return(shootvalue);   
 }
 else if (shootval1) {
  shootvalue = shooting(250);
  return(shootvalue);    
 }
 else {
  return(false);
 }
 }
 int timerdecide() {
        int timerval[2];
        if ((results.value >= 0xA80) && (results.value <= 0xA89)) timerval[0] = results.value - 0xA80;
        else timerval[0] = results.value - 0x280;
        irrecv.resume();
        for(int i=0;i < 3000;i++) {
        if (irrecv.decode(&results)) {
          if ((((results.value >= 0xA80) && (results.value <= 0xA89)) || ((results.value >= 0x280) && (results.value <= 0x289))) && i > 50) {
        if ((results.value >= 0xA80) && (results.value <= 0xA89)) timerval[1] = results.value - 0xA80;
        else timerval[1] = results.value - 0x280;
        irrecv.resume();
        Serial.println((10*timerval[0])+timerval[1]);        
        return((10*timerval[0])+timerval[1]);                   
          }
          else {
            irrecv.resume();
          }
        }
        displaynumber(timerval[0],5,5);
       }
      return(timerval[0]); 
 }
bool shooting(int timeneed) {
   digitalWrite(shoot,HIGH);
   for(int i = 0;i < timeneed/5;i++) {
     if (irrecv.decode(&results)) {
      if ((results.value == 0x28C) || (results.value == 0xA8C)) {
        irrecv.resume();
        digitalWrite(shoot,LOW);
        return(false);
      }
      else {
        irrecv.resume();
      }
     }    
      displaynumber(0,5,5);
    }
    digitalWrite(shoot,LOW);
    return(false);  
}
