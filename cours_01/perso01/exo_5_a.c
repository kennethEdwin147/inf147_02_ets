/* 
Tester si un entier positif N est premier.
*/
#include <stdlib.h>
#include <stdio.h>
#define FALSE 0
#define TRUE 1
/********************************************************************/
/*                      PROGRAMME PRINCIPAL                         */
/********************************************************************/
int main(void)
{
	int mon_nombre;
	int est_premier = TRUE;

	printf("Entrez votre nombre:\n");
    scanf("%d", &mon_nombre);

	int index = 1;
	while (index < mon_nombre)
	{
		if((mon_nombre % index == 0) && (index != 1))
		{
			est_premier = FALSE;
		}

		index ++;
	}

	if(est_premier == TRUE)
	{
		printf("le nombre: %d est premier :)", mon_nombre);
	}
	else
	{
		printf("le nombre %d n'est pas premier", mon_nombre);
	} 



    
	return EXIT_SUCCESS;
}