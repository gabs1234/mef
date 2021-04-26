#include "../headers/tp3.h"
#include <stdio.h>
/*
--------------------------------------------------------------------------------

  Procédure sauvegardant la Structure Morse Desordonnee sous la forme d'un fichier
  séquanciel binaire

  Terminologie :
     "vecteur" : tableau à une dimention
     "matrice" : tableau à deux dimention
     "chaine" : tableau de caractères termine par le caractere NULL

  Arguments d'entree :
     filename : chaine, nom du fichier a creer
     NbLign : entier, nombre de lignes et de colonnes de la matrice A
     NbCoef : entier, nombre de coefficients dans la matrice tri inf
     SecMembre : vecteur de reels
       dimention utile : NbLign
     NumDLDir : vecteur d'entiers
       dimention utile : NbLign
     ValDLDir : vecteur de reels
       dimention utile : NbLign
     AdPrCoefLi : vecteur d'entiers
       diemention utile : NbLign
     Matrice : vecteur de reels
       dimention utile : NbLign + NbCoef
     NumCol : vecteur d'entiers
       dimention utile : NbCoef
     AdSuccLi : vecteur d'entiers
       dimention utile : NbCoef


--------------------------------------------------------------------------------
*/
void EcrSMO(char *filename,
            int *NbLign,
            float *SecMembreO,
            int *AdPrCoLiO,
            float *MatriceO,
            int *NumColO)
{
  FILE * output = fopen(filename, "wb+");

  Nb_coef = (*AdPrCoLiO)[*NbLign-1]-1;

  fwrite(NbLign, sizeof(int), 1, output);
  fwrite(SecMembreO, sizeof(float), *NbLign, output);
  fwrite(AdPrCoLiO, sizeof(int), *NbLign, output);
  fwrite(MatriceO, sizeof(float), *NbLign+NbCoef, output);
  fwrite(NumColO, sizeof(int), NbCoef, output);

  fclose(output);
}
