// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;
const int LED5v = 4;
// the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
long counter = 0;

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(LED5v, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value:
  
  Serial.println(millis() - counter);

  if (millis() - counter > 25000){
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LED5v, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(LED5v, LOW);
    counter = millis();
  }

  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LED5v, HIGH);
    delay(600);
    for (int i = 0; i <= 7; i++) {
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(LED5v, HIGH);
      delay(300);
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(LED5v, LOW);
      delay(100);
    }
   } else {
    // turn LED off:
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(LED5v, LOW);
  }
}
