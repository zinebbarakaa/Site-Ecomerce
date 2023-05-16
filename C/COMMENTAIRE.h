#ifndef COMMENTAIRES_H
#define COMMENTAIRES_H
struct COMMENTAIRES
{
	int   IdComment  ;
	int   IdUtilisateur;
	int   IdArticle  ;
	char  TextComment [100];
	char  DateComment[100];
};
int rech_commentaire(int Idrech);
void AfficherTt_Commentaire();
void AjoutComment();
void ModifierCommentaire();
void Recherche_Commentaire();
void SupprimerCommentaire();
#endif


