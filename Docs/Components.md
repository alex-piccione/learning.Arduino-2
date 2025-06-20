# Components

I bough some used stuff:
- Arduino UNO R3 originale
- Orange Pi PC (una specie di clone del Raspberry Pi)
- Orange PI Zero

- LiPo SHIM Pimoroni, con Adafruit Micro Lipo USB LiIon/LiPoly charger e batteria
- Nokia 5110 LCD con cavetti
- Un sensore di prossimità a ultrasuoni e alcuni sensori di ostacoli a infrarossi
- non ricordo cos'è la schedina che nella foto è vicina all'Arduino, credo un Bluethoot-Seriale

## Real Time Clock (RTC)

Hanno una batteria CR2032 per fargli mantenere l'orario anche se non alimentati.

- DS3231  3 EUR + spedizione su ebay
- DS1307  (vecchio standard, meno preciso e senza compensazione temperatura e con meno funzioni)



## Camera

El ESP32-CAM es un módulo de cámara compacto y de bajo costo que integra un chip ESP32-S (un System-on-Chip o SoC de Espressif) con una cámara y una ranura para tarjeta microSD. Se ha vuelto muy popular en el mundo de Arduino y del IoT (Internet de las Cosas) debido a sus capacidades y su precio asequible.

**¿Qué lo hace especial y por qué se usa con Arduino?**

1.  **Potencia de Procesamiento:** A diferencia de los microcontroladores Arduino tradicionales (como el Uno), el ESP32 es un microprocesador de doble núcleo de 32 bits mucho más potente, con una frecuencia de reloj que puede llegar a 240 MHz. Esto le permite manejar tareas más complejas, como el procesamiento de imágenes y la transmisión de video, que un Arduino normal no podría hacer.

2.  **Conectividad Integrada:** El ESP32 viene con conectividad Wi-Fi y Bluetooth (incluyendo BLE o Bluetooth Low Energy) incorporadas. Esto significa que el ESP32-CAM puede conectarse a tu red local, transmitir video en vivo a través de un navegador web, subir imágenes a la nube, o comunicarse con otros dispositivos Bluetooth.

3.  **Cámara Integrada:** Incluye una cámara OV2640 (comúnmente de 2 megapíxeles), que es capaz de capturar imágenes y video. Algunos módulos también son compatibles con la cámara OV7670.

4.  **Ranura para Tarjeta MicroSD:** Dispone de una ranura para tarjeta microSD, lo que permite almacenar imágenes, videos o cualquier otro dato directamente en el módulo, sin necesidad de un servidor externo.

5.  **Versatilidad para Proyectos IoT:** Gracias a su combinación de cámara, potencia de procesamiento y conectividad inalámbrica, es ideal para una amplia gama de aplicaciones IoT, como:
    * Sistemas de videovigilancia inalámbricos.
    * Monitoreo remoto de espacios.
    * Reconocimiento facial.
    * Sistemas de timbre inteligentes.
    * Cámaras web DIY.
    * Sistemas de automatización del hogar con visión.
    * Drones y robots con capacidades de visión.

6.  **Compatibilidad con el IDE de Arduino:** Aunque el ESP32 es un chip diferente a los de Arduino, se puede programar fácilmente utilizando el entorno de desarrollo integrado (IDE) de Arduino, una vez que se han añadido los "cores" o paquetes de soporte para las placas ESP32. Esto lo hace muy accesible para aquellos que ya están familiarizados con la programación de Arduino.

**Consideraciones al usar el ESP32-CAM:**

