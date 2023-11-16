/*
 * 11/30/2023
 * Joshua Cappella Josiah Harvey
 * Final Project for EGCP-2120
 * Wrist-mounted monitor for tracking heart rate
 */

#include <Wire.h>
//might be worth considering rewriting some of the MAX30100 library functionality
//this would increase lines of code written, but would allow us to learn
//more, and keep the project more our own
#include "MAX30100.h"

void setup(){
  Wire.begin(); // join i2c bus (address optional)
}

void loop(){
  
}
