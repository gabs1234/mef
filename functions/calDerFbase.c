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

void calDerFbase(int nombre_nodes_per_elements, float **value)
{
   /* Cas du triangle : coordonnées barycentriques */
   value[0][0] = 1.0;
   value[0][1] = 0.0;
   value[1][0] = 0.0;
   value[1][1] = 1.0;
   value[2][0] = -1.0;
   value[2][1] = -1.0;
}
