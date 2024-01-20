// Set Threshold distance for car to stop in inches
const int threshold = 7;

// Ultrasonic sensor config
const int pingtrig = 7;
const int pingecho = 2;

// Motor config
const int motorPin = 9;
const int motorRev = 11;

// Led config
const int led = 3;
const int led1 = 10;

void setup() {
  Serial.begin(9600);
  // initialize motor
  pinMode(motorPin, OUTPUT);
  pinMode(motorRev, OUTPUT);

  // initialize leds
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
}

void loop() {
  long inches;
  // Start measuring distance infront using the ultrasonic sensor
  inches = startMeasuring();

    // Decide motor on/off
    if (inches <= threshold) {
    // Obstacle has been detected, stop the motor and turn on the redlights
    digitalWrite(motorPin, LOW);
    digitalWrite(led, HIGH);
    digitalWrite(motorRev, HIGH);
    delay(2000);
  }
  else {
    // Path is clear, turn on the motor, turn off redlights and turn on greenlights
    digitalWrite(motorPin, HIGH);
    digitalWrite(led, LOW);
    digitalWrite(led1, HIGH);
    digitalWrite(motorRev, LOW);
  }
}

long startMeasuring() {
  long duration, inches, cm;

  pinMode(pingtrig, OUTPUT);
  digitalWrite(pingtrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pingtrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingtrig, LOW);

  pinMode(pingecho, INPUT);
  duration = pulseIn(pingecho, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  return inches;
}

// ----------------------------conversion---------------------------------
long microsecondsToInches(long microseconds) {
  /* According to Parallax's datasheet for the PING))), there are
  73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  second).  This gives the distance travelled by the ping, outbound
  and return, so we divide by 2 to get the distance of the obstacle.
  See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf */
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  /*The speed of sound is 340 m/s or 29 microseconds per centimeter.
  The ping travels out and back, so to find the distance of the
  object we take half of the distance travelled. */
  return microseconds / 29 / 2;
}