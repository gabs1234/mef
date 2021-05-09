/* Program reading the file containing reference elements */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int readNumRef(char *file_name,
               int *numRefDomain,
               int *N_numRefDirichletHomogene,
               int **tab_numRefDirichletHomogene,
               int *N_numRefDirichletInhomogene,
               int **tab_numRefDirichletInhomogene,
               int *N_numRefNeumann,
               int **tab_numRefNeumann)
{  
   /* Ouverture du fichier */
   void *input = fopen(file_name, "r");
   if (input == NULL)
   {
     fprintf(stderr, "Erreur: %s\n", strerror(errno));
     return 1;
   }


   /* ===== PROCERURE DE LECTURE ===== */
   int i;

   /* Lecture du numéro de référence du domaine */
   fscanf(input, "%d", numRefDomain);

   /* Lecture du nombre de numeros de reference Dirichlet homogene*/
   fscanf(input, "%d", N_numRefDirichletHomogene);
   *tab_numRefDirichletHomogene = malloc(sizeof(int)*(*N_numRefDirichletHomogene));
   for(i=0; i < *N_numRefDirichletHomogene; i++)
   {
      fscanf(input, "%d", &((*tab_numRefDirichletHomogene)[i]));
   }

   /* Lecture du nombre de numeros de reference Dirichlet non homogene*/
   fscanf(input, "%d", N_numRefDirichletInhomogene);
   *tab_numRefDirichletInhomogene = malloc(sizeof(int)*(*N_numRefDirichletInhomogene));
   for(i=0; i < *N_numRefDirichletInhomogene; i++)
   {
      fscanf(input, "%d", &((*tab_numRefDirichletInhomogene)[i]));
   }
   /* Lecture du nombre de numeros de reference Neumann*/
   fscanf(input, "%d", N_numRefNeumann);
   *tab_numRefNeumann = malloc(sizeof(int)*(*N_numRefNeumann));
   for(i=0; i < *N_numRefNeumann; i++)
   {
      fscanf(input, "%d", &((*tab_numRefNeumann)[i]));
   }
   
   return 0; /* Lecture sans problèmes */
}
