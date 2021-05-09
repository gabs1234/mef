#include "../headers/tp1.h"
#include "../headers/tp2.h"
#include "../headers/tp3.h"
#include "../headers/forfun.h"
#include "../headers/readNumRef.h"
#include <stdio.h>
#include <stdlib.h>


/*
--------------------------------------------------------------------------------
Procédure calculant les matrices et second membres et assemblant le système
global.
--------------------------------------------------------------------------------
*/

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
           float ***node_coord_array)
{

  printf("Le nom du fichier de référence est : %s\n", ref_file_name);
  // Variables du fichier de maillage
  int element_type;
  int nb_nodes;
  int nb_elements;
  int **node_idx_array;
  int nb_node_per_element;
  int nb_vrtx_per_element;
  int **vertex_ref_array;

  // Variables numeros de ref
  int numRefDomain;
  int N_numRefDirichletHomogene;
  int *tab_numRefDirichletHomogene;
  int N_numRefDirichletInhomogene;
  int *tab_numRefDirichletInhomogene;
  int N_numRefNeumann;
  int *tab_numRefNeumann;

  // Variables SMD

  int nb_coefs; /* Nombre de coeff. dans la partie triangulaire inférieur stricte */
  int NextAd;
  float* LowMat;

  /* Lecture du fichier de maillage */
  if(readMeshFile(mesh_file_name,
                  &element_type,
                  &nb_nodes,
                  node_coord_array,
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

  // Nombre maximal de coefficients,
  int NbCoefMax = (nb_nodes*(nb_nodes+1))/2;

  // Initialisations de la SMD
  *Matrice = (float*)( calloc(nb_nodes + NbCoefMax , sizeof(float)) );
  *AdPrCoefLi = (int*)( calloc(nb_nodes, sizeof(int)) );
  *ColInd = (int*)( calloc(NbCoefMax, sizeof(int)) );
  *AdSuccLi = (int*)( calloc(NbCoefMax, sizeof(int)) );
  NextAd = 1;
  *nb_lignes = nb_nodes;
  LowMat = (*Matrice+nb_nodes);

  //TODO:Verifier Initialisation
  *SecMembre = (float*)( calloc(nb_nodes, sizeof(float)) );
  *NumDLDir = (int*)( malloc(nb_nodes*sizeof(float)) );
  for(int z = 0; z < nb_nodes; z++){(*NumDLDir)[z] = z+1;}
  *ValDLDir = (float*)( calloc(nb_nodes, sizeof(float)) );

  /* Pour chaque élément, calcul et affichage de la matrice élémentaire
     puis assemblage en SMD*/
  for(int k = 0; k < nb_elements; k++)
  {

    /* Coordonnées des sommets de l'élément courant */
    float **coorEl;
    coorEl = alloctab_float(nb_node_per_element,2);
    select_points(nb_node_per_element,
      node_idx_array[k],
      *node_coord_array,
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

    // Assemblage des matrices elementaires en SMD
    assemblage(k,
      *Matrice,
      nb_node_per_element,
      node_idx_array,
      MatElem,
      *AdPrCoefLi,
      *ColInd,
      *AdSuccLi,
      LowMat,
      &NextAd,
      NuDElem,
      SMbrElem,
      uDElem,
      *NumDLDir,
      *ValDLDir,
      *SecMembre);

    /* Impression des matrices calculées */
    impCalEl(k+1,
      element_type,
      nb_node_per_element,
      MatElem,
      SMbrElem,
      NuDElem,
      uDElem);
  }

  (*AdPrCoefLi)[*nb_lignes-1] = NextAd;
}
