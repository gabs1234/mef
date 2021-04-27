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


void LecSMD(char *filename,
           int *Nb_lignes,
           float **SecMembre,
           int **NumDLDir,
           float **ValDLDir,
           int **AdPrCoefLi,
           float **Matrice,
           int **AdSuccLi,
           int **NumCol)
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

  int Nb_coefs;
  /* Impression des éléments ATTENTION L'ORDRE IMPORTE */
  fread(Nb_lignes, sizeof(int), 1, input);

  *SecMembre = (float*)(malloc(*Nb_lignes*sizeof(float)));
  fread(*SecMembre, sizeof(float), *Nb_lignes, input);

  for (int i = 0; i < *Nb_lignes; i++) {
    printf("%f\n", *(SecMembre)[i]);
  }

  *NumDLDir = (int*)malloc(*Nb_lignes*sizeof(int));
  fread(*NumDLDir, sizeof(int), *Nb_lignes, input);

  *ValDLDir = (float*)malloc(*Nb_lignes*sizeof(float));
  fread(*ValDLDir, sizeof(float), *Nb_lignes, input);

  *AdPrCoefLi = (int*)malloc(*Nb_lignes*sizeof(int));
  fread(*AdPrCoefLi, sizeof(int), *Nb_lignes, input);

  Nb_coefs = (*AdPrCoefLi)[*Nb_lignes-1]-1;

  *Matrice = (float*)malloc((*Nb_lignes+Nb_coefs)*sizeof(float));
  fread(*Matrice, sizeof(float), *Nb_lignes+Nb_coefs, input);

  *NumCol = (int*)malloc(Nb_coefs*sizeof(int));
  fread(*NumCol, sizeof(int), Nb_coefs, input);

  *AdSuccLi = (int*)malloc(Nb_coefs*sizeof(int));
  fread(*AdSuccLi, sizeof(int), Nb_coefs, input);


  /* Fermeture du fichier de sortie */
  fclose(input);

}
