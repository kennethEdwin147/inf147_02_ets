/*
 * Programme qui calcule la moyenne des données saisies
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{ int          next;               /* prochaine valeur à lire */
  int          somme;              /* total à date*/
  unsigned int n;                  /* nombre de valeurs */
  int          result;             /* avons nous bien lu une valeur? */
  double       moy;                /* moyenne des valeurs lues */

  somme = 0;
  n = 0;
  while ((result = scanf("%i", &next)) == 1)
  {
    somme = somme + next;
    n = n + 1;
  }

  if (result != EOF)
    printf("Warning: bad input after reading %u values\n", n);

  if (n == 0)
    moy = 0.0;
  else
    moy = (double)(somme / n);     /* COMMENT FAIRE POUR AVOIR LE BON CALCUL? */         

  printf("Average of %u values is %f.\n", n, moy);

  system("pause");
  return EXIT_SUCCESS;
}
