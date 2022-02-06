#include <stdio.h>

#include "Premier.c"

/*** Sorting teams **/
void sort(ug_premeir *ug_premier_sort){
    //sort using points

    int i, j;
    for (i = 0; i < 16; i++){
        /* code here */
        for (j = i + 1; j < 16; j++) {
            /* code here */
            if (ug_premier_sort[j].points < ug_premier_sort[j- 1].points){
                /* code here */
                temp_hold = ug_premier_sort[j-1];
                ug_premier_sort[j-1] = ug_premier_sort[j];
                ug_premier_sort[j] = temp_hold;
            }
        }
    }

    printf("\n%-30s %-5s %-5s %-5s %-5s %-5s\n", "TeamName", "MP", "W", "D", "GD", "Pts");

    for (int i = 16; i > 0; i--){
        printf("\n%-30s %-5d %-5d %-5d %-5d %-5d \n", ug_premier_sort[i].football_club,
               ug_premier_sort[i].played, ug_premier_sort[i].won,
               ug_premier_sort[i].drawn, ug_premier_sort[i].diff,
               ug_premier_sort[i].points);
    }

    printf("\n\n|-----> The Related teams are:\n");
    printf("\n%-30s %-5s %-5s %-5s %-5s %-5s\n", "TeamName", "MP", "W", "D", "GD", "Pts");

    for (int i = 2; i >= 0; i--){
        printf("\n%-30s %-5d %-5d %-5d %-5d %-5d \n", ug_premier_sort[i].football_club,
               ug_premier_sort[i].played, ug_premier_sort[i].won,
               ug_premier_sort[i].drawn, ug_premier_sort[i].diff,
               ug_premier_sort[i].points);
    }
}