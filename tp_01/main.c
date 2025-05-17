//=========================================================
// Directive qui permet de d�sactiver certains warnings de Visual-Studio
#define _CRT_SECURE_NO_WARNINGS

// Librairies usuelles � inclure
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//pour la fonction de tests unitaires assert()
#include<assert.h>		


/* NOMBRE TOTALES DE GÉNÉRATEUR */
#define MAX_NOMBRE_GENERATEUR 32
#define MIN_NOMBRE_GENERATEUR 18

/* NOMBRE DE GENERATEUR QUI SIMULTANEMENT --  */
#define N 

/* MINIUM DE GENERATEUR QUI TRAVAILLE -- SIMULTANEMENT --  */
#define K 

#define LIM_BIT_CONSECUTIF 3


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

//=============== VERIFIER_CONSECUTIF ==========================
/*
	Verifie qu'il n'y a pas plus que 2 bits "1" consecutif
	PARAMETRES : nombre, un entier non signe.
	RETOUR : 0 ou 1
	SPECIFICATIONS :
	Si il y a plus que 2 bits "1" consecutif dans le nombre,
	la fonction retourne 0.
*/
int verifier_consecutif(unsigned int nombre);
void test_verifier_consecutif();



unsigned int get_bits_dispo(unsigned int etat_bits);
void tst_get_bits_dispo();


int main(void)
{
    test_verifier_consecutif();
    return EXIT_SUCCESS;
}






unsigned int get_bits_dispo(unsigned int etat_bits)
{ 
    unsigned int bits_possibles = 0; 
    unsigned int nouvelle_etat = 0;

    for (int i =0; i < N; i++)
    {
        if(get_bit(etat_bits, i) == 0 )
        {
            nouvelle_etat = set_bit(etat_bits, i);
            // verification du principe 1 avec un nouveau bit a "1"
            if(verifier_consecutif(nouvelle_etat) == 1)
            {
                bits_possibles = set_bit(bits_possibles, i);
            }
        }
    }

    return bits_possibles;
}


void tst_get_bits_dispo()
{


}












int verifier_consecutif(unsigned int nombre)
{
    int nbits_01_consecutif = 0;
    int bit_actuel;
    int verification = 1;

    int position = 0;
    while (nombre != 0)
    { 
        bit_actuel = get_bit(nombre, position);
        //printf("%d", bit_actuel);
        if(bit_actuel == 1)
        {
            nbits_01_consecutif ++;
        }
        else 
        {
           nbits_01_consecutif = 0; 
        }

        if(nbits_01_consecutif == LIM_BIT_CONSECUTIF)
        {
            verification = 0;
        }

        nombre = nombre / 2;  // (base binaire)
    } 

    //printf("\n %d \n", verification);
    return verification;
}


void test_verifier_consecutif()
{
    /* 
        ===== Liste de valeurs valides =====

        85 ----->  01010101
        195 -----> 11000011
        42 ------> 00101010
        73 ------> 01001001 

        ===== Liste de valeurs invalides =====
        224	-----> 11100000	
        14	-----> 00001110	
        248	-----> 11111000	
        31	-----> 00011111
    */
    unsigned int valeurs_valides[4] = {85, 195, 42, 73};
    unsigned int valeurs_invalides[4] = {224, 14, 248, 31};

    for(int i=0; i<= 3; i++)
    {
        assert(verifier_consecutif(valeurs_valides[i]) == 1);
    }

  
    for(int i=0; i<= 3; i++)
    {
        assert(verifier_consecutif(valeurs_invalides[i]) == 0);
    }
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
