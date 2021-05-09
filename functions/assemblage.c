#include "../headers/tp3.h"
#include "../headers/forfun.h"
#include <stdio.h>
#include <stdlib.h>

void assemblage(int k,
                float *Matrice,
                int nb_node_per_element,
                int **node_idx_array,
                float **MatElem,
                int *AdPrCoefLi,
                int *ColInd,
                int *AdSuccLi,
                float *LowMat,
                int *NextAd,
                int *NuDElem,
                float *SMbrElem,
                float *uDElem,
                int *NumDLDir,
                float *ValDLDir,
                float *SecMembre)
{
  int I, J;
  // Remplissons d'abord la diagonale de Matrice
  // et le second membre
  for (int i=0; i < nb_node_per_element; i++) {
    I = node_idx_array[k][i]-1;
    Matrice[I] = Matrice[I] + MatElem[i][i];
    SecMembre[I] = SecMembre[I] + SMbrElem[i];
    
    if(NuDElem[i] < 0)
    {
      NumDLDir[I] = -(I+1);
      ValDLDir[I] = uDElem[i];
    }
    if(NuDElem[i] == 0)
    {
      NumDLDir[I] = 0;
    }
  }
  // Puis la Matrice inferieure LowMat
  for (int i=0; i < nb_node_per_element; i++) {
    for (int j=0; j < nb_node_per_element; j++) {
      I = node_idx_array[k][i];
      J = node_idx_array[k][j];
      if (I > J) {
        assmat_(&I, &J, &MatElem[i][j], AdPrCoefLi, ColInd, AdSuccLi, LowMat, NextAd);
      }
    }
  }
}
