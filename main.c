#include "headers/tp2.h"
#include "headers/tp1.h"
#include "readNumRef.h"
#include <stdio.h>
#include <stdlib.h>


/*
--------------------------------------------------------------------------------
Programme de test des procédures de calcul des intégrales élémentaires. Celui-ci
lit le fichier de maillage test , calcul pour chaque élément les matrices et
second membres élémentaires et affiche le résultat.
--------------------------------------------------------------------------------
*/


int main()
{

  char *file_name = "mesh/car1x1t_1";
  int element_type;

  int nb_nodes;
  float **node_coord_array;
  int nb_elements;
  int **node_idx_array;
  int nb_node_per_element;
  int nb_vrtx_per_element;
  int **vertex_ref_array;

  /* Lecture du fichier de maillage */
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
  else {printf("Le fichier de maillage a été lu avec succès !\n");}

  char *ref_file_name = "NUMREF.Test";
  int numRefDomain;
  int N_numRefDirichletHomogene;
  int *tab_numRefDirichletHomogene;
  int N_numRefDirichletInhomogene;
  int *tab_numRefDirichletInhomogene;
  int N_numRefNeumann;
  int *tab_numRefNeumann;

  /* Lecture du fichier contenant les conditions aux limites */
  if(readNumRef(ref_file_name,
                &numRefDomain,
                &N_numRefDirichletHomogene,
                &tab_numRefDirichletHomogene,
                &N_numRefDirichletInhomogene,
                &tab_numRefDirichletInhomogene,
                &N_numRefNeumann,
                &tab_numRefNeumann))
  {
    printf("Malfonction de la fonction readNumRef !\n");
    exit(1);
  }
  else {printf("Le fichier de référence a été lu avec succès !\n");}

  /* TESTS TEMPORAIRES !*/
  printf("===== NUMEROS DE REFERENCE =====\n");
  printf("Numéro de référence du domaine : %d\n",numRefDomain);
  printf("Nombre de réfénrences DH : %d\n",N_numRefDirichletHomogene);
  printf("Références DH\n");
  for(int z = 0; z < N_numRefDirichletHomogene ; z++)
  {
     printf("N°%d : %d\n",z,tab_numRefDirichletHomogene[z]);
  }
  printf("Références DNH\n");
  for(int z = 0; z < N_numRefDirichletInhomogene ; z++)
  {
     printf("N°%d : %d\n",z,tab_numRefDirichletInhomogene[z]);
  }
  printf("Références Neumann\n");
  for(int z = 0; z < N_numRefNeumann ; z++)
  {
     printf("N°%d : %d\n",z,tab_numRefNeumann[z]);
  }


  /* Pour chaque élément, calcul et affichage de la matrice élémentaire */
  for(int k = 0; k < nb_elements; k++)
    {

      /* Coordonnées des sommets de l'élément courant */
      float **coorEl;
      coorEl = alloctab_float(nb_node_per_element,2);
      select_points(nb_node_per_element,
		    node_idx_array[k],
		    node_coord_array,
		    coorEl);

      
      // Initialisation de la matrice et du second menbre élémentaire
      float **MatElem;
      MatElem = alloctab_float(nb_node_per_element, nb_node_per_element);

      float SMbrElem[nb_node_per_element];

      int NuDElem[nb_node_per_element];
      for(int l = 0; l < nb_node_per_element; l++)
      {
         NuDElem[l]=1;
      }
      /* Condition de dirichlet au noeud i homogène NuDElem[i] = 0
         Condition de dirichlet au noeud i inhomogène NuDElem[i] = -1
         NuDElem[i] = 1 sinon */
      float uDElem[nb_node_per_element];
      /* Valeur imposée par la condition de dirichlet non homogène au point i
         (si pertinent, 0 sinon) */

      cal1Elem(numRefDomain,
               N_numRefDirichletHomogene,
               tab_numRefDirichletHomogene,
               N_numRefDirichletInhomogene,
               tab_numRefDirichletInhomogene,
               N_numRefNeumann,
               tab_numRefNeumann,
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
}
