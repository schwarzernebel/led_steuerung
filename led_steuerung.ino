#include <IRremote.h>
#define RECV_PIN 13
IRrecv irrecv(RECV_PIN);
decode_results results;
#define ledR1 5                                    //Definiere rote led vom ersten Streifen
#define ledG1 6                                    //Definiere grüne  - '' -
#define ledB1 3                                     //Definiere blaue  - '' -
#define ledR2 10                                     //Definiere rote led vom zweiten Streifen
#define ledG2 11                                     //Definiere grüne  - '' -
#define ledB2 9                                     //Definiere blaue  - '' -

byte ledstatusR1 = 0;                               //Definiere den Status von R1 (an/aus)
byte ledstatusG1 = 0;                               //Definiere den Status von G1 (an/aus)
byte ledstatusB1 = 0;                               //Definiere den Status von B1 (an/aus)

byte lastR;                                         //speichert den letzen Zustand von rot
byte lastG;                                         //speichert den letzen Zustand von grün
byte lastB;                                         //speichert den letzen Zustand von blau

byte memR1;                                         //Speicherplatz 1
byte memG1;
byte memB1;

byte memR2;                                         //Speicherplatz 2
byte memG2;
byte memB2;

byte memR3;                                         //Speicherplatz 3
byte memG3;
byte memB3;

byte FADESP = 10;                                        //Dimmgeschwindigkeit, je höher desto langsamer


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


void rainbow () //farbwechsel, keine endlosschleife?
{
  byte r, g, b;

  // fade from blue to violet
  for (byte r = 0; r < 255; r++) {
    analogWrite(ledR1, r);
    analogWrite(ledR2, r);
    delay(FADESP);
  }
  // fade from violet to red
  for (b = 255; b > 0; b--) {
    analogWrite(ledB1, b);
    analogWrite(ledB2, b);
    delay(FADESP);
  }
  // fade from red to yellow
  for (g = 0; g < 255; g++) {
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
  for (b = 0; b < 255; b++) {
    analogWrite(ledB1, b);
    analogWrite(ledB2, b);
    delay(FADESP);
  }
  // fade from teal to blue
  for (g = 255; g > 0; g--) {
    analogWrite(ledG1, g);
    analogWrite(ledG2, g);
    delay(FADESP);

  }// return;
}

void writeall ()
{
  analogWrite(ledR1, ledstatusR1);
  analogWrite(ledG1, ledstatusG1);
  analogWrite(ledB1, ledstatusB1);
  analogWrite(ledR2, ledstatusR1);
  analogWrite(ledG2, ledstatusG1);
  analogWrite(ledB2, ledstatusB1);
}


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

}
void loop()
{
  while (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    switch (results.value) {
      case (BUT01) :                     //Gesamte Helligkeit erhöhen

        ledstatusR1 = ledstatusR1 + 5;
        ledstatusG1 = ledstatusG1 + 5;
        ledstatusB1 = ledstatusB1 + 5;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT02) :                     //Gesamte Helligkeit verringern
        ledstatusR1--;
        ledstatusG1--;
        ledstatusB1--;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT03) :                        //Speichern, ausschalten
        lastR = ledstatusR1;
        lastG = ledstatusG1;
        lastB = ledstatusB1;
        delay(1);
        ledstatusR1 = 0;
        ledstatusG1 = 0;
        ledstatusB1 = 0;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT04) :                         //Laden, einschalten
        ledstatusR1 = lastR;
        ledstatusG1 = lastG;
        ledstatusB1 = lastB;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT05) :                          //Rote Farbe erhöhen
        ledstatusR1 = ledstatusR1 + 5;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT06) :                          //Grüne Farbe erhöhen
        ledstatusG1 = ledstatusG1 + 5;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT07) :                          //Blaue Farbe erhöhen
        ledstatusB1 = ledstatusB1 + 5;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT08) :                          //warmes weiß
        ledstatusR1 = 255;
        ledstatusG1 = 255;
        ledstatusB1 = 230;
        delay(1); break;
      ////////////////////////////////////////////////////////////////////
      case (BUT09) :                          //Rot verringern
        ledstatusR1--;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT10) :                          //Grün verringern
        ledstatusG1--;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT11) :                           //Blau verringern
        ledstatusB1--;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT12) :                           // abwechselnd blinken, keine endlosschleife?
        ledstatusR1 = 255;
        ledstatusG1 = 0;
        ledstatusB1 = 0;
        writeall();
        delay(500);
        ledstatusR1 = 0;
        ledstatusG1 = 255;
        ledstatusB1 = 0;
        writeall();
        delay(500);
        ledstatusR1 = 0;
        ledstatusG1 = 0;
        ledstatusB1 = 255;
        writeall();
        delay(500);

        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT13) :                          //Chilliges Orange
        ledstatusR1 = 255;
        ledstatusG1 = 120;
        ledstatusB1 = 0;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT14) :                           ///frei

        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT15) :                          ///frei

        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT16) :                          //frei

        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT17) :                          //Speicherplatz 1
        memR1 = ledstatusR1;
        memG1 = ledstatusG1;
        memB1 = ledstatusB1;

        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT18) :                          //Speicherplatz 2
        memR2 = ledstatusR1;
        memG2 = ledstatusG1;
        memB2 = ledstatusB1;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT19) :                          //Speicherplatz 3
        memR3 = ledstatusR1;
        memG3 = ledstatusG1;
        memB3 = ledstatusB1;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT20) :                          //frei

        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT21) :                          // 1 laden
        ledstatusR1 = memR1;
        ledstatusG1 = memG1;
        ledstatusB1 = memB1;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT22) :                          // 2 laden
        ledstatusR1 = memR2;
        ledstatusG1 = memG2;
        ledstatusB1 = memB2;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT23) :                          // 3 laden
        ledstatusR1 = memR3;
        ledstatusG1 = memG3;
        ledstatusB1 = memB3;
        delay(1); break;
      ///////////////////////////////////////////////////////////////////
      case (BUT24) :                          //Farbwechsel smooth, keine endlosschleife?
        rainbow();
      delay(1); break; default: delay(1);
    }

    writeall();
    irrecv.resume();
    Serial.println(ledstatusR1);
    Serial.println(ledstatusG1);
    Serial.println(ledstatusB1);
  }


}



