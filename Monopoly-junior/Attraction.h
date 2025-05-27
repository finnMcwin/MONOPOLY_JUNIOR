#pragma once
#include "Case.h"
#include "Joueur.h"

class Attraction : public Case 
{
private:
	int prix;
	bool occupe;
	Joueur propriétaire; 
	std::string couleur; 

public:
	Attraction(int prix, bool occupe, int position, std::string name, std::string couleur);

	int getPrix();
	bool getOccupe();
	void acheter(Joueur joueur);	
	void changerProprietaire(Joueur joueur);

};

