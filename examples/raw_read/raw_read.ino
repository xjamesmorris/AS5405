/*
 * raw_read.ino - test code for Arduino library for AMS AS5045 magnetic rotary encoder chip
 * version 1.0 2014-04-26
 *
 * Copyright (c) 2014 Dash (Wenchang Zhang).  All rights reserved.
 *
 
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  A copy of the GNU Lesser General Public License, <http://www.gnu.org/licenses/>.
 *
*/

#include <AS5045.h>

// CHANGE THESE AS APPROPRIATE
#define CSpin   2
#define CLKpin  3
#define DOpin   4

AS5045 enc (CLKpin, CSpin, DOpin) ;

// didn't program the OTP
void setup ()
{
	Serial.begin (115200) ;   // NOTE BAUD RATE
	if (!enc.begin ())
		Serial.println ("Error setting up AS5045") ;
}

void loop ()
{
/*
  Serial.print ("value:") ;
  Serial.print (enc.read (), DEC) ;
  Serial.print ("   ") ;
  Serial.print ("status:") ;
  Serial.print (enc.status (), BIN) ;
  Serial.print ("   ") ;
  Serial.print (enc.valid () ? "OK" : "Fault") ;
  Serial.print ("   ") ;
  Serial.print ("Z:") ;
  Serial.println (enc.Zaxis ()) ;
*/
Serial.print (enc.read () , BIN);
Serial.print ("\t");
Serial.print (enc.status (), BIN) ;
Serial.print ("\t");
Serial.print ("Angle : ");
Serial.println (enc.read () * 0.08789, DEC);
delay(10);
}
