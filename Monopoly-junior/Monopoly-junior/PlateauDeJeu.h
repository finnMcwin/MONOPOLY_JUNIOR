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

public : 
	PlateauDeJeu();

	Case chance(int position);
	Attraction attraction(int prix, bool occupe, Joueur proprietaire, int position, std::string couleur);
	Taxe taxe(int prix, int position);
	Taxe depart(int position, int prix); 
	Case inactive(int position); 
	Case petitTrain(int position); 

};

