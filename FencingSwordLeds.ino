// In/out pins
const int buttonPin = 2;
const int LED5v = 4;

// variable declaration
int buttonState = 0;  
long counter = 0;

void setup() {
  Serial.begin(9600);
  // initialization of LED and 5V transistor pin as output
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED5v, OUTPUT);
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
}

void loop() {
  //Process for flashing the lights every 25 seconds to keep power draw above lower limit*
  //MAIN LED 5v NOT NEEDED FOR POWER DRAW ANYMORE DUE TO RESISTOR CHANGE*
  Serial.println(millis() - counter);

  if (millis() - counter > 25000){
    digitalWrite(LED_BUILTIN, HIGH);
    //digitalWrite(LED5v, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    //digitalWrite(LED5v, LOW);
    counter = millis();
  }

  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  // check if the Epee sword tip is pressed
  if (buttonState == HIGH) {
    // If pressed, turn test LED and main lights on
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LED5v, HIGH);
    delay(600);
    for (int i = 0; i <= 7; i++) { //Flash main helmet lights 7 times
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(LED5v, HIGH);
      delay(300);
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(LED5v, LOW);
      delay(100);
    }
   } else {
    // turn LEDs off:
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(LED5v, LOW);
  }
}
