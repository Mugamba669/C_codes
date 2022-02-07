#include <stdio.h>
#define SIZE 16
typedef struct UGPremeir{
    char *football_club;
    int played;
    int won;
    int drawn;
    int diff;
    int points;
    //int lost;
} ug_premeir;

ug_premeir ug_premier_league[SIZE];
ug_premeir temp_hold;