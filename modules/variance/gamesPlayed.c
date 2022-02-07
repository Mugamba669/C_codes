#include<stdio.h>

float computeVariancePlayed(int numsize ,ug_premeir *played_var, float average){
    int x, squareX, totalSquareX = 0;
    float variance;

    for (int i = 0; i < numsize; i++){
        x = played_var[i].drawn;
        squareX = x * x;
        totalSquareX += squareX;
    }
    float meanSq = (float)totalSquareX / 16.0;

    variance = (meanSq) - (average * average);
    return variance;
}