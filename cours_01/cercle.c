/* 
   CERCLE.C
   Exemple d'affichage avec printf() avec formats et mise-en-forme 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define PI  3.141592653589793     /* D�finir une constante */

int  main(void)
{  double  rayon;		/* le rayon d'un cercle, type r�el double-pr�cision */

   system("cls");		/* effacer l'�cran */   

   printf("\n%s\n\n%s",
	        "Ce programme calcule la surface d'un cercle.",
	        "Entrez le rayon du cercle: ");

   /* saisie de la valeur du rayon */
   scanf("%lf", &rayon);   

   /* affichage des formules utilis�es et de la r�ponse */
   printf("\n%s\n%s %.2f %s %.2f %s %.2f\n%s %.5f\n\n",
	        "Surface = PI * rayon * rayon",
	        "        =", PI, "*", rayon, "*", rayon,
	        "        =", PI * rayon * rayon);

   system("pause");        /* pause-�cran */
   return EXIT_SUCCESS;
}
