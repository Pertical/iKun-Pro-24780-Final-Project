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
	

	glColor3f(0, 0, 0);
	glRasterPos2i(100, 100);
	YsGlDrawFontBitmap10x14("Welcome to iKun Pro");
	glRasterPos2i(100, 450);
	YsGlDrawFontBitmap10x14("Choose Game Level: 1 -Easiest 2 -Intermediate 3 -Hardest");
	glRasterPos2i(100, 480);
	YsGlDrawFontBitmap10x14("Q -Quit the program");


}

int main(void)
{
	GameMenu gm;
	YsRawPngDecoder png;

	png.Decode("ji.png");
	png.Flip();

	int GameMode;

	FsOpenWindow(16, 16, png.wid, png.hei, 1);

	for (;;)
	{
		FsPollDevice();
		auto key = FsInkey();
	

		if (key == FSKEY_Q)
		{
			break;
		}
		else if (key == FSKEY_1)
		{
			GameMode = 1;
			//CALL GAME HERE!!!
		}
		else if (key == FSKEY_2)
		{
			GameMode = 2;
			//CALL GAME HERE!!!
		}
		else if (key == FSKEY_3)
		{
			GameMode = 3;
			//CALL GAME HERE!!!
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		int w, h;
	

		FsGetWindowSize(w, h);

		glRasterPos2i(0, h - 1);
		glDrawPixels(png.wid, png.hei, GL_RGBA, GL_UNSIGNED_BYTE, png.rgba);
		gm.Draw();

		FsSwapBuffers();
		FsSleep(25);
	}
	return 0;
}
