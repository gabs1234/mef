#include "../headers/tp1.h"
#include "../headers/tp2.h"
#include "../headers/functions.h"
#include <stdio.h>

/*
--------------------------------------------------------------------------------

  Procédure calculant les intégrales élémentaires de l'élément courant K

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
void intElem(
	     int typEl,
	     int nbeel,
	     float **coorEl,
	     float **MatElem,
	     float *SMbrElem)
{
  /* Initialisation des points de quadrature */
  int nb_quad_point;
  if(typEl == 1){nb_quad_point = 9;}
  else{nb_quad_point = 3;}

  float weights[nb_quad_point];
  float **quad_coords;
  quad_coords = alloctab_float(nb_quad_point,2);

  ppquad(typEl, weights, quad_coords);

  /* Calcul de l'element differentiel */

  float **DerFBase;
  DerFBase = alloctab_float(nbeel,2);
  calDerFbase(typEl,DerFBase);

  float **JFK;
  JFK = alloctab_float(2,2);
  matJacob(typEl, coorEl, DerFBase, JFK);

  float eltdif;
  det_2x2(JFK, &eltdif);

  /* Boucle sur les points de quadrature */
  for(int w = 0; w < nb_quad_point; w++)
    {
      /* Calcul de la valeur des fonctions de base sur les points de quadrature */
      float Fbase[nbeel];
      calFbase(typEl, quad_coords[w], Fbase);

      float node_coords[] = {0.0,0.0};
      transFK(typEl, coorEl, quad_coords[w], node_coords);

      W(nbeel,
        Fbase,
        eltdif*weights[w],
        FOMEGA(node_coords[0],node_coords[1]),
        SMbrElem);

      WW(nbeel,
         Fbase,
         eltdif*weights[w],
         A00(node_coords[0],node_coords[1]),
         MatElem);

     float **cofvar;
     cofvar = alloctab_float(2,2);
     cofvar[0][0] = A11(node_coords[0],node_coords[1]);
     cofvar[0][1] = A12(node_coords[0],node_coords[1]);
     cofvar[1][0] = A12(node_coords[0],node_coords[1]);
     cofvar[1][1] = A22(node_coords[0],node_coords[1]);

     float **invJFK;
     invJFK = alloctab_float(2,2);
     invert_2x2(JFK, eltdif, invJFK);

     ADWDW(nbeel,
         invJFK,
         DerFBase,
         eltdif*weights[w],
         cofvar,
         MatElem);
    }
}