* **No tiene puerto USB integrado:** A diferencia de muchos módulos Arduino o ESP32, el ESP32-CAM no suele incluir un puerto USB para la programación directa. Generalmente, requiere un adaptador USB a serie (como un FTDI o un CP2102) para cargar el código. Algunos módulos vienen con un "shield" o placa adaptadora que sí incluye el puerto USB.
* **Alimentación:** Es crucial proporcionarle una fuente de alimentación estable y suficiente (generalmente 5V y al menos 2A) para un funcionamiento óptimo, especialmente al usar la cámara y el Wi-Fi simultáneamente.
* **Pines GPIO compartidos:** Algunos pines GPIO están internamente conectados a la cámara o a la ranura microSD, lo que puede limitar su uso para otras funciones en ciertos proyectos. El GPIO 0 es particularmente importante, ya que se usa para poner el ESP32 en modo de "flashing" (carga de firmware).

En resumen, el ESP32-CAM es una solución muy potente y económica para añadir capacidades de visión y conectividad inalámbrica a tus proyectos basados en la plataforma Arduino, abriendo un mundo de posibilidades en el desarrollo de dispositivos IoT inteligentes.


## IR Obstacle Sensor 

Infrared (IR) Obstacle Avoidance Sensor Module.


## Buzzer

Active buzzer can only emit a sound.  
Passive buzzer can emit different sounds, by the command _tone()_.  
https://www.youtube.com/watch?v=gj-H_agfd6U&ab_channel=ScienceBuddies  


- 12085: Buzzer passivo 12mm con resistenza 42R 3V~12V


## Wireless Charger Qi standard

Standard Qi fast wireless charger module transmitter PCBA circuit board +coil YK.

Your USB-C 2A charger provides:

5V × 2A = 10W total power

Typical power consumption breakdown:

Arduino Uno/Nano: ~100-200mA (0.5-1W)
LCD display: ~20-50mA (0.1-0.25W)
Buzzer (when active): ~10-50mA (0.05-0.25W)
LEDs, sensors, buttons: ~10-50mA total (0.05-0.25W)
Qi wireless charger: This is the big one - up to 2A (10W) when actively charging

The math:

Alarm clock components: ~1-2W
Qi charger (active charging): ~10W
Total when charging phone: 11-12W

Your 2A USB-C charger might be borderline insufficient when the wireless charger is actively charging a phone at full power.
Solutions:

Upgrade to 3A+ USB-C charger (15W+) - safest option
Use a 12V adapter with a buck converter to 5V - more headroom
Smart power management: Program the Arduino to reduce charging power when needed
Monitor actual consumption: The Qi module might not always draw full 2A

Recommendation:
Get a 5V 3A (15W) USB-C charger or higher. This gives you comfortable headroom for both the alarm clock and wireless charging without voltage drops or overheating.
The good news is that when the phone isn't charging (or is fully charged), the Qi module draws very little power (~50mW standby), so your alarm clock will run fine most of the time.


## Bluetooth

HC-05 o HC-06
![/images/HC-05%20or%2006.png]


È un modulo di comunicazione seriale Bluetooth. Permette al tuo Arduino di inviare e ricevere dati senza fili.  
L'HC-05 è un modulo più versatile che può operare sia in modalità "Master" (può avviare connessioni con altri dispositivi Bluetooth) che in modalità "Slave" (può essere scoperto e connesso da altri dispositivi).  
L'HC-06 è generalmente più semplice e opera solo in modalità "Slave" (quindi può essere solo connesso da altri, non può avviare una connessione).  
Sono molto usati per progetti di domotica (controllare luci o motori via smartphone), telemetria (inviare dati di sensori al computer), o controllo remoto di robot.  


## NTC (Negative Temperature Coefficient) thermistor

I have some marked "22", they should be 22k ohm (at 25*).  
The Beta coefficient is unknown, use 3950.  

"Partitore di tensione"
VCC (5V) -> R_ref -> X -> A0
X -> NTC -> GND

Partitore di Tensione:  
https://www.youtube.com/watch?v=pegxULD-Tdw&ab_channel=VitoBarone  

NTC, good explanation:  
https://www.youtube.com/watch?v=Fs3_zl9GsGc&ab_channel=Playduino

## KY-040

