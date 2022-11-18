#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fssimplewindow.h"


class Bullet_Wave
{
public:
    int cx, cy;
    double bx, by, r, v;
    double vx, vy;
    double duration;
    double direction =0, angle =0 ;
    const double Pi = 3.1415927;
	void Initialize(void);
    void Move(double dx, double dy);
    void Draw_Bullet(void);
};


void Bullet_Wave::Draw_Bullet(void)
{
    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 64; ++i)
    {
        double a = Pi * (double)i / 32;
        double dx = cos(a) * r;
        double dy = sin(a) * r;

        glVertex2d(cx + dx, cy + dy);
        
    }
    glEnd();
}



void Bullet_Wave::Initialize(void)
{
    duration = 1000; // millisecond
	cx = 200;// center of the enemy
    cy = 300;// center of the enemy
    r = 2.5; // radius of the bullet
    v = 5; // velocity of the bullet
}


void Bullet_Wave::Move(double dx, double dy)
{
    cx += dx;
    cy += dy;

    /*if (cx <= 0 || cx >= 800 || cy <= 0 || cy >= 600)
    {
        cx = 200;
        cy = 300;
    }*/
}


void Draw_enemy(double cx, double cy)
{
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(cx + 5, cy + 5);
    glVertex2i(cx + 5, cy - 5);
    glVertex2i(cx - 5, cy - 5);
    glVertex2i(cx - 5, cy + 5);
    glEnd();
}


int main()
{
    int state = 1, duration =3;
    int x = 200, y = 300;
    const int nBullet = 8;
    int dir = 0;
    double dirx, diry;
    const double Pi = 3.1415927;
	Bullet_Wave bullet[nBullet];
    


    for (auto& b : bullet)
    {

        b.Initialize();
    }

    for (int i = 0; i < nBullet; i++)
    {
        bullet[i].angle += i * 45;

        bullet[i].direction = bullet[i].angle / 180 * bullet[i].Pi;

        //printf("%f\n", bullet[i].angle);
        //printf("%f\n\n", bullet[i].direction);  //rads
    }

    for (int j = 0; j < nBullet; j++)
    {
        bullet[j].vx = bullet[j].v * cos(bullet[j].direction);
        bullet[j].vy = bullet[j].v * sin(bullet[j].direction);

        //printf("%f\n", bullet[j].vx);
        //printf("%f\n", bullet[j].vy);
    }

    //printf("%f\n", bullet[2].vx);
    //printf("%f\n", bullet[2].dy);
	
	FsOpenWindow(16, 16, 800, 600, 1);

    FsPollDevice();

    for (;;)
    {
        FsPollDevice();
        auto key = FsInkey();

        if (FSKEY_ESC == key)
        {
            break;
        }


        for (int k = 0; k < nBullet; k++)
        {
            //printf("%f\n", bullet[2].vx);
            bullet[k].Move(bullet[k].vx, bullet[k].vy);
        }




        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        Draw_enemy(x, y);




        for (int d = 0; d < nBullet; d++)
        {
            bullet[d].Draw_Bullet();
            if (d == 2) {
                //printf("%f\n", bullet[d].cx);
                //printf("%f\n", bullet[d].vx);
            }
        }


        FsSwapBuffers();
        FsSleep(25);
    }


	return 0;
}