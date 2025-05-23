import processing.serial.*;

Serial myPort;
int playerALives = 10;
int playerBLives = 10;

void setup() {
  size(400, 300);
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600); // Change [0] if needed
  myPort.bufferUntil('\n');
  textAlign(CENTER, CENTER);
  textSize(24);
}

void draw() {
  background(0);
  
  fill(255);
  text("2-Player LED Pong Scoreboard", width / 2, 30);
  
  fill(0, 255, 0);
  text("Player A Lives: " + playerALives, width / 2, 100);
  
  fill(0, 150, 255);
  text("Player B Lives: " + playerBLives, width / 2, 180);
  
  if (playerALives <= 0) {
    fill(255, 0, 0);
    text("Player B Wins!", width / 2, 250);
  } else if (playerBLives <= 0) {
    fill(255, 0, 0);
    text("Player A Wins!", width / 2, 250);
  }
}

void serialEvent(Serial p) {
  String input = p.readStringUntil('\n');
  if (input != null) {
    input = input.trim();
    
    if (input.startsWith("PLAYER_A_LIVES:")) {
      playerALives = int(input.substring(16));
    } else if (input.startsWith("PLAYER_B_LIVES:")) {
      playerBLives = int(input.substring(16));
    }
  }
}
