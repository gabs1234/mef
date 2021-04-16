/*
--------------------------------------------------------------------------------
  Mise a jour de la matrice elementaire : ajout de la contribution
  d'un point de quadrature d'un element ou de son bord, pour le calcul
  d'integrales elementaires faisant intervenir une seule fonction de base.

  Terminologie : FK designe la transformation qui calcule l'image dans
                 l'element courant d'un point de l'element de reference

  Arguments d'entree :
   nbneel : nombre de noeuds de l'element
   fctbas : valeurs des fonctions de base au point de quadrature courant
            Dimensions utiles : fctbas(nbneel)
   eltdif : element differentiel multiplie par le poids de quadrature
   cofvar : valeur du coefficient variable (fonction a integrer calculee
            en l'image par FK du point de quadrature courant

   smblm : second membre elementaire a actualiser
            Dimensions utiles : matelm(nbneel,nbneel)
  Arguments de sortie :
   smblm : second membre elementaire actualise
--------------------------------------------------------------------------------
*/
void W(int nbneel, float *fctbas, float eltdif, float cofvar, float *smblm) {
  int i;
  float coeff;

  for (i=0; i<nbneel; i++) {
    coeff = eltdif*cofvar*fctbas[i];
    smblm[i] =smblm[i] + coeff;
  }
}
