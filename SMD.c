#include "headers/tp2.h"
#include "headers/tp1.h"
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
  int Nb_lignes;
  int Nb_coefs;
  float *Matrice;
  int *FirstAdLi;
  int *FollowingAdLi;
  int *ColInd;
  int Nextad;

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

  // A determiner
  FirstAdLi = (int*)( calloc(nb_nodes, sizeof(int)) );
  FollowingAdLi = (int*)( calloc(nb_nodes, sizeof(int)) );
  Matrice = (float*)( calloc(nb_nodes*nb_nodes, sizeof(float)) );
  ColInd = (int*)( calloc(nb_nodes*nb_nodes, sizeof(int)) );
  Nextad = 1;



  /* Pour chaque élément, calcul et affichage de la matrice élémentaire
     Puis assemblage en SMD. */
  for(k = 0; k < nb_elements; k++)
  {
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


    printf("%d, %d, %d \n", node_idx_array[k][0], node_idx_array[k][1], node_idx_array[k][2]);
    //Remplissons d'abord la diagonale de Matrice
    


    for (i=0; i < nb_node_per_element; i++) {
      for (j=0; j < nb_node_per_element; j++) {
        I = node_idx_array[k][i];
        J = node_idx_array[k][j];

        if (I > J) {
          assmat_(&I, &J, &MatElem[i][j], FirstAdLi, ColInd, FollowingAdLi, Matrice, &Nextad);
        }

      }
    }
    impCalEl(k+1,
       element_type,
       nb_node_per_element,
       MatElem,
       SMbrElem,
       NuDElem,
       uDElem);

  }

  for(i=0; i<nb_nodes*nb_nodes; i++) {
    printf("%f\n", Matrice[i]);
  }
  free(FirstAdLi);
  free(FollowingAdLi);
  free(Matrice);
}
