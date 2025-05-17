#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int valeur_bin(int nbin);

int main(void)
{
    int valeur_decimale;
    valeur_decimale = valeur_bin(1101);
    printf("%d", valeur_decimale);
    
    return EXIT_SUCCESS;
}

int valeur_bin(int nbin)
{
    int valeur_decimale = 0;
    int index = 0;
    int digit;

    while(nbin !=0)
    {
        digit = nbin % 10;

        if(digit == 1)
        {
            valeur_decimale += pow(2, index);
        }
        nbin = nbin /10;

        index++;
    }
    return valeur_decimale;
}