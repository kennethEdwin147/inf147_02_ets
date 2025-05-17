#include <stdlib.h>
#include <stdio.h>

int somme2(int n);

int main(void)
{
    int somme = 0;

    somme = somme2(4);
    printf("%d",somme);

}

int somme2(int n)
{
    int i = 1;
    int somme =0;

    while(i <= n)
    {   if(i % 2 ==0)
        {
          somme = somme - (i*i); 
        }
        else
        {
            somme = somme + (i*i); 
        }
        i ++;
    }

    return somme;
}