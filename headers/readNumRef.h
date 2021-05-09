/* Program reading the file containing reference elements */

int readNumRef(char *file_name,
               int *numRefDomain,
               int *N_numRefDirichletHomogene,
               int **tab_numRefDirichletHomogene,
               int *N_numRefDirichletInhomogene,
               int **tab_numRefDirichletInHomogene,
               int *N_numRefNeumann,
               int **tab_numRefNeumann);
