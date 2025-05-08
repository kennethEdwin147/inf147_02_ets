/* Pour tester les valeurs de retour des fonctions printf et scanf. */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{ int a, b, c, test;

	system("cls");
	printf("\n%d", a = 3 + 5/4);

	/* tester la valeur de retour d'un "printf()" */
	test = printf("\n allo");
	printf("\nRetourne %d\n\n", test);

	/* tester la valeur de retour d'un "scanf()" */
	test = scanf("%d%d%d", &a, &b, &c);
	printf("\nRetourne %d\n", test);
	printf("\n a= %d,  b= %d, c = %d", a, b, c);

	system("pause");
	return 0;
}
