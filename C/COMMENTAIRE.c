#include"COMMENTAIRE.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct COMMENTAIRES CMTR;
int rech_commentaire(int Idrech)
{
	FILE*F;
	F=fopen("COMMENTAIRES.txt","r");
	do
	{         
	fscanf(F,"%d :%d :%d :%s :%s \n",&CMTR.IdComment,&CMTR.IdUtilisateur,&CMTR.IdArticle,&CMTR.TextComment,&CMTR.DateComment);
		fflush(stdin);
		if(CMTR.IdComment == Idrech)
			{
				fclose(F);
				return 1;
			}
	}while(!feof(F));
	return -1;
}
void AfficherTt_Commentaire()
{
	FILE *F;
	F=fopen("COMMENTAIRES.txt","r");
	if(F==NULL)
	{printf("probleme d'ouverture  \n");
	}
	printf("------------  lA LISTE DE TOUS LES COMMENTAIRES  ---------  : \n");
	printf("\n---------------------------------------------------------------------------------\n");
	
	do{
			fscanf(F,"%d :%d :%d :%s :%s \n",&CMTR.IdComment,&CMTR.IdUtilisateur,&CMTR.IdArticle,&CMTR.TextComment,&CMTR.DateComment);
			fflush(stdin);
			printf(" IdComment :%d\n",CMTR.IdComment);
			printf(" IdUtilisateur %d\n",CMTR.IdUtilisateur);
			printf(" IdArticle%d\n",CMTR.IdArticle);
			printf(" TextComment %s\n",CMTR.TextComment);
			printf(" DateComment %s\n",CMTR.DateComment);
			printf("\n---------------------------------------------------------------------------------\n");

}
	while(!feof(F))	;
	fclose(F);
	
}
void AjoutComment()
{
	FILE*F;
	int num;
	F=fopen("COMMENTAIRES.txt","a");
	printf("\n  entrer l'identifiant de nouveau commentaire: \n ");
	scanf("%d",&num);
	while (rech_commentaire(num)==1 )
	{
	 printf("ce numero existe deja\n");
	 printf("\n  entrer l'identifiant du nouveau commentaire: \n ");
	 scanf("%d",&num);
	}
	CMTR.IdComment= num ;
	printf("\n Entrez le IdUtilisateur du  neauveau commentaire : \n");
	scanf("%d",&CMTR.IdUtilisateur);
	fflush(stdin);
	printf("\n Entrez IdArticle de nouveau article : \n");
	scanf("%d",&CMTR.IdArticle); 
	fflush(stdin);
	printf("\n Entrez le textComment de nouveau article : \n");
	gets(CMTR.TextComment); 
	fflush(stdin);
	printf("\n Entrez la date d'ajout du commentaire : \n");
	gets(CMTR.DateComment);
	fflush(stdin);
	fprintf(F,"%d :%d :%d :%s :%s \n",CMTR.IdComment,CMTR.IdUtilisateur,CMTR.IdArticle,CMTR.TextComment,CMTR.DateComment);
	fclose(F);
	printf("le commentaire est bien ajoutee\n");
}
void ModifierCommentaire()
{
		FILE *Fich,*F;
	
		F = fopen("COMMENTAIRES.txt","r");
		int num,i;
		char rep='n';
		printf("\n Entrez le numero du Commentaire a modifie : \n");
		scanf("%d",&num);
		fflush(stdin);
		if(rech_commentaire(num)==1)
		{
		printf("\n voulez vous vraiment modifier o\n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep == 'o'|| rep == 'O' )
		{
			
			Fich = fopen("TempCommentaire.txt","a");
				do
				{// a chaque fois je fais un fscanf => je lis une ligne du fichier
					fscanf(F,"%d :%d :%d :%s :%s \n",&CMTR.IdComment,&CMTR.IdUtilisateur,&CMTR.IdArticle,&CMTR.TextComment,&CMTR.DateComment);
					if(num == CMTR.IdComment)// je teste si le NumRech = numetudiant dans fscanf
					{
						CMTR.IdComment=num;
						printf("\n Entrez le nouveau  Utilisateur : \n");
							scanf("%d",&CMTR.IdUtilisateur);
							fflush(stdin);
						printf("\n Entrez la nouvelle  article : \n");
							scanf("%d",&CMTR.IdUtilisateur);
							fflush(stdin);
						printf("\n Entrez le nouveau text du commentaire  : \n");
							gets(CMTR.TextComment); 
							fflush(stdin);
						printf("\n Entrez la nouvelle date du commentaire  : \n");
							gets(CMTR.DateComment);
							fflush(stdin);
					}
		fprintf(Fich,"%d :%d :%d :%s :%s \n",CMTR.IdComment,CMTR.IdUtilisateur,CMTR.IdArticle,CMTR.TextComment,CMTR.DateComment);
				}
				while(!feof(F))	;
			fclose(Fich);
			fclose(F);
			remove("COMMENTAIRES.txt");
			rename("TempCommentaire.txt","COMMENTAIRES.txt");
			printf("modification effectue avec succes");
		};
	
		}
	else
	{
		printf("ce numero d'etudiant n'existe pas ");
	}
		
	
}
void Recherche_Commentaire()
{ 
	int NumR;
	printf("\n Entrez le numero du commentaire  a recherche : \n");
	scanf("%d",&NumR);
	FILE*F;
	F=fopen("COMMENTAIRES.txt","r");
	if(rech_commentaire!=1)
	printf(" ce commentaire n'existe pas\n");
	while(!feof(F))
	{
	fscanf(F,"%d :%d :%d :%s :%s \n",&CMTR.IdComment,&CMTR.IdUtilisateur,&CMTR.IdArticle,&CMTR.TextComment,&CMTR.DateComment);
		if(NumR == CMTR.IdComment) // si le numero que tu cherche egale au numero de la structure 
			{ 
				printf("------- Information Sur Le Commentaire : -------\n \n");
				printf("\t IdComment: %d \n",CMTR.IdComment);
				printf("\t IdUtilisateur: %d \n",CMTR.IdUtilisateur);
				printf("\t IdArticle : %d \n",CMTR.IdArticle);
				printf("\t le texte du commentaire : %s \n",CMTR.TextComment);		
				printf("\t Date de Commentaire : %s \n",CMTR.DateComment);	

			}
	}

	fclose(F);
}
void SupprimerCommentaire()
{
	char rep ;
	int IdRech;
	printf("\n Entrez le numero du commentaire  a supprime : \n");
	scanf("%d",&IdRech);
	fflush(stdin);
	while (rech_commentaire(IdRech)!=1 )
		{
		 printf("ce numero n'existe pas\n");
		 printf("\n  entrer l'identifiant du nouveau commentaire: \n ");
		 scanf("%d",&IdRech);
		}
		printf("\n voulez vous vraiment supprimer o\n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep == 'o'|| rep == 'O' )
		{
			FILE *Fich,*F;
			F = fopen("COMMENTAIRES.txt","r");
			Fich = fopen("TempCOMMENTAIRES.txt","a");
				do
				{
					fscanf(F,"%d :%d :%d :%s :%s \n",&CMTR.IdComment,&CMTR.IdUtilisateur,&CMTR.IdArticle,&CMTR.TextComment,&CMTR.DateComment);
					fflush(stdin);
					if(IdRech!=CMTR.IdComment)
					{
						fprintf(Fich,"%d :%d :%d :%s :%s \n",CMTR.IdComment,CMTR.IdUtilisateur,CMTR.IdArticle,CMTR.TextComment,CMTR.DateComment);
						fflush(stdin);
					}
				}
				while(!feof(F))	;
			fclose(Fich);
			fclose(F);
			remove("COMMENTAIRES.txt");
			rename("TempCOMMENTAIRES.txt","COMMENTAIRES.txt");
			printf("suppression effectue avec succes");
		}
	
	
	
}
void Menu_Commentaire()
{
int choix,rep;
	do
	{
		system("cls");//netoyer tous ce qui est ecris dans la console 
		printf("****************  MENU  ****************\n");
		printf("1-Ajouter Un Commentaire \n ");
		printf("2-Rechercher Un Commentaire \n ");
		printf("3-Supprimer Un Commentaire \n ");	
		printf("4-Modifier Un Commentaire \n ");
		printf("5-Afficher tous les Commentaires \n ");
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
			case 1:AjoutComment();
			break;
			case 2:Recherche_Commentaire();
			break;
			case 3:SupprimerCommentaire();
			break;
			case 4:ModifierCommentaire();
			break;
			case 5:AfficherTt_Commentaire();
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

