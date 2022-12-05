//#include "StartMenu.h"
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include "yspng.h"

class GameMenu
{
public:
	void Initialize(void);
	int Run(void);
	int RunOneStep(void);
	void Draw(void);
	void DrawTextOne(void);
	void DrawDead(void);
	void DrawWin(void);
	int GetTime(void);
};

void GameMenu::Initialize(void)
{
	
}

int GameMenu::Run(void)
{
	for (;;)
	{
		auto key = FsInkey();
		if (FSKEY_Q == key || FSKEY_S == key)
		{
			return key;
		}
		else if (FSKEY_1 == key || FSKEY_2 == key || FSKEY_3 == key)
		{
			return key;
		}
	}
}

int GameMenu::RunOneStep(void)
{
	//FsPollDevice();
	return FsInkey();
}

void GameMenu::Draw(void)
{
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2i(0, 0);

	glColor3ub(0, 0, 0);
	glVertex2i(800, 0);

	glColor3ub(0, 0, 0);
	glVertex2i(800, 600);

	glColor3ub(0, 0, 0);
	glVertex2i(0, 600);
	glEnd();
	

}


void GameMenu::DrawTextOne(void)
{

	glColor3f(211, 211, 211);
	glRasterPos2i(280, 240);
	YsGlDrawFontBitmap32x48("iKun Pro");
	glRasterPos2i(270, 270);
	YsGlDrawFontBitmap12x16("Ultimate Game For iKuns");


	glRasterPos2i(270, 340);
	YsGlDrawFontBitmap10x14("Start From Level 1: Press 1");
	glRasterPos2i(270, 370);
	YsGlDrawFontBitmap10x14("Start From Level 2: Press 2");
	glRasterPos2i(270, 400);
	YsGlDrawFontBitmap10x14("Start From Level 3: Press 3");
	glRasterPos2i(330, 430);
	YsGlDrawFontBitmap10x14("Quit: Press ESC");


	glColor3f(0, 255, 0);
	glRasterPos2i(330, 560);
	YsGlDrawFontBitmap10x14("@1980 by HKLSPs");
	glRasterPos2i(330, 580);
	YsGlDrawFontBitmap8x12("All Rights Reserved");
	

}

void GameMenu::DrawDead(void)
{
	glColor3f(211, 211, 211);
	glRasterPos2i(270, 280);
	YsGlDrawFontBitmap32x48("You Lost");
	glRasterPos2i(285, 310);
	YsGlDrawFontBitmap12x16("You are not a iKun");
	glRasterPos2i(310, 430);
	YsGlDrawFontBitmap10x14("Quit: Press ESC");

}



void GameMenu::DrawWin(void)
{
	glColor3f(211, 211, 211);
	glRasterPos2i(270, 280);
	YsGlDrawFontBitmap32x48("You Won");
	glRasterPos2i(255, 310);
	YsGlDrawFontBitmap12x16("You are INDEED a iKun");
	glRasterPos2i(310, 430);
	YsGlDrawFontBitmap10x14("Quit: Press ESC");

}


