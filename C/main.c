#include <stdio.h>
#include <stdlib.h>
#include"ARTICLES.h"
#include"UTILISATEURS.h"
#include"COMMENTAIRE.h"
#include"VILLES.h"
#include"FACTURES.h"
#include"PANIERS.h"
#include"COMMANDES.h"



/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* LORS DE L'UTILISATION DE CE PROGRAMME N'UTILISEZ PAS L'ESPACE ET REMPLACEZ LE PAR UN "_"*/
int main(int argc, char *argv[]) 
{
	
int choix,rep;
	do
	{
		system("cls");//netoyer tous ce qui est ecris dans la console 
		printf("                UN PROJET D'ACHAT EN LIGNE, DEVLOPE PAR :  FATIMA_CHHAIB      MERIEM_EL_AMARI    ZINEB_BARAKA     \n\n");
		printf("*****************************      MENU     *****************************\n\n");
		printf("--------CHOISIR LA TABLE QUE VOUS VOULEZ FAIRE DES TRAITEMENTS SUR:--------\n\n");
		printf(" 1-ARTICLES \n ");
		printf("2-UTILISATEURS\n ");
		printf("3-COMMENTAIRES \n ");	
		printf("4-VILLES \n ");
		printf("5-FACTURES\n ");
		printf("6-PANIERS\n ");
		printf("7-COMMANDES\n ");
		printf("8-Quitter \n ");
		do
		{
			printf("\n==> Entrez votre choix: ");
			scanf("%d",&choix);
		}
		while(choix<1 || choix>8);
		switch(choix)
		{
			case 1:Menu_Articles();
			break;
			case 2:Menu_Utilisateur();
			break;
			case 3:Menu_Commentaire();
			break;
			case 4:Menu_Ville();
			break;
			case 5:Menu_Facture();
			break;
			case 6:Menu_Panier();
			break;
			case 7:Menu_Commande();
			break;
			case 8:
			{exit(1);
			}break;
		}
		printf("Voulez vous continuez o\n:");
		scanf("%s",&rep);
		fflush(stdin);
	}while(rep=='o'|| rep=='O');
	


	return 0;
}
