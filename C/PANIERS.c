#include"PANIERS.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct PANIERS PAN;
void AfficherTt_Paniers()
{
	FILE *F;
	F=fopen("PANIERS.txt","r");
	if(F==NULL)
	{printf("probleme d'ouverture  \n");
	}
	printf("-----------------A LISTE DE TOUS LES PANIERS------------------    : \n");	
	printf("\n---------------------------------------------------------------------------------\n");
	do{
			fscanf(F,"%d :%d :%s \n",&PAN.IdPanier,&PAN.IdUtilisateur,&PAN.StatusPanier);
			fflush(stdin);
			printf(" IdPanier  : %d\n",PAN.IdPanier);
			printf(" IdUtilisateur  : %d\n",PAN.IdUtilisateur);
			printf(" StatusPanier : %s\n",PAN.StatusPanier);
			printf("\n---------------------------------------------------------------------------------\n");
	}
	while(!feof(F))	;
	fclose(F);
	
}
int rech_Panier(int Idrech)
{
	FILE*F;
	F=fopen("PANIERS.txt","r");// ouvrir le fichier pour la lecture 
	do
	{            //le format de lecture
		fscanf(F,"%d :%d :%s \n",&PAN.IdPanier,&PAN.IdUtilisateur,&PAN.StatusPanier);
		fflush(stdin);//liberer la memoire 
		if(PAN.IdPanier== Idrech)
			{
				fclose(F);
				return 1;
			}
	}while(!feof(F));// lire tant que ce n'est pas la fin du fichier 
	return -1;
}
void Ajouter_Panier()
{
	FILE*F;
	int num;
	F=fopen("PANIERS.txt","a");
	printf("\n  Entrer l'identifiant du nouveau panier : \n ");
	scanf("%d",&num);
	while (rech_Panier(num) ==1 )
	{
	 printf("Ce numero existe deje\n");
	 printf("\n  Entrer l'identifiant du nouveau panier : \n ");
	 scanf("%d",&num);
	}
	PAN.IdPanier= num ;
	printf("\n Entrez le IdUtilisateur du nouveau panier: \n");
	scanf("%d",&PAN.IdUtilisateur); 
	fflush(stdin);
	printf("\n Entrez le StatusPanier DESACTIVE /ACTIVE  ? \n");
	gets(PAN.StatusPanier); 
	fflush(stdin);
	fprintf(F,"%d :%d :%s \n",PAN.IdPanier,PAN.IdUtilisateur,PAN.StatusPanier);
	fclose(F);
	printf("la panier est bien ajoutee\n");
}
void ModifierPanier()
{
		FILE *Fich,*F;
	
		F = fopen("PANIERS.txt","r");
		int num,i;
		char rep='n';
		printf("\n Entrez le numero du panier a modifie : \n");
		scanf("%d",&num);
		fflush(stdin);
		while (rech_Panier(num) !=1 )
		{
		 printf("ce numero n'existe pas\n");
		printf("\n Entrez le numero du panier a modifie : \n");
		 scanf("%d",&num);
		}
		printf("\n Voulez vous vraiment modifier o\n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep == 'o'|| rep == 'O' )
		{
			
			Fich = fopen("TempPANIERS.txt","a");
				do
				{// a chaque fois je fais un fscanf => je lis une ligne du fichier
					fscanf(F,"%d :%d :%s \n",&PAN.IdPanier,&PAN.IdUtilisateur,&PAN.StatusPanier);
					if(num == PAN.IdPanier)// je teste si le NumRech = numetudiant dans fscanf
					{
						printf("\n Entrez le nouveau  IdUtilisateur de  panier : \n");
						scanf("%d",&PAN.IdUtilisateur); 
						fflush(stdin);
						printf("\n Entrez  le nouveau Status du Panier : \n");
						gets(PAN.StatusPanier); 
						fflush(stdin);
					}
					fprintf(Fich,"%d :%d :%s \n",PAN.IdPanier,PAN.IdUtilisateur,PAN.StatusPanier);
				}
				while(!feof(F))	;
			fclose(Fich);
			fclose(F);
			remove("PANIERS.txt");
			rename("TempPANIERS.txt","PANIERS.txt");
			printf("Modification effectue avec succes");
		}		
	
}
void Recherche_Panier()
{ 
	int NumR;
	printf("\n Entrez le numero du panier a recherche : \n");
	scanf("%d",&NumR);
	FILE*F;
	F=fopen("PANIERS.txt","r");
	while (rech_Panier(NumR) !=1 )
	{
	 printf("Ce panier   n'existe pas\n");
	printf("\n Entrez le numero du panier a recherche : \n");
	 scanf("%d",&NumR);
	}
	
	while(!feof(F))
	{
		fscanf(F,"%d :%d :%s \n",&PAN.IdPanier,&PAN.IdUtilisateur,&PAN.StatusPanier);
		
		if(NumR==PAN.IdPanier)
		{
		
		printf("------------------LES INFORMATIONS DU PANIER   %d :------------------\n",NumR);
		printf(" IdPanier  : %d\n",PAN.IdPanier);
		printf(" IdUtilisateur  : %d\n",PAN.IdUtilisateur);
		printf(" StatusPanier : %s\n",PAN.StatusPanier);
		printf("\n---------------------------------------------------------------------------------\n");

		}

		
	}

	fclose(F);
}
void SupprimerPanier()
{
	char rep ;
	int IdRech;
	printf("\n Entrez le numero du panier a supprime : \n");
	scanf("%d",&IdRech);
	fflush(stdin);
	if(rech_Panier(IdRech)==1)
	{
		printf("\n Voulez vous vraiment supprimer o\n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep == 'o'|| rep == 'O' )
		{
			FILE *Fich,*F;
			F = fopen("PANIERS.txt","r");
			Fich = fopen("TempPANIERS.txt","a");
				do
				{
					fscanf(F,"%d :%d :%s \n",&PAN.IdPanier,&PAN.IdUtilisateur,&PAN.StatusPanier);
					fflush(stdin);
					if(IdRech!=PAN.IdPanier)
					{
					fprintf(Fich,"%d :%d :%s \n",PAN.IdPanier,PAN.IdUtilisateur,PAN.StatusPanier);
						fflush(stdin);
					}
				}
				while(!feof(F))	;
			fclose(Fich);
			fclose(F);
			remove("PANIERS.txt");
			rename("TempPANIERS.txt","PANIERS.txt");
			printf("suppression effectue avec succes");
		}
	
	}
	else
	printf("Ce panier n existe pas\n ");
	
}
void Menu_Panier()
{
int choix,rep;
	do
	{
		system("cls");//netoyer tous ce qui est ecris dans la console 
		printf("****************  MENU  ****************\n");
		printf("1-Ajouter Un Panier \n ");
		printf("2-Rechercher Un Panier \n ");
		printf("3-Supprimer Un Panier \n ");	
		printf("4-Modifier Un Panier \n ");
		printf("5-Afficher tous les Paniers \n ");
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
			case 1:Ajouter_Panier();
			break;
			case 2:Recherche_Panier();
			break;
			case 3:SupprimerPanier();
			break;
			case 4:ModifierPanier();
			break;
			case 5:AfficherTt_Paniers();
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
