//=========================================================
// EXEMPLES_BITS.C: INF147 - session E2025
//=========================================================
/*
  Dans le cadre du premier devoir en INF147 voici quatre fonctions 
  que vous devrez utiliser. Vous devrez aussi d�velopper pour chacune d'elles :
	- sa forme Macro
	- une fonction de tests unitaires de la Macro avec "assert()"

  Les quatres fonctions agissent sur les bits d'un entier positif 
	get_bit() - obtenir la valeur d'un bit sp�cifique
	set_bit() - mettre un bit sp�cifique � 1 dans un entier 
	clear_bit() - mettre un bit sp�cifique � 0 dans un entier 
	flip_bit()  - inverser un bit sp�cifique dans un entier 

  de plus on offre aussi:
	voir_bits(): une fonction pour afficher les bits d'un unsigned int � l'�cran 

  L'ordre des bits dans un entier selon la tradition  
  commence � 0, ordre du bit le moins significatif,
  jusqu'� 31, ordre du bit le plus significatif.
*/

//=========================================================
/*
  Dans le devoir, vous devez impl�menter pour chacune des quatre
  fonctions (get_bit(), set_bit(), clear_bit(), flip_bit()) dont on vous donne 
  ici les d�clarations et les d�finitions ;
  1) Leur forme Macro-fonction qui restent relativement faciles � d�velopper
  2) Une fonction standardis� r�alisant les tests unitaires de la Macro

  La Macro viendra juste apr�s la d�claration de la fonction correspondante.
  Pour ce faire, les fonctions set_bit() et clear_bit() doivent �tre r�duites
  � UNE SEULE ligne de code sans les variables locales (eg. "return (......);"). 
  On vous a passablement aid� pour le get_bit(), allez voir!
*/

//=========================================================
// Directive qui permet de d�sactiver certains warnings de Visual-Studio
#define _CRT_SECURE_NO_WARNINGS

// Librairies usuelles � inclure
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
	Donne la valeur du bit d'ordre sp�cifi�.
	PARAMETRES : nombre, un entier non sign�.
				 ordre, l'ordre du bit voulu dans le nombre.
	RETOUR : 0 ou 1
	SPECIFICATIONS :
	Si ordre n'est pas dans l'intervalle [0, nb_bits_nombre-1],
	la fonction retourne 0.
*/
int get_bit(unsigned int nombre, int ordre);

// c'est ici que viendra le d�veloppement de sa Macro
//#define GET_BIT(nombre, ordre)  ............
#define GET_BIT(nombre, ordre) (((nombre) >> (ordre)) & 1)
//c'est ici que viendra la d�claration de son test unitaire
void test_macro_GET_BIT(void);

//====================== SET_BIT ==========================
/*
	Donne la valeur du nombre avec le bit d'ordre sp�cifi� mis � 1
	PARAMETRES : nombre, un entier non sign�.
				 ordre, sp�cifie l'ordre du bit mis � 1 dans le nombre.
	RETOUR : la valeur obtenue du param�tre avec ce bit � 1
	SPECIFICATIONS :
	Si ordre n'est pas dans l'intervalle [0, nb_bits_nombre-1],
	la fonction retourne la m�me valeur re�ue.
*/
unsigned int set_bit(unsigned int nombre, int ordre);

// c'est ici que viendra le d�veloppement de sa Macro
//#define SET_BIT(nombre, ordre)   ..........

//c'est ici que viendra la d�claration de son test unitaire
void test_macro_SET_BIT(void);

//====================== CLEAR_BIT ========================
/*
	Donne la valeur du nombre avec le bit d'ordre sp�cifi� mis � 0
	PARAMETRES : nombre, un entier non sign�.
				 ordre, sp�cifie l'ordre du bit mis � 0 dans le nombre.
	RETOUR : la valeur obtenue du param�tre avec ce bit � 0
	SPECIFICATIONS :
	Si ordre n'est pas dans l'intervalle [0, nb_bits_nombre-1],
	la fonction retourne la m�me valeur re�ue.
*/
unsigned int clear_bit(unsigned int  nombre, int ordre);

// c'est ici que viendra le d�veloppement de sa Macro
//#define CLEAR_BIT(nombre, ordre)  ..........

