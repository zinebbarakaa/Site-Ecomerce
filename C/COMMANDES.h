#ifndef COMMANDES_H
#define COMMANDES_H
struct COMMANDES
{
	int IdPanier  ;
	int IdArticle  ;
    int QtCmd ;
	
};
int rech_commande(int Idpanier,int Idarticle);
void Afficher_Tt_Commandes();
void AjoutCommande();
void ModifierCommande();
void Recherche_Commande();
void SupprimerCommande();
void Menu_Commande();

#endif

