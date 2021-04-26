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

  int l; /* variable pour itérer */
  int p[2]; /* variables pour contenir la référence des noeuds d'une arête */

    for(int k = 0; k < nbaret; k++) /* On boucle sur les arêtes */
    {
       /* On boucle sur les conditions de dirichlet homogènes */
       for(l= 0; l < nbRefD0; l++)
       {
          if(numRefD0[l]==nrefArEl[k])
          {
             printf("&&&& HELLO THERE !!!");
             printf("Noeuds de l'arrête %d égaux à 0\n", k);
             numNaret(k, nbeel, p);
             printf("Les id des noeuds associés à l'arête %d sont %d et %d\n",k,p[0],p[1]);
             NuDElem[p[0]] = 0;
             NuDElem[p[1]] = 0;
          }
       }
       /* On boucle sur les conditions de dirichlet inhomogènes */
       for(l= 0; l < nbRefD1; l++)
       { 
          if(numRefD1[l]==nrefArEl[k])
          {
             printf("&&&& HELLO THERE !!!");
             printf("Noeuds de l'arrête %d égaux à -1\n", k);
             numNaret(k, nbeel, p);
             printf("Les id des noeuds associés à l'arête %d sont %d et %d\n",k,p[0],p[1]);
             NuDElem[p[0]] = -1;
             NuDElem[p[1]] = -1;
             uDElem[p[0]] = UD(coorEl[p[0]][0],coorEl[p[0]][1]);
             uDElem[p[1]] = UD(coorEl[p[1]][0],coorEl[p[1]][1]);
          }
       }
    }
}
