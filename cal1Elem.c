#include "tp1.h"
#include "tp2.h"
#include <stdio.h>

/*
--------------------------------------------------------------------------------

  Procédure calculant les intégrales élémentaires de l'élément courant K

  Terminologie :
     "vecteur" : tableau à une dimention
     "matrice" : tableau à deux dimention

  Arguments d'entree :
   nRefDom : entier, numéro de référence des arêtes internes au domaine
   nbRefD0 : nombre de valeurs utiles dans numRefD0
   numRefD0: tableau d'entiers, noeuds appartenant à une arête sur laquelle est définie une condition de Neumann ou Fourrier
   nbRefD1 : nombre de valeurs utiles dans numRefD1
   numRefD1 : tableau d'entiers, noeuds appartenant à une arête sur laquelle est définie une condition de Dirichlet homogène
   nbRefF1 : nombre de valeurs utiles dans numRefF1
   numRefF1 : tableau d'entiers, noeuds appartenant à une arête sur laquelle est définie une condition de Dirichlet inhomogène
   typEl : caractere, type d'élément
   nbeel : entier, nombre de noeuds sur l'élément courant
   **coorEl : matrice de flottants, coordonnées de l'élément
             Dimention utile : nbeel*2
   nbaret : entier, nombre d'arêtes de l'élément
   *nRefArEl : numéros de référence des arrêtes de l'élément (sous-ensemble de nRefAr fourni par lefima)
   **MatElem : matrice élémentaire
   *SMbrElem : second membre élémentaire
   *NuDElem : vecteur d'entiers indexant les noeuds porteurs d'une condition de Dirichlet
             Dimention utile : nbeel
   *uDElem : vecteur contenant la valeur imposée par la condition limite de type Dirichlet
            Dimention utile : nbeel

--------------------------------------------------------------------------------
*/
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
	      int nrefArEl[],
	      float **MatElem,
	      float *SMbrElem,
	      int *NuDElem,
	      float *uDElem)
{

  /* Initilisation des matrice et second membre élémentaire */
    for(int i=0; i < nbeel; i++)
      {
	SMbrElem[i] = 0.0;
	NuDElem[i] = 1;
	uDElem[i] = 0.0;
	for(int j=0; j < nbeel; j++)
	  {
	    MatElem[i][j] = 0.0;
	  }
      }

  /* Calcul des intégrales surfaciques */
    intElem(typEl, nbeel, coorEl, MatElem, SMbrElem);

  /* Prise en compte des conditions limites */
    /* À faire après validation */
}
