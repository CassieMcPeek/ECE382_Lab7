ECE382_Lab7
===========

# Lab 7 - A/D Conversion - "Robot Sensing"

# Overview
  This lab is meant to teach us the concepts associated with analog-to-digital converter (ADC). Each of our robots has three infrared (IR) emitter and detector pairs to bring in analog voltage values for the ADC. The incoming voltages will be used to determine whether the robot is approaching a wall or not. By using the headers on top of our robot PCD, we can read a voltage value between 0 V and 5 V that is proportional to the distance an object is in front of the IR sensor. 
  
# Prelab
  First I tested all three of my sensors using a DMM to ensure they were all functional, and they were. By looking at the lesson 36 notes, I decided to utilize P1.3, P1.4 and P1.5 to correspond to the three IR sensors. I made this decision because the sample code in the lesson notes used P1.4, so using the two surrounding it would make the most sense. The three input channels that correspond to those pins are INCH_3, INCH_4 and INCH_5. The schematic below shows how I will wire the sensors to the LEDS on my MSP430 to demonstrate their effectiveness.
  
   ![alt text] (https://raw.github.com/CassieMcPeek/ECE382_Lab7/master/Prelab.jpg "Schematic")
 
  
# Required Functionality

Once I had a good understanding of how the sample code from the lesson notes, it was pretty simple to implement the same code to work for all three sensors. I wired up the left sensor to LED 1 (required in lab, and shown in schematic above), the right sensor to LED 2 and then the center sensor to LED 1 as well. The code below shows the initializations for the ATD converter as well as the LED bits. 

      ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;		 // ADC10ON, interrupt enabled
      ADC10CTL1 = ADC10DIV_7;   
      ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;  				// Select SMCLK

      P1DIR |= BIT0; 									// Set P1.0 to output direction
      P1DIR |= BIT6;
     
Once I had the inializations all figured out from referencing the data sheet, I began working on the code for each sensor. I created seperate functions for each LED to set the correct input channels and bits for each sensor based on the wiring shown in the schematic above. The code below is the code for the left sensor, the code for the other two sensors was the same aside from the changing of the input channel and bit. 

       ADC10CTL0 &= ~ENC;
       ADC10CTL1 = INCH_3;
       ADC10AE0 |= BIT3;
       ADC10CTL0 |= ENC + ADC10SC;
       __bis_SR_register(CPUOFF + GIE);

       return ADC10MEM;
       

Once I had that code done, I moved on to the for loop to light the LEDS based on each sensor. For this, I would call the particular sensor function and then use an if else statement to compare the voltage value taken in from the sensor and a hex value to light the LED. The hex value is slightly different between the three IR sensors.

      rightSensor();
      if (ADC10MEM < 0x180)
        	P1OUT &= BIT6;
       else
      	P1OUT |= BIT6;
      	
It took quite a bit of testing to determine the hex value to set as the threshold in order to maximize the distance the IR sensor could sense an object. 

# A functionality

Each of the IR sensors on the robot are slightly different in their thresholds. A functionality tasks us with fully characterizing each sensor individually by showing the ATD values for a variety of distances from a wall or object. The graph below shows the voltage response for each sensor for distances ranging from 0 in from the sensor to 10 in from the sensor. 

 ![alt text] (https://raw.github.com/CassieMcPeek/ECE382_Lab7/master/Graph.JPG "Schematic")
 
The table below takes the voltage values measured for each sensor and converts them to decimal and hex values in order to be compared through the code. 
 
  ![alt text] (https://raw.github.com/CassieMcPeek/ECE382_Lab7/master/Table.JPG "Schematic")

# Conclusion

This lab showed that each sensor is different in the values that they take in, and therefore it took a lot of tries to maximize the distance that each sensor would detect an object or wall. By ensuring that I increased the threshold for each sensor will hopefully help my robot to more easily detect a wall in the following lab. 

# Documentation
    Dusty Weisner helped me debug my code and also fix my CCS when it wasn't recognizing my MSP430. 
    
