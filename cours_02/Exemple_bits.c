//=========================================================
// EXEMPLES_BITS.C: INF147 - session E2025
//=========================================================
/*
  Dans le cadre du premier devoir en INF147 voici quatre fonctions 
  que vous devrez utiliser. Vous devrez aussi développer pour chacune d'elles :
	- sa forme Macro
	- une fonction de tests unitaires de la Macro avec "assert()"

  Les quatres fonctions agissent sur les bits d'un entier positif 
	get_bit() - obtenir la valeur d'un bit spécifique
	set_bit() - mettre un bit spécifique à 1 dans un entier 
	clear_bit() - mettre un bit spécifique à 0 dans un entier 
	flip_bit()  - inverser un bit spécifique dans un entier 

  de plus on offre aussi:
	voir_bits(): une fonction pour afficher les bits d'un unsigned int à l'écran 

  L'ordre des bits dans un entier selon la tradition  
  commence à 0, ordre du bit le moins significatif,
  jusqu'à 31, ordre du bit le plus significatif.
*/

//=========================================================
/*
  Dans le devoir, vous devez implémenter pour chacune des quatre
  fonctions (get_bit(), set_bit(), clear_bit(), flip_bit()) dont on vous donne 
  ici les déclarations et les définitions ;
  1) Leur forme Macro-fonction qui restent relativement faciles à développer
  2) Une fonction standardisé réalisant les tests unitaires de la Macro

  La Macro viendra juste après la déclaration de la fonction correspondante.
  Pour ce faire, les fonctions set_bit() et clear_bit() doivent être réduites
  à UNE SEULE ligne de code sans les variables locales (eg. "return (......);"). 
  On vous a passablement aidé pour le get_bit(), allez voir!
*/

//=========================================================
// Directive qui permet de désactiver certains warnings de Visual-Studio
#define _CRT_SECURE_NO_WARNINGS

// Librairies usuelles à inclure
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>		//pour la fonction de tests unitaires assert()

//=========================================================

//=========================================================
/* CONSTANTE essentielle du nombre de bits dans un integer. */
#define INT_BIT	 (sizeof(int) * 8)


//====================== GET_BIT ==========================
/*
	Donne la valeur du bit d'ordre spécifié.
	PARAMETRES : nombre, un entier non signé.
				 ordre, l'ordre du bit voulu dans le nombre.
	RETOUR : 0 ou 1
	SPECIFICATIONS :
	Si ordre n'est pas dans l'intervalle [0, nb_bits_nombre-1],
	la fonction retourne 0.
*/
int get_bit(unsigned int nombre, int ordre);

// c'est ici que viendra le développement de sa Macro
//#define GET_BIT(nombre, ordre)  ............

//c'est ici que viendra la déclaration de son test unitaire
void test_macro_GET_BIT(void);

//====================== SET_BIT ==========================
/*
	Donne la valeur du nombre avec le bit d'ordre spécifié mis à 1
	PARAMETRES : nombre, un entier non signé.
				 ordre, spécifie l'ordre du bit mis à 1 dans le nombre.
	RETOUR : la valeur obtenue du paramètre avec ce bit à 1
	SPECIFICATIONS :
	Si ordre n'est pas dans l'intervalle [0, nb_bits_nombre-1],
	la fonction retourne la même valeur reçue.
*/
unsigned int set_bit(unsigned int nombre, int ordre);

// c'est ici que viendra le développement de sa Macro
//#define SET_BIT(nombre, ordre)   ..........

//c'est ici que viendra la déclaration de son test unitaire
void test_macro_SET_BIT(void);

//====================== CLEAR_BIT ========================
/*
	Donne la valeur du nombre avec le bit d'ordre spécifié mis à 0
	PARAMETRES : nombre, un entier non signé.
				 ordre, spécifie l'ordre du bit mis à 0 dans le nombre.
	RETOUR : la valeur obtenue du paramètre avec ce bit à 0
	SPECIFICATIONS :
	Si ordre n'est pas dans l'intervalle [0, nb_bits_nombre-1],
	la fonction retourne la même valeur reçue.
*/
unsigned int clear_bit(unsigned int  nombre, int ordre);

// c'est ici que viendra le développement de sa Macro
//#define CLEAR_BIT(nombre, ordre)  ..........

//c'est ici que viendra la déclaration de son test unitaire
void test_macro_CLEAR_BIT(void);

