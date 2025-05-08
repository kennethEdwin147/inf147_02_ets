/*==========================================================*/
/* LABORATOIRE 1: Exemple de solution pour l'exercice       */
/* 2.b - les chiffres d'un entier                           */
/* On affiche tous les digits d�un entier A � partir de la  */
/* droite vers la gauche: avec A % 10 on obtient le chiffre */
/* des unit�s de A, puis avec A = A / 10, on se d�barrasse  */
/* du dernier chiffre observ�.                              */
/* On r�p�te ces �tapes tant que A est diff�rent de 0.      */
/*==========================================================*/

#define _CRT_SECURE_NO_WARNINGS  //OBLIGATOIRE pour la librairie <stdio.h>
//les include standars
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


/*==========================================================*/
int main(void){
	// la valeur enti�re � traiter 
	int valeur = 2719404;

	/* variables de travail :
	   une qui copie la valeur originale et qui sera r�duite � 0 dans
	   l'�num�ration des chiffres (on ne d�truit PAS la valeur initiale)
	*/
	int  copie_valeur = valeur;

	// et ici une autre qui comptera le nombre de chiffres  
	int nb_chiffres = 0;
	int chiffre;			//pour r�cup�rer un chiffre de "valeur"

	// la boucle qui �num�re les chiffres de "copie_valeur" de droite � gauche
	while (copie_valeur) {    // TANT QUE elle est diff�rente de 0
		
		chiffre = copie_valeur % 10;		//r�cup�rer le chiffre de droite
		printf("%d  ", chiffre);			//on affiche ce chiffre
		copie_valeur = copie_valeur / 10;	//r�duire la valeur (enl�ve ce chiffre)
		nb_chiffres = nb_chiffres + 1;		//compter un de plus au total

	} // fin du while

	/* l'�num�ration est finie. On affiche le r�sultat.	*/
	printf("\n %d a %d chiffres \n", valeur, nb_chiffres);
	system("pause");

	return EXIT_SUCCESS;   //retour d'une constante valant 0 � Windows
}
/*==========================================================*/
