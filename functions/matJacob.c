/*
--------------------------------------------------------------------------------

  Procédure calculant la matrice jacobienne de la transformation F_K

  Terminologie :
     "vecteur" : tableau à une dimention
     "matrice" : tableau à deux dimention

  Arguments d'entree :
     nbeel : entier, nombre de noeuds sur l'élément courant
     **node_coord : matrice de flottants, coordonnées globales des noeuds de
                    l'element courant
                    Dimention utile : nbeel*2
     **DerValues : matrice de flottants, valeur des dérivées partielles des
                   fonctions de base
                   Dimention utile : nbeel*2
     **output : adresse de la sortie
                Dimention utile : 2*2
  
  Valeurs de sortie :
     **output : matrice jacobienne de la tranformation F_K

--------------------------------------------------------------------------------
*/

void matJacob(int type_element, float **node_coord, float **DerValues, float **output)
   /* Isoparametric case : shape functions tau_i are basis function w_i */
   /* Generic formula : J_ab = sum_i=1^ der(tau_i)/der(x_b).x_ai^K */
{
  switch(type_element)
    {
      case 1:
	{
          break;
	}
      case 2:
	{
          /* Cas du triangle : coordonnées barycentriques */
          output[0][0] = DerValues[0][0]*node_coord[0][0] + DerValues[1][0]*node_coord[1][0] + DerValues[2][0]*node_coord[2][0];
          output[0][1] = DerValues[0][1]*node_coord[0][0] + DerValues[1][1]*node_coord[1][0] + DerValues[2][1]*node_coord[2][0];
          output[1][0] = DerValues[0][0]*node_coord[0][1] + DerValues[1][0]*node_coord[1][1] + DerValues[2][0]*node_coord[2][1];
          output[1][1] = DerValues[0][1]*node_coord[0][1] + DerValues[1][1]*node_coord[1][1] + DerValues[2][1]*node_coord[2][1];
	  break;
	}
      case 3:
	{
          /* Cas du segment */
          /* coords[0] représente l'abscisse linéaire */
          output[0][0] = DerValues[0][0]*node_coord[0][0] + DerValues[1][0]*node_coord[1][0];
          output[1][0] = DerValues[0][0]*node_coord[0][1] + DerValues[1][0]*node_coord[1][1];
	  break;
	}
    }
}
