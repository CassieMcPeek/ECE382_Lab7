ECE382_Lab7
===========

# Lab 7 - A/D Conversion - "Robot Sensing"

# Overview
  This lab is meant to teach us the concepts associated with analog-to-digital converter (ADC). Each of our robots has three infrared (IR) emitter and detector pairs to bring in analog voltage values for the ADC. The incoming voltages will be used to determine whether the robot is approaching a wall or not. By using the headers on top of our robot PCD, we can read a voltage value between 0 V and 5 V that is proportional to the distance an object is in front of the IR sensor. 
  
# Prelab
  First I tested all three of my sensors using a DMM to ensure they were all functional, and they were. By looking at the lesson 36 notes, I decided to utilize P1.3, P1.4 and P1.5 to correspond to the three IR sensors. I made this decision because the sample code in the lesson notes used P1.4, so using the two surrounding it would make the most sense. The three input channels that correspond to those pins are INCH_3, INCH_4 and INCH_5. The schematic below shows how I will wire the sensors to the LEDS on my MSP430 to demonstrate their effectiveness.
  
# Required Functionality

Once I had a good understanding of how the sample code from the lesson notes, it was pretty simple to implement the same code to work for all three sensors. I wired up the left sensor to LED 1 (required in lab, and shown in schematic above), the right sensor to LED 2 and then the center sensor to LED 1 as well.  

# A Functionality


# Conclusion

# Documentation
    
    
