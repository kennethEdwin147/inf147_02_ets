/********************************************************************/
/* Fichier   : Crap_laid.c                                          */
/*                                                                  */
/* Objectifs : Ce programme montre ce qu'il NE FAUT PAS faire.      */
/*             EVITEZ CES PRATIQUES A TOUT PRIX!!!                  */
/*                                                                  */
/********************************************************************/


/********************************************************************/
/* REGLES AFFREUSES EMPLOYEES POUR RENDRE LE CODE ILLISIBLES :      */
/*	1 - Utilisation de variables globales uniquement.               */
/*	2 - Aucun commentaire.                                          */
/*	3 - Absence de macros-constantes.                               */
/*	4 - Indentation douteuse ou absente.                            */
/*	5 - Noms de variables non significatifs.                        */
/*	6 - Noms de fonctions non significatifs.                        */
/*	7 - Retrait d'espacement apres les operateurs et les ",".       */
/*  8 - Fin de blocs "}" placés à la droite de la dernière ligne.   */
/*	9 - Boucle infinie avec un "break".                             */
/********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rn(int,int),jp(void);
int tdd,tddt;long nv,ddt;    /* 4 variables globales!! */

int main(void){
	srand((unsigned)time(NULL));
	for (nv=ddt=0;ddt<1000000;nv+=jp(),++ddt);
	printf("Probabilite de victoire:%.4f%%\n",100.0*nv/1000000);
	return 0;}

int rn(int i,int a){return i+(int)((1.0*rand()/(RAND_MAX+0.5))*(a-i+1));}

int jp(void){
	if ((tdd=rn(1,6)+rn(1,6))==7 || tdd==11) return 1;
	else if (tdd!=2 && tdd!=3 && tdd!=12){
	while (1){
	if((tddt=rn(1,6)+rn(1,6))==tdd || tddt==7) break;}
	return tddt==tdd;}
	return 0;}