//===================== FLIP_BIT ==========================
/*
	Donne la valeur du nombre reçu après l'inversaion du
	bit d'ordre spécifié.
	PARAMETRES: nombre, un entier non signé.
				ordre, spécifie l'ordre du bit à inverser dans le nombre.
	RETOUR : la valeur obtenue du paramètre avec ce bit inversé
	SPECIFICATIONS :
	Si ordre n'est pas dans l'intervalle [0, nb_bits_nombre-1],
	la fonction retourne la même valeur reçue.
*/
unsigned int flip_bit(unsigned int  nombre, int ordre);

// c'est ici que viendra le développement de sa Macro
//#define FLIP_BIT(nombre, ordre)    .......... 

//c'est ici que viendra la déclaration de son test unitaire
void test_macro_FLIP_BIT(void);    

//==================== VOIR_BITS ==========================
/*
	Affiche les bits du nombre reçu à l'écran.
	PARAMETRE : nombre, l'entier non signé à afficher
	RETOUR : rien
	SPECIFICATIONS :
	Les bits sont affichés du plus significatif au moins significatif (de 31->0)
*/
void voir_bits(unsigned int nombre);
//=========================================================

//=========================================================
// le main() de tests
//=========================================================
int main(void) 
{
	unsigned int val = 15;   // = 0000...00001111
	int ordre;

	// petit test au bit d'ordre 21
	printf("val initiale (15):  ");
	voir_bits(val);		// avant le flip_bit()
	ordre = 21;
	val = flip_bit(val, ordre);
	printf("Apres flip_bit() :  ");
	voir_bits(val);		// apres le flip_bit()

	//maitenant sur le bit d'ordre supérieur
	val = set_bit(val, ordre + 1);
	printf("Apres set_bit()  :  ");
	voir_bits(val);// apres le set

	// 31 c'est 0000...00011111 
	val = (val | (31 << 7));
	printf("(val | (31 << 7)):  ");
	voir_bits(val);

	// on se déplace pour un premier assert
	ordre = 7;
	val = clear_bit(val, ordre);

	//et ça c'est un vrai test d'une fonction avec le assert()
	//la fonction arrête immédiatement le programme si la condition donne FAUX
	assert(get_bit(val, ordre) == 0);  
	printf("Apres clear_bit():  ");
	voir_bits(val);

	system("pause");
	return EXIT_SUCCESS;
}


//=========================================================
//		       DEFINITIONS DES FONCTIONS			     
//=========================================================

//=========================================================
/* get_bit(): un test qui dit si un (and) entre la valeur reçue
	et un train de bits tout à 0 sauf un bit 1 en position voulue,
	obtenu avec l'opérateur <<, est différent de 0.  */
int get_bit(unsigned int nombre, int ordre) {
	return (nombre & (1 << ordre)) != 0;
}

//=========================================================
/* set_bit(): un (or) suffit entre la valeur reçue et un train de bits
	tout à 0 sauf pour un bit 1 en position voulue,	obtenu avec l'opérateur <<. */
unsigned int set_bit(unsigned int nombre, int ordre) {
	unsigned int masque = (1 << ordre);
	unsigned int nombre_ou_masque = (nombre | masque);

	return nombre_ou_masque;
}

//=========================================================
/* clear_bit():	un (and) suffit entre la valeur reçue et un train de
	bits tout à 1 sauf un bit 0 à la position voulue, obtenu avec les opérateurs <<, ~. */
unsigned int clear_bit(unsigned int nombre, int ordre) {
	unsigned int masque_inv = ~(1 << ordre);
	unsigned int nombre_et_masque = (nombre & masque_inv);

	return nombre_et_masque;
}

//=========================================================
/* flip_bit(): réutilisation des deux fonctions précédentes
	si le bit est 1, on retourne clear_bit(), sinon, on retourne set_bit(). */
unsigned int flip_bit(unsigned int nombre, int ordre) {
	return get_bit(nombre, ordre) ? clear_bit(nombre, ordre)
		                          : set_bit(nombre, ordre);
}

//=========================================================
/* voir_bits(): avec réutilisation de get_bit()
	 on affiche le résultat de get_bit() pour chaque position de 31 à 0. */
void voir_bits(unsigned int nombre) {
	// pour respecter l'ordre naturel des bits on les
	// affiche du plus représentatif en descendant (ordre 31 à 0)
	for (int i = INT_BIT - 1; i > -1; i -= 1)
		printf("%d", get_bit(nombre, i));
	printf("\n");		//affiche un ENTER après la fin de la boucle for()
}

/*==========================================================*/
/*==========================================================*/
