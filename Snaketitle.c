#include "Snaketitle.h"
#include "Graphics.h"

void DrawSnakeTitlescreen()
{
	int x, y, i;
	unsigned char* pixels = GetTitlescreen();
	for(i = 0; i < 128*64; i++)
	{
		x = i % 128;
		y = i / 128;
		SetPoint(x, y, pixels[i]);
	}
}

unsigned char titlescreen_size = 8192;

unsigned char titlescreen[] = {
	0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,0,
	0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,
	0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	1,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,
	0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,
	0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
	0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,
	0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,
	1,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,
	0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
	0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,
	1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,
	1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
	0,0,1,0,0,0,1,0,0,0,1,1,0,0,1,0,
	1,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,
	0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0,
	0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,
	1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,
	1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,1,0,0,0,0,1,0,1,0,0,1,1,0,0,0,
	0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,
	1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,
	0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,0,
	1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,
	1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,
	1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,0,0,1,0,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,
	1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,
	0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,
	0,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,
	1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,
	1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,
	1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
	1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,
	1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,1,
	1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
	1,1,0,1,1,0,0,0,1,1,0,0,0,0,0,0,
	1,0,0,1,0,0,0,0,0,0,1,1,0,0,1,1,
	0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,
	1,1,0,1,1,0,0,0,1,1,0,0,0,0,0,1,
	1,0,0,1,1,0,0,0,0,0,1,1,0,1,1,0,
	0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,
	1,1,0,0,1,1,0,0,1,1,0,0,0,0,0,1,
	1,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,
	0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,
	1,1,0,0,1,1,0,0,1,1,0,0,0,0,0,1,
	0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,0,
	0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,
	1,1,0,0,0,1,1,0,1,1,0,0,0,0,1,1,
	0,0,0,0,1,1,0,0,0,0,1,1,0,1,1,0,
	0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,
	1,1,0,0,0,1,1,0,1,1,0,0,0,0,1,1,
	0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,
	0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
	0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,
	1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,
	1,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,
	1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,
	1,1,0,0,0,0,1,1,1,1,0,0,0,1,1,0,
	0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,1,
	1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,
	1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,0,
	0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,
	1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,
	1,1,0,0,0,0,0,1,1,1,0,0,1,1,0,0,
	0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,
	0,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,0,0,0,1,0,0,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,0,0,0,0,0,0,0,1,0,1,0,
	0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,
	0,0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,
	0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,
	0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,
	0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,
	1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,
	0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,
	1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
	0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,
	0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
	0,1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,
	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,1,0,0,0,0,0,0,0,1,0,1,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
	0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,
	0,0,0,0,0,0,1,0,0,1,1,0,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,0,0,0,0,0,1,0,1,0,0,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
	0,0,0,0,0,0,1,0,0,0,1,0,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
	0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	
};

unsigned char *GetTitlescreen()
{
	return titlescreen;
}