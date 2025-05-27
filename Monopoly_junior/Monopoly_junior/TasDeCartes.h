#pragma once
#include "Cartes.h"

class TasDeCartes
{
private : 
	Cartes* premiereCarte;
	Cartes* derniereCarte;
	Cartes* getCarte(int position);

public : 
	TasDeCartes();
	~TasDeCartes();

	int size();
	//void add(DefCartes carte);
	//void insert(DefCarte carte, int position);
	void remove(int position);
	int operator[](int position);
};

