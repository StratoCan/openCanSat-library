
#ifndef _OCSGRAPHICS_HH
#define _OCSGRAPHICS_HH

#include <Arduino.h>
#include "Ucglib.h"

class OcsGraphics
{
	public:
	OcsGraphics(Ucglib_ST7735_18x128x160_HWSPI& ucgIn);

	// screens
	void drawHomescreen();
	void drawRightScreen();
	void drawLeftScreen();

	void drawBackground(); //bg stratocan.eu

	// home values
	void drawID(int id);
	void drawBMPalt(float BMPalt);
	void drawBMPtemp(float BMPtemp);
	void drawBMPpress(float BMPpress);
	void drawDHTtemp(float DHTtemp);
	void drawDHThum(float DHThum);
	// left values
	void drawBMEalt(float BMEalt);
	void drawBMEtemp(float BMEtemp);
	void drawBMEpress(float BMEpress);
	void drawBMEhum(float BMEhum);
	// right values
	void drawYaw(float yaw);
	void drawPitch(float pitch);
	void drawRoll(float roll);

	private:
	Ucglib_ST7735_18x128x160_HWSPI& ucg;

	// icons
	void drawHome(int x, int y, int width, int height, int r, int g, int b);
	void drawRightArrow(int x, int y);
	void drawLeftArrow(int x, int y);

	// util
	void drawFullBox(String text, int x, int y, int sizeX); // box for values
	int divide(int x, double y);
	void drawData(String data, int x, int y);
};

#endif /* _OCSGRAPHICS_HH */

