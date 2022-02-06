#include <stdio.h>

// #include "Premier.c"

/*** Sorting teams **/
void sort(ug_premeir *ug_premier_sort){
    //sort using points

    size_t i, j;
    for (i = 0; i < 16; i++){
        /* code here */
        for (j = 0; j < (16 - i - 1); j++) {
            /* code here */
            if (ug_premier_sort[j].points > ug_premier_sort[j+ 1].points){
                /* code here */
                temp_hold = ug_premier_sort[j+1];
                ug_premier_sort[j+1] = ug_premier_sort[j];
                ug_premier_sort[j] = temp_hold;
            }
        }
    }
//  printing the sorted array                                       --------
puts("------------------Sorted Team Data using Bubble sort-------------");
    printf("| %-30s %-5s %-6s %-5s %-5s %-5s %-30c\n", "*Football-Club*", "Plyd", "Won", "Draw", "GD", "Pts",'|');

    for (int i = 0; i < 16; i++){
        printf("| %-30s %-5d %-5d %-5d %-5d %-5d  %-30c\n",
               ug_premier_sort[i].football_club,
               ug_premier_sort[i].played, ug_premier_sort[i].won,
               ug_premier_sort[i].drawn, ug_premier_sort[i].diff,
               ug_premier_sort[i].points,'|');
    }
puts("-----------------------------------------------------------------");
/// printing the relegated teams
    printf("\n-------------------------------The Related teams----------------\n");
    printf("| %-30s %-5s %-5s %-5s %-5s %-5s %-30c\n", "FootBall Club", "Plyd", "Won", "Draw", "GD", "Pts",'|');

    for (int i = 14; i < 17; i++){
        printf("| %-30s %-5d %-5d %-5d %-5d %-5d %-30c\n", ug_premier_sort[i].football_club,
               ug_premier_sort[i].played, ug_premier_sort[i].won,
               ug_premier_sort[i].drawn, ug_premier_sort[i].diff,
               ug_premier_sort[i].points ,'|');
    }
    puts("----------------------------------------------------------------");
}