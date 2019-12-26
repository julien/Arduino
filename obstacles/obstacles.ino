// Digital pin for speed of motors
int speedma_pin = 5;
int speedmb_pin = 6;

// Digital pin for direction of motors
int turnma_pin = 4;
int turnmb_pin = 7;

// Ultrasonic sensor pins
int trig_pin = 13;
int echo_pin = 12;

// Sound speed in cm/us
float sound_speed = 0.0343;

long len;
long dist;

// Digital pins for led 1 and 2
int led1_pin = 9;
int led2_pin = 10;

void setup() {
  pinMode(speedma_pin, OUTPUT);
  pinMode(speedmb_pin, OUTPUT);
  pinMode(turnma_pin, OUTPUT);
  pinMode(turnmb_pin, OUTPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, OUTPUT);
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  // Speed for motors (100-255)
  analogWrite(speedma_pin, 100);
  analogWrite(speedmb_pin, 100);
}

void loop() {
  distance();

  if ((dist > 1) && (dist < 50)) {
    // Turn on leds
    digitalWrite(led1_pin, HIGH);
    digitalWrite(led2_pin, HIGH);

    // Drive backwards
    digitalWrite(turnma_pin, HIGH);
    digitalWrite(turnmb_pin, LOW);

    delay(500);

    // Rotate
    digitalWrite(turnma_pin, HIGH);
    digitalWrite(turnmb_pin, HIGH);

    delay(500);
  
  } else {
    // Turn off leds
    digitalWrite(led1_pin, LOW);
    digitalWrite(led2_pin, LOW);

    // Drive forward
    digitalWrite(turnma_pin, LOW);
    digitalWrite(turnmb_pin, HIGH);  
  }
}

// Calculates the distance in cm
void distance() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(4);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(4);
  digitalWrite(trig_pin, LOW);

  len = pulseIn(echo_pin, HIGH);
  dist = (sound_speed * len) / 2;
}
