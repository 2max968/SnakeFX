#include "fxlib.h"
#include "SNAKE.h"
#include "timer.h"
#include "Graphics.h"
#include <stdlib.h>
#include <stdio.h>
#include "Game.h"
#include "Menu.h"
#include "Maps.h"
#include "Digits.h"
#include "MainMenuDetector.h"

#define TIMER_ID ID_USER_TIMER2

typedef struct point
{
    char x;
    char y;
} point_t;

point_t snake[FWIDTH*FHEIGHT];
int snakeLength;
char dx = 1, dy = 0;
int difficulties[] = {250, 175, 100, 50};
point_t target = {-1, -1};
uint8_t *titlecapt;
int timeout;
int quitGame;
unsigned int *map;

void _setTarget()
{
    int i;
    uchar blocked = 1;

    while(blocked)
    {
        target.x = (uchar)((uint)rand() % FWIDTH);
        target.y = (uchar)((uint)rand() % FHEIGHT);
        blocked = 0;
        if(GetBlock(target.x, target.y, map)) blocked = 1;
        for(i = 0; i < snakeLength; i++)
            if(snake[i].x == target.x && snake[i].y == target.y)
                blocked = 1;
    }
}

void gameLoop1(void)
{
    int i, x, y;
    uchar *digit;

    if(quitGame != 0) return;

    // Move Body of Snake
    for(i = snakeLength - 1; i > 0; i--)
        snake[i] = snake[i - 1];
    
    // Move head of Snake
    snake[0].x += dx;
    snake[0].y += dy;
    if(snake[0].x < 0) snake[0].x = FWIDTH - 1;
    if(snake[0].x >= FWIDTH) snake[0].x = 0;
    if(snake[0].y < 0) snake[0].y = FHEIGHT - 1;
    if(snake[0].y >= FHEIGHT) snake[0].y = 0;

    // Check if Snake hits target
    if(snake[0].x == target.x && snake[0].y == target.y)
    {
        _setTarget();
        snake[snakeLength] = snake[snakeLength - 1];
        snakeLength++;
    }

    // Check if Snake hits itself
    for(i = 1; i < snakeLength; i++)
    {
        if(snake[0].x == snake[i].x && snake[0].y == snake[i].y)
        {
            quitGame = GAMEND_LOOSE;
        }
    }

    // Check if Snake hits wall
    if(GetBlock(snake[0].x, snake[0].y, map))
    {
        quitGame = GAMEND_LOOSE;
    }

    if(quitGame == GAMEND_LOOSE)
    {
        char text[20];
        PopUpWin(5);
        locate(3,3);
        Print((uchar*)"GAME OVER");
        locate(3,4);
        sprintf(text, "Score: %i", snakeLength - START_LENGTH);
        Print((uchar*)text);
        Bdisp_PutDisp_DD();
        return;
    }

    if(CheckForMenu())
    {
        KillTimer(TIMER_ID);
        return;
    }

    Clear();
    for(x = 0; x < FWIDTH; x++)
    {
        for(y = 0; y < FHEIGHT; y++)
        {
            if(GetBlock(x, y, map))
            {
                FillRect(x * TSIZE, y * TSIZE, TSIZE, TSIZE, 1);
            }
        }
    }
    digit = GetDigit(ICON_SNAKE_HEAD);
    DrawDigit(snake[0].x * TSIZE, snake[0].y * TSIZE, digit);
    digit = GetDigit(ICON_SNAKE_BODY);
    for(i = 1; i < snakeLength; i++)
    {
        //FillRect(snake[i].x * TSIZE + 1, snake[i].y * TSIZE + 1, TSIZE - 1, TSIZE - 1, 1);
        DrawDigit(snake[i].x * TSIZE, snake[i].y * TSIZE, digit);
    }
    if(target.x >= 0 && target.y >= 0)
    {
        //DrawRect(target.x * TSIZE, target.y * TSIZE, TSIZE, TSIZE);
        digit = GetDigit(ICON_TARGET);
        DrawDigit(target.x * TSIZE, target.y * TSIZE, digit);
    }
    Bdisp_PutDisp_DD();
}

void gameLoop2(unsigned int key)
{
    char text[20];
    switch(key)
    {
        case KEY_CTRL_DOWN:
        case KEY_CHAR_2:
            if(dy == -1) break;
            dx = 0; dy = 1; break;
        case KEY_CTRL_RIGHT:
        case KEY_CHAR_6:
            if(dx == -1) break;
            dx = 1; dy = 0; break;
        case KEY_CTRL_UP:
        case KEY_CHAR_8:
            if(dy == 1) break;
            dx = 0; dy = -1; break;
        case KEY_CTRL_LEFT:
        case KEY_CHAR_4:
            if(dx == 1) break;
            dx = -1; dy = 0; break;
        case KEY_CTRL_EXIT:
            KillTimer(TIMER_ID);
            PopUpWin(5);
            sprintf(text, "Score: %i", snakeLength - START_LENGTH);
            locate(3, 6);
            Print((uchar*)text);
            if(ShowMenuNoBorder(1, "Continue\nExit") == 1)
            {
                quitGame = GAMEND_USEREXIT;
            }
            else
            {
                SetTimer(TIMER_ID, timeout, gameLoop1);
            }
            break;
    }
    
}

void gameQuit(void)
{
    KillTimer(TIMER_ID);
}

int RunGame(uchar difficulty, int *score, unsigned int *_map)
{
    char text[20];
    int i;
    unsigned int key;

    //titlecapt = CaptureMenuTitle();
    quitGame = 0;
    dx = 1;
    dy = 0;
    map = _map;

    snakeLength = START_LENGTH;
    for(i = 0; i < snakeLength; i++)
    {
        snake[i].y = FHEIGHT / 2;
        snake[i].x = snakeLength - i;
    }
    target.x = FWIDTH / 2;
    target.y = FHEIGHT / 2;

    timeout = difficulties[difficulty];
    SetTimer(TIMER_ID, timeout, gameLoop1);
    SetQuitHandler(gameQuit);

    while(1)
    {
        GetKey(&key);
        if(quitGame == 0)
        {
            gameLoop2(key);
            if(quitGame == GAMEND_USEREXIT) break;
        }
        else if(quitGame == GAMEND_USEREXIT)
        {
            break;
        }
        else
        {
            if(key == KEY_CTRL_EXIT || key == KEY_CTRL_ALPHA || key == KEY_CTRL_EXE)
                break;
        }
    }

    KillTimer(TIMER_ID);
    free(titlecapt);
    *score = snakeLength - START_LENGTH;
    return quitGame;
}