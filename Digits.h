#ifndef DIGITS_H_
#define DIGITS_H_

#include "SNAKE.h"

#define ICON_TARGET 1
#define ICON_SNAKE_HEAD 2
#define ICON_SNAKE_BODY 3

uchar *GetDigit(int ind);
void DrawDigit(int x, int y, uchar *digit);

#endif