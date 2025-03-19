const int LEDs[] = {12, 11, 10, 46, 3};  
int CurrentLED = 0; //Track LED, start at 0, pin 12        
bool movingRight = true; //Move forward in a line

void setup() {

  for (int i = 0; i < 5; i++) //Run once
    pinMode(LEDs[i], OUTPUT); //All LEDs as an OUTPUT
  }
}

void loop() {

  for (int i = 0; i < 5; i++) { { //Run five times, start from 0. Keep one LED at a time ON in a loop
    digitalWrite(LEDs[i], LOW); //Turn LED off when it's selected in the loop
  }


  digitalWrite(LEDs[ledIndex], HIGH);   // Turn LED on when it's selected in the loop


  delay(500);  //

 
  if (movingRight) { 
    CurrentLED++; //if the current LED is 4, change direction
    if (CurrentLED == 4) {  //Start at 0, go until 4 to the right.YES
      movingRight = false;
    }
  } else {
    CurrentLED--;  //if the current LED is 4, change direction
    if (CurrentLED == 0) {  //Start at 0 and restart loop
      movingRight = true;
    }
  }
}