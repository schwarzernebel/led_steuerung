#include <IRremote.h>
#define RECV_PIN 13
IRrecv irrecv(RECV_PIN);
decode_results results;
#define ledR1 3                                    //Definiere rote led vom ersten Streifen
#define ledG1 5                                    //Definiere grüne  - '' -
#define ledB1 6                                     //Definiere blaue  - '' -
#define ledR2 9                                     //Definiere rote led vom zweiten Streifen
#define ledG2 10                                     //Definiere grüne  - '' -
#define ledB2 11                                    //Definiere blaue  - '' -

byte ledstatusR1 = 0;                               //Definiere den Status von R1 (an/aus)
byte ledstatusG1 = 0;                               //Definiere den Status von G1 (an/aus)
byte ledstatusB1 = 0;                               //Definiere den Status von B1 (an/aus)
//byte ledstatusR2 = 0;                               //Definiere den Status von R2 (an/aus)
//byte ledstatusG2 = 0;                               //Definiere den Status von G2 (an/aus)
//byte ledstatusB2 = 0;                               //Definiere den Status von B2 (an/aus)
byte ledlastR1;
//byte ledlastR2;
byte ledlastG1;
//byte ledlastG2;
byte ledlastB1;
//byte ledlastB2;
byte FADESP;


#define BUT01 16187647
#define BUT02 16220287
#define BUT03 16203967
#define BUT04 16236607
#define BUT05 16195807
#define BUT06 16228447
#define BUT07 16212127
#define BUT08 16244767
#define BUT09 16191727
#define BUT10 16224367
#define BUT11 16208047
#define BUT12 16240687
#define BUT13 16199887
#define BUT14 16232527
#define BUT15 16216207
#define BUT16 16248847
#define BUT17 16189687
#define BUT18 16222327
#define BUT19 16206007
#define BUT20 16238647
#define BUT21 16197847
#define BUT22 16230487
#define BUT23 16214167
#define BUT24 16246807








