/* Calcule l'image d'un point de référence par la transformation Fk */


void transFK(int element_type, float **nodes, float **coord, float **point)
{
  switch(element_type)
    {
    case 1  /* Cas quadrangulaire */
	{
	  point[0] = (nodes[0][0]-nodes[3][0])*coord[0] + nodes[3][0];
	  point[1] = (nodes[2][1]-nodes[3][1])*coord[1] + nodes[3][1];
	}
    case 2 /* Cas triangulaire */
	{
	  point[0] = (nodes[0][0]-nodes[2][0])*coord[0] + (nodes[1][0]-nodes[2][0])*coord[1] + nodes[2][0];
	  point[1] = (nodes[0][1]-nodes[2][1])*coord[0] + (nodes[1][1]-nodes[2][1])*coord[1] + nodes[2][1];
	  break;
	}
    case 3 /* Cas segment */
	{
	  point[0] = (nodes[1][0]-nodes[0][0])*coord[0] + nodes[1][0];
	  point[1] = (nodes[1][1]-nodes[1][1])*coord[1] + nodes[1][1];
	  break;
	}
}
