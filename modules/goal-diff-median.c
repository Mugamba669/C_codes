#include<stdio.h>
// #include "Premier.c"

float getGoalDifferenceMedian(ug_premeir *differnce_median, int diff_array){
      int i, j;
        for (i = 0; i < diff_array - 1; i++){
            /* code here */
            for (j = 0; j < (diff_array - i -1); j++) {
                /* code here */
                if (differnce_median[j].diff < differnce_median[j+1].diff){
                    /* code here */
                    int temp = differnce_median[j+1].diff;
                   
                    differnce_median[j+1].diff = differnce_median[j].diff;
                    differnce_median[j].diff = temp;
                }
            }
        }
        if (diff_array % 2 == 0)
        {
            return (differnce_median[(diff_array / 2) + 1].diff +
            differnce_median[(diff_array / 2)].diff) /2;
        } else {
            /* code here */
            return differnce_median[(diff_array / 2) +1].diff;
        }
}
