#include<stdlib.h>
#include <stdio.h>
#include<math.h>


/*
--------------------------------------------------------------------------------
    Evaluation de la solution exacte
--------------------------------------------------------------------------------
*/

float solex(float *coor, int nucas)
{
  const float PI=3.141592653589793;
  float val;

  switch (nucas) {
    case 1 :
	val=16.*coor[0]*coor[1]*(1-coor[0])*(1-coor[1]);
	break;
    case 2 :
	val=sin(PI*coor[0])*sin(PI*coor[1]);
	break;
    case 3 :
	val=cos(PI*coor[0])*cos(PI*coor[1]);
	break;
    default :
	printf("*** SOLEX : exemple non prevu. Abandon.\n");
	exit(1);
	break;
  }
  return(val);
}
