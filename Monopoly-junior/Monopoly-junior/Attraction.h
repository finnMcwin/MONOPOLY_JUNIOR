#pragma once
#include <string>
#include "Joueur.h"
#include "Case.h"

class Attraction : public Case
{
private:
	int prix;
	bool occupe;
	Joueur proprietaire;
	std::string couleur;



public:
	Attraction(int prix, bool occupe, Joueur proprietaire, int position, std::string couleur);

	int getPrix() const;
	bool getOccupe() const;
	void acheter(Joueur joueur);
	void changerProprietaire(Joueur joueur);
};

