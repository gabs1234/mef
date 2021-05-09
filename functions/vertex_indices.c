/* Routine renvoyant le couple de numéros (locaux) des noeuds situés su
   l'arête de numéro 'n', sur l'élément de type 't'. */

void vertex_indices(int n, int element_type, int *nodeOne, int 
*nodeTwo);
{

   &nodeOne = n;

   if(element_type){&nodeTwo = (n+1)%3;} /* Element triangulaire */
   else{&nodeTwo = (n+1)%4;}
}
