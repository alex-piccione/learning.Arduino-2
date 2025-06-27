# Learning Arduino

Arduino Development hints.  
Components.  
Electronic hints.

## Development

Arduino IDE is too limited. I want to use VS Code.   
I use VS Code with **PlatformIO** extension because the Arduino Community extension is not good to build the project:  
too hard and cumbersone to setup the project and still cannot solve the issue with include of external libraries.    
  
PlatformIO IDE extension installed and ready (Build + Upload) for a simple basic project in 10 minutes (it actually took many minutes to create the project), while it took at least 2 hours to configure the Arduino Community plugin !!  
  
### PlatformIO

It requires a platform.ini file, so the VS extension will recognize it and be able to activate intellisense, compiler, and all the features.  
It CANJNOT handle multiple proejcts in the same VS Code instance because to work  it requires to open the folder with the platformio.ini file.  
The board is set on the platform.ini file:
- **uno**  for Arduino UNO
- **nanoatmega328** for Arduino Nano  
  
For Arduino NAno to be visible in PlatformIO for the Upload a proper driver has to be installed in Windows.  
I'm using an Arduino Nano original, and this is the diver to serach for: "CH340G driver Windows".  
Found here: https://www.arduined.eu/ch340-windows-10-driver-download  


### Ardiuino Uno vs Zero vs Nano

[TODO: put comparison]

### Nano Clone

I have a clone of the Nano. It is recognizable because it has the USB-C port instead of standard USB.  
With default settings, it fails the upload because it has a difefrent (older) bootloader.  
The error is like: "".
It probably has the chip CH340G, and it requires a different settings:
_platformio.ini_:
```
[env:nano_blu]
platform = atmelavr
board = nanoatmega328old  ; For older Nano boards with ATmega328P
framework = arduino
upload_speed = 57600 ; Adjust upload speed if necessary
```

I also had to add the right Platform.  
In PlatformIO Home, go to "Platforms", serch "Atmel AVR" and install the latest version.  
This should have the settings for the board clone so the build and upload will work.  


## Components

There are components for everything.  
Look [here](Docs/Components.md).


## Circuit/Board design

_Fritzing_ or _KiCad_.  
Fritzing seems not to be free (8 EUR at least).  
KiCad, I used it to chreate a schema, I added the arduino, buzzer, resistance...


## Resistance to reduce voltage

V_out = V_in + R_tot

R_tot = R

????