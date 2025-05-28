#pragma once
#include "Case.h"
#include "Joueur.h"

class Taxe: private Case
{
private : 
	int prix; 

public : 
	Taxe(int prix, int position);

	int getPrix();
	void payer(Joueur joueur);

};

