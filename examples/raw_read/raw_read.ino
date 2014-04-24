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
		Serial.println ("Error setting up AS5040") ;
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
Serial.print (enc.read (), BIN);
Serial.print ("\t");
Serial.println (enc.status (), BIN) ;

}
