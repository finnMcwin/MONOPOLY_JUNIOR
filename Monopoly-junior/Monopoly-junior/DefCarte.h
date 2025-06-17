#pragma once
#include <string>
#include "Joueur.h"

class PlateauDeJeu;
class ListeCarte;

class DefCarte
{
protected : 
	DefCarte* nextCarte; 
	DefCarte* previousCarte; 
	std::string name; 

public : 
	DefCarte(DefCarte* nextCarte,DefCarte* previousCarte, std::string name); 

	virtual void effetCarte(Joueur* joueurActif, PlateauDeJeu* plateau, int* argenCentre, ListeCarte* Cartes) {};
	void setName(std::string name);
	void setNextCarte(DefCarte* nextCarte); 
	void setPreviousCarte(DefCarte* prevuiousCarte); 
	DefCarte* getNextCarte() const; 
	DefCarte* getPreviousCarte() const; 


};

