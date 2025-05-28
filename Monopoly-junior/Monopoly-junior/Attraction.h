#pragma once
#include "Joueur.h"
#include "Case.h"

class Attraction : private Case
{
private:
	int prix;
	bool occupe;
	Joueur proprietaire;


public:
	Attraction(int prix, bool occupe, Joueur proprietaire, int position);

	int getPrix() const;
	bool getOccupe() const;
	void acheter(Joueur joueur);
	void changerProprietaire(Joueur joueur);
};

