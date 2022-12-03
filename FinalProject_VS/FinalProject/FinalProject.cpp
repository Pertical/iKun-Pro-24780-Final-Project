//
//  Final Project.cpp
//  Final Project
//
//  Created by Peter Zhu on 11/29/22.
//

#define GL_SILENCE_DEPRECATION

#include "ysglfontdata.h"
#include "yssimplesound.h"
#include "Bullet.h"
#include "BulletPattern.h"
#include "enemy.h"
#include "Player.h"
//#include "StartMenu.h"



#include "yspng.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <chrono>


class soundtrack
{
public:
    YsSoundPlayer player;
    YsSoundPlayer::SoundData background;
    soundtrack();
};

soundtrack::soundtrack()
{
    player.MakeCurrent();
    player.Start();
    if (YSOK != background.LoadWav("S"))
    {
        printf("Error!  Cannot load !\n");
    }
}


int main(void)
{
    time_t start = time(0);



    
    //std::cout << timeGone;

    YsRawPngDecoder png;


    srand(time(NULL));
    time_t startTime = time(NULL);
    int windowX = 800;
    int windowY = 600;
    FsOpenWindow(0, 0, windowX, windowY, 1);

    Enemy ey;
    Player pl;
    ey.Initialize_level1();


    double x = 100, y = 450;
    int health = 3;
    double targetxi= 0, targetyi = 0, targetsizex = 3.5, targetsizey = 3.5;
    ey.x = 700;
    ey.y = 100;

    //int x = 200, y = 200;

    /*for (auto& ey : enemy)
    {
        if (timeGone <= 60)
        {
            ey.Initialize_level1();
        }
        if (timeGone > 60 && timeGone < 120)
        {
            ey.Initialize_level2();
        }
        if (timeGone > 120)
        {
            ey.Initialize_level3();
        }

    }*/

    int n = 30;

    BulletPattern bp(ey.x, ey.y, windowX, windowY);


    bp.Initialize(n, 5.0, 3.0, 1, 0, startTime);

    png.Decode("Background/level1.png");
    png.Flip();

    if (0 == png.wid || 0 == png.hei)
    {
        printf("Failed to load image.\n");
        return 1;
    }
    int patternNum = bp.ReturnPatternNum();

    int k = 0;

    for (;;)
    {
        auto ms = FsPassedTime();
        double dt = (double)ms / 1000.0;

        time_t timeGone = difftime(time(0)+55, start);
        std::cout << timeGone;
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        FsPollDevice();
        auto key = FsInkey();

        if (FSKEY_ESC == key)
        {
            break;
        }


        bp.centerX = ey.x;
        bp.centerY = ey.y;

        int w, h;

        FsGetWindowSize(w, h);

        glRasterPos2i(0, h - 1);

        glDrawPixels(png.wid, png.hei, GL_RGBA, GL_UNSIGNED_BYTE, png.rgba);

        bp.DrawPattern(2);//Pattern 0 = wave, 1= spiral, 2=combined

        /*ey.Draw_level1();
        ey.Draw_level2();
        ey.Draw_level3();*/


        if (0 != ey.state)
        {
            // printf(timeGone);
            if (timeGone <= 60)
            {

                int move = rand() % 4;
                if (move == 0)
                {
                    ey.x += ey.vx;
                }
                if (move == 1)
                {
                    ey.x -= ey.vx;
                }
                if (move == 2)
                {
                    ey.y += ey.vy;
                }
                if (move == 3)
                {
                    ey.y -= ey.vy;
                }
                if (ey.x < 30 || 740 < ey.x)
                {
                    ey.vx = -ey.vx;
                };
                if (ey.y < 50 || 540 < ey.y)
                {
                    ey.vy = -ey.vy;
                };
                ey.Draw_level1();

            }
            if (timeGone > 60 && timeGone < 120)
            {
                ey.Initialize_level2();
                ey.Move_x();
                //ey.x += ey.vx;

                /*int move = rand() % 4;
                if (move == 0)
                {
                    ey.x += ey.vx;
                }
                if (move == 1)
                {
                    ey.x -= ey.vx;
                }
                if (move == 2)
                {
                    ey.y += ey.vy;
                }
                if (move == 3)
                {
                    ey.y -= ey.vy;
                }
                if (ey.x < 30 || 740 < ey.x)
                {
                    ey.vx = -ey.vx;
                };
                if (ey.y < 50 || 540 < ey.y)
                {
                    ey.vy = -ey.vy;
                };

                if (ey.x < 30 || 740 < ey.x)
                {
                    ey.vx = -ey.vx;
                }*/

                ey.Draw_level2();
            }
            if (timeGone > 120)
            {
                ey.Initialize_level3();
                //ey.Move_x();
                //ey.Move_y();
                ey.x += ey.vx;
                ey.y += ey.vy;
                if (ey.x < 30 || 740 < ey.x)
                {
                    ey.vx = -ey.vx;
                };
                if (ey.y < 50 || 540 < ey.y)
                {
                    ey.vy = -ey.vy;
                };
                ey.Draw_level3();
            }

        }

            
        
        pl.Move(key, x, y);
        pl.drawPlayer(x, y);
        pl.DrawHealthbar(50, 50, health);

        for (int i = 0; i < patternNum; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bp.bullet[i][j].centerX = ey.x;
                bp.bullet[i][j].centerY = ey.y;
                targetxi = bp.bullet[i][j].x;
                targetyi = bp.bullet[i][j].y;
                //printf("targetx: %f", bp.bullet[i][j].y);

                if (true == pl.CheckCollision(x, y, targetxi, targetyi, targetsizex, targetsizey)) { // TO BE FIXED
                    k++;
                    printf("hit");
                }

                if (k > 0) {
                    health = health - 1;
                    k = 0;
                }

            }
        }



        /*pl.Healthbar(50, 50, 1);
        pl.Healthbar(80, 50, 1);
        pl.Healthbar(110, 50, 1);*/

        //Add test cases here

        FsSwapBuffers();
        FsSleep(10);

    }
    return 0;
}
