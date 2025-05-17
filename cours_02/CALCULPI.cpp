/* Programme qui calcule une approximation de Pi */
#define _CRT_SECURE_NO_WARNINGS  /* permet de compiler la librairie <stdio.h> */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define  MAX  10000

int main(void)
{  double   terme = 1, pi = 1.0;
   int  compteur;

   for (compteur = 2; compteur <= MAX; ++compteur)  {
       terme = 1.0 / (compteur*compteur);
       pi   += terme;
   }
   pi = sqrt(6*pi);
   printf("pi = %.14lf\n", pi);
   
   system("pause");
   return EXIT_SUCCESS;
}