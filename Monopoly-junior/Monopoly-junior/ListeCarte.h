#pragma once
#include "DefCarte.h"
#include "PlateauDeJeu.h"

class ListeCarte
{
private : 
	DefCarte* firstCarte; 
	DefCarte* lastCarte; 
	
	DefCarte* getCarte(int position); 

public: 
	ListeCarte();
	~ListeCarte();

	void addCarte(DefCarte* carte);
	void piocher(Joueur* joueurActif, PlateauDeJeu* plateau, int* argentCentre);
	int size(); 

};

