#include<stdio.h>

float computeVarianceDrawn(int numsize ,ug_premeir *drawn_var, float average){
    printf("%f",average);
    int x, squareX, totalSquareX = 0;
    float variance;

    for (int i = 0; i < numsize; i++){
        x = i;
        totalSquareX = totalSquareX +(drawn_var[x].drawn * drawn_var[x].drawn);
    }
    float meanSq = (float)totalSquareX / 16.0;

    variance = (meanSq) - (average * average);
    return variance;
}