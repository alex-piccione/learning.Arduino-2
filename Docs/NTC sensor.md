# NTC Sensor

"Negative Temperature Coefficient" thermistor.  
Its resistance decreases as the temperature increase.  

I have one NTC marked "103", it means it is "10" followed by 3 "0" ohm: 10 000 Ω .

I measured the resistance at some temperature:
| T  | R     | 
| ---|    ---|
| 37 |  5110 |
| 30 |  7350 |
| 28 |  7680 |
|  2 | 17000 |
| -2 | 81000 |

It doesn't quite fit with expected values. especially the 7680 at 27... that should be much closer to 10000 .  
  
Using a Voltage Divisor with this formula is possible to obtain the resistance of the NTC.  
Note, the reference resistance MUST be the first in the series.
<!-- R_ntc = (R_fix * (V_supply - V_out)) / V_out -->
$$ R_{ntc} = \frac{R_{fix} * (V_{supply} - V_{out})}{V_{out}} $$  
  
Once you know the Resistance you can obtain the temperature with two 2 different formula:
- B-value equation
- Steinhart-Hart equation

## B-value equation

It requires a **B-value** specific of the NTC thermistor.  
It is simpler than the other but less precise, it allows to get a temperature with a 0.1 error.  

<!-- T_k = 1 / (1/T_0 + 1/B_value * log(R_ntc/R_0)) -->

$$ \log{\frac{ R_{ntc} } {R_0} }  $$

$$ T_K = \frac{1}{(\frac{1}{T_0} + \frac{1}{\beta_value} * \log{\frac{R_{ntc}}{R_0}})} $$  
with:   
$T_0$ is the reference temperature (25°C)  
$R_0$ is the reference Resistance (10 000 Ω)  
$\beta_{value}$ is the known beta-value of hte component. Datasheets online about the "103" suggests its value is 3950.    
  


## Steinhart-Hart equation

This formula is more precise but also more complex.  
It requires to have the A, B and C coefficients of the thermistor.  
I have no idea what these valiues can be for my 103 sensor.
They can be calculated measuring hte resistance at 3 different known temperatures.  
Topic/work for another day...  
