/* 
Faire la somme des entiers dans un intervalle. Faites un programme qui demande
les deux bornes. Si la borne supérieure est plus grande que la borne inférieure, on
affiche la somme de toutes les valeurs entre ces 2 bornes.
*/
#include <stdlib.h>
#include <stdio.h>

/********************************************************************/
/*                      PROGRAMME PRINCIPAL                         */
/********************************************************************/
int main(void)
{
	int nb_diviseur = 0;
	int mon_nombre;


	printf("Entrez votre chiffre:\n");
    scanf("%d", &mon_nombre);

	int index = 1;
	while (index <= mon_nombre)
	{
		if(mon_nombre %index == 0)
		{
			nb_diviseur = nb_diviseur + 1;
		}
		index = index +1;
	}

    
	printf("\n nombre de diviseur: %d \n", nb_diviseur);
	return EXIT_SUCCESS;
}