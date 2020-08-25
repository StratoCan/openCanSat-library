
#include "OcsGraphics.h"
#include "Ucglib.h"

#define UCG_MSG_DRAW_L90BF 25

OcsGraphics::OcsGraphics(Ucglib_ST7735_18x128x160_HWSPI& ucgIn)
	:ucg(ucgIn)
{
}

void OcsGraphics::drawLeftScreen() {
	ucg.setRotate90();
	// "center" bg
	ucg.setColor(0, 102, 255);
	ucg.drawBox(2, 10, 156, 116);
	// Screen frame
	ucg.setColor(255, 255, 255);
	ucg.drawRFrame(2, 10, 156, 69, 5);
	// BMEalt box
	drawFullBox("BMEalt", 5, 22, 74);
	// BMEtemp box
	drawFullBox("BMEtemp", 81, 22, 74);
	// BMEpress box
	drawFullBox("BMEpress", 5, 54, 74);
	// BMEhum box
	drawFullBox("BMEhum", 81, 54, 74);
	// stratocan text
	ucg.setFont(ucg_font_inr16_mr);
	ucg.setColor(255, 255, 255);
	ucg.setPrintPos(14, 104);
	ucg.print("Strato");
	ucg.drawBox(93, 82, 45, 30);
	ucg.setPrintPos(95, 104);
	ucg.setColor(0, 102, 255);
	ucg.print("Can");
	// icons
	ucg.setColor(255, 255, 255);
	this->drawRightArrow(141, 118);
	this->drawHome(74, 114, 12, 11, 17, 30, 108);
}

void OcsGraphics::drawRightScreen() {
	ucg.setRotate90();
	// "center" bg
	ucg.setColor(0, 102, 255);
	ucg.drawBox(2, 10, 156, 116);
	// Boxes frame
	ucg.setColor(255, 255, 255);
  ucg.drawRFrame(2, 10, 80, 101, 5);
	// yaw box
	drawFullBox("yaw", 5, 22, 74);
	// pitch box
	drawFullBox("pitch", 5, 54, 74);
	// roll box
	drawFullBox("roll", 5, 86, 74);

	// StratoCan logo
	ucg.setColor(255, 255, 255);
	//ucg_DrawBitmapLine(ucg.getUcg(), 81, 22, 0, 74, stratoCanLogo);

	this->drawLeftArrow(10, 118);
	this->drawHome(74, 114, 12, 11, 17, 30, 108);
}

void OcsGraphics::drawHomescreen() {
	ucg.setRotate90();
	// "center" bg
	ucg.setColor(0, 102, 255);
	ucg.drawBox(2, 10, 156, 103);
	// Screen frame
	ucg.setColor(255, 255, 255);
  ucg.drawRFrame(2, 10, 156, 101, 5);
	// ID box
	drawFullBox("ID", 5, 22, 74);
	// BMPalt box
	drawFullBox("BMPalt", 81, 22, 74);
	// BMPtemp box
	drawFullBox("BMPtemp", 5, 54, 74);
	// BMPpress box
	drawFullBox("BMPpress", 81, 54, 74);
	// DHTtemp box
	drawFullBox("DHTtemp", 5, 86, 74);
	// DHThum box
	drawFullBox("DHThum", 81, 86, 74);
	ucg.setColor(255, 255, 255);
	// icons
	this->drawRightArrow(141, 118);
	this->drawLeftArrow(10, 118);
	this->drawHome(74, 114, 12, 11, 0, 102, 255);
}

void OcsGraphics::drawBackground() {
	ucg.setRotate90();
	// Set position
	ucg.setPrintPos(0, 0);
	// Background color
	ucg.setColor(0, 102, 255);
	ucg.drawBox(0, 0, 160, 128);
	// stratocan.eu text
	ucg.setColor(255, 255, 255);
	ucg.setPrintPos(90, 7);
	ucg.setFontPosBaseline();
	ucg.setFont(ucg_font_5x7_mf);
	ucg.print("stratocan.eu");
	ucg.setRotate270(); /* idk */
}

