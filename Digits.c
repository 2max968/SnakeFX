#include "Digits.h"
#include "fxlib.h"

uchar digitNULL[] = 
{
    1, 1, 1, 1,
    1, 0, 0, 1,
    1, 0, 0, 1,
    1, 1, 1, 1
};

uchar iconTarget[] = 
{
    0, 1, 1, 0,
    1, 0, 0, 1,
    1, 0, 0, 1,
    0, 1, 1, 0
};

uchar snakeHead[] = 
{
    0, 1, 1, 0,
    1, 1, 1, 1,
    1, 1, 1, 1,
    0, 1, 1, 0
};

uchar snakeBody[] = 
{
    1, 0, 0, 1,
    0, 1, 1, 0,
    0, 1, 1, 0,
    1, 0, 0, 1
};

uchar *GetDigit(int ind)
{
    switch(ind)
    {
        case ICON_TARGET: return iconTarget;
        case ICON_SNAKE_HEAD: return snakeHead;
        case ICON_SNAKE_BODY: return snakeBody;
    }
    return digitNULL;
}

void DrawDigit(int x, int y, uchar *digit)
{
    int i, _x, _y;
    for(i = 0; i < 16; i++)
    {
        _x = x + i % 4;
        _y = y + i / 4;
        if(digit[i])
            Bdisp_SetPoint_DDVRAM(_x, _y, 1);
    }
}