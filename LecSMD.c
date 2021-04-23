#include "headers/tp2.h"
#include "headers/tp1.h"
#include <stdio.h>
#include <stdlib.h>


/*
--------------------------------------------------------------------------------
TODO: Lit la structure morse désordonnée dans un fichier binaire
--------------------------------------------------------------------------------
*/


int LecSMD(char* nomfichier,
           int *Nb_lignes,
           float **SecMembre;
           int **NumDLDir,
           float **ValDLDir,
           int **AdPrCoefLi,
           float **Matrice,
           int **AdSuccLi,
           int **NumCol)
{
	/* Ouverture du fichier de sortie */
        void *output;             /* Pointeur du fichier de sortie */
	output = fopen(file_name, "w+");
	if (output == NULL)
	{
		fprintf(stderr, "Erreur: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
        int Nb_coefs;
        
        /* Impression des éléments ATTENTION L'ORDRE IMPORTE */
        fread(Nb_lignes, sizeof(int), 1, output);

        *SecMembre = malloc(&Nb_lignes*sizeof(float));
        fread(*SecMembre, sizeof(float), &Nb_lignes, output);

        *NumDLDir = malloc(&Nb_lignes*sizeof(int));
        fread(*NumDLDir, sizeof(int), &Nb_lignes, output);

        *ValDLDir = malloc(&Nb_lignes*sizeof(float));
        fread(*ValDLDir, sizeof(float), &Nb_lignes, output);

        *AdPrCoefLi = malloc(&Nb_lignes*sizeof(int));
        fread(*AdPrCoefLi, sizeof(int), &Nb_lignes, output);

        Nb_coefs = AdPrCoefLi(&Nb_lignes)-1

        *Matrice = malloc(&Nb_lignes+Nb_coefs*sizeof(float));
        fread(*Matrice, sizeof(float), &Nb_lignes+Nb_coefs, output);

        *NumCol = malloc(Nb_coefs*sizeof(int));
        fread(*NumCol, sizeof(int), Nb_coefs, output);

        *AdSuccLi = malloc(Nb_coefs*sizeof(int));
        fread(*AdSuccLi, sizeof(int), Nb_coefs, output);


        /* Fermeture du fichier de sortie */
        fclose(output);
}
