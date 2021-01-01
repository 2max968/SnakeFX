#ifndef SAVEGAME_H_
#define SAVEGAME_H_

#include "Savegame.h"

typedef struct score
{
    int val;
    char name[5];
} score_t;

typedef struct difficultyCollection
{
    score_t scores[4]; //Number of Maps
} difficultyCollection_t;

typedef struct savegame
{
    difficultyCollection_t scores[4]; // Number of difficulties
} savegame_t;

void SaveScores(const savegame_t *savegame);
void LoadScores(savegame_t *savegame);

#endif