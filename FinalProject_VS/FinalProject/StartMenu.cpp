//#include "StartMenu.h"
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include "yspng.h"

class GameMenu
{
private:
	int StartTime, EndTime;

public:
	void Initialize(void);
	int Run(void);
	int RunOneStep(void);
	void Draw(void);
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
	

	glColor3f(0, 0, 0);
	glRasterPos2i(100, 100);
	YsGlDrawFontBitmap10x14("Welcome to iKun Pro");
	glRasterPos2i(100, 450);
	YsGlDrawFontBitmap10x14("Choose Game Level: 1 -Easiest 2 -Intermediate 3 -Hardest");
	glRasterPos2i(100, 480);
	YsGlDrawFontBitmap10x14("Q -Quit the program");


}


