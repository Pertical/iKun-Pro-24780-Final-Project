#ifndef ENEMY_H_IS_INCLUDED
#define ENEMY_H_IS_INCLUDED


class Enemy
{
public:
	int state, vx, vy;
	double en_x, en_y;
	void Initialize_level1(void);
	void Initialize_level2(void);
	void Initialize_level3(void);
	void Move_x(void);
	void Move_y(void);
	void Draw_level1(void);
	void Draw_level2(void);
	void Draw_level3(void);
};

#endif