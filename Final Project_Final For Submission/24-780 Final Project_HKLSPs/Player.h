#ifndef PLAYER_IS_INCLUDED
#define PLAYER_IS_INCLUDED
#include <stdio.h>
#include <iostream>
#include "fssimplewindow.h"
#include <stdlib.h>


class Player {
public:
	const double YS_PI = 3.1415927;
	double radx = 10.0, rady = 0.75;

	void drawPlayer(double x, double y);
	void Healthbar(int hx, int hy, int health);
	void DrawHealthbar(int hx, int hy, int health);
	bool CheckCollision(double mx, double my, double tx, double ty, double tw, double th);
	void drawBounds(void);
	void Move(int key, double& x, double& y);
};

#endif
