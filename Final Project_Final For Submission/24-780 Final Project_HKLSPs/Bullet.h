#ifndef TEXTSTRING_IS_INCLUDED
#define TEXTSTRING_IS_INCLUDED

#include <stdio.h>
#include <math.h>
#include "fssimplewindow.h"

class Bullet
{
protected:
public:
	int drawType; //chicken, basketball, music note, etc.
	double centerX, centerY, borderX, borderY, r, v, angle;
	double x, y;
	double vx, vy, radians;
	const double Pi = 3.1415927;
	int dstate;

	Bullet();
	Bullet(double &cx, double &cy, double radius, double velocity, double ang, int dType);
	void Initialize(double &cx, double &cy, double radius, double velocity, double ang, int dType);
	void Move(void);
	void Move1(void);
	void DrawBullet(int dType);
	void Update(void);
	void Update1(void);
	void DrawCircle(double cx, double cy, double rad, int fill);
};

#endif