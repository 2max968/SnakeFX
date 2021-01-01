#include "Savegame.h"
#include "fxlib.h"
#include "filebios.h"
#include "Menu.h"
#include <stdio.h>

FONTCHARACTER filename[] = {'\\','\\','f','l','s','0','\\', 's', 'n', 'a', 'k', 'e', '.', 'd', 'a', 't', 0};

void SaveScores(const savegame_t *savegame)
{
    int fileHandle, error;
    fileHandle = Bfile_CreateFile(filename, sizeof(savegame_t));

    if(fileHandle >= 0)
    {
    	Bfile_CloseFile(fileHandle);
    }

    fileHandle = Bfile_OpenFile(filename, _OPENMODE_WRITE);

    if(fileHandle < 0)
    {
        char text[50];
        sprintf(text, "Error saving scores\n0pen File: %i", fileHandle);
        ShowText(text);
        return;
    }

    error = Bfile_WriteFile(fileHandle, savegame, sizeof(savegame_t));

    if(error < 0)
    {
        char text[50];
        sprintf(text, "Error saving scores\nWriting File File: %i", error);
        ShowText(text);
        return;
    }

    Bfile_CloseFile(fileHandle);
}

void LoadScores(savegame_t *savegame)
{
    int fileHandle, fileSize;
    fileHandle = Bfile_OpenFile(filename, _OPENMODE_READ);
    if(fileHandle < 0) return;

    fileSize = Bfile_GetFileSize(fileHandle);
    if(fileSize != sizeof(savegame_t))
    {
        ShowText("The savegame is\ncorrupted.");
        Bfile_CloseFile(fileHandle);
        return;
    }

    Bfile_ReadFile(fileHandle, savegame, sizeof(savegame_t), 0);
    Bfile_CloseFile(fileHandle);
}