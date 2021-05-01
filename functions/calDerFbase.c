/*
--------------------------------------------------------------------------------

  Procédure calculant la dérivée des fonctions de base (identiques partout)

  Terminologie :
     "matrice" : tableau à deux dimention

  Arguments d'entree :
     nbeel : entier, nombre de noeuds sur l'élément courant
     **value : matrice de flottants
               Dimention utile : nbeel*2
  
  Valeurs de sortie :
     **value : matrice de flottants, dérivée des fonctions de base
               Dimention utile : nbeel*2

--------------------------------------------------------------------------------
*/

void calDerFbase(int type_element, float **value)
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
          value[0][0] = 1.0;
          value[0][1] = 0.0;
          value[1][0] = 0.0;
          value[1][1] = 1.0;
          value[2][0] = -1.0;
          value[2][1] = -1.0;
	  break;
	}
      case 3:
	{
          /* Cas du segment */
          /* coords[0] représente l'abscisse linéaire */
          value[0][0] = -1.0;
          value[1][0] = 1.0;
	  break;
	}
    }
}
