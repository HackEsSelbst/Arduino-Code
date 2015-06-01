// Hallo alle zusammen! HIer ist der Code für das Lilypad Projekt!

// Hier werden die Pins und LEDs, die ihr nutzen werdet vorgestellt
const int buttonPin1 = 2; // der erste Schalter (Button) ist an Pin2
const int buttonPin2 = 3; // der zweite Schalter ist an Pin3
const int ledPin1 = 9; // die ersten drei LEDs sind an Pin9
const int ledPin2 = 10; // die zweiten drei LEDs sind an Pin10
const int ledPin3 = 11;// die dritten drei LEDs sind an Pin11

// hier werden die Statusse der Schalter,
//der FadeValue (sozusagen die Helligkeit der LED)
// und des Zählers (counter) festgelegt,
//sie alle stehen auf null
int buttonState1 = 0;
int buttonState2 = 0;
int fadeValue = 0;
int counter = 0;

void setup() {
 
  // Hier wird deklariert, ob es sich bei dem jeweiligen Pin
  //um einen Ein-, oder Ausgang handelt.
  
  //Die LEDs sind alle OUTPUT (Ausgang), da sie ja leuchten sollen, und der
  // Befehl dazu kommt vom Lilypad.
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

// Die Schalter sind INPUT (Eingang), da ihr sie betätigt und damit
// dem Lilypad Informationen gebt.
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT); 
  Serial.begin(9600);
}

// Hier beginnt die sogenannte Loop (Schleife),
// dieser Teil des Programms wird dauerhaft wiederholt,
// jedes Mal, wenn das Programm am Ende angelangt ist, fängt es wieder hier an.
void loop(){
// die folgenden aukommentierten Zeilen geben sozusagen die
// Übersetzung des Programmcodes wieder

  buttonState1 = digitalRead(buttonPin1);// frage den Status des Schalters ab
  buttonState2 = digitalRead(buttonPin2);// frage den Status des Schalters ab
 
  if (buttonState1 == HIGH){  // wenn der Schalter1 gedrückt ist
    fadeValue += 1;                 // zähl die "Helligkeit" auf einen höher
    delay(10);                          // und warte 10 Millisekunden
  }
  if (fadeValue >= 255 ){  // wenn die "Helligkeit" größer als 255 ist,
    fadeValue = 0;              //  fang wieder bei null an
  }
 


if (buttonState2 == HIGH) { // wenn der Schalter2 gedrückt ist
delay(1000);                         // warte 1000 Millisekunden
buttonState2 = digitalRead(buttonPin2);// und frage anschließend den Status
                                                               // des Schalters nochmal ab

if (buttonState2 == LOW) {// wenn der Schalter danach nicht mehr gedrückt ist
counter += 1;                     // setze den Zähler eins höher
}
}
if (counter == 1) { // wenn der Zähler auf 1 ist, dann
  analogWrite(ledPin1, fadeValue); // schalte die Pin1-LEDs mit der eingestellten "Helligkeit" an
}
if (counter == 2) { // wenn der Zähler auf 2 ist, dann
  analogWrite(ledPin1, 0);// mach die Pin1- und Pin3-LEDs aus
  analogWrite(ledPin3, 0);
  analogWrite(ledPin2, fadeValue);// und schalte die Pin2-LEDs zu der eingestellten "Helligkeit" ein
}
if (counter == 3) { // wenn der Zähler auf 3 ist
  analogWrite(ledPin1, 0);// mach die Pin1- und Pin2-LEDs aus
  analogWrite(ledPin2, 0);
  analogWrite(ledPin3, fadeValue);// und schalte die Pin3-LEDs zu der eingestellten "Helligkeit" ein
}
if (counter == 4) {// wenn der Zähler auf 4 ist
  analogWrite(ledPin1, fadeValue);
  analogWrite(ledPin2, fadeValue);
  analogWrite(ledPin3, 0);
  // mach die Pin3-LEDs aus und die Pin1- und Pin2-LEDs zu der eingestellten "Helligkeit" an
}
if (counter == 5) { // (u.s.w.)
  analogWrite(ledPin1, fadeValue);
  analogWrite(ledPin3, fadeValue);
  analogWrite(ledPin2, 0);
  // mach die Pin2-LEDs aus und die Pin1- und Pin3-LEDs zu der eingestellten "Helligkeit" an
}
if (counter == 6) {
  analogWrite(ledPin2, fadeValue);
  analogWrite(ledPin3, fadeValue);
  analogWrite(ledPin1, 0);
  // mach die Pin1-LEDs aus und die Pin2- und Pin3-LEDs zu der eingestellten "Helligkeit" an
}
if (counter == 7) {
  analogWrite(ledPin1, fadeValue);
  analogWrite(ledPin2, fadeValue);
  analogWrite(ledPin3, fadeValue);
  // mach die alle LEDs zu der eingestellten "Helligkeit" an
}
if (counter > 8) {
  analogWrite(ledPin1, 0);
  analogWrite(ledPin2, 0);
  analogWrite(ledPin3, 0);
  // mach alle LEDs wieder aus
  counter = 0; // und setze den Zähler wieder auf Null
  
}
//Serial.println(buttonState1);
//Serial.println(buttonState2);

}
