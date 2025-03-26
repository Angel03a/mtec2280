const int LEDs[] = {10, 11, 12, 13, 46};
const int buttonPin = 2;

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


  if (currentMillis - previousMillis >= speed) { //Speed that LEDs light up with timing (500 Milliseconds)
    previousMillis = currentMillis;

    for (int i = 0; i < 5; i++) {
      digitalWrite(LEDs[i], LOW); //Turn off LEDs in a sequence in a line
    }

    Serial.print("CurrentLED: "); //Check what LEDs are on
    Serial.println(CurrentLED);

    digitalWrite(LEDs[CurrentLED], HIGH);  // Turn ON the current LED


    if ((CurrentLED == 4 && movingRight) || (CurrentLED == 0 && !movingRight)) {     // Check if button is pressed when the last LED is ON
      if (digitalRead(buttonPin) == LOW) { //Pressed it at the right time
        movingRight = !movingRight; //Bounce back LED
        speed = random(300, 700); //Randomize between 300 to 700 milliseconds
      } else { 

        for (int i = 0; i < 5; i++) { //If button isn't pressed turn OFF
          digitalWrite(LEDs[i], LOW);
        }
        delay(2000); // 2 seconds, restart Loop
        CurrentLED = 0;
        movingRight = true;
        speed = 500;
      }
    }

 
    if (movingRight) {   // Move the LED in the correct direction (Follow a loop, left to right)
      CurrentLED++;
    } else {
      CurrentLED--;
    }
    if (CurrentLED > 4) {
      CurrentLED = 0; // Reset to the start
    } else if (CurrentLED < 0) {
      CurrentLED = 4; // Reset to end it
    }
  }
}