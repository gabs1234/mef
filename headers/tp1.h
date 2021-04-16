/* Lit une chaîne d'au plus 'maxlen' caractères depuis la console,
   et renvoie son adresse. */

char *get_string(int maxlen);



/* Initialise une matrice dynamique de 'nb_rows' lignes et 'nb_col' colonnes */

void init_mat_int(int nb_rows, int nb_col, int ***array);
void init_mat_float(int nb_rows, int nb_col, float ***array);



/* La même chose, avec les fonctions données */

float **alloctab_float(int dim1, int dim2);
int **alloctab_int(int dim1, int dim2);



/* Libération de la mémoir allouée par alloctab */

void freetab(void *ptr);



/* Imprime un tableau de longueur 'n' sur la console, en numérotant chaque élément.
   Types de données supportées : 'data_type' = 'i'|'f'|'d'|'c'. */

void print_tab(int n,
               void *tab,
               char data_type);



void print_mat(int n,
               int m,
               void **tab,
               char data_type);



void genRefTab(int element_type,
               int ne1,
               int ne2,
               int **refTab);



int readMeshFile(char *file_name,
                 int *element_type,
                 int *nb_nodes,
                 float ***node_coord_array,
                 int *nb_elements,
                 int ***node_idx_array,
                 int *nb_node_per_element,
                 int *nb_vrtx_per_element,
                 int ***vertex_ref_array);
