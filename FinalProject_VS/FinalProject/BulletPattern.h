#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fssimplewindow.h"
#include "Bullet.h"
#include <vector>

class BulletPattern {
private:
	const static int patternNum = 50; //number of bullet vectors (i.e. number of bullet patterns that can be on the screen at once)

public:
	time_t startTime;
	time_t prevTime;
	int n, f; //number of bullets & frequency of fire
	int state;
	int drawType, windowX, windowY;
	double centerX, centerY, r, v;
	std::vector<std::vector<Bullet>> bullet; //array of array of bullets
	bool fired[patternNum]; //used to check which array of arrays is in use/is currently being drawn
	bool following = false;

	BulletPattern();
	BulletPattern(double &x, double &y, int winX, int winY);
	void FollowEnemy(double& posX, double& posY);
	void Initialize(int num, double radius, double velocity, int frequency, int dType, time_t time1);
	void DrawPattern(int patternType);
	void Update(int patternType);
	int ReturnPatternNum();
};

