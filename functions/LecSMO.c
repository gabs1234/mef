#include "../headers/tp1.h"
#include "../headers/tp2.h"
#include "../headers/tp3.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


/*
--------------------------------------------------------------------------------
TODO: Lit la structure morse désordonnée dans un fichier binaire
--------------------------------------------------------------------------------
*/


void LecSMO(char *filename,
           int *NbLign,
           float **SecMembreO,
           int **AdPrCoLiO,
           float **MatriceO,
           int **NumColO)
{
	/* Ouverture du fichier */
  FILE *input = fopen(filename, "rb");
	if (input == NULL)
	{
    //TODO: strerror
		//fprintf(stderr, "Erreur: ...\n");
    printf("Erreur: fichier non ouvert\n");
		exit(EXIT_FAILURE);
	}
  //Lecture suivant l'ordre defini dans EcrSMO.c
  fread(NbLign, sizeof(int), 1, input);
  printf("%d\n", *NbLign);

  *SecMembreO = (float*)(malloc(*NbLign*sizeof(float)));
  fread(*SecMembreO, sizeof(float), *NbLign, input);

  *AdPrCoLiO = (int*)malloc(*NbLign*sizeof(int));
  fread(*AdPrCoLiO, sizeof(int), *NbLign, input);

  Nb_coefs = (*AdPrCoLiO)[*NbLign-1]-1;

  *MatriceO = (float*)malloc((*NbLign+NbCoef)*sizeof(float));
  fread(*MatriceO, sizeof(float), *NbLign+NbCoef, input);

  *NumColO = (int*)malloc(*NbCoef*sizeof(int));
  fread(*AdPrCoefLi, sizeof(int), *NbCoef, input);

  /* Fermeture du fichier de sortie */
  fclose(input);

}
