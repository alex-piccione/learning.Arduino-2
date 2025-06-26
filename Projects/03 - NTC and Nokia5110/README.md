# NTC and Nokia 5110

(OHM symbol "Ω" is ALT+234)  
  
I have a NTC marked "103".  
It means 10 followed by 3 "0", 10K Ω.
Datasheet suggests is has a range of -40 and 150 Celsius degrees.  
A common B-value is 3950.  
  
   
## How can it be used to measure the temperature

1. The NTC resistance changes predictably with temperature.  
2. We can convert this changing resistance into a measurable voltage using a **voltage divider**.  
3. The Arduino Analog-to-Digital Converter (ADC) can read this voltage.
4. We then use a mathematical formula to convert the read voltage (or derived resistance) back into a temperature value.


## Why we need a Voltage Divider ?

Arduino cannot directly measure the resistance.  
It can measure the voltage.  
Arduino has a Analog-to-Digital Converter (ADC) that convert the Voltage to a numeric value.  
It is a 10 bit ADC, so it provides a value in the range 0-1023.   
Since the min value of the  voltage is 0, and the max value is 5V, a voltage of 5V will give a value og 1023, while 2.5V will give 511-512.  
So, the voltage is NORMALIZED to the range 0-1023.  
If we consider we have 1024 values in the range 0-1023, and the max value is 5,  
it means that each "step"  (increase of 1) has the value of 5/1023.  
So, we need to multiply the read analog value for this factor.  
For example, a read value of 511 will be 511*(5/1023) = 2.49755 Volt.


