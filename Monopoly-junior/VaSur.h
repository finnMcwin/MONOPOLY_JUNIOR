#pragma once
#include "DefCarte.h"
#include "Joueur.h"

class VaSur : private DefCarte
{
protected : 
	int positionOuAller;

public:
	VaSur(int nombre, int positionOuAller);

	void AllerA(Joueur joueur, int position);
};

