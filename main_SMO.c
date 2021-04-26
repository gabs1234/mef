#include "tp1.h"
#include "tp2.h"
#include "tp3.h"
#include "tp4.h"
#include "headers/forfun.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  // Variables SMD
  int Nb_lignes;
  float *SecMembre;
  int *NumDLDir;
  float *ValDLDir;
  int *AdPrCoefLi;
  float *Matrice;
  int *AdSuccLi;
  int *NumCol;

  // Variables SMO
  float *SecMembreO = SecMembre;
  int *AdPrCoLiO = AdPrCoefLi;
  float MatriceO;
  int NumColO;

  // Lecture du nom de fichier à ouvrir
  printf("Entrez le nom du fichier SMD à lire\n");
  char *file_name_smd = get_string(50);

  // Lecture du fichier
  LecSMD(file_name_smd,
    &Nb_lignes,
    &SecMembre,
    &NumDLDir,
    &ValDLDir,
    &AdPrCoefLi,
    &Matrice,
    &AdSuccLi,
    &NumCol);

  // Affichage
  printf("Voulez vous afficher la matrice SMD ? \n");
  int read = 0;
  scanf("oui: 1, non: 0 -> %d \n", &read);

  // Impression de la matrice
  if( read ){
    affsmd_(&Nb_lignes,
      AdPrCoefLi,
      NumCol,
      AdSuccLi,
      Matrice,
      SecMembre,
      NumDLDir,
      ValDLDir);
  }



  // TODO : dSMDaSMO(...)

  printf("Entrez le nom du fichier à générer\n");
  char *file_name_smo = get_string(50);

  //generer le fichier binaire
  EcrSM0(file_name_smo, &NbLign, SecMembreO, AdPrCoLiO, MatriceO, NumColO);

  //Lire le fichier pour tester
  LecSMO(file_name_smo, &NbLign, &SecMembreO, &AdPrCoLiO, &MatriceO, &NumColO);

  // Affichage
  printf("Voulez vous afficher la matrice SMO ? \n");
  read = 0;
  scanf("oui: 1, non: 0 -> %d \n", &read);
  //Afficher la Matrice SMO
  if( read ) {
    affsmo_(&NbLign, AdPrCoLiO, NumColO, MatriceO, SecMembreO);
  }


  free(SecMembre);
  free(NumDLDir);
  free(ValDLDir);
  free(AdPrCoefLi);
  free(Matrice);
  free(NumCol);
  free(AdSuccLi);

  free(SecMembreO);
  free(AdPrCoLiO);
  free(MatriceO);
  free(NumColO);
  return 0;
}
