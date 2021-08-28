#include "src/DS3231.h" //http://www.rinkydinkelectronics.com/library.php?id=73

DS3231  rtc(SDA, SCL);

//Pins
//Pins für Sekunden-Schieberegister
const int clockPinS   = 4;
const int latchPinS   = 3;
const int dataPinS    = 2;
//Pins für Minuten-Schieberegister
const int clockPinM   = 7;
const int latchPinM   = 6;
const int dataPinM    = 5;
//Pins für Stunden-Schieberegister
const int clockPinH   = 10;
const int latchPinH   = 9;
const int dataPinH    = 8;

const int tickled = 13;
const int taster = 12;

//Variablen
long prevMillis = 0;
long interval   = 500;
Time t;
int stunden;
int minuten;
int sekunden;
int tag;
int monat;
int wochentag;
int temp;
int halbesekunde = 0;
int modus = 1;
int modustimer = 0;

void setup(){
  //Outputpins
  pinMode(clockPinS, OUTPUT);
  pinMode(dataPinS,  OUTPUT);
  pinMode(latchPinS, OUTPUT);
  pinMode(clockPinM, OUTPUT);
  pinMode(dataPinM,  OUTPUT);
  pinMode(latchPinM, OUTPUT);
  pinMode(clockPinH, OUTPUT);
  pinMode(dataPinH,  OUTPUT);
  pinMode(latchPinH, OUTPUT);
  pinMode(tickled, OUTPUT);
  
  //Inputpin
  pinMode(taster, INPUT_PULLUP);
  
  //RTC
  rtc.begin();
  
  // Nachfolgende Linien zur Zeiteinstellung unkommentieren
  //rtc.setDOW(2);                // Wochentag einstellen -> 1=Montag, 2=Dienstag, ...
  //rtc.setTime(16, 58, 00);     // Uhrzeit einstellen (Stunde, Minute, Sekunde)
  //rtc.setDate(02, 04, 2019);   // Datum einstellen (Tag, Monat, Jahr)

  
  //für Debugging un-kommentieren
  //Serial.begin(9600);
} //Ende von setup()

void loop(){
  /*if (digitalRead(addhour) == LOW){ //falls Minuten erhöht werden sollen
    delay(100);
    minutes += 1;
    if (minutes > 58){
      minutes = 0;
    }
    Serial.println("Minute++");
    while(digitalRead(2) == LOW){
      delay(10);
      }
  }*/

  if (digitalRead(taster) == LOW){
    modus++;
    modustimer = 0;
    if (modus == 4){
      modus = 1;
    }
    while(digitalRead(taster) == LOW){}
    delay(100);
  }

  if(modustimer >= 10){
    modus = 1;
    modustimer = 0;
  }
     
   unsigned long currentMillis = millis();
   if (currentMillis - prevMillis > interval) {
     prevMillis = currentMillis;

     if(halbesekunde == 1){
       if (modus == 1){
        t = rtc.getTime();
        stunden = t.hour, DEC;
        minuten = t.min, DEC;
        sekunden = t.sec, DEC;
        digitalWrite(tickled, HIGH);
        displayTime();
       }
       else if (modus == 2){
        t = rtc.getTime();
        tag = t.date, DEC;
        monat = t.mon, DEC;
        wochentag = t.dow, DEC;
        modustimer++;
        displayDate();
       }
       else if (modus == 3){
        temp = int(rtc.getTemp());
        modustimer++;
        displayTemp();
       }
       
       //für Debugging un-kommentieren
       /*Serial.println("");
       Serial.println("Zeit:"); //für debugging
       Serial.print(String(stunden));
       Serial.print(":");
       Serial.print(String(minuten));
       Serial.print(":");
       Serial.print(String(sekunden));
       //*/
       
       halbesekunde = 0;
     }
     else{
       digitalWrite(tickled, LOW);
       halbesekunde = 1;
     }
   }
   
} //Ende von loop()


void displayTime(){ //Sendet die Zeit zu den Shiftregistern
    //Sekunden
    digitalWrite(latchPinS, LOW);
    shiftOut(dataPinS, clockPinS, MSBFIRST, sekunden);
    digitalWrite(latchPinS, HIGH);
    //Minuten
    digitalWrite(latchPinM, LOW);
    shiftOut(dataPinM, clockPinM, MSBFIRST, minuten);
    digitalWrite(latchPinM, HIGH);
    //Stunden
    digitalWrite(latchPinH, LOW);
    shiftOut(dataPinH, clockPinH, MSBFIRST, stunden);
    digitalWrite(latchPinH, HIGH);
}

void displayDate(){ //Sendet Datum zu den Shiftregistern
    digitalWrite(latchPinS, LOW);
    shiftOut(dataPinS, clockPinS, MSBFIRST, wochentag);
    digitalWrite(latchPinS, HIGH);
    digitalWrite(latchPinM, LOW);
    shiftOut(dataPinM, clockPinM, MSBFIRST, monat);
    digitalWrite(latchPinM, HIGH);
    digitalWrite(latchPinH, LOW);
    shiftOut(dataPinH, clockPinH, MSBFIRST, tag);
    digitalWrite(latchPinH, HIGH);
}

void displayTemp(){ //Sendet Temperatur zu den Shiftregistern
    digitalWrite(latchPinS, LOW);
    shiftOut(dataPinS, clockPinS, MSBFIRST, temp);
    digitalWrite(latchPinS, HIGH);
    digitalWrite(latchPinM, LOW);
    shiftOut(dataPinM, clockPinM, MSBFIRST, 0);
    digitalWrite(latchPinM, HIGH);
    digitalWrite(latchPinH, LOW);
    shiftOut(dataPinH, clockPinH, MSBFIRST, 0);
    digitalWrite(latchPinH, HIGH);
}
