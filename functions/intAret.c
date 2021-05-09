#include "../headers/tp1.h"
#include "../headers/tp2.h"
#include "../headers/functions.h"
#include <math.h>
#include <stdio.h>

/*
--------------------------------------------------------------------------------

  Procédure calculant les intégrales élémentaires de l'élément courant K
  (passage sur les arêtes)

  Terminologie :
     "vecteur" : tableau à une dimention
     "matrice" : tableau à deux dimention

  Arguments d'entree :

   typEl : caractere, type d'élément
   nbeel : entier, nombre de noeuds sur l'élément courant
   **coorEl : matrice de flottants, coordonnées de l'élément
             Dimention utile : nbeel*2
   **MatElem : matrice élémentaire
   *SMbrElem : second membre élémentaire

--------------------------------------------------------------------------------
*/
void intAret(int typEl,
             int *locNod,
             int nbeel,
	     float **coorAret,
	     float **MatElem,
	     float *SMbrElem)
{
  /* Initialisation des points de quadrature */
  int nb_quad_point = 3; /* Trois points de quadrature dans tous les cas pour un segment 
                            (ça n'est pas très ergonomique, il faudrait le remplacer par une
                             constante) */

  float weights[nb_quad_point];
  float **quad_coords = alloctab_float(nb_quad_point,1); /* Dans le cas du segment, on travaille en 1D,
                                                       mais pour la cohérence de l'interface il faut
                                                       quand même un tableau 2D */

  /* Segment élément de type '3' */
  ppquad(3, weights, quad_coords);


  /* Calcul de l'element differentiel */

  float **DerFBase;
  DerFBase = alloctab_float(2,1); /* Nombre de fonctions de base*dimention */
  calDerFbase(3,DerFBase);

  float **JFK;
  JFK = alloctab_float(2,1);
  matJacob(3, coorAret, DerFBase, JFK);

  /* Dans le cas monodimentionnel, l'élément différentiel est la norme
     euclidienne du vecteur résultat. */
  float eltdif = 1; sqrt((JFK[0][0])*(JFK[0][0]) + (JFK[1][0])*(JFK[0][0]));

  /* Boucle sur les points de quadrature du segment */
  for(int w = 0; w < nb_quad_point; w++)
    {
      /* Calcul de la valeur des fonctions de base sur les points de quadrature */
      float FbaseAret[2]; /* Deux fonctions de base sur le segment */
      calFbase(3, quad_coords[w], FbaseAret); /* On appelle calFbase pour le segment */

      float Fbase[nbeel];
      for(int z = 0; z < nbeel; z++){Fbase[z] = 0.0;}
      Fbase[locNod[0]]=FbaseAret[0];
      Fbase[locNod[1]]=FbaseAret[1];

      float node_coords[] = {0.0,0.0};
      transFK(3, coorAret, quad_coords[w], node_coords);

      W(nbeel,
        Fbase,
        eltdif*weights[w],
        FN(node_coords[0],node_coords[1]),
        SMbrElem);

      WW(nbeel,
         Fbase,
         eltdif*weights[w],
         BN(node_coords[0],node_coords[1]),
         MatElem);
    }
}
