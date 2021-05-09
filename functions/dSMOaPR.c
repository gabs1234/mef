#include "../headers/tp1.h"
#include "../headers/tp2.h"
#include "../headers/tp3.h"
#include "../headers/forfun.h"
#include "../headers/readNumRef.h"
#include <stdio.h>
#include <stdlib.h>


/*
--------------------------------------------------------------------------------
Procédure calculant les matrices et second membres et assemblant le système
global.
--------------------------------------------------------------------------------
*/


void dSMOaPR(int *Nb_lignes,
             float *SecMembreO,
             int *AdPrCoLiO,
             float *MatriceO,
             int *NumColO,
             int **profil, /* Vecteur contenant l'adresse du premier
                              coefficient non nul */
             float **MatProf)
{
             // Variables morse désordonné auxiliaires
             float *LMatO = MatriceO + *Nb_lignes;
             int NbCoefMax = ((*Nb_lignes)*((*Nb_lignes)+1))/2;

              // Variables Stockage Profile
              *profil = (int*)calloc(*Nb_lignes, sizeof(int)); /* Vecteur contenant l'adresse du premier
                                                                coefficient non nul */
              *MatProf = (float*)calloc((*Nb_lignes)+NbCoefMax, sizeof(float));
  	      float *LMatP = *MatProf + *Nb_lignes;

              // Assembler Stockage Profile
              int iterateur_LMatO = 0;
              int nb_elements_profil = 0;
              int colonne =0;
              
              (*MatProf)[0] = MatriceO[0];

              for(int ligne = 1; ligne < *Nb_lignes; ligne++)
                {
                  (*MatProf)[ligne] = MatriceO[ligne];
                  (*profil)[ligne-1] = nb_elements_profil+1;
                  /* On teste s'il y a des valeurs sur la ligne */
                  if(AdPrCoLiO[ligne-1] == AdPrCoLiO[ligne])
                    {
                      colonne = ligne;
                    }
                  /* Sinon la première valuer à considérer est le numéro de colonne de la première valeur
                     non-nulle sur cette ligne */
                  else
                    {
                      colonne = NumColO[iterateur_LMatO]-1;
                    }
                  
                  /* On parcours toutes les colonnes de la ligne à partir de la première */
                  for(colonne; colonne < ligne; colonne++)
                    {
                      /* Si le numéro de colonne correspond à la prochaine valeur à afficher */
                      if(colonne == NumColO[iterateur_LMatO]-1)
                        {
                          LMatP[nb_elements_profil] = LMatO[iterateur_LMatO];
                          iterateur_LMatO++;
                        }
                      /* Sinon, on ajoute un zéro */
                      else
                        {
                          LMatP[nb_elements_profil] = 0.0;
                        }
                    /* Dans tous les cas, on a ajouté un élément au stockage profil */
                    nb_elements_profil++;
                    }
                }
            (*profil)[(*Nb_lignes)-1] = nb_elements_profil+1;

}