//c'est ici que viendra la d�claration de son test unitaire
void test_macro_CLEAR_BIT(void);

//===================== FLIP_BIT ==========================
/*
	Donne la valeur du nombre re�u apr�s l'inversaion du
	bit d'ordre sp�cifi�.
	PARAMETRES: nombre, un entier non sign�.
				ordre, sp�cifie l'ordre du bit � inverser dans le nombre.
	RETOUR : la valeur obtenue du param�tre avec ce bit invers�
	SPECIFICATIONS :
	Si ordre n'est pas dans l'intervalle [0, nb_bits_nombre-1],
	la fonction retourne la m�me valeur re�ue.
*/
unsigned int flip_bit(unsigned int  nombre, int ordre);

// c'est ici que viendra le d�veloppement de sa Macro
//#define FLIP_BIT(nombre, ordre)    .......... 

//c'est ici que viendra la d�claration de son test unitaire
void test_macro_FLIP_BIT(void);    

//==================== VOIR_BITS ==========================
/*
	Affiche les bits du nombre re�u � l'�cran.
	PARAMETRE : nombre, l'entier non sign� � afficher
	RETOUR : rien
	SPECIFICATIONS :
	Les bits sont affich�s du plus significatif au moins significatif (de 31->0)
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

	//maitenant sur le bit d'ordre sup�rieur
	val = set_bit(val, ordre + 1);
	printf("Apres set_bit()  :  ");
	voir_bits(val);// apres le set

	// 31 c'est 0000...00011111 
	val = (val | (31 << 7));
	printf("(val | (31 << 7)):  ");
	voir_bits(val);

	// on se d�place pour un premier assert
	ordre = 7;
	val = clear_bit(val, ordre);

	//et �a c'est un vrai test d'une fonction avec le assert()
	//la fonction arr�te imm�diatement le programme si la condition donne FAUX
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
/* get_bit(): un test qui dit si un (and) entre la valeur re�ue
	et un train de bits tout � 0 sauf un bit 1 en position voulue,
	obtenu avec l'op�rateur <<, est diff�rent de 0.  */
int get_bit(unsigned int nombre, int ordre) {
	return (nombre & (1 << ordre)) != 0;
}

//=========================================================
/* set_bit(): un (or) suffit entre la valeur re�ue et un train de bits
	tout � 0 sauf pour un bit 1 en position voulue,	obtenu avec l'op�rateur <<. */
unsigned int set_bit(unsigned int nombre, int ordre) {
	unsigned int masque = (1 << ordre);
	unsigned int nombre_ou_masque = (nombre | masque);

	return nombre_ou_masque;
}

//=========================================================
/* clear_bit():	un (and) suffit entre la valeur re�ue et un train de
	bits tout � 1 sauf un bit 0 � la position voulue, obtenu avec les op�rateurs <<, ~. */
unsigned int clear_bit(unsigned int nombre, int ordre) {
	unsigned int masque_inv = ~(1 << ordre);
	unsigned int nombre_et_masque = (nombre & masque_inv);

	return nombre_et_masque;
}

//=========================================================
/* flip_bit(): r�utilisation des deux fonctions pr�c�dentes
	si le bit est 1, on retourne clear_bit(), sinon, on retourne set_bit(). */
unsigned int flip_bit(unsigned int nombre, int ordre) {
	return get_bit(nombre, ordre) ? clear_bit(nombre, ordre)
		                          : set_bit(nombre, ordre);
}

//=========================================================
/* voir_bits(): avec r�utilisation de get_bit()
	 on affiche le r�sultat de get_bit() pour chaque position de 31 � 0. */
void voir_bits(unsigned int nombre) {
	// pour respecter l'ordre naturel des bits on les
	// affiche du plus repr�sentatif en descendant (ordre 31 � 0)
	for (int i = INT_BIT - 1; i > -1; i -= 1)
		printf("%d", get_bit(nombre, i));
	printf("\n");		//affiche un ENTER apr�s la fin de la boucle for()
}

/*==========================================================*/
/*==========================================================*/

//=========================================================
//		       DEFINITIONS DES FONCTIONS DE TESTS DE MACRO		     
//=========================================================
