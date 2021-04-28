#include "headers/tp1.h"
#include "headers/tp2.h"
#include "headers/tp3.h"
#include "headers/tp4.h"
#include "headers/forfun.h"
#include <stdio.h>
#include <stdlib.h>

/* Ceci est un commentaire uniquement destiné à modifier le fichier */

int main() {
  // Variables SMD
  int Nb_lignes;
  float *SecMembre;
  int *NumDLDir;
  float *ValDLDir;
  int *AdPrCoefLi;
  float *Matrice;
  int *AdSuccLi;
  int *NumCol;

  // Lecture du nom de fichier à ouvrir
  printf("Entrez le nom du fichier SMD à lire\n"); 
  char *file_name_smd = get_string(50);
  printf("Le nom du fichier est : \"%s\"\n", file_name_smd);

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

  int Nb_coef = AdPrCoefLi[Nb_lignes-1]-1;

  // Variables SMO
  float SecMembreO[Nb_lignes];
  int AdPrCoLiO[Nb_lignes];
  float MatriceO[Nb_lignes+Nb_coef];
  int NumColO[Nb_coef];

  printf("On est bien arrivé ici !");

  // Affichage
  printf("Voulez vous afficher la matrice SMD ? \n");
  printf("oui: 1, non: 0\n");
  int read = 0;
  scanf("%d",&read);

  // Impression de la matrice
  if( read ){
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
  }

  cdesse_(&Nb_lignes,
          AdPrCoefLi,
          NumCol,
          AdSuccLi,
          Matrice,
          SecMembre,
          NumDLDir,
          ValDLDir,
          AdPrCoLiO,
          NumColO,
          MatriceO,
          SecMembreO);
  
  
  char *file_name_smo = "test";

  /*On ne peut pas utiliser la fonction getchar ici. Le problème semble être que des
    caractères s'accumulent dans un buffer au niveau de l'OS. Comme ce n'est pas un
    problème vital j'ai juste mis un nom de fichier fixe. */
  printf("Le nom du fichier est : \"%s\"\n", file_name_smo);

  //generer le fichier binaire
  EcrSMO(file_name_smo, &Nb_lignes, SecMembreO, AdPrCoLiO, MatriceO, NumColO);

  /* Impression des matrices */
  int z;
  for(z = 0; z < Nb_lignes; z++){printf("SMO: %d: %f\n",z,SecMembreO[z]);}
  for(z = 0; z < Nb_lignes; z++){printf("ACO: %d: %d\n",z,AdPrCoLiO[z]);}
  int NbCoefO = AdPrCoLiO[Nb_lignes-1]-1;
  for(z = 0; z < Nb_lignes+NbCoefO; z++){printf("MAO: %d: %f\n",z,MatriceO[z]);}
  for(z = 0; z < NbCoefO; z++){printf("NCO: %d: %d\n",z,NumColO[z]);}

  free(SecMembre);
  free(NumDLDir);
  free(ValDLDir);
  free(AdPrCoefLi);
  free(Matrice);
  free(NumCol);
  free(AdSuccLi);

  return 0;
}
