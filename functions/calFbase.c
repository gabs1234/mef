/*
--------------------------------------------------------------------------------

  Procédure calculant la dérivée des fonctions de base (identiques partout)

  Terminologie :
     "vecteur" : tableau a une dimention

  Arguments d'entree :
     nbeel : entier, nombre de noeuds sur l'élément courant
     *coords : vecteur de flottants, coordonnées du point
                Dimention utile : 2
     *value : vecteur de flottants
               Dimention utile : nbeel
  
  Valeurs de sortie :
     *value : vecteur de flottants, valuer des fonctions de base
               Dimention utile : nbeel

--------------------------------------------------------------------------------
*/
/* Routine initilisant la valeur des n (nombre_nodes) fonctions de base au point de coordonnee coords*/

void calFbase(int type_element, float *coords, float *value)
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
          value[0] = coords[0];
          value[1] = coords[1];
          value[2] = 1 - coords[0] - coords[1];
	  break;
	}
      case 3:
	{
          /* Cas du segment */
          /* coords[0] représente l'abscisse linéaire */
          value[0] = 1 - coords[0];
          value[1] = coords[0];
	  break;
	}
    }
}
