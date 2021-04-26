#include "headers/tp3.h"
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
  /* Declaration des variables */
  char *file_name;
  int Nb_lignes;
  float *SecMembre;
  int *NumDLDir;
  float *ValDLDir;
  int *AdPrCoefLi;
  float *Matrice;
  int *AdSuccLi;
  int *NumCol;

  /* Lecture du nom de fichier à ouvrir */
  printf("Entrez le nom du fichier à générer\n");
  file_name = "SMD_output";

  /* Lecture du fichier */
  LecSMD(file_name,
    &Nb_lignes,
    &SecMembre,
    &NumDLDir,
    &ValDLDir,
    &AdPrCoefLi,
    &Matrice,
    &AdSuccLi,
    &NumCol);

  /* Impression de la matrice */
  affsmd_(&Nb_lignes,
    AdPrCoefLi,
    NumCol,
    AdSuccLi,
    Matrice,
    SecMembre,
    NumDLDir,
    ValDLDir);
    
  free(SecMembre);
  free(NumDLDir);
  free(ValDLDir);
  free(AdPrCoefLi);
  free(Matrice);
  free(NumCol);
  free(AdSuccLi);
}
