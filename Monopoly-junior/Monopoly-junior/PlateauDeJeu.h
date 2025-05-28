#pragma once
#include "Case.h"
#include <vector>

class PlateauDeJeu
{
private: 
	int NbCase = 32; 

public : 
	PlateauDeJeu();

	Case chance(int position);


};

