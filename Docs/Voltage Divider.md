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
`` V_supply--- R1 --- V_out --- R2 --- GND ``

and connecting the V_out point to a Arduino Analog pin, we can calculate the value of one resistence, knowinf the other one.  
`` V_supply --- R1 --- A1 --- R2 --- GND ``

For example if we have:
R1=10_000 Ω
R2=?

To calculate R2 we need to use the **Voltage Divider Formula**:
``` 
V_out = V_supply * R2/(R1 + R2)
```

$$V_{out} = V_{supply} * R2 \frac{R1 + R2}$$


