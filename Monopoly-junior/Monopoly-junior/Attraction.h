#pragma once
#include "Joueur.h"

class Attraction
{
private:
	int prix;
	bool occupe;
	Joueur proprietaire;


public:
	Attraction(int prix, bool occupe, Joueur proprietaire);

	int getPrix() const;
	bool getOccupe() const;
	void acheter(Joueur joueur);
};

