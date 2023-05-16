#ifndef FACTURES_H
#define FACTURES_H
struct FACTURES
{
	int  IdFacture  ;
	int  IdPanier  ;
    char DateFacturation[100] ;
	
};
int rech_facture(int Idrech);
void AfficherTt_Facture();
void AjoutFacture();
void ModifierFacture();
void Recherche_Facture();
void SupprimerFacture();
#endif

