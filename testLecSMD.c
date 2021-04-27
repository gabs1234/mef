#include "headers/tp1.h"
#include "headers/tp2.h"
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
  printf("Entrez le nom du fichier à ouvrir\n");
  file_name = get_string(50);

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
  printf("Nombre de lignes : %d\n", Nb_lignes);
  int z;
  for(z = 0; z < Nb_lignes; z++){printf("SM: %d: %f\n",z,SecMembre[z]);}
  for(z = 0; z < Nb_lignes; z++){printf("ND: %d: %d\n",z,NumDLDir[z]);}
  for(z = 0; z < Nb_lignes; z++){printf("VD: %d: %f\n",z,ValDLDir[z]);}
  for(z = 0; z < Nb_lignes; z++){printf("AC: %d: %d\n",z,AdPrCoefLi[z]);}
  int Nb_coefs = AdPrCoefLi[Nb_lignes-1]-1;
  printf("Le nombre de coefficients est : %d\n",Nb_coefs);
  for(z = 0; z < Nb_lignes+Nb_coefs; z++){printf("MA: %d: %f\n",z,Matrice[z]);}
  for(z = 0; z < Nb_lignes; z++){printf("AS: %d: %d\n",z,AdSuccLi[z]);}
  for(z = 0; z < Nb_lignes; z++){printf("NC: %d: %d\n",z,NumCol[z]);}
  
  /* Impression de la matrice */
  /*affsmd_(&Nb_lignes,
    AdPrCoefLi,
    NumCol,
    AdSuccLi,
    Matrice,
    SecMembre,
    NumDLDir,
    ValDLDir);*/

  free(SecMembre);
  free(NumDLDir);
  free(ValDLDir);
  free(AdPrCoefLi);
  free(Matrice);
  free(NumCol);
  free(AdSuccLi);
}
