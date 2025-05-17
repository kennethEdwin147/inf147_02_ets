/*                   
  PUISSANCE.C

  Programme qui illustre un algorithme rapide pour calculer X^N 
*/
#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>

/*============================================================*/
/* X_ALA_N                                                    */
/* Algorithme tr�s rapide pour obtenir                        */
/* une puissance enti�re  d'un r�el quelconque                */ 
/*                                                            */
/* PARAMETRE : x le nombre r�el et n la puissance enti�re     */
/* RETOUR :  la puissance calcul�e  (type double)             */ 
/*                                                            */
/* SP�CIFICATIONS :                                           */ 
/* On traite correctement le signe de la puissance.           */
/* Le r�sultat d'un appel avec 0 � une puissance n�gative est */
/* impr�visible.                                              */

double x_ala_n(double, int);

/*============================================================*/
/*                   FONCTION PRINCIPALE                      */
/*============================================================*/
int main(){
  double x=2, puiss;
  int    n=5;

  puiss = x_ala_n(x, n);
  
  printf("%.2lf ^ %d = %.2lf\n", x, n, puiss);

  system("pause");
  return EXIT_SUCCESS;
}

/*============================================================*/
/*                D�FINITION DE LA FONCTION                   */
/*============================================================*/ 
double x_ala_n(double x, int puissance){
	double resul = 1;  /* accumulateur de la puissance � rendre */
	int positif = 1;   /* on y gardera  le signe de la puissance */
	
	if ( puissance < 0 ) {	
		positif = 0;
		puissance *= -1;
	}

	/* maintenant une descente � 0 pour la puissance positive */
	while ( puissance ){
		/* si le bit de droite de puissance est 1 (nombre impair) */
		/* on accumule la puissance de x actuelle */
		if (puissance % 2 == 1) {
			resul *= x;	
		} 
		
		x *= x;				/* on passe de (x^k) � (x^2k) */	
		puissance /= 2;		/* on coupe le bit de droite de puissance */
	}

	/* on prend l'inverse si la puissance �tait n�gative */
	if (!positif)  
		return 1/resul; 

	return resul;
}

/*============================================================*/

