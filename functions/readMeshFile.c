/* Program testing the function readMeshFile */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "../headers/tp1.h"

int readMeshFile(char *file_name,
                 int *element_type,
                 int *nb_nodes,
                 float ***node_coord_array,
                 int *nb_elements,
                 int ***node_idx_array,
                 int *nb_node_per_element,
                 int *nb_vrtx_per_element,
                 int ***vertex_ref_array)
{
   void *input = fopen(file_name, "r");
   if (input == NULL)
   {
     fprintf(stderr, "Erreur: %s\n", strerror(errno));
     return 1;
   }

   /* Lecture du nombre de noeuds */
   fscanf(input, "%d", nb_nodes);


   /* Allocation de mémoire pour les coordonnées et lecture dans le fichier */
   *node_coord_array = alloctab_float(*nb_nodes, 2);
   if (*node_coord_array == NULL)
   {
     fprintf(stderr, "Erreur: %s\n", strerror(errno));
     return 1;
   }


   for(int i = 0; i<*nb_nodes; i++)
   {
      fscanf(input, "%f", &((*node_coord_array)[i][0]));
      fscanf(input, "%f", &((*node_coord_array)[i][1]));
   }

   /* Lecture du nombre et du type d'éléments */
   fscanf(input, "%d", nb_elements);
   fscanf(input, "%d", element_type);

   /* Affectation du nombre de vertices et de noeuds par éléments */
   fscanf(input, "%d", nb_node_per_element);
   fscanf(input, "%d", nb_vrtx_per_element);

   /* Allocation de mémoire pour les données élémentaires */
   *node_idx_array = alloctab_int(*nb_elements, *nb_node_per_element);

   if (*node_idx_array == NULL)
   {
     fprintf(stderr, "Erreur: %s\n", strerror(errno));
     return 1;
   }

   *vertex_ref_array = alloctab_int(*nb_elements, *nb_vrtx_per_element);

   if (*vertex_ref_array == NULL)
   {
     fprintf(stderr, "Erreur: %s\n", strerror(errno));
     return 1;
   }

   /* Lecture des données élémentaires */
   for(int i = 0; i<*nb_elements; i++)
   {
      for(int j = 0; j<*nb_node_per_element; j++)
         {
            fscanf(input, "%d", &((*node_idx_array)[i][j]));
         }

      for(int k = 0; k<*nb_vrtx_per_element; k++)
         {
            fscanf(input, "%d", &((*vertex_ref_array)[i][k]));
         }
   }

   return 0; /* Lecture sans problèmes */
}
