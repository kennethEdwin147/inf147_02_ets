/********************************************************************/
/* Fichier    : #DEFINE MACRO.C                                     */
/* References : Philippe Drix, chapitre VI-1 et VII                 */
/*	            Harbison & Steele, chapitre 3.3                     */
/*                                                                  */
/* Objectifs : Ce programme a pour objectif d'introduire le         */
/*			   preprocesseur, plus precisement le #define.          */
/*                                                                  */
/* A noter : NDE signifie "Note de l'enseignant" et souligne les    */
/*			 commentaires qui ne devraient pas faire normalement    */
/*			 partie du code (outre des raisons pedagogiques).       */
/*                                                                  */
/* Il touche aux notions suivantes :                                */
/*		- #define (Drix, chapitre VI-1)                             */
/********************************************************************/
#define _CRT_SECURE_NO_WARNINGS  /* permet de compiler la librairie <stdio.h> */
#include <stdio.h>
#include <stdlib.h>


/********************************************************************/
/*               DEFINITION D'UNE MACRO-CONSTANTE                   */
/********************************************************************/
#define NOMBRE_AFFICHAGE	10

/********************************************************************/
/* NDE : Cette instruction du preprocesseur permet d'effectuer un   */
/*		 remplacement dans le code source. Toutes les occurences,   */
/*		 a quelques exceptions pres, du mot NOMBRE_AFFICHAGE seront */
/*		 remplacees par la valeur 10.                               */
/*                                                                  */
/*		 Cela rend le code plus facile a lire et a modifier.        */
/********************************************************************/


/********************************************************************/
/*                      PROGRAMME PRINCIPAL                         */
/********************************************************************/
int main(void)
{	int i;

	/* On affiche NOMBRE_AFFICHAGE fois "Hello world". */
	for (i = 0; i < NOMBRE_AFFICHAGE; ++i)
		printf("Hello world!\n");

	return EXIT_SUCCESS;
}

/********************************************************************/
/* NDE : Petites informations supplémentaires :                     */
/*                                                                  */
/* 1) Ne mettez pas de = ou de ; dans un define d'une constante.    */
/*                                                                  */
/* 2) Il n'est pas recommandé d'utiliser des mots reserves du C     */
/*	  comme nom de macro.                                           */
/*                                                                  */
/* 3) Par convention, le nom d'une macro sera toujours en           */
/*	  majuscule.                                                    */
/*                                                                  */
/* 4) La substitution ne s'effectue pas dans :                      */
/*		- les chaines de caracteres.                                */
/*		- le passage de la macro a une macro fonction               */
/*		- une chaine de remplacement d'un autre #define             */
/********************************************************************/
