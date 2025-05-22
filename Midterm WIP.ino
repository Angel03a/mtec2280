const int LEDs[] = {10, 11, 12, 13, 24};
const int button = 4;

int CurrentLED = 0; //Start at LED 0 (PIN 12)
bool movingRight = true; //Move in a line

unsigned long previousMillis = 0;
int speed = 500; //Milliseconds

void setup() {
  Serial.begin(115200); 
  for (int i = 0; i < 5; i++) { //Loop, start at i (0) keep increasing.
    pinMode(LEDs[i], OUTPUT); //All LEDs as OUTPUT
  }
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  unsigned long currentMillis = millis();


  if (currentMillis - previousMillis >= speed) { 
    previousMillis = currentMillis;

    for (int i = 0; i < 6; i++) {
      digitalWrite(LEDs[i], LOW); 
    }

    Serial.print("LED NOW: ");
    Serial.println(LED NOW);

    digitalWrite(LEDs[CurrentLED], HIGH); 


    if ((CurrentLED == 3 && movingRight) || (CurrentLED == 0 & & !movingRight)) {  
      if (digitalRead(buttonPin) == LOW) { //Pressed it at the right time
        movingRight = !movingRight; 
        speed = random(200, 500); 
  }
}