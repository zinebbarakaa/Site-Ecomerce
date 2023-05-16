#include"FACTURES.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct FACTURES FACT;
int rech_facture(int Idrech)
{
	FILE*F;
	F=fopen("FACTURES.txt","r");// ouvrir le fichier pour la lecture 
	do
	{            //le format de lecture
		fscanf(F,"%d :%d :%s \n",&FACT.IdFacture,&FACT.IdPanier,&FACT.DateFacturation);
		fflush(stdin);//liberer la memoire 
		if(FACT.IdFacture== Idrech)
			{
				fclose(F);
				return 1;
			}
	}while(!feof(F));// lire tant que ce n'est pas la fin du fichier 
	return -1;
}
void AfficherTt_Facture()
{
	FILE *F;
	F=fopen("FACTURES.txt","r");
	if(F==NULL)
	{printf("probleme d'ouverture  \n");
	}
	printf("-----------------lA LISTE DE TOUS LES FACTURES ----------------   : \n");	
	printf("\n---------------------------------------------------------------------------------\n");
	do{
			fscanf(F,"%d :%d :%s \n",&FACT.IdFacture,&FACT.IdPanier,&FACT.DateFacturation);
			fflush(stdin);
			printf(" IdFacture  : %d\n",FACT.IdFacture);
			printf(" IdPanier  : %d\n",FACT.IdPanier);
			printf(" DateFacturation : %s\n",FACT.DateFacturation);
			printf("\n---------------------------------------------------------------------------------\n");
	}
	while(!feof(F))	;
	fclose(F);
	
}
void AjoutFacture()
{
	FILE*F;
	int num;
	F=fopen("FACTURES.txt","a");
	printf("\n  entrer l'identifiant de la nouvelle facture : \n ");
	scanf("%d",&num);
	while (rech_facture(num) ==1 )
	{
	 printf("ce numero existe deje\n");
	 printf("\n  entrer l'identifiant de la nouvelle facture : \n ");
	 scanf("%d",&num);
	}
	FACT.IdFacture= num ;
	printf("\n Entrez le IdPanier de la nouvelle  facture : \n");
	scanf("%d",&FACT.IdPanier); 
	fflush(stdin);
	printf("\n Entrez la Date de Facturation de la nouvelle  facture : \n");
	gets(FACT.DateFacturation); 
	fflush(stdin);
	fprintf(F,"%d :%d :%s \n",FACT.IdFacture,FACT.IdPanier,FACT.DateFacturation);
	fclose(F);
	printf("la facture est bien ajoutee\n");
}
void ModifierFacture()
{
		FILE *Fich,*F;
	
		F = fopen("FACTURES.txt","r");
		int num,i;
		char rep='n';
		printf("\n Entrez le numero de la facture a modifie : \n");
		scanf("%d",&num);
		fflush(stdin);
		while (rech_facture(num) !=1 )
		{
		 printf("Ce numero n'existe pas\n");
		 printf("\n  Entrez l'identifiant de la nouvelle facture : \n ");
		 scanf("%d",&num);
		}
		printf("\n Voulez vous vraiment modifier o\n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep == 'o'|| rep == 'O' )
		{
			
			Fich = fopen("TempFACTURES.txt","a");
				do
				{// a chaque fois je fais un fscanf => je lis une ligne du fichier
					fscanf(F,"%d :%d :%s \n",&FACT.IdFacture,&FACT.IdPanier,&FACT.DateFacturation);
					if(num == FACT.IdFacture)// je teste si le NumRech = numetudiant dans fscanf
					{
						printf("\n Entrez le nouveau  IdPanier de  facture : \n");
						scanf("%d",&FACT.IdPanier); 
						fflush(stdin);
						printf("\n Entrez la nouvelle Date de Facturation de la facture : \n");
						gets(FACT.DateFacturation); 
						fflush(stdin);
					}
					fprintf(Fich,"%d :%d :%s \n",FACT.IdFacture,FACT.IdPanier,FACT.DateFacturation);
				}
				while(!feof(F))	;
			fclose(Fich);
			fclose(F);
			remove("FACTURES.txt");
			rename("TempFACTURES.txt","FACTURES.txt");
			printf("Modification effectue avec succes");
		}		
	
}
void Recherche_Facture()
{ 
	int NumR;
	printf("\n Entrez le numero de la Facture a recherche : \n");
	scanf("%d",&NumR);
	FILE*F;
	F=fopen("FACTURES.txt","r");
	while (rech_facture(NumR) !=1 )
	{
	 printf("Cette Facture  n'existe pas\n");
	 printf("\n Entrez le numero de la Facture a recherche  : \n ");
	 scanf("%d",&NumR);
	}
	
	while(!feof(F))
	{
		fscanf(F,"%d :%d :%s \n",&FACT.IdFacture,&FACT.IdPanier,&FACT.DateFacturation);
		
		if(NumR==FACT.IdFacture)
		{
		
		printf("------------------Les informations de la ville  %d :------------------\n",NumR);
		printf(" IdFacture  : %d\n",FACT.IdFacture);
		printf(" IdPanier  : %d\n",FACT.IdPanier);
		printf(" DateFacturation : %s\n",FACT.DateFacturation);
		printf("\n---------------------------------------------------------------------------------\n");

		}

		
	}

	fclose(F);
}
void SupprimerFacture()
{
	char rep ;
	int IdRech;
	printf("\n Entrez le numero de la Facture a supprime : \n");
	scanf("%d",&IdRech);
	fflush(stdin);
	while (rech_facture(IdRech) !=1 )
	{
	 printf("Cette Facture  n'existe pas\n");
	 printf("\n Entrez le numero de la Facture a recherche  : \n ");
	 scanf("%d",&IdRech);
	}
		printf("\nVoulez vous vraiment supprimer o\n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep == 'o'|| rep == 'O' )
		{
			FILE *Fich,*F;
			F = fopen("FACTURES.txt","r");
			Fich = fopen("TempFACTURES.txt","a");
				do
				{
					fscanf(F,"%d :%d :%s \n",&FACT.IdFacture,&FACT.IdPanier,&FACT.DateFacturation);
					fflush(stdin);
					if(IdRech!=FACT.IdFacture)
					{
					fprintf(Fich,"%d :%d :%s \n",FACT.IdFacture,FACT.IdPanier,FACT.DateFacturation);
						fflush(stdin);
					}
				}
				while(!feof(F))	;
			fclose(Fich);
			fclose(F);
			remove("FACTURES.txt");
			rename("TempFACTURES.txt","FACTURES.txt");
			printf("suppression effectue avec succes");
		}
	
	
}
void Menu_Facture()
{
int choix,rep;
	do
	{
		system("cls");//netoyer tous ce qui est ecris dans la console 
		printf("****************  MENU  ****************\n");
		printf("1-Ajouter Une Facture \n ");
		printf("2-Rechercher Une Facture \n ");
		printf("3-Supprimer Une Facture \n ");	
		printf("4-Modifier Une Facture \n ");
		printf("5-Afficher tous les Factures \n ");
		printf("6-Quitter \n ");
		printf("7-Retourner Au Menu Principale \n ");

		do
		{
			printf("\n Entrez votre choix: ");
			scanf("%d",&choix);
		}
		while(choix<1 || choix>7);
		switch(choix)
		{
			case 1:AjoutFacture();
			break;
			case 2:Recherche_Facture();
			break;
			case 3:SupprimerFacture();
			break;
			case 4:ModifierFacture();
			break;
			case 5:AfficherTt_Facture();
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

