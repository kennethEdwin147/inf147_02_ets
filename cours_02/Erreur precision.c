/*********************************************************************/
/* Fichier    : ERREUR PRECISION.C                                   */
/*                                                                   */
/* Objectifs : Ce programme a pour objectif de verifier la précision */
/*             des types reels.                                      */
/*                                                                   */
/* A noter : NDE signifie "Note de l'enseignant" et souligne les     */
/*			 commentaires qui ne devraient pas faire normalement     */
/*			 partie du code (outre des raisons pedagogiques).        */
/*                                                                   */
/* Il touche aux notions suivantes :                                 */
/*     - Les types fondamentaux (Drix, chapitre II)                  */
/*********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

/*********************************************************************/
/*                      PROGRAMME PRINCIPAL                          */
/*********************************************************************/
int main(void)
{
	double i;

	for (i = 0.0; i != 1.0; i += 0.1)
		printf("i == %.17lf\n", i);

	/* NDE : En raison des erreurs de precision, on ne fera JAMAIS de */
	/* comparaison entres valeurs reelles avec l'operateur "==", "!=" */
	system("pause");
	return EXIT_SUCCESS;
}


/********************************************************************/
/*                  INFORMATIONS SUPPLEMENTAIRES                    */
/*               Mais d'ou viennent les erreurs ???                 */
/********************************************************************/
/* Il existe plusieurs facons de conserver un nombre reel.          */
/* Peu importe la methode, celui-ci sera toujours emmagasiné sous   */
/* forme de bits.                                                   */
/*                                                                  */
/* Une methode nommee "IEEE 754 double precision" consiste à écrire	*/
/* le nombre sous le format suivant :                               */
/*  - 1  bit de signe.                                              */
/*  - 11 bits d'exposant.                                           */
/*  - 52 bits de mantisse.                                          */
/*                                                                  */
/* Le probleme se situe au niveau de la mantisse. On tente de       */
/* representer une valeur decimale a l'aide d'une somme de          */
/* puissances de 2. Ainsi, si la mantisse vaut 0.125, il n'y aura   */
/* aucune erreur de precision parce que                             */
/*			0.125 = 0/2 + 0/4 + 1/8 + 0/16 + 0/32 + ...	            */
/* ce qui, en bits, donne :                                         */
/*		0010000000000000000000000000000000000000000000000000        */
/* Mais, si on veut representer 0.1, il y aura des erreurs...       */
/********************************************************************/
