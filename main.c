#include "headers/actions.h"
#include "headers/forfun.h"
#include "headers/tp1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
--------------------------------------------------------------------------------
Programme principal, sélection d'une action à effectuer.
--------------------------------------------------------------------------------
*/


void main(int argc, char const *argv[])
{
  int choice;

  if (argc <= 1) {
    printf("La fonction attend le nom du fichier de maillage\n");
    exit(0);
  }

  /* FILENAMES */
  char mesh_file_name[strlen(argv[1])];
  strcpy(mesh_file_name, argv[1]);
  char ref_file_name[] = "NUMREF1.Test";
  char SMD_save_name[] = "saves/SAVE_SMD";
  char SMO_save_name[] = "saves/SAVE_SMO";

  /* DONNÉES GÉNÉRALES */
  int Nb_lignes;
  float **node_coord_array;

  /* DONNÉES SMD */
  int SMD_data = 0; /* Vrai si des données SMD ont été initialisées */
  float *SecMembre;
  int *NumDLDir;
  float *ValDLDir;
  int *AdPrCoefLi;
  float *Matrice;
  int *AdSuccLi;
  int *NumCol;


  /* DONNÉES SMO */
  int SMO_data = 0; /* Vrai si des données SMO ont été initialisées */
  float *SecMembreO;
  int *AdPrCoLiO;
  float *MatriceO;
  int *NumColO;

  /* DONNÉES PROFIL */
  int profil_data = 0;
  int *profil; /* Vecteur contenant l'adresse du premier
                  coefficient non nul */
  float *MatProf;

  LOOP:
  printf("\n===== Choisissez une action à effectuer =====\n");
  printf("1.  Assemblage du système linéaire\n");
  printf("2.  Affichage du système morse désordonné\n");
  printf("3.  Sauvegarde du système morse désordonné\n");
  printf("4.  Lecture du système morse désordonné\n\n");
  printf("5.  Création du système morse ordonné\n");
  printf("6.  Affichage du système morse ordonné\n");
  printf("7.  Sauvegarde du système morse ordonné\n");
  printf("8.  Lecture du système morse ordonné\n\n");
  printf("9.  Création du système profil\n");
  printf("10. Affichage du système profil\n");
  printf("11. Résolution du système et affichage des solutions\n");
  printf("12. Quitter\n\n");
  scanf("%d", &choice);


  switch(choice)
    {

      case 1:
	{
          printf("Assemblage du système\n");
          build(mesh_file_name,
                ref_file_name,
                &Nb_lignes,
                &Matrice,
                &AdPrCoefLi,
                &AdSuccLi,
                &NumCol,
                &SecMembre,
                &NumDLDir,
                &ValDLDir,
                &node_coord_array);
          SMD_data = 1; /* Données SMD disponibles */
          break;
	}

      case 2:
	{
          printf("Affichage du système morse désordonné\n");
          if(SMD_data)
            {
              /* Impression de la matrice */
              affsmd_(&Nb_lignes,
                      AdPrCoefLi,
                      NumCol,
                      AdSuccLi,
                      Matrice,
                      SecMembre,
                      NumDLDir,
                      ValDLDir);
            }
           else
            {
              printf("Pas de données à écrire\n");
            }
	  break;
        }

      case 3:
	{
          printf("Écriture du stockage morse déordonné.\n");
          if(SMD_data)
            {
              /* Écriture du fichier */
              EcrSMD(SMD_save_name,
                     &Nb_lignes,
                     SecMembre,
                     NumDLDir,
                     ValDLDir,
                     AdPrCoefLi,
                     Matrice,
                     NumCol,
                     AdSuccLi);
            }
           else
            {
              printf("Pas de données SMD à afficher\n");
            }
	  break;
        }

      case 4:
	{
          printf("Lecture du stockage morse désordonné.\n");
          /* Tentative de lecture des données */
          SMD_data = LecSMD(SMD_save_name,
                            &Nb_lignes,
                            &SecMembre,
                            &NumDLDir,
                            &ValDLDir,
                            &AdPrCoefLi,
                            &Matrice,
                            &AdSuccLi,
                            &NumCol);
          if(SMD_data)
            {
              printf("La récupération de donnée SMD est un succès\n");
            }
           else
            {
              printf("Échec de la lecture des données\n");
            }
	  break;
	}

      case 5:
	{
          printf("Construction et sauvegarde du stockage morse ordonné.\n");
          if(SMD_data)
            {
              /* Assemblage du système SMO */
              int Nb_coef = AdPrCoefLi[Nb_lignes-1]-1;  /* Variable SMD supplémentaire */

              /* Initialisation des variables SMO */
              SecMembreO = (float*)(calloc(Nb_lignes, sizeof(float)));
              AdPrCoLiO = (int*)(calloc(Nb_lignes, sizeof(int)));
              MatriceO = (float*)(calloc(Nb_lignes+Nb_coef, sizeof(float)));
              NumColO = (int*)(calloc(Nb_coef, sizeof(int)));

              /* Construction du sytème */
              cdesse_(&Nb_lignes,
                      AdPrCoefLi,
                      NumCol,
                      AdSuccLi,
                      Matrice,
                      SecMembre,
                      NumDLDir,
                      ValDLDir,
                      AdPrCoLiO,
                      NumColO,
                      MatriceO,
                      SecMembreO);

              SMO_data = 1; /* Données SMO disponibles */
            }
          else
            {
              printf("Pas de données SMD pour construire le SMO !\n");
            }
          break;
	}

      case 6:
        {
          if(SMO_data)
            {
              /* Impression des matrices */
              affsmo_(&Nb_lignes,
                      AdPrCoLiO,
                      NumColO,
                      MatriceO,
                      SecMembreO);
            }
           else
            {
              printf("Pas de données SMO à afficher !\n");
            }
	  break;
        }

      case 7:
        {
          if(SMO_data)
            {
              /* Écriture du fichier */
              EcrSMO(SMO_save_name,
                     Nb_lignes,
                     SecMembreO,
                     AdPrCoLiO,
                     MatriceO,
                     NumColO);
            }
           else
            {
              printf("Pas de données SMO à afficher !\n");
            }
	  break;
        }

      case 8:
	{
          printf("Lecture du stockage morse ordonné.\n");
          /* Tentative de lecture des données */
          SMO_data = LecSMO(SMO_save_name,
                            &Nb_lignes,
                            &SecMembreO,
                            &AdPrCoLiO,
                            &MatriceO,
                            &NumColO);
          if(SMO_data)
            {
              printf("La récupération de donnée SMO est un succès\n");
            }
           else
            {
              printf("Échec de la lecture des données\n");
            }
	  break;
	}

      case 9:
        {
          if(SMO_data)
            {
              printf("Création du sytème profil\n");
              dSMOaPR(&Nb_lignes,
                      SecMembreO,
                      AdPrCoLiO,
                      MatriceO,
                      NumColO,
                      &profil,
                      &MatProf);

            profil_data = 1;
            }
          else
            {
              printf("Impossible, le programme n'a aucun SMO en mémoire.\n");
            }
          break;
        }

      case 10:
	{
          printf("Affichage du système profil\n");
          if(profil_data)
            {
              int nb_elements_profil = profil[Nb_lignes-1]-1;

              /* Impression des vecteurs profil à des fins de test */
              printf("Impression des vecteurs profil\n");
              printf("Le nombre de lignes est %d\n", Nb_lignes);
              printf("Le nombre d'éléments profil est %d\n", nb_elements_profil);
              for(int z = 0; z < Nb_lignes+nb_elements_profil; z++){printf("MatP[%d] : %f\n", z, MatProf[z]);}
              for(int z = 0; z < Nb_lignes; z++){printf("Prof[%d] : %d\n", z, profil[z]);}
            }
           else
            {
              printf("Pas de données profil à écrire\n");
            }
	  break;
        }

      case 11:
	{
          printf("Résolution du système\n");
          if(profil_data)
            {
              int nb_elements_profil = profil[Nb_lignes-1]-1;
 	      float *LMatP = MatProf + Nb_lignes;

              /* Variables décomposition LLT */
              float diagL[Nb_lignes];
              float lowerL[nb_elements_profil];
              float *Y = (float*)calloc(Nb_lignes, sizeof(float));
              float *X = (float*)calloc(Nb_lignes, sizeof(float));
              float eps = 0.0001;
 
              /* Résolution */
              ltlpr_(&Nb_lignes, profil, MatProf, LMatP, &eps, diagL, lowerL);
              rsprl_(&Nb_lignes, profil, diagL, lowerL, SecMembreO, Y);
              rspru_(&Nb_lignes, profil, diagL, lowerL, Y, X);

              /* Si l'on a pas récupéré de données SMD à cette session,
                 le tableau node_coord_array est vide */
              if(!SMD_data)
                {
                  /* Variables du fichier de maillage */
                  int element_type;
                  int nb_nodes;
                  int nb_elements;
                  int **node_idx_array;
                  int nb_node_per_element;
                  int nb_vrtx_per_element;
                  int **vertex_ref_array;
                  if(readMeshFile(mesh_file_name,
                                  &element_type,
                                  &nb_nodes,
                                  &node_coord_array,
                                  &nb_elements,
                                  &node_idx_array,
                                  &nb_node_per_element,
                                  &nb_vrtx_per_element,
                                  &vertex_ref_array))
                      {
                        printf("Malfonction de la fonction readMeshFile !\n");
                        exit(1);
                      }
                    else {printf("Le fichier de maillage a été lu avec succès !\n");}
                }

              /* Production des résultats */
              int nucas = 1;
              float UEX[Nb_lignes];
              printf("Le nombre de lignes est %i\n", Nb_lignes);
              CalSol(Nb_lignes, node_coord_array, &UEX, nucas);

              int file_int = 0;
              affsol_(&Nb_lignes, *node_coord_array, X, UEX, &file_int);

              /* Impression dans un fichier de la solution */
              FILE *output_result = fopen("results/output_t64_5.dat", "w+");
              for (int k = 0; k < Nb_lignes; k++)
                {
                  fprintf(output_result, "%f\t%f\t%f\t%f\n", node_coord_array[k][0], node_coord_array[k][1], X[k], UEX[k]);
                }

            }
           else
            {
              printf("Pas de données profil pour la résolution\n");
            }
	  break;
        }

      case 12:
	{
          exit(0);
	  break;
	}
    }

    goto LOOP;
}
