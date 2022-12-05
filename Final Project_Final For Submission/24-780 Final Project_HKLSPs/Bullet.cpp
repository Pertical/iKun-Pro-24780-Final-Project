#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
#include <math.h>
#include "fssimplewindow.h"
#include "Bullet.h"

Bullet::Bullet() {
	//blank default constructor
}
Bullet::Bullet(double &cx, double &cy, double radius, double velocity, double ang, int dType) { //defaults
	centerX = cx;
	centerY = cy;
	x = centerX;
	y = centerY;
	r = radius;
	v = velocity;
	angle = ang;//in deg
	drawType = dType; //type of bullet to draw
}
//TODO: Add cleanup function/destructor to delete bullets once screen borders are hit. Might need to add variables for screen border.
void Bullet::Initialize(double &cx, double &cy, double radius, double velocity, double ang, int dType) { //defaults
	centerX = cx;
	centerY = cy;
	x = centerX;
	y = centerY;
	r = radius;
	v = velocity;
	angle = ang;//in deg
	drawType = dType; //type of bullet to draw
}
void Bullet::Move(void) {
	radians = angle * (Pi / 180.0);
	vx = v * (double)cos((double)radians);
	vy = v * (double)sin((double)radians);

	x += vx;
	y += vy;
}

void Bullet::Move1(void) {
	angle += 0.3;
	radians = angle * (Pi / 180.0);

	vx = v * (double)cos((double)radians);
	vy = v * (double)sin((double)radians);

	x += vx;
	y += vy;
	if (angle >= 360)
	{
		angle = 0;
	}

}

void Bullet::DrawBullet(int dType) {
	//TODO: Add function to attach png for Draw
	if (drawType == 0) {
		//attach pic1
	}
	else if (drawType == 1) {
		//attach pic2
	}
	else if (drawType == 2) {
		//attach pic3
	}
	DrawCircle(x, y, r, 1);
}
void Bullet::Update(void) {
	Move();
	glColor3ub(150, 70, 132);
	DrawBullet(drawType);
	
}

void Bullet::Update1(void) {
	Move1();
	glColor3ub(255, 111, 123);
	DrawBullet(drawType);
	
}

//Temp functions to remove
void Bullet::DrawCircle(double cx, double cy, double rad, int fill)
{
	const double YS_PI = 3.1415927;
	
	if (0 != fill) //fill
	{
		glBegin(GL_POLYGON);
	}
	else //hollow
	{
		glBegin(GL_LINE_LOOP);
	}

	int i;
	for (i = 0; i < 64; i++)
	{
		double angle = (double)i * YS_PI / 32.0;
		double x = (double)cx + cos(angle) * (double)rad;
		double y = (double)cy + sin(angle) * (double)rad;
		glVertex2d(x, y);
	}

	glEnd();
}

/*class Bullet {
public:
	int drawType; //chicken, basketball, music note, etc.
	double centerX, centerY, borderX, borderY, r, v, angle;
	double vx, vy, radians;
	const double Pi = 3.1415927;

	Bullet() {
		//blank default constructor
	}
	void Initialize(double cx, double cy, double radius, double velocity, double ang, int dType) { //defaults
		centerX = cx;
		centerY = cy;
		r = radius;
		v = velocity;
		angle = ang;//in deg
		drawType = dType; //type of bullet to draw
	}
	void Move(void) {
		radians = angle * (Pi / 180.0);
		vx = v * (double)cos((double)radians);
		vy = v * (double)sin((double)radians);

		centerX += vx;
		centerY += vy;
	}
	void DrawBullet(int dType) {
		//TODO: Add function to attach png for Draw
		if (drawType == 0) {
			//attach pic1
		}
		else if (drawType == 1) {
			//attach pic2
		}
		else if (drawType == 2) {
			//attach pic3
		}
		DrawCircle(centerX, centerY, r, 1);
	}
	void Update(void) {
		Move();
		DrawBullet(drawType);
	}

	//Temp functions to remove
	void DrawCircle(int cx, int cy, int rad, int fill)
	{
		const double YS_PI = 3.1415927;

		if (0 != fill) //fill
		{
			glBegin(GL_POLYGON);
		}
		else //hollow
		{
			glBegin(GL_LINE_LOOP);
		}

		int i;
		for (i = 0; i < 64; i++)
		{
			double angle = (double)i * YS_PI / 32.0;
			double x = (double)cx + cos(angle) * (double)rad;
			double y = (double)cy + sin(angle) * (double)rad;
			glVertex2d(x, y);
		}

		glEnd();
	}
};*/
/*
int main() {//Test
	FsOpenWindow(16, 16, 800, 600, 1);

	Bullet b1;
	b1.Initialize(400, 300, 10.0, 5.0, 45.0, 1); //x, y, radius, velocity (total), angle, drawType


	for (;;) {
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		FsPollDevice();
		auto key = FsInkey();

		if (FSKEY_ESC == key)
		{
			break;
		}

		b1.Update();

		FsSwapBuffers();
		FsSleep(25);
	}
	return 0;
}*/
