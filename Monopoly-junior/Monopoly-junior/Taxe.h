#pragma once
#include "Case.h"

class Joueur;

class Taxe: public Case
{
private : 
	int prix; 

public : 
	Taxe(int prix, int position, std::string name);

	int getPrix() const;
	void payer(Joueur* joueur);

};

