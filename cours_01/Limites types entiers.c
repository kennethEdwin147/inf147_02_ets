/********************************************************************/
/* Fichier    : LIMITES TYPES ENTIERS.C                             */
/* References : Philippe Drix, chapitre II                          */
/*              Harbison & Steele, chapitre 5.1.1                   */
/*                                                                  */
/* Objectifs : Ce programme a pour objectif de verifier la taille   */
/*             des types entiers.                                   */
/*                                                                  */
/* A noter : NDE signifie "Note de l'enseignant" et souligne les    */
/*			 commentaires qui ne devraient pas faire normalement    */
/*			 partie du code (outre des raisons pedagogiques).       */
/*                                                                  */
/* Il touche aux notions suivantes :                                */
/*		- Les types fondamentaux (Drix, chapitre II)                */
/********************************************************************/
#define _CRT_SECURE_NO_WARNINGS  /* permet de compiler la librairie <stdio.h> */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>		/* NDE : Pour les limites des types entiers.*/


/********************************************************************/
/*                     PROGRAMME PRINCIPAL                          */
/********************************************************************/
int main(void)
{
	printf("Un %18s va de %12i a %10i\n", "char", CHAR_MIN, CHAR_MAX);
	printf("Un %18s va de %12u a %10u\n", "unsigned char", 0, UCHAR_MAX);
	printf("Un %18s va de %12i a %10i\n", "short int", SHRT_MIN, SHRT_MAX);
	printf("Un %18s va de %12u a %10u\n", "unsigned short int", 0, USHRT_MAX);
	printf("Un %18s va de %12i a %10i\n", "int", INT_MIN, INT_MAX);
	printf("Un %18s va de %12u a %10u\n", "unsigned int", 0, UINT_MAX);
	printf("Un %18s va de %12li a %10li\n", "long int", LONG_MIN, LONG_MAX);
	printf("Un %18s va de %12lu a %10lu\n", "unsigned long int", 0, ULONG_MAX);

	return EXIT_SUCCESS;
}
