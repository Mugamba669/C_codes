#include <stdio.h>
#include <math.h>
#include "modules/Premier.c"
#include "modules/median-drawn.c"
#include "modules/median-played.c"
#include "modules/median-points.c"
#include "modules/median-won-games.c"
#include "modules/goal-diff-median.c"
#include "modules/Sort.c"
#include "modules/variance/drawn.c"
#include "modules/variance/gamePoints.c"
#include "modules/variance/gamesPlayed.c"
#include "modules/variance/gameswon.c"
#include "modules/variance/goalDiff.c"

/** median computations **/

float median(ug_premeir *median_var, int size, int prop){
        switch (prop){
        case 1:
            return computeMedianPlayed(median_var,size); // computes the median for played games
            break;

         case 2:
            return computeWonGames(median_var,size);// computes the median for won goals
            break;
        
        case 3:
            return computeMedianForDrawn(median_var,size);// computes the median for drawn goals
            break;
        case 4:
            return getGoalDifferenceMedian(median_var,size);// computes the median for goal difference
            break;
        case 5:
            return medianPoints(median_var,size);/** Computes median for game points**/
            break;
        }
}
/*******Method to compute the mean*********/

float computeMean(int arr,ug_premeir *mean_values, int m){
    switch (m){
    case 1:
         int sum = 0.0;
            for (int i = 0; i < arr; i++){
            sum = sum + mean_values[i].played;
            }
            return (sum / arr);
        break;
    
    case 2:
         int won = 0.0;
            for (int i = 0; i < arr; i++){
            won = won + mean_values[i].won;
            }
            return (won / arr);
        break;
    case 3:
         int dra = 0;
            for (int i = 0; i < arr; i++){
            dra += mean_values[i].drawn;
            }
            return (dra / arr);
        break;

    case 4:
         int diff = 0;
            for (int i = 0; i < arr; i++){
            diff = diff + mean_values[i].diff;
            }
            // printf("the diff is %d",diff);
            return diff;
        break;
    
    case 5:
         int pts = 0.0;
            for (int i = 0; i < arr; i++){
            pts = pts +mean_values[i].points;
            }
            return (pts / arr);
        break;
    }
}

