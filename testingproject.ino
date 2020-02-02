// This #include statement was automatically added by the Particle IDE.
#include <Grove_4Digit_Display.h>

// This #include statement was automatically added by the Particle IDE.
#include <Grove-Ultrasonic-Ranger.h>

#define CLK D4
#define DIO D5
Ultrasonic ultrasonic(D2);
TM1637 disp(CLK,DIO);

#include <math.h>

const int sensor=A0; //set the sensor to pin A0

int lastRange = 0;
void setup() {
    Serial.begin(9600);
    disp.init();
    //Options are: BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
    disp.set(BRIGHT_TYPICAL);
}

void loop() {
    
      int sensorValue=analogRead(sensor);//create a var to store the value of the sensor
      Serial.println("the analog read data is ");//print on the serial monitor what's in the ""
      Serial.println(sensorValue);// print the value of the sensor on the serial monitor
      delay(1000);
    
    int digit;
    int pos = 3;
    
    int range;
    
    Serial.println("Obstacle found at:");
    
    range = ultrasonic.MeasureInCentimeters();
    Serial.print(range); //0~400cm
    Serial.println(" cm");
    delay(250);
    
    if (range != lastRange) {
    lastRange = range;
    
    // Fill display with zeros
    for (int i = 0; i < 4; i++) {
        disp.display(i, 0);
    }
    
    // Extract each digit from the range and write it to the display
    while (range >= 1) {
        // Get the current digit by performing modulo (%) division on the range
        digit  = range % 10;
        // Remove the trailing digit by whole-number division
        range /= 10;
    
        disp.display(pos, digit);
        pos--;
    }
}
    
}