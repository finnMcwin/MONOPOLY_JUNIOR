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
	std::vector <Case> listeCases;

	void caseAttractions(int position, Joueur* joueurActif); 
	//Case chance(int position);
	//Attraction attraction(int prix, bool occupe, Joueur proprietaire, int position, std::string couleur);
	//Taxe taxe(int prix, int position);
	//Taxe depart(int position, int prix); 
	//Case inactive(int position); 
	//Case petitTrain(int position); 

public : 
	PlateauDeJeu();

	void setCase(Case newCase);
	void effetCase(Joueur* joueurActif, int position); 

};

