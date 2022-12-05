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
	FsPollDevice();
	
	
	
	//if (i == 0)
	//{
	//	glColor3f(0, 0, 0);
	//	glBegin(GL_QUADS);
    //    glVertex2i(0, 0); glVertex2i(800, 0); glVertex2i(800, 600); glVertex2i(0, 600);
	//	
	//}
	//i = 1;
	glColor3f(0, 255, 0);
	glRasterPos2i(100, 100);
	YsGlDrawFontBitmap10x14("Welcome to iKun Pro");
	glRasterPos2i(150, 450);
	YsGlDrawFontBitmap10x14("Choose Game Level: 1 -Easiest 2 -Intermediate 3 -Hardest");
	glRasterPos2i(150, 480);
	YsGlDrawFontBitmap10x14("ESC -Quit the program");

	glEnd();
}

void GameMenu::DrawDead(void)
{
	FsPollDevice();


	//glColor3f(0, 0, 0);
	//glBegin(GL_QUADS);
	//glVertex2i(0, 0); glVertex2i(800, 0); glVertex2i(800, 600); glVertex2i(0, 600);

	glColor3f(0, 255, 0);

	glRasterPos2i(100, 450);
	YsGlDrawFontBitmap10x14("You DEAD!");
	glRasterPos2i(100, 480);
	YsGlDrawFontBitmap10x14("ESC -Quit the program");

}

void GameMenu::DrawWin(void)
{
	FsPollDevice();


	//glColor3f(0, 0, 0);
	//glBegin(GL_QUADS);
	//glVertex2i(0, 0); glVertex2i(800, 0); glVertex2i(800, 600); glVertex2i(0, 600);

	glColor3f(0, 255, 0);

	glRasterPos2i(100, 450);
	YsGlDrawFontBitmap10x14("You WIN!");
	glRasterPos2i(100, 480);
	YsGlDrawFontBitmap10x14("ESC -Quit the program");

}


