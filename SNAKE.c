/*****************************************************************/
/*                                                               */
/*   CASIO fx-9860G SDK Library                                  */
/*                                                               */
/*   File name : [ProjectName].c                                 */
/*                                                               */
/*   Copyright (c) 2006 CASIO COMPUTER CO., LTD.                 */
/*                                                               */
/*****************************************************************/
#include "fxlib.h"
#include "timer.h"
#include "SNAKE.h"
#include <stdio.h>
#include "Menu.h"
#include "Game.h"
#include "Maps.h"
#include "MainMenuDetector.h"

#define STATE_MAINMENU 1
#define STATE_DIFFSELECT 2
#define STATE_MAPSELECT 3
#define STATE_GAME 4
#define STATE_GAMEOVERSCREEN 5
#define STATE_HELP 6
#define STATE_ABOUT 7

const char *txtHelp = "[\xE3,8] Move up\n[DOWN, 2] Move down\n[\xE4, 4] Move left\n[RIGHT, 6] Move right\n[EXIT] Game Menu";
const char *txtAbout = "Snake for\nCasio fx-9860GII\n\nby Max Haag";

//****************************************************************************
//  AddIn_main (Sample program main function)
//
//  param   :   isAppli   : 1 = This application is launched by MAIN MENU.
//                        : 0 = This application is launched by a strip in eACT application.
//
//              OptionNum : Strip number (0~3)
//                         (This parameter is only used when isAppli parameter is 0.)
//
//  retval  :   1 = No error / 0 = Error
//
//****************************************************************************
int AddIn_main(int isAppli, unsigned short OptionNum)
{
    unsigned int key;
    int score, exitReason, res, difficulty, map;
    unsigned int state = STATE_MAINMENU;
    char text[30];

    InitDetector();
    Bdisp_AllClr_DDVRAM();

    while(1)
    {
        switch(state)
        {
            case STATE_MAINMENU:
                res = ShowMenu(0, "Start Game\nHelp\nAbout");
                if(res == 0) state = STATE_DIFFSELECT;
                else if(res == 1) state = STATE_HELP;
                else if(res == 2) state = STATE_ABOUT;
                break;
            case STATE_DIFFSELECT:
                difficulty = ShowMenu(1, "Easy\nMiddle\nHard\nExtreme");
                if(difficulty < 0) state = STATE_MAINMENU;
                else state = STATE_MAPSELECT;
                break;
            case STATE_MAPSELECT:
                map = MapSelector();
                if(map < 0) state = STATE_DIFFSELECT;
                else state = STATE_GAME;
                break;
            case STATE_GAME:
                exitReason = RunGame(difficulty, &score, GetMap(map));
                if(exitReason == GAMEND_LOOSE) state = STATE_GAMEOVERSCREEN;
                else state = STATE_MAINMENU;
                break;
            case STATE_GAMEOVERSCREEN:
                //sprintf(text, "\nGAME OVER\nScore: %i", score);
                //ShowText(text);
                state = STATE_MAINMENU;
                break;
            case STATE_HELP:
                ShowText(txtHelp);
                state = STATE_MAINMENU;
                break;
            case STATE_ABOUT:
                ShowText(txtAbout);
                state = STATE_MAINMENU;
                break;
        }
    }

    UninitDetector();
    return 1;
}

char* malloc_sec(int size)
{
    char* ptr = (char*)malloc(size);
    if(ptr == NULL)
    {
        unsigned int key;
        char text[10];
        PopUpWin(2);
        locate(3,3);
        sprintf(text, "Allocating %iBytes", size);
        locate(3,4);
        Print((uchar*)"Out of memory");
        while(1) GetKey(&key);
    }
    return ptr;
}


//****************************************************************************
//**************                                              ****************
//**************                 Notice!                      ****************
//**************                                              ****************
//**************  Please do not change the following source.  ****************
//**************                                              ****************
//****************************************************************************


#pragma section _BR_Size
unsigned long BR_Size;
#pragma section


#pragma section _TOP

//****************************************************************************
//  InitializeSystem
//
//  param   :   isAppli   : 1 = Application / 0 = eActivity
//              OptionNum : Option Number (only eActivity)
//
//  retval  :   1 = No error / 0 = Error
//
//****************************************************************************
int InitializeSystem(int isAppli, unsigned short OptionNum)
{
    return INIT_ADDIN_APPLICATION(isAppli, OptionNum);
}

#pragma section

