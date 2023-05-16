#include"UTILISATEURS.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"RECHERCHE.h"
int rech_utilisateur(int Idrech)
{
	FILE*F;
	F=fopen("UTILISATEURS.txt","r");
	do
	{         
			fscanf(F,"%d :%s :%s :%s :%s :%s :%s :%s :%s \n",&UTIL.IdUtilisateur,&UTIL.NomUtilisateur,&UTIL.PrenomUtilisateur,&UTIL.EmailUtilisateur,&UTIL.DateNaissUtilisateur,&UTIL.AdresseUtilisateur,&UTIL.TelUtilisateur,&UTIL.TypeUtilisateur,&UTIL.MotPasseUtilisateur);
		fflush(stdin);
		if(UTIL.IdUtilisateur == Idrech)
			{
				fclose(F);
				return 1;
			}
	}while(!feof(F));
	return -1;
}
void AfficherTt_Utilisateur()
{
	FILE *F;
	F=fopen("UTILISATEURS.txt","r");
	if(F==NULL)
	{printf("probleme d'ouverture  \n");
	}
	printf("------------  lA LISTE DE TOUS LES UTILISATEURS  ---------  : \n");	
	printf("\n---------------------------------------------------------------------------------\n");
	do{
			fscanf(F,"%d :%s :%s :%s :%s :%s :%s :%s :%s \n",&UTIL.IdUtilisateur,&UTIL.NomUtilisateur,&UTIL.PrenomUtilisateur,&UTIL.EmailUtilisateur,&UTIL.DateNaissUtilisateur,&UTIL.AdresseUtilisateur,&UTIL.TelUtilisateur,&UTIL.TypeUtilisateur,&UTIL.MotPasseUtilisateur);
			fflush(stdin);
			printf(" IdUtilisateur  : %d\n",UTIL.IdUtilisateur);
			printf(" NomUtilisateur  : %s\n",UTIL.NomUtilisateur);
			printf(" PrenomUtilisateur : %s\n",UTIL.PrenomUtilisateur);
			printf(" EmailUtilisateur  : %s\n",UTIL.EmailUtilisateur);
			printf(" DateNaissUtilisateur  : %s\n",UTIL.DateNaissUtilisateur);
			printf(" AdresseUtilisateur  : %s\n",UTIL.AdresseUtilisateur);
			printf(" TelUtilisateur  : %s\n",UTIL.TelUtilisateur);
			printf(" TypeUtilisateur  : %s\n",UTIL.TypeUtilisateur);
			printf(" MotPasseUtilisateur  : %s\n",UTIL.MotPasseUtilisateur);
			printf("\n---------------------------------------------------------------------------------\n");
	}
	while(!feof(F))	;
	fclose(F);
	
}
void AjoutUtilisateur()
{
	FILE*F;
	int num;
	F=fopen("UTILISATEURS.txt","a");
	printf("\n  entrer l'identifiant de nouveau utilisateur: \n ");
	scanf("%d",&num);
	while (rech_utilisateur(num) ==1 )
	{
	 printf("ce numero existe deja\n");
	 printf("\n  entrer l'identifiant de nouveau Utilisateur: \n ");
	 scanf("%d",&num);
	}
	UTIL.IdUtilisateur= num ;
	printf("\n Entrez le nom du  nouveau utilisateur : \n");
		gets(UTIL.NomUtilisateur); 
	fflush(stdin);
	printf("\n Entrez e prenom de nouveau utilisateur : \n");
		gets(UTIL.PrenomUtilisateur); 
	fflush(stdin);
	printf("\n Entrez le email de nouveau utilisateur : \n");
	gets(UTIL.EmailUtilisateur); 
	fflush(stdin);
	printf("\n Entrez la date de naissance  du nouveau  utilisateur : \n");
	gets(UTIL.DateNaissUtilisateur);
	fflush(stdin);
	printf("\n Entrez l'adresse   du nouveau  utilisateur : \n");
	gets(UTIL.AdresseUtilisateur);
	fflush(stdin);
	printf("\n Entrez la numero de telephone   du nouveau  utilisateur : \n");
	gets(UTIL.TelUtilisateur);
	fflush(stdin);
	printf("\n Entrez le type  du nouveau  utilisateur : \n");
	gets(UTIL.TypeUtilisateur);
	fflush(stdin);
	printf("\n Entrez la mot passe  du nouveau  utilisateur : \n");
	gets(UTIL.MotPasseUtilisateur);
	fflush(stdin);
	fprintf(F,"%d :%s :%s :%s :%s :%s :%s :%s :%s \n",UTIL.IdUtilisateur,UTIL.NomUtilisateur,UTIL.PrenomUtilisateur,UTIL.EmailUtilisateur,UTIL.DateNaissUtilisateur,UTIL.AdresseUtilisateur,UTIL.TelUtilisateur,UTIL.TypeUtilisateur,UTIL.MotPasseUtilisateur);
	fclose(F);
	printf("le utilisateur est bien ajoutee\n");
}
void ModifierUtilisateur()
{
		FILE *Fich,*F;
	
		F = fopen("UTILISATEURS.txt","r");
		int num,i;
		char rep='n';
		printf("\n Entrez le numero du Utilisateur a modifie : \n");
		scanf("%d",&num);
		fflush(stdin);
		if(rech_utilisateur(num)==1)
		{
		printf("\n voulez vous vraiment modifier o\n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep == 'o'|| rep == 'O' )
		{
			
			Fich = fopen("TempUTILISATEURS.txt","a");
				do
				{// a chaque fois je fais un fscanf => je lis une ligne du fichier
			fscanf(F,"%d :%s :%s :%s :%s :%s :%s :%s :%s \n",&UTIL.IdUtilisateur,&UTIL.NomUtilisateur,&UTIL.PrenomUtilisateur,&UTIL.EmailUtilisateur,&UTIL.DateNaissUtilisateur,&UTIL.AdresseUtilisateur,&UTIL.TelUtilisateur,&UTIL.TypeUtilisateur,&UTIL.MotPasseUtilisateur);
					if(num == UTIL.IdUtilisateur)// je teste si le NumRech = numetudiant dans fscanf
					{
						UTIL.IdUtilisateur = num;
						printf("\n Entrez le  nouveau nom de l'utilisateur : \n");
						gets(UTIL.NomUtilisateur); 
						fflush(stdin);
						printf("\n Entrez le nouveau prenom de l'utilisateur : \n");
						gets(UTIL.PrenomUtilisateur);  
						fflush(stdin);
						printf("\n Entrez le nouveau email de nouveau de l'utilisateur : \n");
						gets(UTIL.EmailUtilisateur); 
						fflush(stdin);
						printf("\n Entrez la nouvelle  date de naissance  de l'utilisateur : \n");
						gets(UTIL.DateNaissUtilisateur);
						fflush(stdin);
						printf("\n Entrez  la nouvelle adresse de l'utilisateur : \n");
						gets(UTIL.AdresseUtilisateur);
						fflush(stdin);
						printf("\n Entrez  le nouveau numero de telephone  de l'utilisateur : \n");
						gets(UTIL.TelUtilisateur);
						fflush(stdin);
						printf("\n Entrez  le nouveau type  de l'utilisateur: \n");
						gets(UTIL.TypeUtilisateur);
						fflush(stdin);
						printf("\n Entrez  le nouveau mot passe  de l'utilisateur : \n");
						gets(UTIL.MotPasseUtilisateur);
						fflush(stdin);
					}
						fprintf(Fich,"%d :%s :%s :%s :%s :%s :%s :%s :%s \n",UTIL.IdUtilisateur,UTIL.NomUtilisateur,UTIL.PrenomUtilisateur,UTIL.EmailUtilisateur,UTIL.DateNaissUtilisateur,UTIL.AdresseUtilisateur,UTIL.TelUtilisateur,UTIL.TypeUtilisateur,UTIL.MotPasseUtilisateur);
				}
				while(!feof(F))	;
			fclose(Fich);
			fclose(F);
			remove("UTILISATEURS.txt");
			rename("TempUTILISATEURS.txt","UTILISATEURS.txt");
			printf("modification effectue avec succes");
		};
	
		}
	else
	{
		printf("ce numero d'etudiant n'existe pas ");
	}
		
	
}
void Recherche_Utilisateur()
{ 
	int NumR;
	printf("\n Entrez le numero du Utilisateur  a recherche : \n");
	scanf("%d",&NumR);
	FILE*F;
	F=fopen("UTILISATEURS.txt","r");
	if(rech_utilisateur!=1)
	printf("l'utilisateur recherche n'existe pas \n");
	while(!feof(F))
	{
		fscanf(F,"%d :%s :%s :%s :%s :%s :%s :%s :%s \n",&UTIL.IdUtilisateur,&UTIL.NomUtilisateur,&UTIL.PrenomUtilisateur,&UTIL.EmailUtilisateur,&UTIL.DateNaissUtilisateur,&UTIL.AdresseUtilisateur,&UTIL.TelUtilisateur,&UTIL.TypeUtilisateur,&UTIL.MotPasseUtilisateur);
		if(NumR == UTIL.IdUtilisateur) // si le numero que tu cherche egale au numero de la structure 
			{ 
			printf("Les informations de l'utilisateur %d :\n",NumR);
			printf(" IdUtilisateur  : %d\n",UTIL.IdUtilisateur);
			printf(" NomUtilisateur  : %s\n",UTIL.NomUtilisateur);
			printf(" PrenomUtilisateur : %s\n",UTIL.PrenomUtilisateur);
			printf(" EmailUtilisateur  : %s\n",UTIL.EmailUtilisateur);
			printf(" DateNaissUtilisateur  : %s\n",UTIL.DateNaissUtilisateur);
			printf(" AdresseUtilisateur  : %s\n",UTIL.AdresseUtilisateur);
			printf(" TelUtilisateur  : %s\n",UTIL.TelUtilisateur);
			printf(" TypeUtilisateur  : %s\n",UTIL.TypeUtilisateur);
			printf(" MotPasseUtilisateur  : %s\n",UTIL.MotPasseUtilisateur);
			printf("\n---------------------------------------------------------------------------------\n");

			}
	}

	fclose(F);
}
void SupprimerUtilisateur()
{
	char rep ;
	int IdRech;
	printf("\n Entrez le numero du utilisateur  a supprime : \n");
	scanf("%d",&IdRech);
	fflush(stdin);
	if(rech_utilisateur(IdRech)==1)
	{
		printf("\n voulez vous vraiment supprimer o\n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep == 'o'|| rep == 'O' )
		{
			FILE *Fich,*F;
			F = fopen("UTILISATEURS.txt","r");
			Fich = fopen("TempUTILISATEURS.txt","a");
				do
				{
					fscanf(F,"%d :%s :%s :%s :%s :%s :%s :%s :%s \n",&UTIL.IdUtilisateur,&UTIL.NomUtilisateur,&UTIL.PrenomUtilisateur,&UTIL.EmailUtilisateur,&UTIL.DateNaissUtilisateur,&UTIL.AdresseUtilisateur,&UTIL.TelUtilisateur,&UTIL.TypeUtilisateur,&UTIL.MotPasseUtilisateur);
					fflush(stdin);
					if(IdRech!=UTIL.IdUtilisateur)
					{
					fprintf(Fich,"%d :%s :%s :%s :%s :%s :%s :%s :%s \n",UTIL.IdUtilisateur,UTIL.NomUtilisateur,UTIL.PrenomUtilisateur,UTIL.EmailUtilisateur,UTIL.DateNaissUtilisateur,UTIL.AdresseUtilisateur,UTIL.TelUtilisateur,UTIL.TypeUtilisateur,UTIL.MotPasseUtilisateur);
						fflush(stdin);
					}
				}
				while(!feof(F))	;
			fclose(Fich);
			fclose(F);
			remove("UTILISATEURS.txt");
			rename("TempUTILISATEURS.txt","UTILISATEURS.txt");
			printf("suppression effectue avec succes");
		}
	
	}
	else
	printf("ce Utilisateur n existe pas\n ");
	
}
void Menu_Utilisateur()
{
int choix,rep;
	do
	{
		system("cls");//netoyer tous ce qui est ecris dans la console 
		printf("****************  MENU  ****************\n");
		printf("1-Ajouter Un Utilisateur \n ");
		printf("2-Rechercher Un Utilisateur \n ");
		printf("3-Supprimer Un Utilisateur \n ");	
		printf("4-Modifier Un Utilisateur \n ");
		printf("5-Afficher tous les Utilisateurs \n ");
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
			case 1:AjoutUtilisateur();
			break;
			case 2:Recherche_Utilisateur();
			break;
			case 3:SupprimerUtilisateur();
			break;
			case 4:ModifierUtilisateur();
			break;
			case 5:AfficherTt_Utilisateur();
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
