/********************************************************************/
/* Fichier    : Exemples de conversions.c                           */
/* References : Philippe Drix, chapitre IV-10                       */
/*              Harbison & Steele, chapitre 6.2                     */
/*                                                                  */
/* Objectifs : Ce programme a pour objectif de presenter les        */
/*             conversions de types numériques.                     */
/*                                                                  */
/* Il touche aux notions suivantes :                                */
/*     - Conversion de type (Drix, chapitre IV-10)                  */
/********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/********************************************************************/
/*               DEFINITIONS DE MACROS-CONSTANTES                   */
/********************************************************************/
#define EPSILON 0.99999998		 /* Gere l'erreur sur la precision. */

/********************************************************************/
/*                DEFINITIONS DE MACRO-FONCTIONS                    */
/********************************************************************/
/* Si x est pres d'un nombre naturel, il ne changera pas. */
/* Sinon, il prendra la valeur du naturel superieur.      */
#define PLAFOND(x)  (long int)((x) + EPSILON)

/* On laisse tomber les decimales.	*/
#define PLANCHER(x) (long int)(x)

/* Soit n le naturel le plus grand inferieur a x.	*/
/*     n   <=  x  <  n + 0.5  -->  (long int) (x + 0.5) == n.     */
/* n + 0.5 <=  x  <  n + 1.0  -->  (long int) (x + 0.5) == n + 1. */
#define ARRONDI(x)  (long int)((x) + 0.5)


/********************************************************************/
/*                      PROGRAMME PRINCIPAL                         */
/********************************************************************/
int main(void)
{
	double reel = 25.5;		/* Pour tester avec des reels. */
	int    entier = 10;		/* Pour tester avec des entiers. */

	printf("Nombre reel   : %.2f\n", reel);
	printf("Nombre entier : %i\n", entier);

	printf("Conversion de reel en entier : %i\n", (int) reel);
	printf("Conversion d'entier en reel  : %.2f\n", (double) entier);

	printf("Plancher de reel  : %li\n", PLANCHER(reel));
	printf("Plafond de reel   : %li\n", PLAFOND(reel));
	printf("Arrondi de reel   : %li\n", ARRONDI(reel));
	printf("Arrondi de reel - 0.1 : %li\n", ARRONDI(reel - 0.1));
	printf("Arrondi de reel + 0.1 : %li\n", ARRONDI(reel + 0.1));

	system("pause");
	return EXIT_SUCCESS;
}
