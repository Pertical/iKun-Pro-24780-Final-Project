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
#include "StartMenu.h"



#include "yspng.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <chrono>


int main(void)
{
    srand(time(NULL));

    YsSoundPlayer player;
    YsSoundPlayer::SoundData background;
    char fName[256];



    if (YSOK != background.LoadWav("Music/background.wav"))
    {
        printf("Failed to read %s\n", fName);
        return 1;
    }


    player.Start();
    int windowX = 800;
    int windowY = 600;
    FsOpenWindow(0, 0, windowX, windowY, 1);
    
    YsRawPngDecoder png1;
    YsRawPngDecoder png2;
    YsRawPngDecoder png3;

    png1.Decode("Background/level1.png");
    png1.Flip();

    png2.Decode("Background/level2.png");
    png2.Flip();

    png3.Decode("Background/level3.png");
    png3.Flip();


    time_t start = time(0);
    time_t startTime = time(NULL);
    
    int health = 3;
    int state =0;


    Enemy ey;
    Player pl;
    GameMenu gm;

    ey.Initialize_level1();

    double x = 100, y = 450; //player location
    ey.en_x = 700;
    ey.en_y = 100;
    
    double targetxi= 0, targetyi = 0, targetsizex = 3.5, targetsizey = 3.5; //bullet coll info 
    int n = 25; //bullet num 
    
    BulletPattern bp(ey.en_x, ey.en_y, windowX, windowY);
    bp.Initialize(n, 5.0, 3.0, 1, 0, startTime);

    int patternNum = bp.ReturnPatternNum();

    int k = 0;

    for (;;)
    {
     
        int w, h;
        FsGetWindowSize(w, h);
        
        auto ms = FsPassedTime();
        double dt = (double)ms / 1000.0;
        time_t timeGone = difftime(time(0), start);
        std::cout << timeGone;


        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        FsPollDevice();
        glRasterPos2i(0, h - 1);
        

        auto key = FsInkey();
        if (FSKEY_ESC == key)
        {
            break;
        }
        
        if (state == 0)
        {
            gm.Draw();
            gm.DrawTextOne();

            if (FSKEY_1 == key)
            {
                state = 1;
                time_t timeGone = difftime(time(0), start);
                player.PlayOneShot(background);

            }
            if (FSKEY_2 == key)
            {
                state = 2;
                time_t timeGone = difftime(time(0) + 60, start);
                player.PlayOneShot(background);

            }
            if (FSKEY_3 == key)
            {
                state = 3;
                time_t timeGone = difftime(time(0) + 120, start);
                player.PlayOneShot(background);
            }

        }


        if (timeGone >= 60)
        {
            state = 2;
        }
        if (timeGone >= 120)
        {
            state = 3;
        }
        if (timeGone >= 180)
        {
            state = 4;
        }

        for (int i = 0; i < patternNum; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bp.centerX = ey.en_x;
                bp.centerY = ey.en_y;
                targetxi = bp.bullet[i][j].x;
                targetyi = bp.bullet[i][j].y;
                //printf("targetx: %f", bp.bullet[i][j].y);

                if (true == pl.CheckCollision(x, y, targetxi, targetyi, targetsizex, targetsizey)) { // TO BE FIXED
                    k++;
                    printf("hit");
                }

                if (k == 10) {
                    health = health - 1;
                    k = 0;
                }

            }
        }

        
        if (state == 1)
        {
            glDrawPixels(png1.wid, png1.hei, GL_RGBA, GL_UNSIGNED_BYTE, png1.rgba);
            
            int move = rand() % 4;
            if (move == 0)
            {
                ey.en_x += ey.vx;
            }
            if (move == 1)
            {
                ey.en_x -= ey.vx;
            }
            if (move == 2)
            {
                ey.en_y += ey.vy;
            }
            if (move == 3)
            {
                ey.en_y -= ey.vy;
            }
            if (ey.en_x < 30 || 740 < ey.en_x)
            {
                ey.vx = -ey.vx;
            };
            if (ey.en_y < 50 || 540 < ey.en_y)
            {
                ey.vy = -ey.vy;
            };
            ey.Draw_level1();
            bp.DrawPattern(0);
            pl.Move(key, x, y);
            pl.drawPlayer(x, y);
            pl.DrawHealthbar(50, 50, health);

        }

        if (state ==2)
        {
            glDrawPixels(png2.wid, png2.hei, GL_RGBA, GL_UNSIGNED_BYTE, png2.rgba);
            ey.en_x = ey.en_x + ey.vx;

            if (ey.en_x <= 30 || 740 <= ey.en_x)
            {
                ey.vx = -ey.vx;
            }
            ey.Draw_level2();
            bp.DrawPattern(1);//Pattern 0 = wave, 1= spiral, 2=combined
            pl.Move(key, x, y);
            pl.drawPlayer(x, y);
            pl.DrawHealthbar(50, 50, health);

        }
        if (state == 3)
        {

            glDrawPixels(png3.wid, png3.hei, GL_RGBA, GL_UNSIGNED_BYTE, png3.rgba);
            ey.en_x = ey.en_x + ey.vx;
            ey.en_y = ey.en_y + ey.vy;
     
            if (ey.en_x < 30 || 740 < ey.en_x)
            {
                ey.vx = -ey.vx;
            };
            if (ey.en_y < 50 || 540 < ey.en_y)
            {
                ey.vy = -ey.vy;
            };
            ey.Draw_level3();
            bp.DrawPattern(2);//Pattern 0 = wave, 1= spiral, 2=combined
            pl.Move(key, x, y);
            pl.drawPlayer(x, y);
            pl.DrawHealthbar(50, 50, health);

        }
        if (state == 4)
        {
            gm.Draw();
            gm.DrawWin();
            player.End();
        }

        if (health <= 0)
        {
            state = 5;
        }

        if (state == 5 || health <= 0)
        {
            gm.Draw();
            gm.DrawDead();
            player.End();

    
        }
        
        glFlush();
        FsSwapBuffers();
        FsSleep(10);

    }
    player.End();
    return 0;
}
