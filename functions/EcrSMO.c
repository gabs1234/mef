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
     SecMembreO : taille NbLign
     AdPrCoLiO  : taille NbLign
     MatriceO   : taille NbLign+NbCoef
     NumColO    : taille NbCoef


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

  int NbCoef = AdPrCoLiO[*NbLign-1]-1;

  fwrite(NbLign, sizeof(int), 1, output);
  fwrite(SecMembreO, sizeof(float), *NbLign, output);
  fwrite(AdPrCoLiO, sizeof(int), *NbLign, output);
  fwrite(MatriceO, sizeof(float), *NbLign+NbCoef, output);
  fwrite(NumColO, sizeof(int), NbCoef, output);

  fclose(output);
}
