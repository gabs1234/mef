#include "tp1.h"
#include "tp2.h"
#include <stdio.h>
#include <stdlib.h>
#include "forfun.h"

int main(int argc, char const *argv[]) {
  // Nombre ligne et colonnes de A
  unsigned int NbLign;
  // Nombre coefficients partie trig inf stricte
  unsigned int NbCoef*;
  /* Coefficients de la diagonale + des coefs non nuls partie inféfieure stricte
  dim = NbLign + NbCoef
  Matrice = DiagMat + LowMat */
  float Matrice*;
  /* Position par ligne dans LowMat du premier coef non nul
  dim >= NbLign
  Si tous les coefs de la ligne I sont nuls, AdPrCoefLi[I] = 0
  AdPrCoefLi[NbLign] = NbCoef + 1 */
  int AdPrCoefLi*;
  /* Position dans les lignes des elements suivants dans LowMat
  dim >= NbCoef
  0 si y'a rien d'autre */
  int AdSuccLi*;
  /* En avaceant de gauche a droite, le numero de colonne de chaque element dans LowMat.
  dim >= NbCoef */
  int NumCol*;
  // Second membre, dim >= NbLign
  float SecMembre*;
  // Numeros de degre de liberte de Dirichlet
  int NumDLDir*;
  // Valeurs associes aux conditions de Dirichlet en ces d.d.l
  int ValDLDir*;

  char *file_name = "car1x1t_1";
  int element_type;

  int nb_nodes;
  float **node_coord_array;
  int nb_elements;
  int **node_idx_array;
  int nb_node_per_element;
  int nb_vrtx_per_element;
  int **vertex_ref_array;

  Matrice = (float)(malloc(nb_node_per_element*nb_elements*siezof(float)));


  if(readMeshFile(file_name,
                  &element_type,
                  &nb_nodes,
                  &node_coord_array,
                  &nb_elements,
                  &node_idx_array,
                  &nb_node_per_element,
                  &nb_vrtx_per_element,
                  &vertex_ref_array))
  {
    printf("Malfonction de la fonction readMeshFile !\n");
    exit(1);
  }
  else {printf("Le fichier a été lu avec succès !\n");}


  // Pour chaque élément, calcul et affichage de la matrice élémentaire
  for (int k = 0; k < nb_elements; k++) {
    // Coordonnées des sommets de l'élément courant
    float **coorEl;
    coorEl = alloctab_float(nb_node_per_element,2);
    select_points(nb_node_per_element,
	    node_idx_array[k],
	    node_coord_array,
	    coorEl);

    // Matrice et second menbre élémentaire
    float **MatElem;
    MatElem = alloctab_float(nb_node_per_element, nb_node_per_element);

    int len_matrix = sqrt(nb_elements);
    SecMembre = (float)(malloc(len_matrix*siezof(float)));

    int NuDElem[nb_node_per_element];
    float uDElem[nb_node_per_element];

    // Tableaux de référence
    int nbRefD0 = 0;
    int numRefD0[nb_vrtx_per_element];
    int nbRefD1 = 0;
    int numRefD1[nb_vrtx_per_element];
    int nbRefF1 = 0;
    int numRefF1[nb_vrtx_per_element];

    cal1Elem(0,
       nbRefD0,
       numRefD0,
       nbRefD1,
       numRefD1,
       nbRefF1,
       numRefF1,
       element_type,
       nb_node_per_element,
       coorEl,
       nb_vrtx_per_element,
       vertex_ref_array[k],
       MatElem,
       SMbrElem,
       NuDElem,
       uDElem);

    /* Impression des matrices calculées */
    impCalEl(k+1,
       element_type,
       nb_node_per_element,
       MatElem,
       SMbrElem,
       NuDElem,
       uDElem);

    }


  return 0;
}
