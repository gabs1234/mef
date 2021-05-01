/* Prototype des fonctions et routines utiles pour le tp 2 */


void select_points(int nombre_points, int num[], float *coord_set[], float *coord_selected[]);
void numNaret(int refAret, int nb_node_per_element, int *refNodes);
void ppquad(int element_type, float *weights, float **coords);

void calFbase(int nombre_nodes_per_elements, float *coords, float *value);
void calDerFbase(int nombre_nodes_per_elements, float **value);
void transFK(int element_type, int **nodes, float **point, float *coord);
void matJacob(int nbeel, float **node_coord, float **DerValues, float **output);
void det_2x2(float **mat_2x2, float *det);
void invert_2x2(float **mat_2x2, float det, float **out_2x2);

/* Procedure de calcul des intégrales elementaires */

void W(int nbneel, float *fctbas, float eltdif, float cofvar, float *smblm);
void WW(int nbneel, float *fctbas, float eltdif, float cofvar, float **matelm);
void ADWDW(int nbneel, float **invJFK, float **derfctbas, float eltdif, float **cofvar, float **matelm);


/* Procedure de calcul des intégrales linéique et surfacique */

void intElem(int typEl,
	     int nbeel,
	     float **coorEl,
	     float **MatElem,
	     float *SMbrElem);

void intAret(int *locNod,
             int nbeel,
	     float **coorEl,
	     float **MatElem,
	     float *SMbrElem);

void cal1Elem(int nrefDom,
	      int nbRefD0,
	      int *numRefD0,
	      int nbRefD1,
	      int *numRefD1,
	      int nbRefF1,
	      int *numRefF1,
	      int typEl,
	      int nbeel,
	      float **coorEl,
	      int nbaret,
	      int *nrefArEl,
	      float **MatElem,
	      float *SMbrElem,
	      int *NuDElem,
	      float *uDElem);

void impCalEl(int K,
              int typEl,
              int nbneel,
              float **MatElem,
              float *SMbrElem,
              int *NuDElem,
              float *uDElem);
