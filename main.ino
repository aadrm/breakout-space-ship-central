
int progress = 0;
/////PINS/////
int doorLED = 2;
int throttleLED = 3;
int USBLED = 4;
int buttonLED = 5;
int batteryLED = 6;
int throttleLEDg = 7;
int throttleLEDr = 8;
int relayRaspi = 13;
int doorEM = 14;
int throttleEM = 15;
int door = 16;
int battery = 17;
int button = 18;
int USB = A5;
int throttle = A6;

/////STATES/////
int stateDoor;
int stateThrottle;
int stateButton;
int stateUSB;
int stateBattery;



void setup() {

  Serial.begin(9600);

  pinMode(doorLED, OUTPUT);
  pinMode(throttleLED, OUTPUT);
  pinMode(USBLED, OUTPUT);
  pinMode(buttonLED, OUTPUT);
  pinMode(batteryLED, OUTPUT);
  pinMode(throttleLEDg, OUTPUT);
  pinMode(throttleLEDr, OUTPUT);
  pinMode(relayRaspi, OUTPUT);
  pinMode(doorEM, OUTPUT);
  pinMode(throttleEM, OUTPUT);
  pinMode(door, INPUT_PULLUP);
  pinMode(battery, INPUT_PULLUP);
  pinMode(USB, INPUT_PULLUP);
  pinMode(button, INPUT_PULLUP);
  pinMode(throttle, INPUT);

  digitalWrite(doorLED, HIGH);
  digitalWrite(throttleLED, HIGH);
  digitalWrite(USBLED, HIGH);
  digitalWrite(buttonLED, HIGH);
  digitalWrite(batteryLED, HIGH);
  digitalWrite(throttleLEDg, LOW);
  digitalWrite(throttleLEDr, HIGH);
  digitalWrite(relayRaspi, HIGH);
  digitalWrite(doorEM, LOW);
  digitalWrite(throttleEM, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(progress);

  progress = 0;
  Serial.println(progress);
  stateThrottle = analogRead(throttle);
  stateDoor = digitalRead(door);
  stateUSB = analogRead(USB);
  stateButton = digitalRead(button);
  stateBattery = digitalRead(battery);

  //////////Door
  if (stateDoor == LOW) {
    digitalWrite(doorLED, LOW);
    progress += 1;
  }
  else {
    digitalWrite(doorLED, HIGH);
  }

  //////////USB
  if (stateUSB < 100) {
    digitalWrite(USBLED, LOW);
    progress += 1;
  }
  else {
    digitalWrite(USBLED, HIGH);
  }

  //////////Buttons
  if (stateButton == LOW) {
    digitalWrite(buttonLED, LOW);
    progress += 1;
  }
  else {
    digitalWrite(buttonLED, HIGH);
  }

  //////////Batteries

  if (stateBattery == LOW) {
    digitalWrite(batteryLED, LOW);
    progress += 1;
  }
  else {
    digitalWrite(batteryLED, HIGH);
  }
  ///////////Throttle

  if (progress == 4) {
    digitalWrite(throttleEM, HIGH);
    digitalWrite(throttleLEDg, HIGH);
    digitalWrite(throttleLEDr, LOW);
  }
  else {
    digitalWrite(throttleEM, LOW);
    digitalWrite(throttleLEDg, LOW);
    digitalWrite(throttleLEDr, HIGH);
  }

  if (stateThrottle > 999) {
    digitalWrite(relayRaspi, HIGH);
    delay(15000);
    digitalWrite(doorEM, HIGH);
  }
  else {
    digitalWrite(relayRaspi, LOW);
    digitalWrite(doorEM, LOW);
  }
  delay(500);
}
