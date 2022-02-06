#include<stdio.h>
#include "Premier.c"

/***compute median for goal points */
float medianPoints(ug_premeir *median_points, int points_array){
     int i, j;
        for (i = 0; i < points_array - 1; i++) {
            /* code here */
            for (j = i + 1; j < points_array; j++)
            {
                /* code here */
                if (median_points[j].points < median_points[j-1].points)
                {
                    /* code here */
                    int temp = median_points[j-1].points;
                    //printf("%d\n", temp);
                    median_points[j-1].points = median_points[j].points;
                    median_points[j].points = temp;
                }
            }
        }
        if (points_array % 2 == 0)
        {
            return (median_points[(points_array / 2) - 1].points +
            median_points[(points_array / 2)].points) /2;
        } else {
            /* code here */
            return median_points[(points_array / 2)].points;
        }

}