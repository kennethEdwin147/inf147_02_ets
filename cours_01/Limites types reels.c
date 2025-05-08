/********************************************************************/
/* Fichier    : LIMITES TYPES REELS.C                               */
/* References : Philippe Drix, chapitre II                          */
/*              Harbison & Steele, chapitre 5.2                     */
/*                                                                  */
/* Objectifs : Ce programme a pour objectif de verifier la taille   */
/*             des types reels.                                     */
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
#include <float.h>		/* NDE : Pour les limites des types reels.	*/


/********************************************************************/
/*                     PROGRAMME PRINCIPAL                          */
/********************************************************************/
int main(void)
{
	printf("Un %11s va de %12e a %10e\n", "float", FLT_MIN, FLT_MAX);
	printf("Un %11s va de %12e a %10e\n", "double", DBL_MIN, DBL_MAX);
	printf("Un %11s va de %12e a %10e\n\n", "long double", LDBL_MIN, LDBL_MAX);

	printf("Plus petite valeur reelle x > 0.0 telle que 1.0 + x > 1.0 : %e\n\n", 
	        LDBL_EPSILON);

	return EXIT_SUCCESS;
}
