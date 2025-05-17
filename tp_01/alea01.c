//=========================================================
// 	ALEA01.c : Programme qui offre des fonctions pour
//  la génération de nombres pseudo-aléatoires
//  dans diverses distributions uniformes.
//=========================================================

/*=========================================================*/
/* la constante qui permet de désactiver certains 
	warnings achalants de Visual-Studio.                   */
#define _CRT_SECURE_NO_WARNINGS

// les include
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
/*=========================================================*/

/*=========================================================*/
/*                   LES CONSTANTES                        */
/*=========================================================*/
#define EPSILON (0.0000000001)    //la différence réelle minimale

 
/*=========================================================*/
/*
	Voici quatre fonctions offertes pour réaliser certains 
	exercices ou devoirs qui  ont  besoin d'un générateur 
	de nombres pseudo-aléatoires:

	randf(), randi() et randf_bornes() civilisent le rand() du C pour 
	émette dans la distribution uniforme spécifiée.
	srand_sys() rend plus simple l'initialisation du generateur
	en utilisant l'horloge interne de la machine.
*/

/*=========================================================*/
// LES DECLARTIONS DE FONCTIONS ( on dit aussi prototypes)
/*=========================================================*/
/*  randf() donne un nombre réel dans l'intervalle ouvert (0,1)
	
	PARAMETRES :  aucun
	RETOUR : une valeur réelle dans l'intervalle (0,1)

	SPECIFICATIONS : aucune
*/
double randf(void);

/*=========================================================*/
/*  randi() donne un nombre entier dans l'intervalle [0, N[ 
    (un entier positif entre 0 et la borne reçue - 1)
	PARAMETRES : nombre, un entier positif
	RETOUR : une valeur entre 0 et (nombre-1)

	SPECIFICATIONS : recevant nombre <= 0 retour automatique de 0
*/
int randi(int nombre);

/*=========================================================*/
/*  randf_bornes() donne un nombre réel dans l'intervalle spécifié
	PARAMETRES : deux réels quelconques
	RETOUR : une valeur réelle dans l'intervalle défini par ses
			 deux paramètres

	SPECIFICATIONS : l'ordre des paramètres est sans importance
*/
double randf_bornes(double b1, double b2);

/*=========================================================*/
/*  srand_sys() initialise le générateur de la valeur de 
    l'horloge interne de la machine
	PARAMETRES :  Rien
	RETOUR : Rien

	SPECIFICATIONS : DANS UNE SIMULATION NUMÉRIQUE, ON NE DOIT JAMAIS
		             INITIALISER PLUS D'UNE FOIS LE GÉNÉRATEUR
*/
void srand_sys(void);


/*=========================================================*/
/*=========================================================*/
int main(void) {
	// on déclare un entier et un réel
	int mon_entier = 135;
	double mon_reel = 0;

	// init du PSG  (Pseudo Random Gen)
	srand_sys(); 

	// premier usage de randi() suivi d'un  
	// test unitaire de la fonction avec "assert()"
	mon_entier = randi(17);
	assert((mon_entier >= 0) && (mon_entier < 17));

	printf("valeur = %d\n", mon_entier);

	//   pareil  pour un réel
	mon_reel = randf_bornes(184, 2904.9988);
	assert(mon_reel > 184);
	assert(mon_reel < 2905);

	printf("valeur = %.4lf\n", mon_reel);

	// et décommentez pour voir une exception :)
	// assert(randf() > 1);

	system("pause");
	return EXIT_SUCCESS; 
}


/*=========================================================*/
/*=========================================================*/
// Définitions des quatre fonctions offertes
/*=========================================================*/
double randf(void) {
	// STRATEGIE
	// calcul du rapport de la valeur issue de rand au 
	// maximum emissible + epsilon  
	return (1.0*rand()) / (RAND_MAX + EPSILON) ;
}

/*=========================================================*/
int randi(int n) {
	// STRATEGIE
	// si n <= 0 retour 0 
	// n * randf()) donne un réel dans (0, n-1)
	// le typecast (int) va le tronquer dans [0, n[
	return (n <= 0) ? 0 : ((int)(n * randf())); 
}

/*=========================================================*/
double randf_bornes(double b1, double b2) {
	// STRATEGIE
	// passer de l'intervalle réel (0,1) à l'intervalle 
	// désigné par les paramètres
	// maths :  une dilatation de (0,1) par le facteur(b2 - b1)
	// suivie d'une translation de b1
	return b1 + ((b2 - b1) * randf());
}

/*=========================================================*/
void srand_sys(void) {
	unsigned int secondes;

	// obtenir le décalage secondes (Unix timestamp)
	secondes = (unsigned int)time(NULL);
	// init le generateur du C du temps obtenu
	srand(secondes);
	// qui par tradition est suivi d'un premier appel au generateur
	rand(); 
}
/*=========================================================*/
/*=========================================================*/
