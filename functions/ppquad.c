#include <stdio.h>

/* Fonction renvoyant le schéma de quadrature */


void ppquad(int element_type, float *weights, float **coords)
{
  switch(element_type)
    {
      case 1:
	{
          /* Cas du quadrangle */
	  float w1 = 1.0/36.0;
	  float w2 = 1.0/9.0;
	  float w3 = 4.0/9.0;

          weights[0] = w1;
          weights[1] = w1;
          weights[2] = w1;
          weights[3] = w1;
          weights[4] = w1;
          weights[5] = w1;
          weights[6] = w1;
          weights[7] = w1;
          weights[8] = w1;

	  coords[0][0] = 1;
          coords[0][1] = 0;
	  coords[1][0] = 1;
          coords[1][1] = 1;
	  coords[2][0] = 0;
          coords[2][1] = 1;
	  coords[3][0] = 0;
          coords[3][1] = 0;
	  coords[4][0] = 1;
          coords[4][1] = 1.0;
	  coords[5][0] = 0.5;
          coords[5][1] = 0.5;
	  coords[6][0] = 1;
          coords[6][1] = 0;
	  coords[7][0] = 0.5;
          coords[7][1] = 0;
	  coords[8][0] = 0.5;
          coords[8][1] = 0.5;
	  break;
	}
      case 2:
	{
          /* Cas du triangle */
	  float w = 1.0/6.0;

          weights[0] = w;
          weights[1] = w;
          weights[2] = w;

	  coords[0][0] = 0.5;
          coords[0][1] = 0.5;
	  coords[1][0] = 0;
          coords[1][1] = 0.5;
	  coords[2][0] = 0.5;
          coords[2][1] = 0;
	  break;
	}
      case 3:
	{
          /* Cas du segment */
	  float w1 = 1.0/6.0;
	  float w2 = 2.0/3.0;

          weights[0] = w1;
          weights[1] = w1;
          weights[2] = w2;

	  coords[0][0] = 1;
          coords[0][1] = 0;
	  coords[1][0] = 0;
          coords[1][1] = 0;
	  coords[2][0] = 0.5;
          coords[2][1] = 0;
	  break;
	}
    }
}
