#pragma once
#ifndef GAMEMENU_IS_INCLUDED
#define GAMEMENU_IS_INCLUDED
/* { */

class GameMenu
{
public:
	void Initialize(void);
	int Run(void);
	int RunOneStep(void);
	void Draw(void);
	void DrawDead(void);
	void DrawWin(void);
};

/* } */
#endif