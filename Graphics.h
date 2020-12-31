#ifndef GRAPHICS_H_
#define GRAPHICS_H_

typedef unsigned char uint8_t;

void DrawRect(int x, int y, int w, int h);
void SetPoint(int x, int y, uint8_t val);
void Clear();
void FillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t val);
void FillDotted();
uint8_t* CaptureAreaVRAM(uint8_t x, uint8_t y, uint8_t w, uint8_t h);
uint8_t* CaptureMenuTitle();
uint8_t CompareMenuTitle(uint8_t* title);

#endif