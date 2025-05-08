#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int borne_inf, borne_sup;

    printf("Entrez la borne superieur: \n");
    scanf("%d", &borne_sup);

    printf("Entrez la borne inferieur:\n");
    scanf("%d", &borne_inf);

    if (borne_sup > borne_inf)
    {
        printf("voici le resultat \n");

        while(borne_inf <= borne_sup)
        {
            borne_inf = borne_inf + 1;
            printf("%d \n", borne_inf);
        }


    }
   

    return EXIT_SUCCESS;
}