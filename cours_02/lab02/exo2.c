/* 

2. Faites la fonction « int somme(int n); » qui calcule la somme des chiffres d’un nombre.
Par exemple, somme(124)→ 1 + 2 + 4 = 7. Ou encore, somme(79001)→ 7 + 9 + 0 + 0 + 1.
➔ Ensuite, tracez cette fonction avec n = 254 en utilisant le débogueur du Visual-C.

*/

#include <stdlib.h>
#include <stdio.h>

int somme(int nombre);

int main(void)
{
    int nb = 124;

   printf("%d", somme(nb));

    return EXIT_SUCCESS;
}

int somme(int nombre)
{
    int digit;
    int somme = 0;

    while(nombre !=0)
    {
        digit = nombre % 10;
        somme += digit;

        nombre = nombre/10; 
    }


    return somme;
}