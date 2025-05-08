/********************************************************************/
/* Fichier    : #INCLUDE.C                                          */
/* References : Philippe Drix, chapitre VI-3 et VII                 */
/*              Harbison & Steele, chapitre 3.4                     */
/*                                                                  */
/* Objectifs : Ce programme a pour objectif d'introduire le         */
/*			   preprocesseur, plus precisement le #include.         */
/*                                                                  */
/* A noter : NDE signifie "Note de l'enseignant" et souligne les    */
/*			 commentaires qui ne devraient pas faire normalement    */
/*			 partie du code (outre des raisons pedagogiques).       */
/*                                                                  */
/* Il touche aux notions suivantes :                                */
/*		- #include (Drix, chapitre VI-3)                            */
/********************************************************************/


/********************************************************************/
/* NDE : Le preprocesseur n'est rien d'autre qu'un programme qui    */
/*		 prend le fichier source, le modifie (en suivant les        */
/*		 commandes du programmeur) et le passe au compilateur.      */
/********************************************************************/


/********************************************************************/
/* NDE : #include est l'instruction du preprocesseur la plus        */
/*       utilisee. Elle realise la tache suivante :                 */
/*                                                                  */
/*	#include <NOM_FICHIER> : Remplace cette ligne par le contenu    */
/*							 du fichier NOM_FICHIER situé dans le   */
/*							 repertoire special des modules du C.   */
/*                                                                  */
/*	#include "NOM_FICHIER" : Remplace cette ligne par le contenu    */
/*	                du fichier NOM_FICHIER situé dans le répertoire */
/*                  de travail courant. On peut specifier le chemin */
/*                  avec le nom de fichier.		                    */
/********************************************************************/
#define _CRT_SECURE_NO_WARNINGS  /* permet de compiler la librairie <stdio.h> */
#include <stdio.h>				 /* pour la fonction printf() */
#include <stdlib.h>				 /* pour la constante EXIT_SUCCESS */


/********************************************************************/
/*                      PROGRAMME PRINCIPAL                         */
/********************************************************************/
int main(void)
{
	printf("Hello world!\n");
	return EXIT_SUCCESS;
}


/********************************************************************/
/* NDE : Petites informations supplémentaires :                     */
/*                                                                  */
/* 1) Le C permet qu'il y ait des espaces avant et après le #, mais	*/
/*	  certains compilateurs peuvent ne pas le permettre.            */
/*                                                                  */
/* 2) Le C requiere au maximum le support de 8 niveau d'imbrication	*/
/*	  d'include. Donc, un fichier qui inclut un autre qui inclut    */
/*	  un autre jusqu'a 8 niveau d'inclusions.                       */
/********************************************************************/
