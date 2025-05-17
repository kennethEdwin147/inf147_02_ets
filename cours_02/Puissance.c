/*                   
  PUISSANCE.C

  Programme qui illustre un algorithme rapide pour calculer X^N 
*/
#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>

/*============================================================*/
/* X_ALA_N                                                    */
/* Algorithme très rapide pour obtenir                        */
/* une puissance entière  d'un réel quelconque                */ 
/*                                                            */
/* PARAMETRE : x le nombre réel et n la puissance entière     */
/* RETOUR :  la puissance calculée  (type double)             */ 
/*                                                            */
/* SPÉCIFICATIONS :                                           */ 
/* On traite correctement le signe de la puissance.           */
/* Le résultat d'un appel avec 0 à une puissance négative est */
/* imprévisible.                                              */

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
/*                DÉFINITION DE LA FONCTION                   */
/*============================================================*/ 
double x_ala_n(double x, int puissance){
	double resul = 1;  /* accumulateur de la puissance à rendre */
	int positif = 1;   /* on y gardera  le signe de la puissance */
	
	if ( puissance < 0 ) {	
		positif = 0;
		puissance *= -1;
	}

	/* maintenant une descente à 0 pour la puissance positive */
	while ( puissance ){
		/* si le bit de droite de puissance est 1 (nombre impair) */
		/* on accumule la puissance de x actuelle */
		if (puissance % 2 == 1) {
			resul *= x;	
		} 
		
		x *= x;				/* on passe de (x^k) à (x^2k) */	
		puissance /= 2;		/* on coupe le bit de droite de puissance */
	}

	/* on prend l'inverse si la puissance était négative */
	if (!positif)  
		return 1/resul; 

	return resul;
}

/*============================================================*/

