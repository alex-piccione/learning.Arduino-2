# Nokia 5110 display

Il display Nokia 5110 richiede una libreria specifica (es. Adafruit_PCD8544 o LCD5110_Graph) e più collegamenti.

Collegamenti Display Nokia 5110:

Il display Nokia 5110 di solito ha 8 pin. Se il tuo è montato su un breakout board (come sembra dalla foto), potrebbe avere solo 6 o 8 pin sul lato per facilitare i collegamenti. Ecco i collegamenti tipici (possono variare leggermente, controlla il pinout stampato sul tuo modulo se lo trovi):

Pin Display Nokia 5110	Pin Arduino Uno
VCC	3.3V
GND	GND
SCE (CS)	Pin Digitale 7
RST	Pin Digitale 6
DC	Pin Digitale 5
DIN (MOSI)	Pin Digitale 4
CLK	Pin Digitale 3
BL (Backlight)	3.3V (o pin digitale con resistenza per controllo luminosità)

Export to Sheets
IMPORTANTE: Il display Nokia 5110 funziona a 3.3V. Se lo colleghi direttamente ai pin digitali di Arduino a 5V, potresti danneggiarlo. Idealmente, dovresti usare un level shifter (convertitore di livello logico) tra Arduino (5V) e il display (3.3V) per i pin di dati (SCE, RST, DC, DIN, CLK).

Soluzioni per il Voltaggio:

Level Shifter (raccomandato per la massima sicurezza): Se hai un convertitore di livello logico (bidirezionale 5V-3.3V), usalo per i pin di dati.
Resistenze in Serie (soluzione comune ma meno ideale): Per i pin di segnale da Arduino (5V) al display (3.3V), puoi mettere una resistenza da 10kΩ in serie tra il pin di Arduino e il pin corrispondente del display. Questo limita la corrente. Non è il massimo, ma spesso funziona. Non fare questo per VCC e GND.
Arduino a 3.3V (se hai un Arduino Pro Mini 3.3V): Non è il tuo caso con un Uno, ma è la soluzione più diretta se si usa un Arduino a 3.3V.  
  

Example:  
https://registry.platformio.org/libraries/adafruit/Adafruit%20PCD8544%20Nokia%205110%20LCD%20library/examples/pcdtest/pcdtest.ino
