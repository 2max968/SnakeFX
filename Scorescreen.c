#include "Scorescreen.h"
#include "fxlib.h"
#include "SNAKE.h"
#include <stdio.h>
#include "Maps.h"

void _printDifficulty(int diff)
{
    switch(diff)
    {
        case 0: Print((uchar*)"Easy"); break;
        case 1: Print((uchar*)"Middle"); break;
        case 2: Print((uchar*)"Hard"); break;
        case 3: Print((uchar*)"Extreme"); break;
    }
}

void ShowScores(const savegame_t *scores)
{
    int diff = 0;
    unsigned int key;
    int i;
    char text[22];

    while(1)
    {
        Bdisp_AllClr_DDVRAM();
        locate(1,1);
        _printDifficulty(diff);

        for(i = 0; i < 4; i++)
        {
            sprintf(text, "%s", GetMapName(i));
            locate(1,i+3);
            Print((uchar*)text);
            if(scores->scores[diff].scores[i].val > 0)
                sprintf(text, ":     %i", scores->scores[diff].scores[i].val);
            else
                sprintf(text, ":     -");
            locate(12,i+3);
            Print((uchar*)text);
        }

        GetKey(&key);
        switch(key)
        {
            case KEY_CTRL_EXIT:
                return;
            case KEY_CTRL_LEFT:
                diff--;
                if(diff < 0) diff = 3;
                break;
            case KEY_CTRL_RIGHT:
                diff++;
                if(diff > 3) diff = 0;
                break;
        }
    }
}