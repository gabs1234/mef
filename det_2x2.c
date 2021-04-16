void det_2x2(float **mat_2x2, float *det)
{
   *det = mat_2x2[0][0]*mat_2x2[1][1]-mat_2x2[0][1]*mat_2x2[1][0];
}
