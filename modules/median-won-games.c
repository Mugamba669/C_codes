#include "Premier.c"
/***Compute median for Games won *****/
float computeWonGames(ug_premeir *won_median,int won_arr){
         int i, j;
        for (i = 0; i < won_arr - 1; i++){
            /* code here */
            for (j = i + 1; j < won_arr; j++){
                /* code here */
                if (won_median[j].won < won_median[j-1].won) {
                    /* code here */
                    int temp = won_median[j-1].won;
                    //printf("%d\n", temp);
                    won_median[j-1].won = won_median[j].won;
                    won_median[j].won = temp;
                }
            }
        }
        if (won_arr % 2 == 0){
            return (won_median[(won_arr / 2) - 1].won + won_median[(won_arr / 2)].won) /2;
        } else {
            /* code here */
            return won_median[(won_arr / 2)].won;
        }
}
