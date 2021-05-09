#include "../headers/tp5.h"
#include <stdlib.h>
#include <stdio.h>

void CalSol(int Nb_lignes, float **coord, float (*UEX)[Nb_lignes], int nucas)
{
  for (int i = 0; i < Nb_lignes; i++)
  {
    (*UEX)[i] = solex(coord[i], nucas);
  }
}