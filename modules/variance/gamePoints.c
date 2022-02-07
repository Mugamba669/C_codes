#include<stdio.h>

float computeVariancePoints(int numsize ,ug_premeir *points_var, float average){
    int x, squareX, totalSquareX = 0;
    float variance;

    for (int i = 0; i < numsize; i++){
        x = points_var[i].drawn;
        squareX = x * x;
        totalSquareX += squareX;
    }
    float meanSq = (float)totalSquareX / 16.0;

    variance = (meanSq) - (average * average);
    return variance;
}