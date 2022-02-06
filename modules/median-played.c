#include<stdio.h>
#include "Premier.c"

float computeMedianPlayed(ug_premeir *median_played,int array){
     //for games played
        int i, j;
        for (i = 0; i < array - 1; i++){
            /* code here */
            for (j = i + 1; j < array; j++){
                /* code here */
                if (median_played[j].played < median_played[j-1].played){
                    /* code here */
                    int temp = median_played[j - 1].played;
                    //printf("%d\n", temp);
                    median_played[j-1].played = median_played[j].played;
                    median_played[j].played = temp;
                }
            }
        }
        if (array % 2 == 0) {
            return (median_var[(array / 2) - 1].played + median_var[(array / 2)].played) / 2;
        } else {
            /* code here */
            return median_var[(array / 2)].played;
        }
}
