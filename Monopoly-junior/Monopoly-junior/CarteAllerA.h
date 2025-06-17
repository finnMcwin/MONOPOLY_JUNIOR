#pragma once
#include "DefCarte.h"


class CarteAllerA : public DefCarte
{
private : 
	int position; 

public : 
	CarteAllerA(int position, std::string name, DefCarte* nextCarte); 

	void effetCarte(Joueur* joueurActif, PlateauDeJeu* plateau, int* argentCentre) override;
};

