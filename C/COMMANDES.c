#include"COMMANDES.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct COMMANDES CMD;
// DANS CETTE TABLE ON A TRAVAILLE DANS TOUS LES FONCTINS PAR LE IdPanier ET L'idArticle CAR LA TABLE COMMANDES EST UNE ASSOCTIATION DONC SON CLE PRIMAIRE EST (IdPanier,IdArticle)
//la fonction rech_commande a pour but de recherche une commande dans le ficchier COMMANDES si il trouve le couple  Idpanier et IdArtcle  il retourne 1 sinon il retourne -1

int rech_commande(int Idpanier,int Idarticle)
{
	FILE*F;
	F=fopen("COMMANDES.txt","r");// ouvrir le fichier pour la lecture 
	do
	{            //le format de lecture
		fscanf(F,"%d :%d :%d \n",&CMD.IdPanier,&CMD.IdArticle,&CMD.QtCmd);
		fflush(stdin);//liberer la memoire 
		if((CMD.IdPanier == Idpanier)&&(CMD.IdArticle == Idarticle))
			{
				fclose(F);
				return 1;
			}
	}while(!feof(F));// lire tant que ce n'est pas la fin du fichier 
	return -1;
}
// la fonction AfficherTt_Article() il affiche tous les articles stockee dans le fichier ARTICLES 


void Afficher_Tt_Commandes()
{
	FILE *F;
	F=fopen("COMMANDES.txt","r");
	if(F==NULL)
	{printf("Probleme d'ouverture  \n");
	}
	printf("------------  lA LISTE DE TOUS LES COMMANDES  ---------  : \n");	
	printf("\n---------------------------------------------------------------------------------\n");
	do{
			fscanf(F,"%d :%d :%d \n",&CMD.IdPanier,&CMD.IdArticle,&CMD.QtCmd);
			fflush(stdin);
			printf(" IdPanier  : %d\n",CMD.IdPanier);
			printf(" IdArticle  : %d\n",CMD.IdArticle);
			printf(" QtCmd : %d\n",CMD.QtCmd);
			printf("\n---------------------------------------------------------------------------------\n");
	}
	while(!feof(F))	;
	fclose(F);
	
}
/*la fonction AjoutCommande() a pour but d'ajouter une nouvelle commande dans le fichiers des COMMANDES le principe c'est que on demande le IdPanier et l'IdArticle de La commande et on recherche
 si il existe avant a l'aide de la fonction rech_Commande si la commande  il ne se trouve pas dans le fichier on demande les informations de la commnade puis  on les ecrit dans le fichier COMMANDES  
 a l'aie de la fonction fprintf */
