#include "Maps.h"
#include "Game.h"
#include "Graphics.h"
#include <stdio.h>
#include "fxlib.h"

int GetMapCount()
{
    // If value changed, value has to be changed in "Savegame.h" too
    return 4;
}

unsigned int map0[32] = {0,};
unsigned int map1[] = {0xFFFF, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 
                    0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0xFFFF};
unsigned int map2[] = {0xF81F, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0, 0, 0, 0, 0, 0, 
                    0, 0, 0, 0, 0, 0, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0xF81F};
unsigned int map3[] = {0xF81F, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x810, 0x810, 0x810, 0x810, 0x810, 0x810, 
                    0x810, 0x810, 0x810, 0x810, 0x810, 0x810, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0x8001, 0xF81F};

unsigned int *GetMap(int index)
{
    switch(index)
    {
        case 0: return map0;
        case 1: return map1;
        case 2: return map2;
        case 3: return map3;
        default: return map0;
    }
}

char* GetMapName(int index)
{
    switch(index)
    {
        case 0: return "Normal";
        case 1: return "Walls";
        case 2: return "Corners";
        case 3: return "Pipes";
        default: return "#Mapname";
    }
}

uchar GetBlock(int x, int y, unsigned int *map)
{
    unsigned int col;
    uchar block;
    
    if(x < 0 || y < 0 || x >= FWIDTH || y >= FHEIGHT) return 1;

    col = map[x];
    block = (col >> y) & 1;
    return block;
}

void DrawMap(int x, int y, unsigned int *map)
{
    int _x, _y;

    DrawRect(x, y, FWIDTH*2+2, FHEIGHT*2+2);
    x++;
    y++;
    for(_x = 0; _x < FWIDTH; _x++)
    {
        for(_y = 0; _y < FHEIGHT; _y++)
        {
            uchar block = GetBlock(_x,_y,map);
            FillRect(x + _x*2, y + _y*2,2,2,block);
        }
    }
}

int MapSelector(const difficultyCollection_t *scores)
{
    int currentMap = 0;
    unsigned int key;
    char text[20];
    int mapCount = GetMapCount();

    while(1)
    {
        Clear();
        locate(1,1);
        sprintf(text, "Map %i/%i", currentMap + 1, mapCount);
        Print((uchar*)text);
        locate(1,2);
        Print((uchar*)GetMapName(currentMap));
        DrawMap(32,16,GetMap(currentMap));

        if(scores != NULL)
        {
            if(scores->scores[currentMap].val > 0)
            {
                sprintf(text, "Highscore: %i", scores->scores[currentMap].val);
                locate(1, 8); Print((uchar*)text);
            }
        }

        GetKey(&key);
        switch(key)
        {
            case KEY_CTRL_EXE:
            case KEY_CTRL_ALPHA:
                return currentMap;
            case KEY_CTRL_EXIT:
                return -1;
            case KEY_CTRL_LEFT:
                currentMap--;
                if(currentMap < 0) currentMap = mapCount - 1;
                break;
            case KEY_CTRL_RIGHT:
                currentMap++;
                if(currentMap >= mapCount) currentMap = 0;
                break;
        }
    }
}