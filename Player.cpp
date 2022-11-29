#include <stdio.h>
#include <iostream>
#include "fssimplewindow.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

class Player {
public:
	const double YS_PI = 3.1415927;
	double radx = 10.0, rady = 0.75;

	//Test
	void drawPlayer(double x, double y) {
		glColor3ub(0, 0, 255);
		glBegin(GL_QUADS);
		glVertex2i(x, y);
		glVertex2i(x + 20, y);
		glVertex2i(x + 20, y - 20);
		glVertex2i(x, y - 20);

		glEnd();
	}
	void Healthbar(int hx, int hy, int fill) {
		if (0 != fill) {
			glColor3ub(255, 0, 0);
			glBegin(GL_POLYGON);
		}
		else {
			glColor3ub(0, 0, 0);
			glBegin(GL_LINE_LOOP);
		}
		for (int i = 0; i < 80; i++) { //Approximating a circle with a 64-corner polygon
			double angle = (double)i * YS_PI / 40.0; //64/2
			double htx = (double)hx - pow(sin(angle),3) * (double)radx;
			double hty = (double)hy - (13 * cos(angle) - 5 * cos(2 * angle) - 2 * cos(3 * angle) - cos(4 * angle)) * (double)rady;
			glVertex2d(htx, hty);
		}
		glEnd();
	}
	bool CheckCollision(int mx, int my, int tx, int ty, int tw, int th)
	{
		if ((mx + 20) >= tx && (mx + 20) <= tx + tw)
		{
			if (my >= ty - th && my <= ty) {
				return true;
			}
		}
		return false;
		
	}

};

//Test target

void drawBounds(void) {
	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, 600);
	glVertex2i(370, 600);
	glVertex2i(370, 330);
	glVertex2i(0, 330);
	glEnd();

}

void drawTarget(double xi, double yi, int sizex, int sizey)
{
	glColor3ub(255, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(xi, yi);
	glVertex2i(xi + sizex, yi);
	glVertex2i(xi + sizex, yi - sizey);
	glVertex2i(xi, yi - sizey);

	glEnd();
}

void moveTarget(double& x, double& y, int scrnsizex, int scrnsizey)
{
	double v = 1;
	x -= 2.5 * v; // 0.25m
	if ((x + 50) == scrnsizex)
	{
		x = 800.0;
		v += 0.5;
		printf("%lf", v);
	}
}


int main(void)
{
	srand(time(NULL));
	Player p;

	int pState = 0; // 0 full health; 1 hitted; 
	int x = 100, y = 450;
	int hx = 50, hy = 50;
	int hx2 = 80, hx3 = 110;
	int health = 3;
	int i = 0;

	//Test target
	double targetxi = 600.0, targetyi = 500.0;
	int targetsizex = 50, targetsizey = 50;

	FsOpenWindow(16, 16, 800, 600, 1);

	for (;;)
	{
		FsPollDevice();
		auto key = FsInkey();
		if (FSKEY_ESC == key)
		{
			break;
		}

		if (FSKEY_LEFT == key)
		{
			x -= 10;
		}
		else if (FSKEY_RIGHT == key)
		{
			x += 10;
		}
		else if (FSKEY_DOWN == key)
		{
			y += 10;
		}
		else if (FSKEY_UP == key)
		{
			y -= 10;
		}

		if (x + 50 > 400) {
			x = 350;
		}
		else if (x < 0) {
			x = 0;
		}
		if (y > 600) {
			y = 600;
		}
		else if (y - 50 < 300) {
			y = 350;
		}
		//cout << x << endl;
		//cout << y << endl;


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		drawBounds();

		p.drawPlayer(x, y);
		
		//p.Healthbar(hx, hy, 0);
		//Test
		drawTarget(targetxi, targetyi, targetsizex, targetsizey);
		moveTarget(targetxi, targetyi, 0, 600);
		//
		if (health == 3) {
			p.Healthbar(hx, hy, 1);
			p.Healthbar(hx2, hy, 1);
			p.Healthbar(hx3, hy, 1);
		}
		if (health == 2) {
			p.Healthbar(hx, hy, 1);
			p.Healthbar(hx2, hy, 1);
			p.Healthbar(hx3, hy, 0);
		}
		if (health == 1) {
			p.Healthbar(hx, hy, 1);
			p.Healthbar(hx2, hy, 0);
			p.Healthbar(hx3, hy, 0);
		}
		if (health == 0) {
			p.Healthbar(hx, hy, 0);
			p.Healthbar(hx2, hy, 0);
			p.Healthbar(hx3, hy, 0);
		}

		if (true == p.CheckCollision(x, y, targetxi, targetyi, targetsizex, targetsizey)) { // TO BE FIXED
			i++;
			//printf("1");
		}

		if (i > 7) {
			health = health - 1;
			i = 0;
		}

		FsSwapBuffers();
		FsSleep(25);
	}
	return 0;
}



