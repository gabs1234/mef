void invert_2x2(float **mat_2x2, float det, float **out_2x2)
{
   out_2x2[0][0] = 1/det*mat_2x2[1][1];
   out_2x2[0][1] = -1/det*mat_2x2[1][0];
   out_2x2[1][0] = -1/det*mat_2x2[0][1];
   out_2x2[1][1] = 1/det*mat_2x2[0][0];
}
