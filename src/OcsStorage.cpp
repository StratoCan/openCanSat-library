#include <OcsStorage.h>

OcsStorage::OcsStorage(OcsGraphics& ocsDesignIn)
 : isInitalize(false),
   isTransition(false),
   ocsDesign(ocsDesignIn)
{
}

void OcsStorage::Update(message income, uint8_t screenNum)
{
	if(screenNum == 1) { // home
		ocsDesign.drawID(income.id);
		ocsDesign.drawBMPalt(income.BMPalt);
		ocsDesign.drawBMPtemp(income.BMPtemp);
		ocsDesign.drawBMPpress(income.BMPpress);
		ocsDesign.drawDHTtemp(income.DHTtemp);
		ocsDesign.drawDHThum(income.DHThum);
	}
	else if(screenNum == 0) { // left
		ocsDesign.drawBMEalt(income.BMEalt);
		ocsDesign.drawBMEtemp(income.BMEtemp);
		ocsDesign.drawBMEpress(income.BMEpress);
		ocsDesign.drawBMEhum(income.BMEhum);
	}
	else if(screenNum == 2) { // right
		ocsDesign.drawYaw(income.yaw);
		ocsDesign.drawPitch(income.pitch);
		ocsDesign.drawRoll(income.roll);
	}
}