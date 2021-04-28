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

  int Nb_coef = (*AdPrCoLiO)[*NbLign-1]-1;

  *MatriceO = (float*)malloc((*NbLign+Nb_coef)*sizeof(float));
  fread(*MatriceO, sizeof(float), *NbLign+Nb_coef, input);

  *NumColO = (int*)malloc(Nb_coef*sizeof(int));
  fread(*NumColO, sizeof(int), Nb_coef, input);

  /* Fermeture du fichier de sortie */
  fclose(input);

}
