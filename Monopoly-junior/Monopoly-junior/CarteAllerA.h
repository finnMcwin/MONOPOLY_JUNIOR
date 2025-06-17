#pragma once
#include "DefCarte.h"

class ListeCarte;

class CarteAllerA : public DefCarte
{
private : 
	int position; 

public : 
	CarteAllerA(int position, std::string name, DefCarte* nextCarte, DefCarte* previousCarte);

	void effetCarte(Joueur* joueurActif, PlateauDeJeu* plateau, int* argentCentre, ListeCarte* Cartes) override;
};

