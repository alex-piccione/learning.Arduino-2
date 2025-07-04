# Voltage Divider

The voltage divider works by creating two resistors in series. When you do this, the total current flowing through the series is determined
by the sum of their resistances (R_tot = R_1 + R_2).  
If you measure the Voltage in a point between the two resistances is lower then the positive pole.
  
`` +5V --- R1 --- V_out --- R2 --- GND ``
  
Giving R1=100 ohm, R2=50 ohm and the positive pole at 5V, the Current can be calculated as:
```
I = V / R1 + R2
= 5 / (100 + 50)
= 5 / 150
= 0.033 A (33.33mA)
```

Since we know the current (33.33mA) we can find the V_out:
```
V = I * R2  
= 0.03333 * 50
= 1.6665 V
```

## Find out a Resistance value

Using the same circuit:  
`` V_supply --- R1 --- V_out --- R2 --- GND ``

and connecting the V_out point to a Arduino Analog pin, we can calculate the value of one resistance, knowing the other one.  

For example if we know R1 but we don't know R2, to calculate R2 we need to use the **Voltage Divider Formula**:
<!-- V_out = V_supply * R2/(R1 + R2) -->
$$ V_{out} = V_{supply} * \frac{R2}{R1 + R2} $$

From that formu;a we can derive the one to obtain the value of R2:  
<!-- R2 = (R1 * (V_supply-V_out)) / V_out  -->
$$ R2 = \frac{R1 * (V_{supply} - V_{out})}{V_{out}} $$