#include <stdio.h>

typedef struct UGPremeir{
    char *football_club;
    int played;
    int won;
    int drawn;
    int diff;
    int points;
    //int lost;
} ug_premeir;

ug_premeir ug_premier_league[16];
ug_premeir temp_hold;