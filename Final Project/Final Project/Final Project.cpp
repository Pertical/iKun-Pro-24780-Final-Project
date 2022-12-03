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

    YsRawPngDecoder png;

    srand(time(NULL));
    time_t startTime = time(NULL);
    int windowX = 800;
    int windowY = 600;
    FsOpenWindow(0, 0, windowX, windowY, 1);

    Enemy ey;
    Player pl;

    int x = 100, y = 450;
    ey.x = 700;
    ey.y = 100;

    BulletPattern bp(ey.x, ey.y, windowX, windowY);

    bp.Initialize(15, 5.0, 3.0, 1, 0, startTime);

    png.Decode("/level1.png");
    png.Flip();

    if(0==png.wid || 0==png.hei)
    {
        printf("Failed to load image.\n");
        return 1;
    }


    for (;;)
    {

        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        FsPollDevice();
        auto key = FsInkey();

        if (FSKEY_ESC == key)
        {
            break;
        }
        
        int w, h;

        FsGetWindowSize(w, h);

        glRasterPos2i(0, h - 1);
        
        
        glDrawPixels(png.wid, png.hei, GL_RGBA, GL_UNSIGNED_BYTE, png.rgba);

        bp.DrawPattern(2);//Pattern 0 = wave, 1= spiral, 2=combined

        ey.Draw_level1();
        ey.Draw_level2();
        ey.Draw_level3();

        pl.Move(key, x, y);
        pl.drawPlayer(x, y);
        pl.Healthbar(50, 50, 1);
        pl.Healthbar(80, 50, 1);
        pl.Healthbar(110, 50, 1);

        //Add test cases here

        FsSwapBuffers();
        FsSleep(25);

    }
    return 0;
}
