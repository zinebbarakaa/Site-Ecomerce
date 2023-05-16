#ifndef ARTICLES_H
#define ARTICLES_H
struct ARTICLES
{
	int    IdArticle ;
	int    IdType ;
	char   DesingationArticle[100];
	char   DescriptionArticle[200];
	char   TailleArticle[10];
	char   CouleurArticle[100];
    int    PrixArticle;
    int    Qtstock;
	char   DateAjoutArticle[100];
};
struct ARTICLES ARTC;
//
int rech_Artcile(int Idrech);
void AfficherTt_Article();
void AjoutArticle();
void ModifierArticle();
void SupprimerArticle();
void Recherche_Article();
void Menu_Articles();
#endif
