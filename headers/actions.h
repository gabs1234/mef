/* header contenant les prototypes des routines principales */

void build(char mesh_file_name[],
           char ref_file_name[],
           int *nb_lignes,
           float **Matrice,
           int **AdPrCoefLi,
           int **AdSuccLi,
           int **ColInd,
           float **SecMembre,
           int **NumDLDir,
           float **ValDLDir,
           float ***node_coord_array);

void EcrSMD(char *filename,
            int *NbLign,
            float *SecMembre,
            int *NumDLDir,
            float *ValDLDir,
            int *AdPrCoefLi,
            float *Matrice,
            int *NumCol,
            int *AdSuccLi);

int LecSMD(char *nomfichier,
           int *Nb_lignes,
           float **SecMembre,
           int **NumDLDir,
           float **ValDLDir,
           int **AdPrCoefLi,
           float **Matrice,
           int **AdSuccLi,
           int **NumCol);

void EcrSMO(char *filename,
            int NbLign,
            float *SecMembreO,
            int *AdPrCoLiO,
            float *MatriceO,
            int *NumColO);

int LecSMO(char *filename,
           int *NbLign,
           float **SecMembreO,
           int **AdPrCoLiO,
           float **MatriceO,
           int **NumColO);
           
void dSMOaPR(int *nb_lignes,
             float *SecMembreO,
             int *AdPrCoLiO,
             float *MatriceO,
             int *NumColO,
             int **profil,
             float **MatProf);

void CalSol(int Nb_lignes,
            float **coord,
            float (*UEX)[Nb_lignes],
            int nucas);
