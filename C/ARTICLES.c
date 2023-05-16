#include"ARTICLES.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ARTICLES ARTC;
//la fonction rech_Article a pour but de recherche une article dans le ficchier ARTICLES si il trouve l Id Article il retourne 1 sinon il retourne -1
int rech_Artcile(int Idrech)
{
	FILE*F;
	F=fopen("ARTICLES.txt","r");// ouvrir le fichier pour la lecture 
	do
	{            //le format de lecture
	fscanf(F,"%d :%d :%s :%s :%s :%s :%d :%d :%s \n",&ARTC.IdArticle,&ARTC.IdType,&ARTC.DesingationArticle,&ARTC.DescriptionArticle,&ARTC.TailleArticle,&ARTC.CouleurArticle,&ARTC.PrixArticle,&ARTC.Qtstock,&ARTC.DateAjoutArticle);
		fflush(stdin);//liberer la memoire 
		if(ARTC.IdArticle == Idrech)
			{
				fclose(F);
				return 1;
			}
	}while(!feof(F));// lire tant que ce n'est pas la fin du fichier 
	fclose(F);
	return -1;
}
// la fonction Recherche_Article() il recherche une article et affiche tous les informations de l'article revherche 
void Recherche_Article()
{ 
	int NumR;
	printf("\n Entrez le numero de l'article a recherche : \n");
	scanf("%d",&NumR);
	FILE*F;
	F=fopen("ARTICLES.txt","r");
	if(F==NULL)
	printf("Probleme d'ouverture\n");
	if(rech_Artcile(NumR)!=1)
	printf("Cette article n'existe pas\n");
	while(!feof(F))
	{
	fscanf(F,"%d :%d :%s :%s :%s :%s :%d :%d :%s \n",&ARTC.IdArticle,&ARTC.IdType,&ARTC.DesingationArticle,&ARTC.DescriptionArticle,&ARTC.TailleArticle,&ARTC.CouleurArticle,&ARTC.PrixArticle,&ARTC.Qtstock,&ARTC.DateAjoutArticle);
		if(NumR == ARTC.IdArticle) // si le numero que tu cherche egale au numero de la structure 
			{ 
				printf("------- Information de L'article: -------\n \n");
				printf("\t IdArticle: %d \n",ARTC.IdArticle);
				printf("\t IdType: %d \n",ARTC.IdType);
				printf("\t DesingationArticle: %s \n",ARTC.DesingationArticle);
				printf("\t DescriptionArticle: %s \n",ARTC.DescriptionArticle);	
				printf("\t TailleArticle: %s \n",ARTC.TailleArticle);	
				printf("\t CouleurArticle: %s \n",ARTC.CouleurArticle);	
				printf("\t PrixArticle: %d \n",ARTC.PrixArticle);
				printf("\t Qtstock: %d \n",ARTC.Qtstock);
				printf("\t DateAjoutArticle: %s \n",ARTC.DateAjoutArticle);

			}
	}

	fclose(F);
}
// la fonction AfficherTt_Article() il affiche tous les articles stockee dans le fichier ARTICLES 
void AfficherTt_Article()
{
	FILE *F;
	F=fopen("ARTICLES.txt","r");
	if(F==NULL)
	{printf("probleme d'ouverture  \n");
	}
	printf("LA LISTE DE TOUS LES ARTICLES \n");
	printf("---------------------------------------------------------------------------------------\n");
	do{
		fscanf(F,"%d :%d :%s :%s :%s :%s :%d :%d :%s \n",&ARTC.IdArticle,&ARTC.IdType,&ARTC.DesingationArticle,&ARTC.DescriptionArticle,&ARTC.TailleArticle,&ARTC.CouleurArticle,&ARTC.PrixArticle,&ARTC.Qtstock,&ARTC.DateAjoutArticle);
		fflush(stdin);
		printf(" Article  :  %d\n",ARTC.IdArticle);
		printf(" IdType  :  %d\n",ARTC.IdType);
		printf(" Designation  :  %s\n",ARTC.DesingationArticle);
		printf(" Description  :  %s\n",ARTC.DescriptionArticle);
		printf(" Taille  :  %s\n",ARTC.TailleArticle);
		printf(" Couleur  :  %s\n",ARTC.CouleurArticle);
		printf(" PrixUnitaireArticle  :  %d\n",ARTC.PrixArticle);
		printf(" Qtstock  :  %d\n",ARTC.Qtstock);
		printf(" DateAjoutArticle %s\n",ARTC.DateAjoutArticle);
		printf("---------------------------------------------------------------------------------------\n");
	}
	while(!feof(F))	;
	fclose(F);
}
/*la fonction AjoutArticle() a pour but d'ajouter une nouvelle article dans le fichiers des ARTICLES le principe c'est que on demande le Id de L'article et on recherche si il existe avant
a l'aide de la fonction rech_Artcile si l'article il ne se trouve pas dans le fichier on demande les informations de l'article puis  on les ecrit dans le fichier ARTICLES a l'aie de 
la fonction fprintf */
void AjoutArticle()
{
	FILE*F;
	int num;
	F=fopen("ARTICLES.txt","a");
	printf("\n  entrer l'identifiant de la nouvelle Article: \n ");
	scanf("%d",&num);
	while (rech_Artcile(num) ==1 )
	{
	 printf("ce numero existe deje\n");
	 printf("\n  entrer l'identifiant de la nouvelle Article: \n ");
	 scanf("%d",&num);
	}
	ARTC.IdArticle = num ;
	printf("\n Entrez le IdType de la nouvelle  article : \n");
	scanf("%d",&ARTC.IdType);
	fflush(stdin);
	printf("\n Entrez la designation de la nouvelle article : \n");
	gets(ARTC.DesingationArticle); 
	fflush(stdin);
	printf("\n Entrez la description de la nouvelle article : \n");
	gets(ARTC.DescriptionArticle); 
	fflush(stdin);
	printf("\n Entrez la taille  de la nouvelle article : \n");
	gets(ARTC.TailleArticle);
	fflush(stdin);
	printf("\n Entrez le couleur   de la nouvelle article : \n");
	gets(ARTC.CouleurArticle);
	fflush(stdin);
	printf("\n Entrez le prix   de la nouvelle article : \n");
	scanf("%d",&ARTC.PrixArticle);
	fflush(stdin);	
	printf("\n Entrez la quantite de stock de la nouvelle article : \n");
	scanf("%d",&ARTC.Qtstock);
	fflush(stdin);
	printf("\n Entrez le date d ajout de la nouvelle article : \n");
	gets(ARTC.DateAjoutArticle);
	fflush(stdin);
	fprintf(F,"%d :%d :%s :%s :%s :%s :%d :%d :%s \n",ARTC.IdArticle,ARTC.IdType,ARTC.DesingationArticle,ARTC.DescriptionArticle,ARTC.TailleArticle,ARTC.CouleurArticle,ARTC.PrixArticle,ARTC.Qtstock,ARTC.DateAjoutArticle);
	fclose(F);
	printf("l'article est bien ajoutee\n");
}
/* la fonction ModifierArticle a pour but de modifier les informations d'une article le principe de la fonction c'est que elle demande le IdArticle de l'artilce a modifie puis si l'article
lit se trouve vraiment elle  cree un nouveau fichier TempARTICLES en mode lecture et ecriture puis il fait une boucle sur le fichier ARTICLES tant que on est pas arrive a la fin du fichier il lit 
les lignes de fichier si l'IdArticle de la ligne lit egale a l IdArticle de l'article  demande a modifie elle demande les nouveaux informations puis elle ecrit la ligne dans le fichier 
TempArticles sinon il ecrit la ligne dirictement dans le Fichier TempArticles ,apres qu'il sort du boucle il ferme les deux fichiers et supprime le fichier originale Articles et
renome le fichier TempArticles par ARTICLES */
void ModifierArticle()
{
		FILE *Fich,*F;
	
		F = fopen("ARTICLES.txt","r");
		int num,i;
		char rep='n';
		printf("\n Entrez le numero de l article a modifie : \n");
		scanf("%d",&num);
		fflush(stdin);
		if(rech_Artcile(num)==1)
		{
		printf("\n voulez vous vraiment modifier o\n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep == 'o'|| rep == 'O' )
		{
			
			Fich = fopen("TempArticles.txt","a");
				do
				{// a chaque fois je fais un fscanf => je lis une ligne du fichier
				fscanf(F,"%d :%d :%s :%s :%s :%s :%d :%d :%s \n",&ARTC.IdArticle,&ARTC.IdType,&ARTC.DesingationArticle,&ARTC.DescriptionArticle,&ARTC.TailleArticle,&ARTC.CouleurArticle,&ARTC.PrixArticle,&ARTC.Qtstock,&ARTC.DateAjoutArticle);
					if(num == ARTC.IdArticle)// je teste si le NumRech = numetudiant dans fscanf
					{
						ARTC.IdArticle=num;
						printf("\n Entrez le nouveau  IdType de  l'article : \n");
							scanf("%d",&ARTC.IdType);
							fflush(stdin);
						printf("\n Entrez la nouvelle designation de l'article : \n");
							gets(ARTC.DesingationArticle);// le nom est une chaine de caractere donc je la lis aves la methode gtes 
							fflush(stdin);
						printf("\n Entrez la nouvelle description de l'article : \n");
							gets(ARTC.DescriptionArticle); 
							fflush(stdin);
						printf("\n Entrez la nouvelle taille de l'article : \n");
							gets(ARTC.TailleArticle);
							fflush(stdin);
						printf("\n Entrez le nouveau couleur   de l'article : \n");
							gets(ARTC.CouleurArticle);
							fflush(stdin);
						printf("\n Entrez le  nouveau prix   de l'article : \n");
							scanf("%d",&ARTC.PrixArticle);
							fflush(stdin);	
						printf("\n Entrez  la nouvelle quantite de stock de  l'article : \n");
							scanf("%d",&ARTC.Qtstock);
							fflush(stdin);
						printf("\n Entrez  la nouvelle date d ajout de  l'article : \n");
							gets(ARTC.DateAjoutArticle);
							fflush(stdin);
					}
		fprintf(Fich,"%d :%d :%s :%s :%s :%s :%d :%d :%s \n",ARTC.IdArticle,ARTC.IdType,ARTC.DesingationArticle,ARTC.DescriptionArticle,ARTC.TailleArticle,ARTC.CouleurArticle,ARTC.PrixArticle,ARTC.Qtstock,ARTC.DateAjoutArticle);
					
				}
				while(!feof(F))	;
			fclose(Fich);
			fclose(F);
			remove("ARTICLES.txt");
			rename("TempArticles.txt","ARTICLES.txt");
			printf("modification effectue avec succes");
		};
	
		}
	else
	{
		printf("cette article n'existe pas ");
	}
		
	
}
/*la fonction SupprimerArticle a pour but de supprimer une article le principe c'est qu'elle demande l'IdArticle de l'article a supprime puis elle cree et ouvre unnouveau fichier
 TempARTICLES en mode lecture et ecriture puis il fait une boucle sur le fichier ARTICLES tant que on est pas arrive a la fin du fichier il lit 
les lignes de fichier si l'IdArticle de la ligne lit egale a l IdArticle de l'article  demande a supprime  elle ne l'ecrit pas  dans le fichier 
TempArticles sinon il ecrit la ligne dirictement dans le Fichier TempArticles ,apres qu'il sort du boucle il ferme les deux fichiers et supprime le fichier originale Articles et
renome le fichier TempArticles par ARTICLES */
void SupprimerArticle()
{
	char rep ;
	int IdRech;
	printf("\n Entrez le numero de l'article a supprime : \n");
	scanf("%d",&IdRech);
	fflush(stdin);
	if(rech_Artcile(IdRech)==1)
	{
		printf("\n voulez vous vraiment supprimer o\n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if(rep == 'o'|| rep == 'O' )
		{
			FILE *Fich,*F;
			F = fopen("ARTICLES.txt","r");
			Fich = fopen("TempARTICLES.txt","a");
				do
				{
					fscanf(F,"%d :%d :%s :%s :%s :%s :%d :%d :%s \n",&ARTC.IdArticle,&ARTC.IdType,&ARTC.DesingationArticle,&ARTC.DescriptionArticle,&ARTC.TailleArticle,&ARTC.CouleurArticle,&ARTC.PrixArticle,&ARTC.Qtstock,&ARTC.DateAjoutArticle);
					fflush(stdin);
					if(IdRech!=ARTC.IdArticle)
					{
						fprintf(Fich,"%d :%d :%s :%s :%s :%s :%d :%d :%s \n",ARTC.IdArticle,ARTC.IdType,ARTC.DesingationArticle,ARTC.DescriptionArticle,ARTC.TailleArticle,ARTC.CouleurArticle,ARTC.PrixArticle,ARTC.Qtstock,ARTC.DateAjoutArticle);
						fflush(stdin);
					}
				}
				while(!feof(F))	;
			fclose(Fich);
			fclose(F);
			remove("ARTICLES.txt");
			rename("TempARTICLES.txt","ARTICLES.txt");
			printf("suppression effectue avec succes");
		}
	
	}
	else
	printf("cette article n'existe pas\n ");
	
}
void Menu_Articles()
{
int choix,rep;
	do
	{
		system("cls");//netoyer tous ce qui est ecris dans la console 
		printf("****************  MENU  ****************\n");
		printf("1-Ajouter Une Article \n ");
		printf("2-Rechercher Une Article \n ");
		printf("3-Supprimer Une Article \n ");	
		printf("4-Modifier Une Article \n ");
		printf("5-Afficher tous les Articles \n ");
		printf("6-Quitter \n ");
		printf("7-Rtourner Au Menu Principale \n ");

		do
		{
			printf("\n Entrez votre choix: ");
			scanf("%d",&choix);
		}
		while(choix<1 || choix>7);
		switch(choix)
		{
			case 1:AjoutArticle();
			break;
			case 2:Recherche_Article();
			break;
			case 3:SupprimerArticle();
			break;
			case 4:ModifierArticle();
			break;
			case 5:AfficherTt_Article();
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
