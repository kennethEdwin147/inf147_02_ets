//=========================================================
// 	ALEA01.c : Programme qui offre des fonctions pour
//  la g�n�ration de nombres pseudo-al�atoires
//  dans diverses distributions uniformes.
//=========================================================

/*=========================================================*/
/* la constante qui permet de d�sactiver certains 
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
#define EPSILON (0.0000000001)    //la diff�rence r�elle minimale

 
/*=========================================================*/
/*
	Voici quatre fonctions offertes pour r�aliser certains 
	exercices ou devoirs qui  ont  besoin d'un g�n�rateur 
	de nombres pseudo-al�atoires:

	randf(), randi() et randf_bornes() civilisent le rand() du C pour 
	�mette dans la distribution uniforme sp�cifi�e.
	srand_sys() rend plus simple l'initialisation du generateur
	en utilisant l'horloge interne de la machine.
*/

/*=========================================================*/
// LES DECLARTIONS DE FONCTIONS ( on dit aussi prototypes)
/*=========================================================*/
/*  randf() donne un nombre r�el dans l'intervalle ouvert (0,1)
	
	PARAMETRES :  aucun
	RETOUR : une valeur r�elle dans l'intervalle (0,1)

	SPECIFICATIONS : aucune
*/
double randf(void);

/*=========================================================*/
/*  randi() donne un nombre entier dans l'intervalle [0, N[ 
    (un entier positif entre 0 et la borne re�ue - 1)
	PARAMETRES : nombre, un entier positif
	RETOUR : une valeur entre 0 et (nombre-1)

	SPECIFICATIONS : recevant nombre <= 0 retour automatique de 0
*/
int randi(int nombre);

/*=========================================================*/
/*  randf_bornes() donne un nombre r�el dans l'intervalle sp�cifi�
	PARAMETRES : deux r�els quelconques
	RETOUR : une valeur r�elle dans l'intervalle d�fini par ses
			 deux param�tres

	SPECIFICATIONS : l'ordre des param�tres est sans importance
*/
double randf_bornes(double b1, double b2);

/*=========================================================*/
/*  srand_sys() initialise le g�n�rateur de la valeur de 
    l'horloge interne de la machine
	PARAMETRES :  Rien
	RETOUR : Rien

	SPECIFICATIONS : DANS UNE SIMULATION NUM�RIQUE, ON NE DOIT JAMAIS
		             INITIALISER PLUS D'UNE FOIS LE G�N�RATEUR
*/
void srand_sys(void);


/*=========================================================*/
/*=========================================================*/
int main(void) {
	// on d�clare un entier et un r�el
	int mon_entier = 135;
	double mon_reel = 0;

	// init du PSG  (Pseudo Random Gen)
	srand_sys(); 

	// premier usage de randi() suivi d'un  
	// test unitaire de la fonction avec "assert()"
	mon_entier = randi(17);
	assert((mon_entier >= 0) && (mon_entier < 17));

	printf("valeur = %d\n", mon_entier);

	//   pareil  pour un r�el
	mon_reel = randf_bornes(184, 2904.9988);
	assert(mon_reel > 184);
	assert(mon_reel < 2905);

	printf("valeur = %.4lf\n", mon_reel);

	// et d�commentez pour voir une exception :)
	// assert(randf() > 1);

	system("pause");
	return EXIT_SUCCESS; 
}


/*=========================================================*/
/*=========================================================*/
// D�finitions des quatre fonctions offertes
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
	// n * randf()) donne un r�el dans (0, n-1)
	// le typecast (int) va le tronquer dans [0, n[
	return (n <= 0) ? 0 : ((int)(n * randf())); 
}

/*=========================================================*/
double randf_bornes(double b1, double b2) {
	// STRATEGIE
	// passer de l'intervalle r�el (0,1) � l'intervalle 
	// d�sign� par les param�tres
	// maths :  une dilatation de (0,1) par le facteur(b2 - b1)
	// suivie d'une translation de b1
	return b1 + ((b2 - b1) * randf());
}

/*=========================================================*/
void srand_sys(void) {
	unsigned int secondes;

	// obtenir le d�calage secondes (Unix timestamp)
	secondes = (unsigned int)time(NULL);
	// init le generateur du C du temps obtenu
	srand(secondes);
	// qui par tradition est suivi d'un premier appel au generateur
	rand(); 
}
/*=========================================================*/
/*=========================================================*/
