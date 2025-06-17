#pragma once
#include <string>
#include "Joueur.h"
#include "PlateauDeJeu.h"


class DefCarte
{
protected : 
	DefCarte* nextCarte; 
	std::string name; 

public : 
	DefCarte(DefCarte* nextCarte, std::string name); 

	virtual void effetCarte(Joueur* joueurActif, PlateauDeJeu* plateau, int* argenCentre);
	void setName(std::string name);
	void setNextCarte(DefCarte* nextCarte); 

};