float computeVariance(int numsize ,ug_premeir *variance, float average ,int iter){
        switch (iter){
        case 1:
        printf("played");
           return computeVariancePlayed(numsize,variance,average);
         break;

         case 2:
           return computeVarianceWon(numsize,variance,average);
         break;

         case 3:
           return computeVarianceDrawn(numsize,variance,average);
         break;

         case 4:
           return computeVarianceDiff(numsize,variance,average);
         break;

         case 5:
           return computeVariancePoints(numsize,variance,average);
         break;
        }
}
int main(void){
    /***Uganda priemer legue teams**/
    char* team[16]  = {"VipersSC","Kcca FC","ScVilla","BusogaUnited","Ura Fc","Onduparaka FC","Bul Fc","Mbarara City","Express FC","Wakiso Giants FC","Kyetume FC","BrightStars FC","Police FC","Maroons FC","Proline","TororoUnited"};
  /***Team points****/
    int points[16] = {54,50,46,42,40,36,36,31,31,30,30,29,25,24,22,22};

    int won_games[16]= {16,15,13,13,10,10,10,9,9,8,9,7,8,6,8,6};

    int drawn_game[16] = {6,5,7,3,10,6,6,4,4,6,3,8,4,6,4,4};

    int play = 25;

    int goals_dif[16]= {23,21,12,8,7,6,2,2,-7,-3,-13,-4,-4,-15,-14,-21};

    for (size_t i = 0; i < 16; i++){
        /* Storing the differents teams in th for uganda premier league */
        ug_premier_league[i].played = play;
        ug_premier_league[i].won = won_games[i];
        ug_premier_league[i].diff = goals_dif[i];
        ug_premier_league[i].football_club = team[i];
        ug_premier_league[i].drawn = drawn_game[i];
        ug_premier_league[i].points = points[i];
    }

    //calc average games drawn
/************Average of games played **********************/
    float played_average = computeMean(16,ug_premier_league,1);
    
    //average games won
    float won_average = computeMean(16,ug_premier_league,2);
printf("The avearage won %f\n",won_average);
    //average game_drawn

    float drawn_average = computeMean(16 ,ug_premier_league,3);

    //average goal diff
    float diff_average = computeMean(16,ug_premier_league,4);

    //points average
    float points_average = computeMean(16,ug_premier_league,5);


/***********************computing the variance of the different data********************/
    // variance and standard deviation for games played
    
    float variance = computeVariance(16 ,ug_premier_league,played_average,1);
    printf("%f\n",variance);
   /*****The standard deviation***/
   float sd = sqrt(variance);
/*---------------------------------*/
  
  
    // variance and standard deviation for  games won
    float variance_won = computeVariance(16,ug_premier_league,won_average,2);
 /****The standard deviation for won ***/
  float sd__won = sqrt(variance_won);

/**************variance and standard deviation for games drwan****/
    float variance_drawn = computeVariance(16,ug_premier_league,drawn_average,3);
 /***The standard deviation for drawn**/
   float sd_drawn = sqrt(variance_drawn);
//-----------------------------------------------

    //variance and standard deviation for goal difference;
    int K, square_diff, totalsquare_diff = 0;
    float variance_diff = computeVariance(16,ug_premier_league,diff_average,4);
  /***The standard deviation for diff ***/
   float sd_diff = sqrt(variance_diff);

    //variance and standard deviation for game points
    float variance_points = computeVariance(16,ug_premier_league,points_average,5);
    // standard deviation
    float sd_points = sqrt(variance_points);
    printf("%f,%f,%f,%f",variance,variance_diff,variance_drawn,variance_points);
// ----------------------------------------------------


    /****Coeficient for games played **/
    float coff_played = (sd / played_average) * 100;


    /***coefficient of variation for games won*/
    float coff_won = (sd__won / won_average) * 100;
 
    /*****coefficient of variation for games drawn***/
    float coff_drawn = (sd_drawn / drawn_average) * 100;

    /********coefficient of variation for goal diff ******/
    float coff_diff = (sd_diff / diff_average) * 100;

    /****coefficient of variation for team points***/
    float coff_points = (sd_points / points_average) * 100;

    int choice;
 intro_screen:  printf("\n\t*************************Uganda Premier League *******************************\n");
    printf("\n1:Display Average");
    printf("\n2:Display Median");
    printf("\n3:Display Standard Devitiation");
    printf("\n4:Display Coefficient Of Variation");
    printf("\n5:Display Sorted List And Related Teams");
    printf("\n6: Clear Screen\n");

    printf("\nEnter Choice:");

    scanf("%d", &choice);
    switch (choice){
    case 1:
        puts("\n=========AVERAGES================================\n");
        printf("Goal points: %f\n", points_average);
        printf("Games played: %f\n", played_average);
        printf("Games drawn: %f\n", drawn_average);
        printf("Goal Difference: %f\n", diff_average);
        printf("Games won: %f\n", won_average);
        goto intro_screen;

        break;
    case 2:
    puts("\t---------------------MEDIAN VALUES---------------------------------");
    printf("Games played: %f\n", median(ug_premier_league, SIZE, 1));
    printf("Games won: %f\n", median(ug_premier_league, SIZE ,2));
    printf("Games drawn: %f\n", median(ug_premier_league, SIZE, 3));
    printf("Goal difference: %f\n", median(ug_premier_league, SIZE, 4));
    printf("Game points: %f\n", median(ug_premier_league, SIZE, 5));
    puts("---------------------------End of median ------------------------");
goto intro_screen;
        break;
    case 3:
        printf("\t============THE STANDARD DEVIATION==============\n");
        printf("Games played is : %f\n", sd);
        printf("Games won is : %f\n", sd__won);
        printf("\nGames drawn is : %f\n", sd_drawn);
        printf("\nGoal difference is : %f\n", sd_diff);
        printf("\nGame points is : %f\n", sd_points);
    puts("---------------------------End of standard deviation ------------------------");


        goto intro_screen;
        break;
    case 4:
        printf("\n\t----------------COEFFICIENT OF VARRIATION--------------------\n");

        printf("Games played is : %.f\n", coff_played);
        printf("Games won is : %.f\n", coff_won);
        printf("Games drawn is : %.f\n", coff_drawn);
        printf("Goal difference is :  %.f\n", coff_diff);
        printf("Geam points is:  %.f", coff_points);
    puts("---------------------------End of coefficient ------------------------");

        goto intro_screen;
        break;


    case 5:
    /***** Sorting the different teams stored in the UGPremier**/
        sort(ug_premier_league);
          goto intro_screen;
      break;

    case 6:
        system("clear");
        goto intro_screen;
    }
}