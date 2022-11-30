#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "fssimplewindow.h"
#include "enemy.h"
#include <math.h>


#define GL_SILENCE_DEPRECATION

void Enemy::Initialize_level1(void)
{
	state = 1;
	x = 700;
	y = 100;
	vx = 2;
	vy = 2;
}
void Enemy::Initialize_level2(void)
{
	state = 1;
	x = 700;
	y = 100;
	vx = 10;
}
void Enemy::Initialize_level3(void)
{
	state = 1;
	x = 700;
	y = 100;
	vx = 20;
	vy = 20;
}
void Enemy::Move_x(void)
{
	x += vx;
}
void Enemy::Move_y(void)
{
	y += vy;
}

void Enemy::Draw_level1(void)
{
	glColor3ub(0, 0, 0);

	glBegin(GL_POLYGON);
	glVertex2i(x - 10, y - 10);
	glVertex2i(x - 10, y - 7);
	glVertex2i(x + 10, y - 10);
	glVertex2i(x + 10, y - 7);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 10, y + 7);
	glVertex2f(x - 10 - 2, y + 6);
	glVertex2f(x - 10 - 4, y + 7);
	glVertex2f(x - 10 - 5, y + 9);
	glVertex2f(x - 10 - 4, y + 11);
	glVertex2f(x - 10 - 2, y + 12);
	glVertex2f(x - 10 + 1, y + 10);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 8, y + 7);
	glVertex2f(x + 6, y + 6);
	glVertex2f(x + 4, y + 7);
	glVertex2f(x + 3, y + 9);
	glVertex2f(x + 4, y + 11);
	glVertex2f(x + 6, y + 12);
	glVertex2f(x + 9, y + 10);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(x - 10, y - 7);
	glVertex2f(x - 10, y + 7);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(x + 10, y - 10);
	glVertex2f(x + 9, y + 10);
	glEnd();
}

void Enemy::Draw_level2(void)
{
	double PI = 3.1415927;
	double rad = 10;
	glColor3ub(181, 66, 19);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i += 30)
	{
		double angle = (double)i * PI / 180;
		glVertex2d((x)+cos(angle) * rad, (y)+sin(angle) * rad);
	}
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	for (int i = 0; i < 360; i += 30)
	{
		double angle = (double)i * PI / 180;
		glVertex2d((x)+cos(angle) * rad, (y)+sin(angle) * rad);
	}
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(x, y - rad);
	glVertex2i(x, y + rad);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(x - rad, y);
	glVertex2i(x + rad, y);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(x - 7.07, y - 7.07);
	glVertex2f(x - 6, y - 6);
	glVertex2f(x - 5, y - 5);
	glVertex2f(x - 4, y - 3.5);
	glVertex2f(x - 3.5, y);
	glVertex2f(x - 4, y + 3.5);
	glVertex2f(x - 5, y + 5);
	glVertex2f(x - 6, y + 6);
	glVertex2f(x - 7.07, y + 7.07);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 7.07, y - 7.07);
	glVertex2f(x + 6, y - 6);
	glVertex2f(x + 5, y - 5);
	glVertex2f(x + 4, y - 3.5);
	glVertex2f(x + 3.5, y);
	glVertex2f(x + 4, y + 3.5);
	glVertex2f(x + 5, y + 5);
	glVertex2f(x + 6, y + 6);
	glVertex2f(x + 7.07, y + 7.07);
	glEnd();
}

