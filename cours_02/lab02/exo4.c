#include <stdlib.h>
#include <stdio.h>
#define FALSE 0
#define TRUE 1

int estPremier(int n);

int main(void)
{
    int resultat;

    resultat = estPremier(3);
    printf("%d",resultat);

}

int estPremier(int n)
{
    int i = 2;
    int estPremier = TRUE;
    if (n <= 1)
    {
        estPremier =  FALSE;
    }
    while(i < n)
    {
        if (n % i ==0)
        {
            estPremier = FALSE;
        }
                printf("%d \n",i);

        i++;
    }

 printf("\n resultat \n");
   return estPremier;
}