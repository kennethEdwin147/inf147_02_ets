/* 
f) Itérer la somme des digits de N jusqu’à l’invariance : N = 156773 → 29 → 11 → 2→ 2

*/
#include <stdio.h>
#include <stdlib.h>

int somme_des_chiffres(int nombre);

int main(void)
{
	int mon_nombre;

	printf("Entrez votre nombre:\n");
    scanf("%d", &mon_nombre);

    while(mon_nombre >= 10)
    {
        mon_nombre = somme_des_chiffres(mon_nombre);
        printf("%d->", mon_nombre);
    }

	return EXIT_SUCCESS;
}


/* 
    https://www.youtube.com/watch?v=_fHTUj6BzY0
    acceder a un chiffre
    on utilise module % 10 pour acceder au plus petit index
    et ensuite on divise le nombre par "/ 10 "
*/
int somme_des_chiffres(int nombre)
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