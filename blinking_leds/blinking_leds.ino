// Digital pins for led 1 and 2
int led1_pin = 9;
int led2_pin = 10;
// Current pin
int current = 0;

void setup() {
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
}

void loop() {
  if (!current) {
    digitalWrite(led1_pin, HIGH);
    digitalWrite(led2_pin, LOW);
    current = 1;
  } else {
    digitalWrite(led1_pin, LOW);
    digitalWrite(led2_pin, HIGH);
    current = 0; 
  }
  delay(1000);
}
