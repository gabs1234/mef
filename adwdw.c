#include <stdio.h>

/*
--------------------------------------------------------------------------------
  Mise a jour de la matrice elementaire : ajout de la contribution
  d'un point de quadrature d'un element ou de son bord, pour le calcul
  d'integrales elementaires faisant intervenir le produit de deux
  fonctions de base.

  Arguments d'entree :
   nbneel : nombre de noeuds de l'element
   JFK : matrice jacobienne inverse de la transformation
   derfctbas : valeurs des fonctions de base au point de quadrature courant
            Dimensions utiles : nbneel*2
   eltdif : element differentiel multiplie par le poids de quadrature
   cofvar : valeur du coefficient variable (fonction a integrer calculee
            en l'image par FK du point de quadrature courant)
   matelm : matrice elementaire de masse a actualiser
            Dimensions utiles : matelm(nbneel,nbneel)
  Arguments de sortie :
   matelm : matrice elementaire de masse actualisee
--------------------------------------------------------------------------------
*/
void ADWDW(int nbneel, float **B, float **derfctbas, float eltdif, float **cofvar, float **matelm) {
  int i, j, alph, beta;

  for (i=0; i<nbneel; i++) {
    for (j=0; j<nbneel; j++) {
      for(alph = 0; alph < 2; alph++){
        float scal1 = derfctbas[i][0]*B[0][alph]+derfctbas[i][1]*B[1][alph];
        for(beta = 0; beta < 2; beta++){
          float scal2 = derfctbas[j][0]*B[0][beta]+derfctbas[j][1]*B[1][beta];
          matelm[i][j] = matelm[i][j] + eltdif*cofvar[alph][beta]*scal1*scal2;
        }
      }
    }
  }
}
