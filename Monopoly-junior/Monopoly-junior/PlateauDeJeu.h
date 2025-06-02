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
	void caseTaxe(int position, Joueur* joueurActif, int* argentCentre);
	void caseAllerCafe(Joueur* joueurActif, int position, int* argentCentre);
	void caseCafe(int position, Joueur* joueurActif); 
	void caseFortune(int position, Joueur* joueurActif, int* argentCentre);
	void casePetitTrain(int position, Joueur* joueurActif, int* argentCentre);
	int rollDiceP(); 

public : 
	PlateauDeJeu();

	void setCase(Case* newCase);
	
	void effetCase(int position, Joueur* joueurActif, int* argentCentre); 
	Case* getCase(int position);

};

