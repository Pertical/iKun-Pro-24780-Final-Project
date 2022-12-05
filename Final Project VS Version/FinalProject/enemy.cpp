#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "fssimplewindow.h"
#include "enemy.h"
#include <math.h>


#define GL_SILENCE_DEPRECATION

void Enemy::Initialize_level1(void)
{
	state = 0;
	en_x = 700.0;
	en_y = 100.0;
	vx = 1;
	vy = 1;
}
void Enemy::Initialize_level2(void)
{
	//state = 1;
	en_x = 700;
	en_y = 100;
	vx = 10;
}
void Enemy::Initialize_level3(void)
{
	//state = 1;
	en_x = 700;
	en_y = 100;
	vx = 20;
	vy = 20;
}
void Enemy::Move_x(void)
{
	en_x += vx;
}
void Enemy::Move_y(void)
{
	en_y += vy;
}

void Enemy::Draw_level1(void)
{
	glColor3ub(0, 0, 0);

	glBegin(GL_POLYGON);
	glVertex2i(en_x - 10, en_y - 10);
	glVertex2i(en_x - 10, en_y - 7);
	glVertex2i(en_x + 10, en_y - 10);
	glVertex2i(en_x + 10, en_y - 7);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(en_x - 10, en_y + 7);
	glVertex2f(en_x - 10 - 2, en_y + 6);
	glVertex2f(en_x - 10 - 4, en_y + 7);
	glVertex2f(en_x - 10 - 5, en_y + 9);
	glVertex2f(en_x - 10 - 4, en_y + 11);
	glVertex2f(en_x - 10 - 2, en_y + 12);
	glVertex2f(en_x - 10 + 1, en_y + 10);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(en_x + 8, en_y + 7);
	glVertex2f(en_x + 6, en_y + 6);
	glVertex2f(en_x + 4, en_y + 7);
	glVertex2f(en_x + 3, en_y + 9);
	glVertex2f(en_x + 4, en_y + 11);
	glVertex2f(en_x + 6, en_y + 12);
	glVertex2f(en_x + 9, en_y + 10);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(en_x - 10, en_y - 7);
	glVertex2f(en_x - 10, en_y + 7);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(en_x + 10, en_y - 10);
	glVertex2f(en_x + 9, en_y + 10);
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
		glVertex2d((en_x)+cos(angle) * rad, (en_y)+sin(angle) * rad);
	}
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	for (int i = 0; i < 360; i += 30)
	{
		double angle = (double)i * PI / 180;
		glVertex2d((en_x)+cos(angle) * rad, (en_y)+sin(angle) * rad);
	}
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(en_x, en_y - rad);
	glVertex2i(en_x, en_y + rad);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(en_x - rad, en_y);
	glVertex2i(en_x + rad, en_y);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(en_x - 7.07, en_y - 7.07);
	glVertex2f(en_x - 6, en_y - 6);
	glVertex2f(en_x - 5, en_y - 5);
	glVertex2f(en_x - 4, en_y - 3.5);
	glVertex2f(en_x - 3.5, en_y);
	glVertex2f(en_x - 4, en_y + 3.5);
	glVertex2f(en_x - 5, en_y + 5);
	glVertex2f(en_x - 6, en_y + 6);
	glVertex2f(en_x - 7.07, en_y + 7.07);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(en_x + 7.07, en_y - 7.07);
	glVertex2f(en_x + 6, en_y - 6);
	glVertex2f(en_x + 5, en_y - 5);
	glVertex2f(en_x + 4, en_y - 3.5);
	glVertex2f(en_x + 3.5, en_y);
	glVertex2f(en_x + 4, en_y + 3.5);
	glVertex2f(en_x + 5, en_y + 5);
	glVertex2f(en_x + 6, en_y + 6);
	glVertex2f(en_x + 7.07, en_y + 7.07);
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
		glVertex2d(en_x + c * 23, en_y + s * 23);
	}
	glEnd();

	glColor3ub(249, 225, 17);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 64; ++i)
	{
		double a = (double)i * PI * 2.0 / 64.0;
		double s = sin(a);  double c = cos(a);
		glVertex2d(en_x + c * 20, en_y + s * 20);
	}
	glEnd();
	//face

	//basketball
	double rad = 12;
	int xb, yb;
	xb = en_x - 20;
	yb = en_y + 10;
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
		glVertex2d(en_x + 8 + c * 8, en_y - 5 + s * 8);
	}
	glEnd();

	glColor3ub(250, 250, 250);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 64; ++i)
	{
		double a = (double)i * PI * 2.0 / 64.0;
		double s = sin(a);  double c = cos(a);
		glVertex2d(en_x + 8 + c * 5, en_y - 5 + s * 5);
	}
	glEnd();

	glColor3ub(50, 50, 50);
	glPointSize(4.0);
	glBegin(GL_POINTS);
	glVertex2i(en_x + 10, en_y - 5);
	glEnd();
	//left eye

	//right eye
	glColor3ub(50, 50, 50);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 64; ++i)
	{
		double a = (double)i * PI * 2.0 / 64.0;
		double s = sin(a);  double c = cos(a);
		glVertex2d(en_x - 8 + c * 8, en_y - 5 + s * 8);
	}
	glEnd();

	glColor3ub(250, 250, 250);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 64; ++i)
	{
		double a = (double)i * PI * 2.0 / 64.0;
		double s = sin(a);  double c = cos(a);
		glVertex2d(en_x - 8 + c * 5, en_y - 5 + s * 5);
	}
	glEnd();

	glColor3ub(50, 50, 50);
	glPointSize(4.0);
	glBegin(GL_POINTS);
	glVertex2i(en_x - 6, en_y - 5);
	glEnd();
	//right eye

	//mouth
	glColor3ub(255, 165, 0);
	glBegin(GL_POLYGON);
	glVertex2f(en_x, en_y);
	glVertex2f(en_x - 4, en_y + 2);
	glVertex2f(en_x - 8, en_y + 6);

	glVertex2f(en_x - 10, en_y + 7.5);
	glVertex2f(en_x - 8, en_y + 9);
	glVertex2f(en_x - 4, en_y + 13);

	glVertex2f(en_x, en_y + 15);
	glVertex2f(en_x + 4, en_y + 13);
	glVertex2f(en_x + 8, en_y + 9);

	glVertex2f(en_x + 10, en_y + 7.5);
	glVertex2f(en_x + 8, en_y + 6);
	glVertex2f(en_x + 4, en_y + 2);
	glEnd();

	glColor3ub(50, 50, 50);
	glBegin(GL_LINE_STRIP);
	glVertex2f(en_x, en_y);
	glVertex2f(en_x - 4, en_y + 2);
	glVertex2f(en_x - 8, en_y + 6);

	glVertex2f(en_x - 10, en_y + 7.5);
	glVertex2f(en_x - 8, en_y + 9);
	glVertex2f(en_x - 4, en_y + 13);

	glVertex2f(en_x, en_y + 15);
	glVertex2f(en_x + 4, en_y + 13);
	glVertex2f(en_x + 8, en_y + 9);

	glVertex2f(en_x + 10, en_y + 7.5);
	glVertex2f(en_x + 8, en_y + 6);
	glVertex2f(en_x + 4, en_y + 2);
	glEnd();


	glColor3ub(50, 50, 50);
	glBegin(GL_LINE_STRIP);
	glVertex2f(en_x - 10, en_y + 7.5);
	glVertex2f(en_x + 10, en_y + 7.5);
	glEnd();
	//mouth


	//hair
	glColor3ub(128, 128, 128);
	glBegin(GL_POLYGON);
	glVertex2f(en_x, en_y - 30);
	glVertex2f(en_x - 5, en_y - 28);
	glVertex2f(en_x - 15, en_y - 24);
	glVertex2f(en_x - 20, en_y - 20);

	glVertex2f(en_x - 25, en_y - 15);
	glVertex2f(en_x - 20, en_y - 5);


	glVertex2f(en_x - 15, en_y - 10);
	glVertex2f(en_x - 10, en_y - 12);
	glVertex2f(en_x - 5, en_y - 14);

	glVertex2f(en_x, en_y - 20);
	glVertex2f(en_x + 5, en_y - 14);
	glVertex2f(en_x + 10, en_y - 12);

	glVertex2f(en_x + 15, en_y - 10);
	glVertex2f(en_x + 20, en_y - 5);

	glVertex2f(en_x + 25, en_y - 15);
	glVertex2f(en_x + 20, en_y - 20);
	glVertex2f(en_x + 15, en_y - 24);
	glVertex2f(en_x + 5, en_y - 28);

	glEnd();
	//hair

}

