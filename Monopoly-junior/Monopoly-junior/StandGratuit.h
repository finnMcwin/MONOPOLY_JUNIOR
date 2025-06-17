#pragma once
#include "DefCarte.h"




class StandGratuit : public DefCarte
{
private : 
	std::string couleur; 


public : 
	StandGratuit(std::string couleur, std::string name, DefCarte* nextCarte, DefCarte* previousCarte); 

	void effetCarte(Joueur* joueurActif, PlateauDeJeu* plateau, int* argentCentre, ListeCarte* Cartes) override;
};

