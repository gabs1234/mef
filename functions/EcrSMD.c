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
void EcrSMD(char *filename,
            int *NbLign,
            float *SecMembre,
            int *NumDLDir,
            float *ValDLDir,
            int *AdPrCoefLi,
            float *Matrice,
            int *NumCol,
            int *AdSuccLi)
{
  FILE * output = fopen(filename, "wb+");

  int NbCoef = AdPrCoefLi[*NbLign-1]-1;

  fwrite(NbLign, sizeof(int), 1, output);
  fwrite(SecMembre, sizeof(float), *NbLign, output);
  fwrite(NumDLDir, sizeof(int), *NbLign, output);
  fwrite(ValDLDir, sizeof(float), *NbLign, output);
  fwrite(AdPrCoefLi, sizeof(int), *NbLign, output);
  fwrite(Matrice, sizeof(float), *NbLign + NbCoef, output);
  fwrite(NumCol, sizeof(int), NbCoef, output);
  fwrite(AdSuccLi, sizeof(int), NbCoef, output);

  fclose(output);
}
