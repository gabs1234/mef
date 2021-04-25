#include "headers/tp2.h"
#include "headers/tp1.h"
#include "headers/tp3.h"
#include "headers/forfun.h"
#include <stdio.h>
#include <stdlib.h>


/*
--------------------------------------------------------------------------------
TODO: Description
--------------------------------------------------------------------------------
*/


int main()
{
  // Variables SMD
  int nb_lignes;
  int nb_coefs;
  float *Matrice;
  float *LowMat;
  int *AdPrCoefLi;
  int *AdSuccLi;
  int *ColInd;
  int NextAd;

  float *SecMembre;
  int *NumDLDir;
  float *ValDLDir;

  // Variables pre assemblage
  char *file_name = "mesh/car1x1t_1";
  int element_type;

  int nb_nodes;
  float **node_coord_array;
  int nb_elements;
  int **node_idx_array;
  int nb_node_per_element;
  int nb_vrtx_per_element;
  int **vertex_ref_array;

  int I, J, i, j, k;


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

  // Nombre maximal de coefficients,
  int NbCoefMax = (nb_nodes*(nb_nodes+1))/2;

  // Initialisations de la SMD
  AdPrCoefLi = (int*)( calloc(nb_nodes, sizeof(int)) );
  AdSuccLi = (int*)( calloc(nb_nodes, sizeof(int)) );
  Matrice = (float*)( calloc(nb_nodes + NbCoefMax , sizeof(float)) );
  LowMat = (float*)( calloc(NbCoefMax , sizeof(float)) );
  ColInd = (int*)( calloc(nb_nodes*nb_nodes, sizeof(int)) );
  NextAd = 1;
  nb_lignes = nb_nodes;
  LowMat = (Matrice+nb_nodes+1);

  SecMembre = (float*)( calloc(nb_nodes, sizeof(float)) );
  NumDLDir = (int*)( malloc(nb_nodes*sizeof(float)) );
  ValDLDir = (float*)( malloc(nb_nodes*sizeof(float)) );
  

  /* Pour chaque élément, calcul et affichage de la matrice élémentaire
     Puis assemblage en SMD. */
  for(k = 0; k < nb_elements; k++) {
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

    float SMbrElem[nb_node_per_element];

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

    assemblage(k,
      Matrice,
      nb_node_per_element,
      node_idx_array,
      MatElem,
      AdPrCoefLi,
      ColInd,
      AdSuccLi,
      LowMat,
      &NextAd,
      NuDElem,
      SMbrElem,
      uDElem,
      NumDLDir,
      ValDLDir,
      SecMembre);

    impCalEl(k+1,
       element_type,
       nb_node_per_element,
       MatElem,
       SMbrElem,
       NuDElem,
       uDElem);

  }

  AdPrCoefLi[nb_lignes-1] = NextAd;
  //A verifier
  nb_coefs = AdPrCoefLi[nb_lignes-1]-1;


  char filename[10] = "SMD_output";

  //EcrSMD(filename, nb_nodes, Nb_coefs, SecMembre, NumDLDir, ValDLDir, AdPrCoefLi, Matrice, ColInd, AdSuccLi);


  free(AdPrCoefLi);
  free(AdSuccLi);
  free(ColInd);
  free(Matrice);
  free(SecMembre);
  free(NumDLDir);
  free(ValDLDir);
}
