int a  = 2;
int b = 5;
int c  = 6;
int d  = 4;
int e = 7;
int f = 8;
int g = 3;
int dizaine = A1;
int unite = A2;
int timer = 60;
int up = 9;
int down = 10;
int set = 11;
int shoot = 12;
int whiletime = 0;
void setup() {
    delay(1000);
  // put your setup code here, to run once:
  for(int i = 0;i<12;i++) {
    if(i<9) {
    pinMode(i+2,OUTPUT);
    }
    else {
    pinMode(i+2,INPUT);  
    } 
  }
  pinMode(dizaine,OUTPUT);
  pinMode(unite,OUTPUT);
  pinMode(up,INPUT);
  pinMode(down,INPUT);
  pinMode(set,INPUT);
  pinMode(shoot,OUTPUT);
  /*for(int i=0;i<100;i++){
    displaynumber(i,5,10);
  }*/
 }
void loop() {
  timer = timerr();
  if (digitalRead(set == HIGH)) {
    for(int i = 0;i < 99;i++) {
     displaynumber(99-i,5,1000);
  }
  digitalWrite(shoot,HIGH);
  while(true) {
      displaynumber(0,5,1000);
    }
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
  int actualtime = millis();
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
  while((digitalRead(up) || digitalRead(down)) == HIGH) {
    int add;
    if (digitalRead(up) == HIGH) {
      add = 1;
    }
    else if (digitalRead(down) == HIGH) {
      add = -1;
    }
     if (timer < 99) {
      timer = timer+add;
      whiletime = whiletime+1;
     }
     if (whiletime < 6) {
      displaynumber(timer,5,500);
     }
     else {
      displaynumber(timer,5,200);
   }
   if ((digitalRead(up) && digitalRead(down)) == LOW) {
    return(timer);
   }
  }
 }
