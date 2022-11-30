#include <stdio.h>
#include <time.h>
#include <iostream>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include <string>
#include <charconv>


class Timer
{
public:
	void DrawTimer(void);

};

void Timer::DrawTimer(void)
{
	int ini_time, final_time, time_used;
	char timeused[10];
	ini_time = time(NULL);
	for(;;)
	{
		FsPollDevice();
		auto key = FsInkey();
		
		if (key == FSKEY_ESC)
		{
			break;
		}
	
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		glColor3f(0, 0, 0);
		glRasterPos2i(650, 100);
		final_time = time(NULL);
		time_used = final_time - ini_time;


		sprintf_s(timeused,"%d", time_used);


		YsGlDrawFontBitmap10x14(timeused);

		glColor3f(0, 0, 0);
		glRasterPos2i(500, 100);
		YsGlDrawFontBitmap10x14("Time Elasped:   s");

		FsSwapBuffers();
		FsSleep(25);
	}

}

int main(void)
{
	Timer t;
	FsOpenWindow(32, 32, 800, 600, 1);
	t.DrawTimer();

	return 0;

}