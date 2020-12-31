#ifndef GAME_H_
#define GAME_H_

#include "SNAKE.h"

#define TSIZE 4
#define FWIDTH (128/TSIZE)
#define FHEIGHT (64/TSIZE)
#define START_LENGTH 4

#define GAMEND_USEREXIT 1
#define GAMEND_LOOSE 2
#define GAMEND_WIN 3

int RunGame(uchar difficulty, int *score, unsigned int *map);

#endif