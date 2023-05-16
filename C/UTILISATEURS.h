#ifndef UTILISATEURS_H
#define UTILISATEURS_H
struct UTILISATEURS
{
	int  IdUtilisateur  ;
	char NomUtilisateur [100];
	char PrenomUtilisateur[100];
	char EmailUtilisateur[100];
	char DateNaissUtilisateur[100];
	char AdresseUtilisateur[50];
	char TelUtilisateur[50];
    char TypeUtilisateur[50];
    char MotPasseUtilisateur[50];
	
};
struct UTILISATEURS UTIL;
int rech_utilisateur(int Idrech);
void AfficherTt_Utilisateur();
void Recherche_Utilisateur();
void AjoutUtilisateur();
void ModifierUtilisateur();
void SupprimerUtilisateur();
#endif


