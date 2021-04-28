#include "headers/tp1.h"
#include "headers/tp2.h"
#include "headers/tp3.h"
#include "headers/tp4.h"
#include "headers/forfun.h"
#include <stdio.h>
#include <stdlib.h>


/*
--------------------------------------------------------------------------------
TODO: Lit le fichier de sauvegarde et affiche son contenu
    compilation:
    gcc testLecSMD.c functions/LecSMD.c affsmd.o -lgfortran -o testLec
--------------------------------------------------------------------------------
*/

int main()
{
  // Variables SMO
  int Nb_lignes;
  float *SecMembreO;
  int *AdPrCoLiO;
  float *MatriceO;
  int *NumColO;

  /* Lecture du nom de fichier à ouvrir */
  printf("Entrez le nom du fichier à ouvrir\n");
  char *file_name = get_string(50);

  /* Lecture du fichier */
  LecSMO(file_name,
         &Nb_lignes,
         &SecMembreO,
         &AdPrCoLiO,
         &MatriceO,
         &NumColO);

  /* Impression des matrices */
  int z;
  for(z = 0; z < Nb_lignes; z++){printf("SMO: %d: %f\n",z,SecMembreO[z]);}
  for(z = 0; z < Nb_lignes; z++){printf("ACO: %d: %d\n",z,AdPrCoLiO[z]);}
  int Nb_coef = AdPrCoLiO[Nb_lignes-1]-1;
  printf("Le nombre de coefficients est : %d\n",Nb_coef);
  for(z = 0; z < Nb_lignes+Nb_coef; z++){printf("MAO: %d: %f\n",z,MatriceO[z]);}
  for(z = 0; z < Nb_coef; z++){printf("NCO: %d: %d\n",z,NumColO[z]);}
}
