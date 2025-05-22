const int playerA_LEDs[] = {13, 14, 15, 16, 17};  // Safe GPIOs for Player A
const int playerB_LEDs[] = {18, 19, 21, 22, 23};  // Safe GPIOs for Player B

const int buttonA = 4;  // Player A 
const int buttonB = 5;  // Player B 

int currentLED = 0;
bool movingRight = true;

unsigned long previousMillis = 0;
int speed = 400;  

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 5; i++) {
    pinMode(playerA_LEDs[i], OUTPUT);
    pinMode(playerB_LEDs[i], OUTPUT);
  }

  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= speed) {
    previousMillis = currentMillis;

    // Turn off all LEDs
    for (int i = 0; i < 5; i++) {
      digitalWrite(playerA_LEDs[i], LOW);
      digitalWrite(playerB_LEDs[i], LOW);
    }

    // Light up both current LEDs
    digitalWrite(playerA_LEDs[currentLED], HIGH);
    digitalWrite(playerB_LEDs[currentLED], HIGH);

    Serial.print("LED Index: ");
    Serial.println(currentLED);

    // Check bounce condition
    if ((currentLED == 4 && movingRight) || (currentLED == 0 && !movingRight)) {
      bool buttonPressedA = digitalRead(buttonA) == LOW;
      bool buttonPressedB = digitalRead(buttonB) == LOW;

      if (buttonPressedA && buttonPressedB) {
        movingRight = !movingRight;
        speed = random(300, 700); 
    }
  }
