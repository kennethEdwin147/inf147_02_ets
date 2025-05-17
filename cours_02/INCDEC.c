/* Exercice pour illustrer le comportement des opérateurs ++, -- */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{  int  a = 1, i = 1;

   a += i++;
   printf(" apres a += i++ ... \n");
   printf(" a = %d i = %d \n\n", a, i);

   a=i=1;
   a += ++i;
   printf(" apres a += ++i ... \n");
   printf(" a = %d i = %d \n\n", a, i);

   a=i=1;
   a += i--;
   printf(" apres a += i-- ... \n");
   printf(" a = %d i = %d \n\n", a, i);

   a=i=1;
   a += --i;
   printf(" apres a += --i ... \n");
   printf(" a = %d i = %d \n", a, i);

   system("pause");
   return EXIT_SUCCESS;
}