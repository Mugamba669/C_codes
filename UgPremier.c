#include <stdio.h>
#include <math.h>
//global structure

typedef struct UGPremeir{
    char *football_club;
    int played;
    int won;
    int drawn;
    int diff;
    int points;
    //int lost;
} ug_premeir;
//structure type
ug_premeir ug_premier_league[16];
ug_premeir temp_hold;
//
float median(ug_premeir *variable_median_structure, int size, int num){
    if (num == 1){

        //for games played
        int i, j;
        for (i = 0; i < size - 1; i++){
            /* code here */
            for (j = i + 1; j < size; j++){
                /* code here */
                if (variable_median_structure[j].played < variable_median_structure[j-1].played){
                    /* code here */
                    int temp = variable_median_structure[j - 1].played;
                    //printf("%d\n", temp);
                    variable_median_structure[j-1].played = variable_median_structure[j].played;
                    variable_median_structure[j].played = temp;
                }
            }
        }
        if (size % 2 == 0) {
            return (variable_median_structure[(size / 2) - 1].played + variable_median_structure[(size / 2)].played) / 2;
        } else {
            /* code here */
            return variable_median_structure[(size / 2)].played;
        }
    }else if (num == 2){
        //games won
        int i, j;
        for (i = 0; i < size - 1; i++){
            /* code here */
            for (j = i + 1; j < size; j++){
                /* code here */
                if (variable_median_structure[j].won < variable_median_structure[j-1].won) {
                    /* code here */
                    int temp = variable_median_structure[j-1].won;
                    //printf("%d\n", temp);
                    variable_median_structure[j-1].won = variable_median_structure[j].won;
                    variable_median_structure[j].won = temp;
                }
            }
        }
        if (size % 2 == 0){
            return (variable_median_structure[(size / 2) - 1].won + variable_median_structure[(size / 2)].won) /2;
        } else {
            /* code here */
            return variable_median_structure[(size / 2)].won;
        }

    } else if(num==3){
                //games won
        int i, j;
        for (i = 0; i < size - 1; i++) {
            /* code here */
            for (j = i + 1; j < size; j++) {
                /* code here */
                if (variable_median_structure[j].drawn < variable_median_structure[j-1].drawn)
                {
                    /* code here */
                    int temp = variable_median_structure[j-1].drawn;
                    //printf("%d\n", temp);
                    variable_median_structure[j-1].drawn = variable_median_structure[j].drawn;
                    variable_median_structure[j].drawn = temp;
                }
            }
        }
        if (size % 2 == 0){
            return (variable_median_structure[(size / 2) - 1].drawn +
            variable_median_structure[(size / 2)].drawn) /2;
        } else {
            /* code here */
            return variable_median_structure[(size / 2)].drawn;
        }

    } else if(num ==4){
                //games won
        int i, j;
        for (i = 0; i < size - 1; i++){
            /* code here */
            for (j = i + 1; j < size; j++) {
                /* code here */
                if (variable_median_structure[j].diff < variable_median_structure[j-1].diff){
                    /* code here */
                    int temp = variable_median_structure[j-1].diff;
                   
                    variable_median_structure[j-1].diff = variable_median_structure[j].diff;
                    variable_median_structure[j].diff = temp;
                }
            }
        }
        if (size % 2 == 0)
        {
            return (variable_median_structure[(size / 2) - 1].diff +
            variable_median_structure[(size / 2)].diff) /2;
        } else {
            /* code here */
            return variable_median_structure[(size / 2)].diff;
        }

    } else{
  //games won
        int i, j;
        for (i = 0; i < size - 1; i++)
        {
            /* code here */
            for (j = i + 1; j < size; j++)
            {
                /* code here */
                if (variable_median_structure[j].points < variable_median_structure[j-1].points)
                {
                    /* code here */
                    int temp = variable_median_structure[j-1].points;
                    //printf("%d\n", temp);
                    variable_median_structure[j-1].points = variable_median_structure[j].points;
                    variable_median_structure[j].points = temp;
                }
            }
        }
        if (size % 2 == 0)
        {
            return (variable_median_structure[(size / 2) - 1].points +
            variable_median_structure[(size / 2)].points) /2;
        } else {
            /* code here */
            return variable_median_structure[(size / 2)].points;
        }

    }
}
//sort teams
void sort(ug_premeir *variables_premeier_structure){
    //sort using points

    int i, j;
    for (i = 0; i < 16; i++){
        /* code here */
        for (j = i + 1; j < 16; j++) {
            /* code here */
            if (variables_premeier_structure[j].points < variables_premeier_structure[j- 1].points){
                /* code here */
                temp_hold = variables_premeier_structure[j-1];
                variables_premeier_structure[j-1] = variables_premeier_structure[j];
                variables_premeier_structure[j] = temp_hold;
            }
        }
    }

    printf("\n%-30s %-5s %-5s %-5s %-5s %-5s\n", "TeamName", "MP", "W", "D", "GD", "Pts");

    for (int i = 16; i > 0; i--){
        printf("\n%-30s %-5d %-5d %-5d %-5d %-5d \n", variables_premeier_structure[i].football_club,
               variables_premeier_structure[i].played, variables_premeier_structure[i].won,
               variables_premeier_structure[i].drawn, variables_premeier_structure[i].diff,
               variables_premeier_structure[i].points);
    }

    printf("\n\nThe Related teams are:\n");
    printf("\n%-30s %-5s %-5s %-5s %-5s %-5s\n", "TeamName", "MP", "W", "D", "GD", "Pts");

    for (int i = 2; i >= 0; i--){
        printf("\n%-30s %-5d %-5d %-5d %-5d %-5d \n", variables_premeier_structure[i].football_club,
               variables_premeier_structure[i].played, variables_premeier_structure[i].won,
               variables_premeier_structure[i].drawn, variables_premeier_structure[i].diff,
               variables_premeier_structure[i].points);
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
    float played_average;
    int sum_played = 0;
    int p;
    //loop structure
    for (p = 0; p <= 16; p++){
        sum_played += ug_premier_league[p].played;
    }
    played_average = sum_played/16.0;


    //averag games won
    float won_average;
    int sum_won = 0;
    int w;
    //loop structure
    for (w = 0; w < 16; w++){
        sum_won += ug_premier_league[w].won;
    }
    won_average = sum_won / 16.0;
    

    //average game_drawn

    float drawn_average;
    int sum_drawn = 0;
    int d;
    //loop structure
    for (d = 0; d < 16; d++){
        sum_drawn += ug_premier_league[d].drawn;
    }
    drawn_average = sum_drawn / 16.0;

    //average goal diff
    float diff_average;
    int sum_diff = 0;
    int gd;
    //loop structure
    for (gd = 0; gd < 16; gd++)
    {
        sum_diff += ug_premier_league[gd].diff;
    }
    diff_average = sum_diff / 16.0;
  

    //points average
    //average goal diff
    float points_average;
    int sum_points = 0;
    int pa;
    //loop structure
    for (pa = 0; pa < 16; pa++){
        sum_points += ug_premier_league[pa].points;
    }
    points_average = sum_points / 16.0;

    //  sizes
    int array_size_played = 16;
    int array_size_won = 16;
    int array_size_drawn = 16;
    int array_size_difference = 16;
    int array_size_points = 16;



    //games played
    int x, squareX, totalSquareX = 0;
    float variance, sd;

    for (int i = 0; i < 16; i++)
    {
        x = ug_premier_league[i].played;
        squareX = x * x;
        totalSquareX += squareX;
    }
    double totalAfterDivide = totalSquareX / 16.0;
    variance = (totalAfterDivide) - (played_average * played_average);
   /*****The standard deviation***/
    sd = sqrt(variance);
   

    //won

    int val;
    int m;
    int squareX_won;
    float variance_won;
    float sd__won;
    float total_square_won = 0.0;

    for (m = 0; m <= 16; m++)
    {
        val = ug_premier_league[m].won;
        squareX_won = val * val;
        total_square_won += squareX_won;
    }
    double divide_won = total_square_won / 16.0;
    variance_won = divide_won - (won_average * won_average);
 /****The standard deviation for won ***/
   sd__won = sqrt(variance_won);

    //drawn
    int D, squareX_drawn, totalSquareX_drawn = 0;
    float variance_drawn, sd_drawn;
    for (int _m = 0; _m < 16; _m++)
    {
        D = ug_premier_league[_m].drawn;
        squareX_drawn = D * D;
        totalSquareX_drawn += squareX_drawn;
    }
    double divide_drawn = totalSquareX_drawn / 16.0;
    variance_drawn = divide_drawn - (drawn_average * drawn_average);
 /***The standard deviation for drawn**/
    sd_drawn = sqrt(variance_drawn);
   
    //diff;
    int K, square_diff, totalsquare_diff = 0;
    float variance_diff, sd_diff;
    for (int k = 0; k < 16; k++)
    {
        K = ug_premier_league[k].diff;
        square_diff = K * K;
        totalsquare_diff += square_diff;
    }
    double divide_diff_total_square = totalsquare_diff / 16.0;
    variance_diff = divide_diff_total_square - (diff_average * diff_average);
  /***The standard deviation for diff ***/
    sd_diff = sqrt(variance_diff);

    //points

    int P, square_points, totalsquare_points = 0;
    float variance_points, sd_points;
    for (int p = 0; p < 16; p++) {
        P = ug_premier_league[p].points;
        square_points = P * P;
        totalsquare_points += square_points;
    }


    double divide_points_total_square = totalsquare_points / 16.0;
    variance_points = divide_points_total_square - (points_average * points_average);
    sd_points = sqrt(variance_points);

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

    /*sorting teams by points
     sort(ug_premier_league);*/
    int choice;
 intro_screen:  printf("\n\t*************************Uganda Premier League *******************************\n");
    printf("\n1:DISPLAY AVERAGE ");
    printf("\n2:DISPLAY MEDIAN");
    printf("\n3:DISPLAY STANDARD DEVIATION");
    printf("\n4:DISPLAY COEFFICIENT OF VARIATION");
    printf("\n5:DISPLAY SORTED LIST AND RELEGATED TEAMS\n");

    printf("\nEnter Choice:");

    scanf("%d", &choice);
    switch (choice){
    case 1:
        puts("\n=========AVERAGES================================\n");
        printf("Average for the goal points: %f\n", points_average);
        printf("Average for games played: %f\n", played_average);
        printf("Average for games drawn: %f\n", drawn_average);
        printf("Average for  goal Difference: %f\n", diff_average);
        printf("Average for games won: %f\n", won_average);
        goto intro_screen;

        break;
    case 2:
    puts("\t---------------------MEDIAN---------------------------------");
    printf("The median for games played: %f\n", median(ug_premier_league, array_size_played, 1));
    printf("The median for games won: %f\n", median(ug_premier_league, array_size_won, 2));
    printf("The median for drawn: %f\n", median(ug_premier_league, array_size_drawn, 3));
    printf("The median for goal difference: %f\n", median(ug_premier_league, array_size_difference, 4));
    printf("The median for points: %f\n", median(ug_premier_league, array_size_points, 5));
    puts("---------------------------End of median ------------------------");
goto intro_screen;
        break;
    case 3:
        printf("\t============THE STANDARD DEVIATION==============\n");
        printf("The standard deviation for played is : %f\n", sd);
        printf("The standard deviation for won is : %f\n", sd__won);
        printf("\nThe standard deviation for drawn is : %f\n", sd_drawn);
        printf("\nThe standard deviation for diff is : %f\n", sd_diff);
        printf("\nThe standard deviation for points is : %f\n", sd_points);
    puts("---------------------------End of standard deviation ------------------------");


        goto intro_screen;
        break;
    case 4:
        printf("\n\t============COEFFICIENT OF VARRIATION==============\n");

        printf("coefficient of variation for games played is : %.f\n", coff_played);
        printf("coefficient of variation for games won is : %.f\n", coff_won);
        printf("coefficient of variation for games drawn is :%.f\n", coff_drawn);
        printf("coefficient of variation for goal diff is :  %.f\n", coff_diff);
        printf("coefficient of variation for team points is:  %.f", coff_points);
    puts("---------------------------End of coefficient ------------------------");

        goto intro_screen;
        break;


    case 5:
    /***** Sorting the different teams stored in the UGPremier**/
        sort(ug_premier_league);
      break;

    case 6:
        system("clear");
        goto intro_screen;
    }
}