#ifndef PANIERS_H
#define PANIERS_H
struct PANIERS
{
	int  IdPanier  ;
	int  IdUtilisateur;
    char StatusPanier [100] ;
};
void AfficherTt_Paniers();
int rech_Panier(int Idrech);
void Ajouter_Panier();
void ModifierPanier();
void Recherche_Panier();
void SupprimerPanier();
#endif

