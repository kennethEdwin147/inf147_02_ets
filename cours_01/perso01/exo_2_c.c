/* 
Trouver et afficher tous les diviseurs d’un entier positif P. Traversez l’intervalle des
entiers allant de 1 à P/2 et alors tout entier dont le reste après division avec P donne
0 est un diviseur.
*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int mon_chiffre;
    int index = 1;

    printf("Entrez votre chiffre:\n");
    scanf("%d", &mon_chiffre);
    printf("Voici le resultat: \n");
    
    while(index <= mon_chiffre/2)
    {
        if(mon_chiffre % index == 0)
        {
            printf("%d \n", index);
        }
        index = index + 1;
    }



    return EXIT_SUCCESS;
}