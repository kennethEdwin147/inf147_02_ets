/* 
   SIZEOF.C
   Programme qui affiche les tailles en octets des types de base en C. 
   Ce programme démontre comment utiliser la fonction "sizeof()".    
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void)
{  char  nom[32];      /* tableau de 32 caractères */
   float nombres[9];   /* tableau de 9 réels simple-précision */

   printf("Nombre d'octets associes a chacun des types de base...\n\n");
   printf("int      ==> %d		long          ==> %d\n",
		   sizeof(int), sizeof(long));
   printf("unsigned ==> %d		unsigned long ==> %d\n",
		   sizeof(unsigned), sizeof(unsigned long));
   printf("char     ==> %d		unsigned char ==> %d\n",
		   sizeof(char), sizeof(unsigned char));
   printf("float    ==> %d		double        ==> %d\n",
		   sizeof(float), sizeof(double));
   printf("void     ==> %d\n\n\n", 0);  /* sizeof(void) est interdit! */

	 /* on affiche la dimension des 2 tableaux */
   printf("char  nom[32]    ==> %d\n", sizeof(nom));
   printf("float nombres[9] ==> %d\n\n\n", sizeof(nombres));

   system("pause");
   return EXIT_SUCCESS;
}