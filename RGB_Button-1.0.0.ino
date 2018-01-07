// Version: 1.0.0
// Created By: Jmere36
// Purpose: To change the colour of an led or more from Red to Green to Blue by a push of a button
// Instead of turning on when button is realeased it turns on when button is pressed
// Removes the flicker of holding the button as well
// This can add many functionalities to your build including: changing a acrylic light stand between r,g,b and potentialy more in future updates
// You can also monitor what colour the the led is at in the serial monitor 
// If there's any issues or questions please contact my email at: jmere36@icloud.com


// Red led is connected to pin 9
// Green led is connected to pin 10
// Blue led is connected to pin 11
// Button or sensor is connected to pin 8

// Change Log:
// Created 1.0.0 with bugs seemed to be all removed

const int button = 8;
  // Adds the button or sensor for changing the colour or the led
const int r = 9;
const int g = 10;
const int b = 11;
  // Adds the three colours for for a tri led (you can also use seperate leds if you want)
int in = 0;
  // The input int used by the button
int prev = "OFF";
  // Used to set the next colour or led
int prevprev = 0;
  // Used so that the 'if' loops do not conflict each other
int milli = 0;
  // Used to see how long it has been since last button press
int prevmilli = 0;
  // Used to set the milli int to the time of last button press
void setup() {
Serial.begin(9600);
  // Turns on serial communication
pinMode(button, INPUT);
pinMode(r, OUTPUT);
pinMode(g, OUTPUT);
pinMode(b, OUTPUT);
  // Sets the pins to the correct modes
}

void loop() {
in = digitalRead(button);
 // Reads the value of the button
if (in == HIGH) {
  // If the button is pressed
milli = milli - prevmilli;
  // Set milli to the last time the button has been pressed
prevmilli = millis();
  // Set prevmilli to the current millis time
  if (milli > 1) {
    // If the last time the button has been pressed is greater than 1 proceed
   // Can be changed to ignore a sensor for a period of time
  // E.g set a shock sensor to 100-200 because it can send a signal multiple times  
   if (prev == "BLUE") {
      // If previous colour was blue continue
     prevprev = 1;
      // Set prevprev to 1 for later use
     prev = "0";
     // Set prev to 0 so it does not conflict with later 'if' statements   
     digitalWrite(b, LOW);
      // Set the blue led to low/off
    }
    if (prev == "GREEN") {
        // If previous colour was green continue
      prev = "BLUE";
        // Set prev to blue
     digitalWrite(g, LOW);
       // Set the green led to low/off
     digitalWrite(b, HIGH);  
      // Set the green led to high/on
    }
    if (prev == "RED") {
        // If previous colour was red continue
      prev = "GREEN";
        // Set prev to green
     digitalWrite(r, LOW);
      // Set the red led to low/off
     digitalWrite(g, HIGH);
      // Set the green led to high/on
    }        
    if (prev == "OFF") {
      // If previous state was off continue
     prev = "RED";
      //  Set prev to to red
     digitalWrite(r, HIGH);
      // Set the red led to high/on
    }
  }
}
milli = millis();
  // Set milli to millis to count how long the last press has been
if (prevprev == 1) {
  // If prevprev is equal to 1 continue
  // This is used to change the state of prev without messing up the 'if' statements
  prevprev = 0;
    // Set prevprev to 0
  prev = "OFF";
    // Set prev to off
}
if (prev == "OFF") {
  // If prev is set to off continue
  Serial.println("STATE: OFF");
    // Print to serial communicaion saying the led is in the off state
}
if (prev == "RED") {
  // If prev is set to red continue
  Serial.println("STATE: RED");
    // Print to serial communication saying the led is in the red colour state
  digitalWrite(r, HIGH);
    // Set the red led to high/on
}

if (prev == "GREEN") {
  // If prev is set to green continue
  Serial.println("STATE: GREEN");
    // Print to serial communication saying the led is in the green colour state
  digitalWrite(g, HIGH);
    // Set the green led to high/on
}

if (prev == "BLUE") {
  // Id prev is set to blue continue
  Serial.println("STATE: BLUE");
    // Print to serial communication saying the led is in the blue colour state
  digitalWrite(b, HIGH);
    // Set the blue led to high
}
}
