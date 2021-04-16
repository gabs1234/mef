/* Initialise une matrice dynamique de 'nb_rows' lignes et 'nb_col' colonnes */


#include <stdio.h>
#include <stdlib.h>


void init_mat_int(int nb_rows, int nb_col, int ***array)
{
   *array = malloc(nb_rows*sizeof(int*));
   for(int k=0; k<nb_rows; k++){(*array)[k] = malloc(nb_col*sizeof(int));}
}

void init_mat_float(int nb_rows, int nb_col, float ***array)
{
   *array = malloc(nb_rows*sizeof(float*));
   for(int k=0; k<nb_rows; k++){(*array)[k] = malloc(nb_col*sizeof(float));}
}
