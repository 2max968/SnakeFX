#ifndef MAPS_H_
#define MAPS_H_

#include "SNAKE.h"

unsigned int *GetMap(int index);
int GetMapCount();
uchar GetBlock(int x, int y, unsigned int *map);
void DrawMap(int x, int y, unsigned int *map);
int MapSelector();
char* GetMapName(int index);

#endif