//
//  Final Project.cpp
//  Final Project
//
//  Created by Peter Zhu on 11/29/22.
//

#include "yssimplesound.h"

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
    
    
    while(1)
    {
        
        
        
        
        
    }
    return 0;
    
    
    
}
