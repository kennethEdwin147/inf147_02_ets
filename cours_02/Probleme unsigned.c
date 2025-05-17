/********************************************************************/
/* Fichier    : PROBLEME UNSIGNED.C                                 */
/* References : Philippe Drix, chapitre II                          */
/*              Harbison & Steele, chapitre 5.1.2                   */
/*                                                                  */
/* Objectifs : Ce programme a pour objectif de presenter un         */
/*             possible probleme avec les valeurs non signees.      */
/*                                                                  */
/* A noter : NDE signifie "Note de l'enseignant" et souligne les    */
/*			 commentaires qui ne devraient pas faire normalement    */
/*			 partie du code (outre des raisons pedagogiques).       */
/*                                                                  */
/* Il touche aux notions suivantes :                                */
/*     - Les types fondamentaux (Drix, chapitre II)                 */
/********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

/********************************************************************/
/*                     PROGRAMME PRINCIPAL                          */
/********************************************************************/
int main(void)
{
	unsigned int nb = 10;

	if (nb > -1)
		printf("%u est plus grand que -1\n", nb);
	else
		printf("%u n'est pas plus grand que -1\n", nb);

	system("pause");
	return EXIT_SUCCESS;
}


/********************************************************************/
/* NDE : Pour comprendre ce qui se produit reellement, utilisez     */
/*		 le code suivant :                                          */
/*                                                                  */
/*	if (nb > -1)                                                    */
/*		printf("%u est plus grand que %u\n", nb, -1);               */
/*	else                                                            */
/*		printf("%u n'est pas plus grand que %u\n", nb, -1);         */
/********************************************************************/
