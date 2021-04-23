#include "headers/tp2.h"
#include "headers/tp1.h"
#include <stdio.h>
#include <stdlib.h>


/*
--------------------------------------------------------------------------------
TODO: Lit le fichier de sauvegarde et affiche son contenu
--------------------------------------------------------------------------------
*/

int main()
{
  /* Déclaration des variables */
  char* file_name;
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
  file_name = get_string(63);

  /* Lecture du fichier */
  LecSMD(file_name,
         &Nb_lignes,
         &SecMembre;
         &NumDLDir,
         &ValDLDir,
         &AdPrCoefLi,
         &Matrice,
         &AdSuccLi,
         &NumCol);
  
  /* Impression de la matrice */
   affsmd_(&NbLign,
          &AdPrCoefLi,
          &NumCol,
          &AdSuccLi,
          &Matrice,
          &SecMembre,
          &NumDlDir,
          &ValDLDir);
}
