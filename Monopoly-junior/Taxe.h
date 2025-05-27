#pragma once
#include "Case.h"

class Taxe : public Case
{
private : 
	int prix;

public : 
	Taxe(int prix, int position, std::string name);

	void getPrix();
};

