#pragma once
#include "Case.h"
#include "Joueur.h"

class Taxe: public Case
{
private : 
	int prix; 

public : 
	Taxe(int prix, int position);

	int getPrix() const;
	void payer(Joueur joueur);

};

