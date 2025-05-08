/*==========================================================*/
/* LABORATOIRE 1: Exemple de solution pour l'exercice       */
/* 2.b - les chiffres d'un entier                           */
/* On affiche tous les digits d’un entier A à partir de la  */
/* droite vers la gauche: avec A % 10 on obtient le chiffre */
/* des unités de A, puis avec A = A / 10, on se débarrasse  */
/* du dernier chiffre observé.                              */
/* On répète ces étapes tant que A est différent de 0.      */
/*==========================================================*/

#define _CRT_SECURE_NO_WARNINGS  //OBLIGATOIRE pour la librairie <stdio.h>
//les include standars
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


/*==========================================================*/
int main(void){
	// la valeur entière à traiter 
	int valeur = 2719404;

	/* variables de travail :
	   une qui copie la valeur originale et qui sera réduite à 0 dans
	   l'énumération des chiffres (on ne détruit PAS la valeur initiale)
	*/
	int  copie_valeur = valeur;

	// et ici une autre qui comptera le nombre de chiffres  
	int nb_chiffres = 0;
	int chiffre;			//pour récupérer un chiffre de "valeur"

	// la boucle qui énumère les chiffres de "copie_valeur" de droite à gauche
	while (copie_valeur) {    // TANT QUE elle est différente de 0
		
		chiffre = copie_valeur % 10;		//récupérer le chiffre de droite
		printf("%d  ", chiffre);			//on affiche ce chiffre
		copie_valeur = copie_valeur / 10;	//réduire la valeur (enlève ce chiffre)
		nb_chiffres = nb_chiffres + 1;		//compter un de plus au total

	} // fin du while

	/* l'énumération est finie. On affiche le résultat.	*/
	printf("\n %d a %d chiffres \n", valeur, nb_chiffres);
	system("pause");

	return EXIT_SUCCESS;   //retour d'une constante valant 0 à Windows
}
/*==========================================================*/
