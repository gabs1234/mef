#include <stdio.h>

void print_mat(int nb_row, int nb_col, void **tab, char data_type)
{
   switch (data_type)
   {
   case 'i':
      {
      int **p = (int**)tab;
      for(int i = 0; i<nb_row; i++)
         {
            printf("%d :",i);
            for(int j = 0; j<nb_col; j++){printf(" %d",p[i][j]);}
            printf("\n");
         }
      break;
      }

   case 'f':
      {
      float **p = (float**)tab;
      for(int i = 0; i<nb_row; i++)
         {
            printf("%d :",i);
            for(int j = 0; j<nb_col; j++){printf(" %f",p[i][j]);}
            printf("\n");
         }
      break;
      }

   case 'd':
      {
      double **p = (double**)tab;
      for(int i = 0; i<nb_row; i++)
         {
            printf("%d :",i);
            for(int j = 0; j<nb_col; j++){printf(" %e",p[i][j]);}
            printf("\n");
         }
      break;
      }

   case 'c':
      {
      char **p = (char**)tab;
      for(int i = 0; i<nb_row; i++)
         {
            printf("%d :",i);
            for(int j = 0; j<nb_col; j++){printf(" %c",p[i][j]);}
            printf("\n");
         }
      break;
      }
   }
}
