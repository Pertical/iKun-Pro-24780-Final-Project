#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fssimplewindow.h"
#include "Bullet.h"
#include "BulletPattern.h"
#include <vector>


BulletPattern::BulletPattern() {
	//default constructor
}
BulletPattern::BulletPattern(double x, double y, int winX, int winY) { //enemy xy variables & window XY
	centerX = x;
	centerY = y;
	windowX = winX;
	windowY = winY;
}
void BulletPattern::FollowEnemy(double& posX, double& posY) {//makes bullet pattern move with enemy
	centerX = posX;
	centerY = posY;
	following = true; //not used
}
void BulletPattern::Initialize(int num, double radius, double velocity, int frequency, int dType, time_t time1) { //can initialize at start of program to potentially prevent lag during actual level
	//printf("A\n");
	std::fill_n(fired, patternNum, false);
	n = num;
	f = frequency;
	r = radius;
	v = velocity;
	drawType = dType;
	startTime = time1;
	prevTime = 0;
	state = 0;
	//add cleanup function to clear bullet[n] first
	double angle = 360.0 / (double)n;

	bullet.resize(patternNum); //sets size of first dimension

	for (int j = 0; j < patternNum; j++) {
		for (int i = 0; i < n; i++) {

			//bullet[j][i].Initialize(centerX, centerY, r, v, i * angle, 1); //bullets initialized in circular pattern
			//printf("C %d\n",bullet.size());
			bullet[j].push_back(Bullet(centerX, centerY, r, v, i * angle, 1));
		}
	}
	//printf("B\n");
}
void BulletPattern::DrawPattern(int patternType) {
	Update(patternType);//Update currently shot bullet patterns
	bool noFreeSets = false;
	time_t currentTime = time(NULL);


	if (((currentTime - startTime) % f == 0) && (currentTime != prevTime)) { //Check if time to shoot additional new wave
		prevTime = currentTime;
		for (int i = 0; i < patternNum; i++) { //check for free set of bullets not fired
			printf("Check: %d\n", i);
			if (!fired[i]) {//if that row of bullets is currently NOT fired
				for (int j = 0; j < n; j++) { //shoot bullets

					if (patternType == 0) {

						bullet[i][j].Update();//moves bullets and draws them
						//wave; don't need to do anything, default Update()s will be wave
					}
					else if (patternType == 1) {

						bullet[i][j].Update1();

						//TODO: spiral; will need to modify time each bullet is shot, rather than being shot together like wave
					}
					else if (patternType == 2) {
						//TODO: third
						if (j % 2 == 0)
						{
							bullet[i][j].Update();
						}
						else
						{
							bullet[i][j].Update1();
						}

					}

				}
				fired[i] = true;
				printf("Free Set found: %d\n", i);
				break; //break out of checking through all bullet sets
			}
			if (i == patternNum - 1) {
				noFreeSets = true;
			}
		}
		//No free bullet sets
		if (noFreeSets) { printf("All bullets on screen\n"); }
	}
	//Maybe add straight or arced continuous beam attacks later.
}
void BulletPattern::Update(int patternType) {
	//Update currently shot bullets
	bool outOfBounds = true;
	for (int i = 0; i < patternNum; i++) {//go through all bullet sets

		if (fired[i]) {//if that row of bullets is currently fired
			for (int j = 0; j < n; j++) {

				if (bullet[i][j].x <= windowX && bullet[i][j].x >= 0 && bullet[i][j].y >= 0 && bullet[i][j].y <= windowY) {//check if in bounds
					outOfBounds = false;
					if (patternType == 1)
					{
						bullet[i][j].Update1();
					}
					else if (patternType == 0)
					{
						bullet[i][j].Update();
					}
					else
					{
						if (j % 2 == 0)
						{
							bullet[i][j].Update();
						}
						else
						{
							bullet[i][j].Update1();
						}
					}

					//moves bullets and draws them
				}
			}
		}
		if (outOfBounds) {
			fired[i] = false; //not fired, stop updating from now on
			for (int a = 0; a < n; a++) {
				bullet[i][a].x = centerX;
				bullet[i][a].y = centerY;
			}
		}
	}
}