void Enemy::Draw_level3(void)
{
	double PI = 3.1415927;

	//face
	glColor3ub(50, 50, 50);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 64; ++i)
	{
		double a = (double)i * PI * 2.0 / 64.0;
		double s = sin(a);  double c = cos(a);
		glVertex2d(x + c * 23, y + s * 23);
	}
	glEnd();

	glColor3ub(249, 225, 17);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 64; ++i)
	{
		double a = (double)i * PI * 2.0 / 64.0;
		double s = sin(a);  double c = cos(a);
		glVertex2d(x + c * 20, y + s * 20);
	}
	glEnd();
	//face

	//basketball
	double rad = 12;
	int xb, yb;
	xb = x - 20;
	yb = y + 10;
	glColor3ub(181, 66, 19);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i += 30)
	{
		double angle = (double)i * PI / 180;
		glVertex2d((xb)+cos(angle) * rad, (yb)+sin(angle) * rad);
	}
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	for (int i = 0; i < 360; i += 30)
	{
		double angle = (double)i * PI / 180;
		glVertex2d((xb)+cos(angle) * rad, (yb)+sin(angle) * rad);
	}
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(xb, yb - rad);
	glVertex2i(xb, yb + rad);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(xb - rad, yb);
	glVertex2i(xb + rad, yb);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(xb - 7.07, yb - 7.07);
	glVertex2f(xb - 6, yb - 6);
	glVertex2f(xb - 5, yb - 5);
	glVertex2f(xb - 4, yb - 3.5);
	glVertex2f(xb - 3.5, yb);
	glVertex2f(xb - 4, yb + 3.5);
	glVertex2f(xb - 5, yb + 5);
	glVertex2f(xb - 6, yb + 6);
	glVertex2f(xb - 7.07, yb + 7.07);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(xb + 7.07, yb - 7.07);
	glVertex2f(xb + 6, yb - 6);
	glVertex2f(xb + 5, yb - 5);
	glVertex2f(xb + 4, yb - 3.5);
	glVertex2f(xb + 3.5, yb);
	glVertex2f(xb + 4, yb + 3.5);
	glVertex2f(xb + 5, yb + 5);
	glVertex2f(xb + 6, yb + 6);
	glVertex2f(xb + 7.07, yb + 7.07);
	glEnd();
	//basketball

	//left eye
	glColor3ub(50, 50, 50);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 64; ++i)
	{
		double a = (double)i * PI * 2.0 / 64.0;
		double s = sin(a);  double c = cos(a);
		glVertex2d(x + 8 + c * 8, y - 5 + s * 8);
	}
	glEnd();

	glColor3ub(250, 250, 250);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 64; ++i)
	{
		double a = (double)i * PI * 2.0 / 64.0;
		double s = sin(a);  double c = cos(a);
		glVertex2d(x + 8 + c * 5, y - 5 + s * 5);
	}
	glEnd();

	glColor3ub(50, 50, 50);
	glPointSize(4.0);
	glBegin(GL_POINTS);
	glVertex2i(x + 10, y - 5);
	glEnd();
	//left eye

	//right eye
	glColor3ub(50, 50, 50);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 64; ++i)
	{
		double a = (double)i * PI * 2.0 / 64.0;
		double s = sin(a);  double c = cos(a);
		glVertex2d(x - 8 + c * 8, y - 5 + s * 8);
	}
	glEnd();

	glColor3ub(250, 250, 250);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 64; ++i)
	{
		double a = (double)i * PI * 2.0 / 64.0;
		double s = sin(a);  double c = cos(a);
		glVertex2d(x - 8 + c * 5, y - 5 + s * 5);
	}
	glEnd();

	glColor3ub(50, 50, 50);
	glPointSize(4.0);
	glBegin(GL_POINTS);
	glVertex2i(x - 6, y - 5);
	glEnd();
	//right eye

	//mouth
	glColor3ub(255, 165, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x - 4, y + 2);
	glVertex2f(x - 8, y + 6);

	glVertex2f(x - 10, y + 7.5);
	glVertex2f(x - 8, y + 9);
	glVertex2f(x - 4, y + 13);

	glVertex2f(x, y + 15);
	glVertex2f(x + 4, y + 13);
	glVertex2f(x + 8, y + 9);

	glVertex2f(x + 10, y + 7.5);
	glVertex2f(x + 8, y + 6);
	glVertex2f(x + 4, y + 2);
	glEnd();

	glColor3ub(50, 50, 50);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x, y);
	glVertex2f(x - 4, y + 2);
	glVertex2f(x - 8, y + 6);

	glVertex2f(x - 10, y + 7.5);
	glVertex2f(x - 8, y + 9);
	glVertex2f(x - 4, y + 13);

	glVertex2f(x, y + 15);
	glVertex2f(x + 4, y + 13);
	glVertex2f(x + 8, y + 9);

	glVertex2f(x + 10, y + 7.5);
	glVertex2f(x + 8, y + 6);
	glVertex2f(x + 4, y + 2);
	glEnd();


	glColor3ub(50, 50, 50);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x - 10, y + 7.5);
	glVertex2f(x + 10, y + 7.5);
	glEnd();
	//mouth


	//hair
	glColor3ub(128, 128, 128);
	glBegin(GL_POLYGON);
	glVertex2f(x, y - 30);
	glVertex2f(x - 5, y - 28);
	glVertex2f(x - 15, y - 24);
	glVertex2f(x - 20, y - 20);

	glVertex2f(x - 25, y - 15);
	glVertex2f(x - 20, y - 5);


	glVertex2f(x - 15, y - 10);
	glVertex2f(x - 10, y - 12);
	glVertex2f(x - 5, y - 14);

	glVertex2f(x, y - 20);
	glVertex2f(x + 5, y - 14);
	glVertex2f(x + 10, y - 12);

	glVertex2f(x + 15, y - 10);
	glVertex2f(x + 20, y - 5);

	glVertex2f(x + 25, y - 15);
	glVertex2f(x + 20, y - 20);
	glVertex2f(x + 15, y - 24);
	glVertex2f(x + 5, y - 28);

	glEnd();
	//hair

}

