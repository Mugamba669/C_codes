#include <stdio.h>
// #include "Premier.c"


/**Computing median for  games drawn***/
float computeMedianForDrawn(ug_premeir *drawn_median ,int drawn_array){
       int i, j;
        for (i = 0; i < drawn_array - 1; i++) {
            /* code here */
            for (j = i + 1; j < drawn_array; j++) {
                /* code here */
                if (drawn_median[j].drawn < drawn_median[j-1].drawn)
                {
                    /* code here */
                    int temp = drawn_median[j-1].drawn;
                    //printf("%d\n", temp);
                    drawn_median[j-1].drawn = drawn_median[j].drawn;
                    drawn_median[j].drawn = temp;
                }
            }
        }


        if (drawn_array % 2 == 0){
            return (drawn_median[(drawn_array / 2) - 1].drawn + drawn_median[(drawn_array / 2)].drawn) / 2;
        } else {
            /* code here */
            return drawn_median[(drawn_array / 2)].drawn;
        }
}
