#include <stdio.h>
#include <iostream>
#include "fssimplewindow.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Player.h"

using namespace std;


void Player::drawPlayer(double player_x, double player_y) {

	//Draw Face
	glColor3ub(255, 195, 170);
	glBegin(GL_POLYGON);
	glVertex2i(player_x + 5, player_y);
	glVertex2i(player_x + 10, player_y + 5);
	glVertex2i(player_x + 10, player_y + 10);
	glVertex2i(player_x, player_y + 10);
	glVertex2i(player_x, player_y + 5);
	glEnd();
	//Draw Hair
	glColor3ub(192, 192, 192);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(player_x, player_y);
	glVertex2i(player_x + 5, player_y);
	glVertex2i(player_x, player_y + 5);
	glVertex2i(player_x + 10, player_y);
	glVertex2i(player_x + 10, player_y + 5);
	glEnd();

	//Draw Main Body
	glColor3ub(36, 36, 36);
	glBegin(GL_QUADS);
	glVertex2i(player_x - 5, player_y + 10);
	glVertex2i(player_x + 15, player_y + 10);
	glVertex2i(player_x + 15, player_y + 30);
	glVertex2i(player_x - 5, player_y + 30);
	glEnd();

	//Draw Legs
	glColor3ub(128, 128, 128);
	glBegin(GL_QUADS);
	glVertex2i(player_x, player_y + 30);
	glVertex2i(player_x + 10, player_y + 30);
	glVertex2i(player_x + 10, player_y + 50);
	glVertex2i(player_x, player_y + 50);
	//Draw Beidai

	glColor3ub(242, 243, 245);
	glVertex2i(player_x + 1, player_y + 10);
	glVertex2i(player_x + 3, player_y + 10);
	glVertex2i(player_x + 3, player_y + 30);
	glVertex2i(player_x + 1, player_y + 30);

	glVertex2i(player_x + 7, player_y + 10);
	glVertex2i(player_x + 9, player_y + 10);
	glVertex2i(player_x + 9, player_y + 30);
	glVertex2i(player_x + 7, player_y + 30);
	glEnd();

	//Draw foot & hands
	glColor3ub(255, 195, 170);
	glBegin(GL_QUADS);
	glVertex2i(player_x - 5, player_y + 27);
	glVertex2i(player_x, player_y + 27);
	glVertex2i(player_x, player_y + 30);
	glVertex2i(player_x - 5, player_y + 30);

	glVertex2i(player_x + 10, player_y + 27);
	glVertex2i(player_x + 15, player_y + 27);
	glVertex2i(player_x + 15, player_y + 30);
	glVertex2i(player_x + 10, player_y + 30);
	glEnd();

	glColor3ub(126, 84, 41);
	glBegin(GL_QUADS);
	glVertex2i(player_x, player_y + 47);
	glVertex2i(player_x + 10, player_y + 47);
	glVertex2i(player_x + 10, player_y + 50);
	glVertex2i(player_x, player_y + 50);
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



bool Player::CheckCollision(double mx, double my, double tx, double ty, double tw, double th)
{
	//if ((mx + 20) >= tx && (mx + 20) <= tx + tw)
	if((tx+tw) <= mx+10 && (tx+tw) >= mx)
	{
		//if ((my-20) >= ty - th && (my-20)<= (ty-th)) {
		//if ((my) >= ty - th && my <= (ty)) {
		if((ty+th) >= my && (ty-th) <= my+50){
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

void Player::Move(int key, double& x, double& y) {
	
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


	if (x < 0) {
		x = 0;
	}
	if (y > 550) {
		y = 550;
	}
	if (y < 0) {
		y = 0;
	}
	if (x > 770) {
		x = 770;
	}

}

