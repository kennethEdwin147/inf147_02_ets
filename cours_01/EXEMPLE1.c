/*
   EXEMPLE1.C
   Programme qui illustre la lecture et �criture de donn�es avec
   printf() et scanf() 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>        /* pour printf() et scanf()  */
#include <stdlib.h>       /* pour la fonction system() */

int main(void)
{  int a,			/* premier nombre */
       b,			/* deuxi�me nombre */
       somme;       /* sommme des 2 nombres */

   system("cls");         /* effacer l'�cran */

   /* Saisie des 2 nombres */
   printf("Entrez deux nombres : ");
   scanf("%d", &a);
   scanf("%d", &b);

   /* Calcul et affichage de la somme */
   somme = a + b;
   printf("La somme de %d + %d = %d\n", a, b, somme);

   system("pause");       /* attendre qu'une touche soit pes� */
   return EXIT_SUCCESS;
}