void AjoutCommande()
{
	FILE*F;
	int Idpanier,Idarticle;
	F=fopen("COMMANDES.txt","a");
	if(F==NULL)
	printf("Probleme d'ouverture\n");
	printf("\n  Entrer le couple des identifiants de la nouvelle commande: \n ");
	scanf("%d%d",&Idpanier,&Idarticle);
	while (rech_commande(Idpanier,Idarticle) ==1 )
	{
	 printf("Ce couple existe deja \n");
	 printf("\n  Entrer le couple des identifiants de la nouvelle commande: \n ");
	scanf("%d%d",&Idpanier,&Idarticle);
	}
	CMD.IdPanier= Idpanier ;
	CMD.IdArticle=Idarticle;
	printf("\n Entrez la quantite commande de l'article : \n");
	scanf("%d",&CMD.QtCmd);
	fflush(stdin);
	fprintf(F,"%d :%d :%d \n",CMD.IdPanier,CMD.IdArticle,CMD.QtCmd);
	fclose(F);
	printf("la Commande est bien ajoutee\n");
}
void ModifierCommande()
{
		FILE *Fich,*F;
	
		F = fopen("COMMANDES.txt","r");
		int Idpanier,Idarticle,i;
		char rep='n';
		printf("\n Entrez le couple d'identidiant  de la commande a modifie : \n");
		scanf("%d%d",&Idpanier,&Idarticle);
		fflush(stdin);
		while (rech_commande(Idpanier,Idarticle) !=1 )
		{
		 printf("Ce numero n'existe pas\n");
		printf("\n Entrez le couple d'identidiant  de la commande a modifie : \n");
		scanf("%d%d",&Idpanier,&Idarticle);
		}
		printf("\n Voulez vous vraiment modifier o\n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep == 'o'|| rep == 'O' )
		{
			
			Fich = fopen("TempCOMMANDES.txt","a");
				do
				{// a chaque fois je fais un fscanf => je lis une ligne du fichier
					fscanf(F,"%d :%d :%d \n",&CMD.IdPanier,&CMD.IdArticle,&CMD.QtCmd);
					if((Idpanier == CMD.IdPanier)&&(Idarticle==CMD.IdArticle))// je teste si le NumRech = numetudiant dans fscanf
					{
						printf("\n Entrez le nouvelle quantite de la commande : \n");
						scanf("%d",&CMD.QtCmd); 
						fflush(stdin);
					}
					fprintf(Fich,"%d :%d :%d \n",CMD.IdPanier,CMD.IdArticle,CMD.QtCmd);
				}
				while(!feof(F))	;
			fclose(Fich);
			fclose(F);
			remove("COMMANDES.txt");
			rename("TempCOMMANDES.txt","COMMANDES.txt");
			printf("suppression effectue avec succes");
		}		
	
}
 // la fonction Recherche_Commande() il recherche une commande et affiche tous les informations de la commande recherche 

void Recherche_Commande()
{ 
		int Idpanier,Idarticle,i;
	printf("\n Entrez le couple d'identidiant  de la commande a recherche : \n");
	scanf("%d%d",&Idpanier,&Idarticle);
	FILE*F;
	F=fopen("COMMANDES.txt","r");
	while (rech_commande(Idpanier,Idarticle) !=1 )
	{
	 printf("Cette commande  n'existe pas\n");
	 printf("\n Entrez le couple d'identidiant  de la commande a recherche  : \n ");
	scanf("%d%d",&Idpanier,&Idarticle);
	}
	
	while(!feof(F))
	{
		fscanf(F,"%d :%d :%d \n",&CMD.IdPanier,&CMD.IdArticle,&CMD.QtCmd);
		
		if((Idpanier==CMD.IdPanier)&&(Idarticle==CMD.IdArticle))
		{
		
		printf("------------------Les informations de la Commande (%d,%d) :------------------\n",Idpanier,Idarticle);
		printf(" IdPanier  : %d\n",CMD.IdPanier);
		printf(" IdArticle  : %d\n",CMD.IdArticle);
		printf(" QtCmd : %d\n",CMD.QtCmd);
		printf("\n---------------------------------------------------------------------------------\n");

		}

		
	}

	fclose(F);
}
void SupprimerCommande()
{
	char rep ;
	int Idpanier,Idarticle,i;
	printf("\n Entrez le couple d'identifiant  de la commande a supprime : \n");
	scanf("%d%d",&Idpanier,&Idarticle);
	FILE*F;
	F=fopen("COMMANDES.txt","r");
	while (rech_commande(Idpanier,Idarticle) !=1 )
	{
	 printf("Cette commande  n'existe pas\n");
	 printf("\n Entrez le couple d'identifiant  de la commande a supprime  : \n ");
	scanf("%d%d",&Idpanier,&Idarticle);
	}
	
		printf("\n Voulez vous vraiment supprimer o\n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep == 'o'|| rep == 'O' )
		{
			FILE *Fich,*F;
			F = fopen("COMMANDES.txt","r");
			Fich = fopen("TempCOMMANDES.txt","a");
				do
				{
					fscanf(F,"%d :%d :%d \n",&CMD.IdPanier,&CMD.IdArticle,&CMD.QtCmd);
					fflush(stdin);
					if((Idpanier != CMD.IdPanier)&&(Idarticle!=CMD.IdArticle))// je teste si le NumRech = numetudiant dans fscanf
					{
					fprintf(Fich,"%d :%d :%d \n",CMD.IdPanier,CMD.IdArticle,CMD.QtCmd);
						fflush(stdin);
					}
				}
				while(!feof(F))	;
			fclose(Fich);
			fclose(F);
			remove("COMMANDES.txt");
			rename("TempCOMMANDES.txt","COMMANDES.txt");
			printf("suppression effectue avec succes");
		}
	
	
}
void Menu_Commande()
{
int choix,rep;
	do
	{
		system("cls");//netoyer tous ce qui est ecris dans la console 
		printf("****************  MENU  ****************\n");
		printf("1-Ajouter Une Commande \n ");
		printf("2-Rechercher Une Commande\n ");
		printf("3-Supprimer Une Commande \n ");	
		printf("4-Modifier Une Commande \n ");
		printf("5-Afficher tous les Commandes \n ");
		printf("7-Retourner Au Menu Principale \n ");
		printf("6-Quitter \n ");
		do
		{
			printf("\n Entrez votre choix: ");
			scanf("%d",&choix);
		}
		while(choix<1 || choix>7);
		switch(choix)
		{
			case 1:AjoutCommande();
			break;
			case 2:Recherche_Commande();
			break;
			case 3:SupprimerCommande();
			break;
			case 4:ModifierCommande();
			break;
			case 5:Afficher_Tt_Commandes();
			break;
			case 6:
			{exit(1);
			}break;
			case 7:
				{int choix,rep;
	do
	{
		system("cls");//netoyer tous ce qui est ecris dans la console 
		printf("*****************************      MENU     *****************************\n\n");
		printf("------CHOISIR LA TABLE QUE VOUS VOULEZ FAIRE DES TRAITEMENTS SUR:----\n\n");
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
			case 6:Menu_Commande();
			break;
			case 7:Menu_Panier();
			break;
			case 8:
			{exit(1);
			}break;
		}
		printf("Voulez vous continuez o\n:");
		scanf("%s",&rep);
		fflush(stdin);
	}while(rep=='o'|| rep=='O');
				}
			break;
		}
		printf("Voulez vous continuez o\n:");
		scanf("%s",&rep);
		fflush(stdin);
	}while(rep=='o'|| rep=='O');
	
}
