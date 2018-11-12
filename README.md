AS5045
======

Dash's AS5045 library for Arduino

This library is successfully tested using AS5045 with the official magnet under the recommended assembly position, see more details on AMS's website [here](https://ams.com/as5045).

# AS5045 Rotary Sensor Library for Arduino
## Introduction
This package contains the AS5045 rotary sensor library for Arduino. The absolute angle measurement provides instant indication of the magnet’s angular position with a resolution of 0.0879° = 4096 positions per revolution. This digital data is available as a serial bit stream and as a PWM signal(PWM is disabled by default).

The sensor driver package includes AS5045.cpp, AS5045.h and keywords.txt files.

## Integration details
Include the AS5045.h file in your code like below.
``` c++
#include <AS5045.h>
```

## File information
* AS5045.cpp : This source file contains the definitions of the sensor driver APIs.
* AS5045.h : This header file has the constants, macros and datatype declarations.
* keywords.txt : This keywords file contains the library specified syntax highlight.

## Supported sensor interfaces
* Input : SSI
* Output : PWM, serial bit stream

## Usage guide
### Initializing the sensor
To initialize the sensor, user need to create a device instance. At least the following parameters need to be provided when creating said instance.
* CS pin : Chip Select, active low
* CLK pin : Clock Input of Synchronous Serial Interface
* DO pin : Data Output of Synchronous Serial Interface

#### Example
``` c++
#define CSpin   2
#define CLKpin  3
#define DOpin   4

AS5045 enc (CSpin, CLKpin, DOpin);
```

### Zero Position Programming
An one time offset during a programming cycle. Personally not recommended usless you want no one else to modify the OTP afterwards.

### OTP register contents
* CCW : increase in clockwise(ccw=0), counter clockwise(ccw=1)
* Z[11:0] : Programmable Zero Position
* PWM dis : disable PWM output
* MagCompEn : When set, activates LIN alarm both when magnetic field is too high and too low
* PWMHalfEn : When set, PWM frequency is 122Hz or 2μs / step (when PWMhalfEN = 0, PWM frequency is 244Hz, 1μs / step)

Default value for all OTP bits is 0. You can modify the OTP register value using either of the functions below directly, for detailed explaination of each bit please ref to this [datasheet](https://ams.com/documents/20143/36005/AS5045_DS000101_2-00.pdf/5a2a30ca-e323-82dd-63a9-8fc3d5f7b6c4):

```c++
boolean progOTP (byte mode);
boolean progOTP (byte mode, boolean reverse, unsigned int offset);
```

### Credit

Mark's AS5040 library for Arduino
https://github.com/MarkTillotson/AS5040.git