void setup()
{
  Serial.begin(9600);
  pinMode (ledR1, OUTPUT);                               //Pins als OUTPUT setzen
  pinMode (ledG1, OUTPUT);
  pinMode (ledB1, OUTPUT);
  pinMode (ledR2, OUTPUT);
  pinMode (ledG2, OUTPUT);
  pinMode (ledB2, OUTPUT);
  irrecv.enableIRIn();                              //Start IrReciver

} void loop() {
  ledstatusR1 = analogRead(ledR1);                      //aktuelle Einstellung lesen und speichern
  // ledstatusR2 = analogRead(ledR2);
  ledstatusG1 = analogRead(ledG1);
  // ledstatusG2 = analogRead(ledG2);
  ledstatusB1 = analogRead(ledB1);
  // ledstatusB2 = analogRead(ledB2);

  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    switch (results.value) {
      case (BUT01) :                     //Gesamte Helligkeit erhöhen
        ledstatusR1++;
        analogWrite(ledR1, ledstatusR1);
        //  ledstatusR2++;
        analogWrite(ledR2, ledstatusR1);
        ledstatusG1++;
        analogWrite(ledG1, ledstatusG1);
        //  ledstatusG2++;
        analogWrite(ledG2, ledstatusG1);
        ledstatusB1++;
        analogWrite(ledB1, ledstatusB1);
        //  ledstatusB2++;
        analogWrite(ledB2, ledstatusB1);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT02) :                     //Gesamte Helligkeit verringern
        ledstatusR1--;
        analogWrite(ledR1, ledstatusR1);
        //   ledstatusR2--;
        analogWrite(ledR2, ledstatusR1);
        ledstatusG1--;
        analogWrite(ledG1, ledstatusG1);
        //   ledstatusG2--;
        analogWrite(ledG2, ledstatusG1);
        ledstatusB1--;
        analogWrite(ledB1, ledstatusB1);
        //   ledstatusB2--;
        analogWrite(ledB2, ledstatusB1);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT03) :                        //Ausschalten, Zustand speichern
        ledlastR1 = analogRead(ledR1);                                //die gelesenen/gespeicherten Werte scheinen willkürlich zu sein
        ledlastG1 = analogRead(ledG1);
        ledlastB1 = analogRead(ledB1);
        //    ledlastG2 = analogRead(ledG2);
        //    ledlastB1 = analogRead(ledB1);
        //    ledlastB2 = analogRead(ledB2);
        analogWrite(ledR1, 0);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        analogWrite(ledR2, 0);
        analogWrite(ledG2, 0);
        analogWrite(ledB2, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT04) :                         //Einschalten, Zustand laden
        analogWrite(ledR1, ledlastR1);                              //die geladenen Werte entsprechen nicht den gespeicherten 
        analogWrite(ledG1, ledlastG1);
        analogWrite(ledB1, ledlastB1);
        analogWrite(ledR2, ledlastR1);
        analogWrite(ledG2, ledlastG1);
        analogWrite(ledB2, ledlastB1);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT05) :                          //Rote Farbe erhöhen (funktioniert so nicht, Helligkeit ändert sich ich beide Richtungen)
        ledstatusR1++;
        analogWrite(ledR1, ledstatusR1);


        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT06) :                          //Grüne Farbe erhöhen (funktioniert so auch nicht)
        ledstatusG1 = ledstatusG1 + 10;
        analogWrite(ledG1, ledstatusG1);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT07) :                          //Blaue Farbe erhöhen (dann... erst noch test)
        analogWrite(ledR1, 0);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT08) :                          //Weiß max (noch test)
        analogWrite(ledR1, 2);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ////////////////////////////////////////////////////////////////////
      case (BUT09) :                          //Rot verringern (noch test)
        analogWrite(ledR1, 3);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT10) :                          //Grün verringern (noch test)
        analogWrite(ledR1, 4);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT11) :                           //Blau verringern (noch test)
        analogWrite(ledR1, 6);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT12) :                           // (noch test)
        analogWrite(ledR1, 8);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT13) :                          //Chilliges Orange (noch test)
        analogWrite(ledR1, 11);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT14) :                           //(noch test)
        analogWrite(ledR1, 16);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT15) :                          //(noch test)
        analogWrite(ledR1, 23);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT16) :                          //(noch test)
        analogWrite(ledR1, 32);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT17) :                          //(noch test)
        analogWrite(ledR1, 45);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT18) :                          //(noch test)
        analogWrite(ledR1, 64);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT19) :                          //(noch test)
        analogWrite(ledR1, 90);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT20) :                          //(noch test)
        analogWrite(ledR1, 128);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT21) :                          //(noch test)
        analogWrite(ledR1, 181);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT22) :                          //(noch test)
        analogWrite(ledR1, 255);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT23) :                          //(noch test)
        analogWrite(ledR1, 128);
        analogWrite(ledG1, 0);
        analogWrite(ledB1, 0);
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT24) :
        //Farbwechsel smooth langsam (funtioniert so, wenn einzeln hochgeladen, in case nicht)
        byte r, g, b;
        FADESP = 10;
        {
          // fade from blue to violet
          for (r = 0; r < 256; r++) {
            analogWrite(ledR1, r);
            analogWrite(ledR2, r);
            delay(FADESP);
          }                                           //ab hier bricht es ab und startet den ersten fade erneut
          // fade from violet to red
          for (b = 255; b > 0; b--) {
            analogWrite(ledB1, b);
            analogWrite(ledB2, b);
            delay(FADESP);
          }
          // fade from red to yellow
          for (g = 0; g < 256; g++) {
            analogWrite(ledG1, g);
            analogWrite(ledG2, g);
            delay(FADESP);
          }
          // fade from yellow to green
          for (r = 255; r > 0; r--) {
            analogWrite(ledR1, r);
            analogWrite(ledR2, r);
            delay(FADESP);
          }
          // fade from green to teal
          for (b = 0; b < 256; b++) {
            analogWrite(ledB1, b);
            analogWrite(ledB2, b);
            delay(FADESP);
          }
          // fade from teal to blue
          for (g = 255; g > 0; g--) {
            analogWrite(ledG1, g);
            analogWrite(ledG2, g);
            delay(FADESP);
          }
        }
      delay(1); break; default: delay(1);
    }

    irrecv.resume();
    Serial.println(ledstatusR1);
    Serial.println(ledstatusG1);
    Serial.println(ledstatusB1);
    Serial.println(ledlastR1);
    Serial.println(ledlastG1);
    Serial.println(ledlastB1);

  }


}



