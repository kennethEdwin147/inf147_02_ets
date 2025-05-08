/* 
Tester si un entier positif N est premier.
*/
#include <stdlib.h>
#include <stdio.h>

/********************************************************************/
/*                      PROGRAMME PRINCIPAL                         */
/********************************************************************/

/* 
/*  Faire la somme des chiffres d’un entier donné : ex. 5067220 donne 22
*/

int somme_chiffre(int nombre);

int main(void)
{
	int mon_nombre;
    int somme = 0;

	printf("Entrez votre nombre:\n");
    scanf("%d", &mon_nombre);

    somme = somme_chiffre(mon_nombre);
    printf("\n voici la somme %d \n", somme);

	return EXIT_SUCCESS;
}


/* 
    https://www.youtube.com/watch?v=_fHTUj6BzY0
    acceder a un chiffre
    on utilise module % 10 pour acceder au plus petit index
    et ensuite on divise le nombre par "/ 10 "
*/
int somme_chiffre(int nombre)
{
    int somme = 0;
    int chiffre_k;

    while(nombre != 0)
    {
        chiffre_k = nombre % 10;
        somme += chiffre_k;

        nombre = nombre /10;
    }

    return somme;
}