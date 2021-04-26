/* Fonction renvoyant la référence des noeuds locaux d'une arrête de numéro de référence */

/* refnodes tableau de taille 2*/

void numNaret(int refAret, int nb_node_per_element, int *refNodes)
{
  refNodes[0] = refAret;
  refNodes[1] = refAret + 1 % nb_node_per_element; 
}
