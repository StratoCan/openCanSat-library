#ifndef _OCSDATASTORAGE_HH
#define _OCSDATASTORAGE_HH

#include <Arduino.h>
#include "OcsGraphics.h"

class OcsStorage
{
  public:
	OcsStorage(OcsGraphics& ocsDesignIn);

	// define our own struct data type with variables
	typedef struct
	{
		int id;
		int16_t rssi;
		float DHTtemp;
		float DHThum;
		float BMPtemp;
		float BMPpress;
		float BMPalt;
		float BMEtemp;
		float BMEpress;
		float BMEalt;
		float BMEhum;
		float yaw;
		float pitch;
		float roll;
	} message;

	void Update(message income, uint8_t screenNum);

	private:
		bool isInitalize;
		bool isTransition;
		OcsGraphics ocsDesign;
		message actualData {};
};

#endif /* _OCSGRAPHICS_HH */

