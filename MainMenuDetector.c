#include "MainMenuDetector.h"
#include "fxlib.h"
#include "SNAKE.h"
#include <stdlib.h>

uchar *m;

void InitDetector()
{
    int i, x, y;
    m = (uchar*)malloc_sec(6*8);
    Bdisp_AllClr_VRAM();
    PrintXY(0, 0, (uchar*)"M", 0);
    for(i = 0; i < 8*6; i++)
    {
        x = i % 6;
        y = i / 6;
        m[i] = Bdisp_GetPoint_VRAM(x, y);
    }
}

void UninitDetector()
{
    free(m);
}

uchar CheckForMenu()
{
    int i, x, y, offs;

    offs = 6*6+1;
    for(i = 0; i < 6*8; i++)
    {
        x = offs + i % 6;
        y = i / 6;
        if(m[i] != Bdisp_GetPoint_VRAM(x, y)) return 0;
    }
    return 1;
}