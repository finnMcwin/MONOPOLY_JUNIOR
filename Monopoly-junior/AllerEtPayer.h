#pragma once
#include "VaSur.h"

class AllerEtPayer : VaSur
{
private: 
	int prix; 

public : 
	AllerEtPayer(int nombre, int positionOuAller, int prix); 

	void payer(Joueur joueur); 
};

