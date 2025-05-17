/********************************************************************/
/* Fichier    : PASSAGE PAR VALEUR.C                                */
/* References : Philippe Drix, chapitre IX - 7                      */
/*              Harbison & Steele, chapitre 7.4.3                   */
/*                                                                  */
/* Objectifs : Ce programme a pour objectif de presenter le passage */
/*             par valeur.                                          */
/*                                                                  */
/* Il touche aux notions suivantes :                                */
/*    - Passage par valeur (Drix, chapitre IX)                      */
/********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>


/********************************************************************/
/*                 DECLARATION DE LA FONCTION                       */
/********************************************************************/
void fonction_quelconque(int x);
/* Cette fonction affiche la valeur qu'elle a recu, l'incremente et	*/
/* l'affiche a nouveau.                                             */
/* PARAMETRE :                                                      */
/*	- x : La valeur a afficher, incrementer et afficher de nouveau.	*/


/********************************************************************/
/*                      PROGRAMME PRINCIPAL                         */
/********************************************************************/
int main(void)
{	int x = 0;

	printf("main(): Adresse de x AVANT l'appel : %x\n", &x);   //"%x" = hexadécimal
	printf("main(): contenu de x AVANT l'appel : %i\n\n", x);

	fonction_quelconque(x);

	printf("\nmain(): Adresse de x APRES l'appel : %x\n", &x);  //"%x" = hexadécimal
	printf("main(): contenu de x APRES l'appel : %i\n", x);

	/* NDE : On remarque que la variable x dans le main() n'est pas	*/
	/*		 la meme que la variabale x dans la fonction puisque	*/
	/*		 l'adresse affichée dans la fonction n'est pas la même!	*/

	system("pause");
	return EXIT_SUCCESS;
}


/********************************************************************/
/*                   DEFINITION DE LA FONCTION                      */
/********************************************************************/
void fonction_quelconque(int x)
{
	printf("  fonction_quelconque : adresse de x : %x\n", &x);   //"%x" = hexadécimal
	printf("  fonction_quelconque : contenu du x au debut de la fonction : %i\n", x);

	++x;

	printf("  fonction_quelconque : contenu du x a la fin de la fonction : %i\n", x);
}