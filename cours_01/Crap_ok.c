/********************************************************************/
/* Fichier   : Crap_ok.c                                            */
/*                                                                  */
/* Objectifs : Ce programme permet de simuler des parties de CRAP   */
/*             et calcule ainsi la probabilite de gain.             */
/*             Genre de probleme typique d'ingenierie.              */
/*                                                                  */
/* A noter : NDE signifie "Note de l'enseignant" et souligne les    */
/*			 commentaires qui ne devraient pas faire normalement    */
/*			 partie du code (outre des raisons pedagogiques).       */
/********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/********************************************************************/
/*                   DEFINITION DES CONSTANTES                      */
/********************************************************************/
#define NB_ESSAI_TEST	100		/* Nombre de parties a jouer.	*/
#define NB_FACE_DES		  6		/* Nombre de faces des des.		*/

#define DEBUG  1        /* PERMET D'ACTIVER LES AFFICHAGES DE DEBUG */


/********************************************************************/
/*                   DECLARATIONS DES FONCTIONS                     */
/********************************************************************/
int alea(int min, int max);
/* Cette fonction retourne un nombre entre min et max.  */
/* On suppose que min <= max. */

int jouer_une_partie(void);
/* Cette fonction joue une partie de CRAP.	*/
/* Retourne 1 en cas de victoire, 0 sinon.  */


/********************************************************************/
/*						PROGRAMME PRINCIPAL							*/
/********************************************************************/
int main(void)
{
	long nb_victoires = 0;	/* Pour compter le nombre de victoires.	*/
	long i;				    /* Pour iterer sur les parties.			*/

	/* Initialisation du generateur aleatoire.	*/
	srand((unsigned) time(NULL));

	/* On joue le nombre de parties indiquees.	*/
	for (i = 0; i < NB_ESSAI_TEST; ++i)
	{
		nb_victoires += jouer_une_partie();
	}

	/* On affiche le pourcentage de gains.	*/
	printf("Probabilite de victoire : %.4f%%\n", 
	        100.0 * nb_victoires / NB_ESSAI_TEST);

	return EXIT_SUCCESS;
}


/***********************************************************************/
/*                      DEFINITIONS DES FONCTIONS                      */
/***********************************************************************/
int alea(int min, int max)
{
	return min + (int) ((1.0 * rand() / (RAND_MAX + 0.5)) * (max - min + 1));
}

/***********************************************************************/
int jouer_une_partie(void)
{
	int d1, d2, total_des;		/* Pour recevoir le resultat des dés. */
	int total_des_temp = 0;		/* Pour relancer les des. */
	int resultat_partie = 0;

	/* Voici la version sans BREAK et CONTINUE (propre). */
	total_des = (d1=alea(1, NB_FACE_DES)) + (d2=alea(1, NB_FACE_DES));

/* le code suivant sera exécuté seulement si la constante DEBUG == 1 */
#if DEBUG
  printf("De #1 = %d,  De #2 = %d\n", d1, d2);  /* utile pour débugger */  
#endif

	if (total_des == 7 || total_des == 11)
	{
		resultat_partie = 1;
	}
	else if (total_des != 2 && total_des != 3 && total_des != 12)
	{
		while (total_des_temp != total_des && total_des_temp != 7)
		{
			total_des_temp = alea(1, NB_FACE_DES) + alea(1, NB_FACE_DES);
		} 

		resultat_partie = (total_des_temp == total_des);
	}

	return resultat_partie;
}