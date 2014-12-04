/*
 * main2.c
 *
 *  Created on: Dec 3, 2014
 *      Author: C15Cassandra.McPeek
 */

#include <msp430g2553.h>
#include "Required_Funct.h"

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                			 // Stop WDT

  ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;		 // ADC10ON, interrupt enabled
  ADC10CTL1 = ADC10DIV_7;
  ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;  				// Select SMCLK

  P1DIR |= BIT0; 									// Set P1.0 to output direction
  P1DIR |= BIT6;

  for (;;){

    leftSensor();
    if (ADC10MEM < 0x180)
      P1OUT &= BIT0;   						// Clear P1.0 LED off
    else
      P1OUT |= BIT0;  						// Set P1.0 LED on

    _delay_cycles(1000);
    rightSensor();
    if (ADC10MEM < 0x180)
    	P1OUT &= BIT6;
    else
    	P1OUT |= BIT6;

    _delay_cycles(1000);
    centerSensor();
    if (ADC10MEM < 0x150)
       	P1OUT &= BIT0;
    else
       	P1OUT |= BIT0;
  }

    return 0;
}


