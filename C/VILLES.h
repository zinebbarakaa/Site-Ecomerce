#ifndef VILLES_H
#define VILLES_H
struct VILLES
{
	int   IdVille  ;
	char  NomVille[100];
	char  CodePostalVille[100];
	float PrixLivraisonVille;
};
int rech_Ville(int Idrech);
void AfficherTt_Ville();
void AjoutVille();
void ModifierVille();
void Recherche_Ville();
void SupprimerVille();
#endif

