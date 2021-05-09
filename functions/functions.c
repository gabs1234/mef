#include <math.h>

/*  Fonctions définissant le problème
    les valeurs sont définies temporairement */

    float pi = 3.141592653589793;

float A11(float x, float y){
    return 1.0;
    }

float A22(float x, float y){
    return 1.0;
    }

float A12(float x, float y){
    return 0.0;
    }

float A00(float x, float y){
    return 0.0;
    }

float BN(float x, float y){
    return 0.0;
    }

float FOMEGA(float x, float y){

    return /*2*pi*pi*sin(pi*x)*sin(pi*y)*/ -32*(x*x-x+y*y-y); /*(2*pi*pi+1)*cos(pi*x)*cos(pi*y)*/;
    }

float FN(float x, float y){
    return /*-pi*(sin(pi*x)*cos(pi*y)+cos(pi*x)*sin(pi*y))*/ 0.0;
    }

float UD(float x, float y){
    return /*sin(pi*x)*sin(pi*y)*/16*x*y*(1-x)*(1-y)/*cos(pi*x)*cos(pi*y)*/;
    }