// home icon
void OcsGraphics::drawHome(int x, int y, int width, int height, int r, int g, int b) {
	int halfSizeHeight = divide(height, 2);
	int halfSizeWidth = divide(width, 2);
	ucg.setColor(255, 255, 255);
	ucg.drawBox(x + divide(width, 4), y + halfSizeHeight, halfSizeWidth, halfSizeHeight);
	ucg.drawTriangle(x + halfSizeWidth, y, x + width, y + halfSizeHeight, x, y + halfSizeHeight);
	ucg.setColor(r, g, b);
	ucg.drawBox(x + 5*divide(width, 12), y + 4*divide(height, 6), divide(width, 6), divide(height, 3));
	ucg.setColor(255, 255, 255);
}

// right arrow icon
void OcsGraphics::drawRightArrow(int x, int y) {
	ucg.setColor(255, 255, 255);
	ucg.drawBox(x, y, 8, 5);
	ucg.drawTriangle(x + 8, y - 4, x + 8, y + 8, x + 14, y + 2);
}

// left arrow icon
void OcsGraphics::drawLeftArrow(int x, int y) {
	ucg.setColor(255, 255, 255);
	ucg.drawBox(x, y, 8, 5);
	ucg.drawTriangle(x, y - 5, x, y + 8, x - 6, y + 2);
}

void OcsGraphics::drawID(int id) {
	drawData(String(id), 16, 36);
}

void OcsGraphics::drawBMPalt(float BMPalt) {
	drawData(String(BMPalt), 92, 36);
}

void OcsGraphics::drawBMPtemp(float BMPtemp) {
	drawData(String(BMPtemp), 16, 68);
}

void OcsGraphics::drawBMPpress(float BMPpress) {
	drawData(String(BMPpress), 92, 68);
}

void OcsGraphics::drawDHTtemp(float DHTtemp) {
	drawData(String(DHTtemp), 16, 100);
}

void OcsGraphics::drawDHThum(float DHThum) {
	drawData(String(DHThum), 92, 100);
}

void OcsGraphics::drawBMEalt(float BMEalt) {
	drawData(String(BMEalt), 16, 36);
}

void OcsGraphics::drawBMEtemp(float BMEtemp) {
	drawData(String(BMEtemp), 92, 36);
}

void OcsGraphics::drawBMEpress(float BMEpress) {
	drawData(String(BMEpress), 16, 68);
}

void OcsGraphics::drawBMEhum(float BMEhum) {
	drawData(String(BMEhum), 92, 68);
}

void OcsGraphics::drawYaw(float yaw) {
	drawData(String(yaw), 16, 36);
}

void OcsGraphics::drawPitch(float pitch) {
	drawData(String(pitch), 16, 68);
}

void OcsGraphics::drawRoll(float roll) {
	drawData(String(roll), 16, 100);
}

// Box for values "ALTITUDE, 82, 22, 67"
void OcsGraphics::drawFullBox(String text, int x, int y, int sizeX) {
	ucg.setColor(255, 255, 255);
	ucg.setPrintPos(x + 2, y - 2);
	ucg.setFont(ucg_font_5x7_mf);
	ucg.print(text);
	ucg.setColor(255, 255, 255);
	ucg.drawRBox(x, y, sizeX, 20, 3);
}

int OcsGraphics::divide(int x, double y) {
	return ceil(x/y);
}

void OcsGraphics::drawData(String data, int x, int y) {
	ucg.begin(UCG_FONT_MODE_SOLID);
	ucg.setRotate90();
	ucg.setColor(0, 102, 255);
	ucg.setColor(1, 255, 255, 255);
	ucg.setPrintPos(x, y);
	ucg.setFont(ucg_font_7x13B_tf);
	ucg.print(data);
	ucg.begin(UCG_FONT_MODE_TRANSPARENT);
}