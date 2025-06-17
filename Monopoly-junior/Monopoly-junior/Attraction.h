#pragma once
#include <string>
#include "Case.h"

class Joueur; 

class Attraction : public Case
{
private:
	int prix;
	bool occupe;
	Joueur* proprietaire = nullptr;
	std::string couleur;



public:
	Attraction(int prix, bool occupe, Joueur* proprietaire, int position, std::string couleur, std::string name);

	int getPrix() const;
	bool getOccupe() const;
	void setProprio(Joueur* joueur);
	void acheter(Joueur* joueur);
	std::string getCouleur() const { return couleur; };
	void changerProprietaire(Joueur* joueur);
	void visite(Joueur* visiteur);
	Joueur* getProprio() const { return proprietaire; };
	
};

