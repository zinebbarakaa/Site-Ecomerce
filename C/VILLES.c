#include"VILLES.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct VILLES VL;
int rech_Ville(int Idrech)
{
	FILE*F;
	F=fopen("VILLES.txt","r");// ouvrir le fichier pour la lecture 
	do
	{            //le format de lecture
		fscanf(F,"%d :%s :%s :%f \n",&VL.IdVille,&VL.NomVille,&VL.CodePostalVille,&VL.PrixLivraisonVille);
		fflush(stdin);//liberer la memoire 
		if(VL.IdVille == Idrech)
			{
				fclose(F);
				return 1;
			}
	}while(!feof(F));// lire tant que ce n'est pas la fin du fichier 
	return -1;
}
void AfficherTt_Ville()
{
	FILE *F;
	F=fopen("VILLES.txt","r");
	if(F==NULL)
	{printf("probleme d'ouverture  \n");
	}
	printf("------------  lA LISTE DE TOUS LES VILLES  ---------  : \n");	
	printf("\n---------------------------------------------------------------------------------\n");
	do{
			fscanf(F,"%d :%s :%s :%f \n",&VL.IdVille,&VL.NomVille,&VL.CodePostalVille,&VL.PrixLivraisonVille);
			fflush(stdin);
			printf(" IdVille  : %d\n",VL.IdVille);
			printf(" NomVille  : %s\n",VL.NomVille);
			printf(" CodePostalVille : %s\n",VL.CodePostalVille);
			printf(" PrixLivraisonVille  : %f\n",VL.PrixLivraisonVille);
			printf("\n---------------------------------------------------------------------------------\n");
	}
	while(!feof(F))	;
	fclose(F);
	
}
void AjoutVille()
{
	FILE*F;
	int num;
	F=fopen("VILLES.txt","a");
	printf("\n  entrer l'identifiant de nouveau Ville: \n ");
	scanf("%d",&num);
	while (rech_Ville(num) ==1 )
	{
	 printf("ce numero existe deje\n");
	 printf("\n  entrer l'identifiant de nouveau Ville: \n ");
	 scanf("%d",&num);
	}
	VL.IdVille = num ;
	printf("\n Entrez le nom de la nouvelle  Ville : \n");
	scanf("%d",&VL.NomVille);
	fflush(stdin);
	printf("\n Entrez la code postal de la nouvelle  Ville : \n");
	gets(VL.CodePostalVille); 
	fflush(stdin);
	printf("\n Entrez le prix de la livraison  de la nouvelle Ville : \n");
	scanf("%f",&VL.PrixLivraisonVille);
	fflush(stdin);
	fprintf(F,"%d :%s :%s :%.2f \n",VL.IdVille,VL.NomVille,VL.CodePostalVille,VL.PrixLivraisonVille);
	fclose(F);
	printf("la ville est bien ajoutee\n");
}
void ModifierVille()
{
		FILE *Fich,*F;
	
		F = fopen("VILLES.txt","r");
		int num,i;
		char rep='n';
		printf("\n Entrez le numero de la ville a modifie : \n");
		scanf("%d",&num);
		fflush(stdin);
		while (rech_Ville(num) !=1 )
		{
		 printf("ce numero n'existe pas\n");
		 printf("\n  Entrez le numero de la ville a modifie : \n ");
		 scanf("%d",&num);
		}
		printf("\n voulez vous vraiment modifier o\n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep == 'o'|| rep == 'O' )
		{
			
			Fich = fopen("TempVILLES.txt","a");
				do
				{// a chaque fois je fais un fscanf => je lis une ligne du fichier
					fscanf(F,"%d :%s :%s :%f \n",&VL.IdVille,&VL.NomVille,&VL.CodePostalVille,&VL.PrixLivraisonVille);
					if(num == VL.IdVille)// je teste si le NumRech = numetudiant dans fscanf
					{
						VL.IdVille=num;
						printf("\n Entrez le nom de la nouvelle  Ville : \n");
						gets(VL.NomVille); 
						fflush(stdin);
						printf("\n Entrez la code postal de la nouvelle  Ville : \n");
						gets(VL.CodePostalVille); 
						fflush(stdin);
						printf("\n Entrez le prix de la livraison  de la nouvelle Ville : \n");
						scanf("%f",&VL.PrixLivraisonVille);
						fflush(stdin);
					}
					fprintf(Fich,"%d :%s :%s :%.2f \n",VL.IdVille,VL.NomVille,VL.CodePostalVille,VL.PrixLivraisonVille);
				}
				while(!feof(F))	;
			fclose(Fich);
			fclose(F);
			remove("VILLES.txt");
			rename("TempVILLES.txt","VILLES.txt");
			printf("modification effectue avec succes");
		};
	
		
		
	
}
void Recherche_Ville()
{ 
	int NumR;
	printf("\n Entrez le numero de la ville a recherche : \n");
	scanf("%d",&NumR);
	FILE*F;
	F=fopen("VILLES.txt","r");
	while (rech_Ville(NumR)!=1 )
	{
	 printf("cette ville  n'existe pas\n");
	 printf("\n Entrez le numero de la ville a recherche  : \n ");
	 scanf("%d",&NumR);
	}
	
	while(!feof(F))
	{
		fscanf(F,"%d :%s :%s :%f \n",&VL.IdVille,&VL.NomVille,&VL.CodePostalVille,&VL.PrixLivraisonVille);
		
		if(NumR==VL.IdVille)
		{
		
		printf("------------------Les informations de la ville  %d :------------------\n",NumR);
		printf(" IdVille  : %d\n",VL.IdVille);
		printf(" NomVille  : %s\n",VL.NomVille);
		printf(" CodePostalVille : %s\n",VL.CodePostalVille);
		printf(" PrixLivraisonVille  : %.2f\n",VL.PrixLivraisonVille);
		printf("\n---------------------------------------------------------------------------------\n");

		}

		
	}

	fclose(F);
}
void SupprimerVille()
{
	char rep ;
	int IdRech;
	printf("\n Entrez le numero de la ville a supprime : \n");
	scanf("%d",&IdRech);
	fflush(stdin);
	if(rech_Ville(IdRech)==1)
	{
		printf("\n voulez vous vraiment supprimer o\n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep == 'o'|| rep == 'O' )
		{
			FILE *Fich,*F;
			F = fopen("VILLES.txt","r");
			Fich = fopen("TempVILLES.txt","a");
				do
				{
					fscanf(F,"%d :%s :%s :%f \n",&VL.IdVille,&VL.NomVille,&VL.CodePostalVille,&VL.PrixLivraisonVille);
					fflush(stdin);
					if(IdRech!=VL.IdVille)
					{
					fprintf(Fich,"%d :%s :%s :%.2f \n",VL.IdVille,VL.NomVille,VL.CodePostalVille,VL.PrixLivraisonVille);
						fflush(stdin);
					}
				}
				while(!feof(F))	;
			fclose(Fich);
			fclose(F);
			remove("VILLES.txt");
			rename("TempVILLES.txt","VILLES.txt");
			printf("Suppression effectue avec succes");
		}
	
	}
	else
	printf("cette ville n existe pas\n ");
	
}
void Menu_Ville()
{
int choix,rep;
	do
	{
		system("cls");//netoyer tous ce qui est ecris dans la console 
		printf("****************  MENU  ****************\n");
		printf("1-Ajouter Une Ville \n ");
		printf("2-Rechercher Une Ville \n ");
		printf("3-Supprimer Une Ville \n ");	
		printf("4-Modifier Une Ville \n ");
		printf("5-Afficher tous les Villes \n ");
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
			case 1:AjoutVille();
			break;
			case 2:Recherche_Ville();
			break;
			case 3:SupprimerVille();
			break;
			case 4:ModifierVille();
			break;
			case 5:AfficherTt_Ville();
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

