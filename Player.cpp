#include <stdio.h>
#include <iostream>
#include "fssimplewindow.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Player.h"

using namespace std;


void Player::drawPlayer(double x, double y) {
	glColor3ub(0, 0, 255);
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x + 20, y);
	glVertex2i(x + 20, y - 20);
	glVertex2i(x, y - 20);

	glEnd();
}
void Player::Healthbar(int hx, int hy, int fill) {
	
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

void Player::DrawHealthbar(int hx, int hy, int health) {
	int hx2 = hx + 30;
	int hx3 = hx2 + 30;

	if (health == 3) {
		Healthbar(hx, hy, 1);
		Healthbar(hx2, hy, 1);
		Healthbar(hx3, hy, 1);
	}
	if (health == 2) {
		Healthbar(hx, hy, 1);
		Healthbar(hx2, hy, 1);
		Healthbar(hx3, hy, 0);
	}
	if (health == 1) {
		Healthbar(hx, hy, 1);
		Healthbar(hx2, hy, 0);
		Healthbar(hx3, hy, 0);
	}
	if (health == 0) {
		Healthbar(hx, hy, 0);
		Healthbar(hx2, hy, 0);
		Healthbar(hx3, hy, 0);
	}
}



bool Player::CheckCollision(int mx, int my, int tx, int ty, int tw, int th)
{
	if ((mx + 20) >= tx && (mx + 20) <= tx + tw)
	{
		if (my >= ty - th && my <= ty) {
			return true;
		}
	}
	return false;
		
}
void Player::drawBounds(void) {
	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, 600);
	glVertex2i(370, 600);
	glVertex2i(370, 330);
	glVertex2i(0, 330);
	glEnd();

}

void Player::Move(int key, int& x, int& y) {
	
	if (FSKEY_LEFT == key)
	{
		x -= 10;
		//cout << 1 << endl;
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
}

