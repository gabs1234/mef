# include <stdio.h>

void select_points(int nombre_points, int num[], float *coord_set[], 
float *coord_selected[])
{
   for(int k = 0; k < nombre_points; k++)
   {
       coord_selected[k][0] = coord_set[num[k]-1][0];
       coord_selected[k][1] = coord_set[num[k]-1][1];
   }
}
