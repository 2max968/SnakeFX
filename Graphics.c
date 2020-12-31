#include "Graphics.h"
#include "fxlib.h"
#include <string.h>
#include "SNAKE.h"

void DrawRect(int x, int y, int w, int h)
{
    int i;

    for(i = 0; i < w; i++)
    {
        Bdisp_SetPoint_VRAM(x + i, y, 1);
        Bdisp_SetPoint_VRAM(x + i, y + h - 1, 1);
    }
    for(i = 1; i < h - 1; i++)
    {
        Bdisp_SetPoint_VRAM(x, y + i, 1);
        Bdisp_SetPoint_VRAM(x + w - 1, y + i, 1);
    }
}

void SetPoint(int x, int y, uint8_t val)
{
    Bdisp_SetPoint_VRAM(x, y, val);
}

void Clear()
{
    Bdisp_AllClr_DDVRAM();
}

void FillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t val)
{
    uint8_t i,j;
    for(i = 0; i < w; i++)
    {
        for(j = 0; j < h; j++)
        {
            Bdisp_SetPoint_VRAM(x+i,y+j,val);
        }
    }
}

void FillDotted()
{
    int x,y;
    for(x = 0; x < 128; x++)
    {
        for(y = 0; y < 64; y++)
        {
            if((x%2)==(y%2))
                Bdisp_SetPoint_VRAM(x, y, 1);
            else
                Bdisp_SetPoint_VRAM(x, y, 0);
        }
    }
}

#define CMPX (6*6)
#define CMPY (0)
#define CMPW (6*2)/*(6*9)*/
#define CMPH (8)

uint8_t* CaptureAreaVRAM(uint8_t x, uint8_t y, uint8_t w, uint8_t h)
{
    int i;
    uint8_t* result = (uint8_t*)malloc(w * h);
    for(i = 0; i < (w*h); i++)
    {
        uint8_t _x = i % w;
        uint8_t _y = i / w;
        result[i] = Bdisp_GetPoint_VRAM(x + _x, y + _y);
    }
}

uint8_t* CaptureMenuTitle()
{
    Bdisp_AllClr_DDVRAM();
    PrintXY(6*6, 0, (uint8_t*)"     MENU", 0);
    PrintXY(6*6+1, 0, (uint8_t*)"MAIN", 0);
    return CaptureAreaVRAM(CMPX, CMPY, CMPW, CMPH);
}

uint8_t CompareMenuTitle(uint8_t* title)
{
    int i, x, y;

    for(i = 0; i < CMPW*CMPH; i++)
    {
        int val1, val2;
        x = i % CMPW;
        y = i / CMPW;
        val1 = Bdisp_GetPoint_VRAM(CMPX+x,CMPY+y);
        val2 = title[i];
        if(val1 != val2)
            {return 0;}
    }
    return 1;
}