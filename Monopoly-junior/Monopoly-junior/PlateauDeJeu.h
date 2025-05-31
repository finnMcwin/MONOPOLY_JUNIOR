#pragma once
#include "Case.h"
#include <vector>
#include <string>
#include "Joueur.h"
#include "Attraction.h"
#include "Taxe.h"

class PlateauDeJeu
{
private: 
	int NbCase = 32; 
	std::vector <Case*> listeCases;
	
	void caseAttractions(int position, Joueur* joueurActif); 
	void caseTaxe(int position, Joueur* joueurActif);

public : 
	PlateauDeJeu();

	void setCase(Case* newCase);
	
	//void effetCase(Joueur* joueurActif, int position); 
	Case* getCase(int position);

};

