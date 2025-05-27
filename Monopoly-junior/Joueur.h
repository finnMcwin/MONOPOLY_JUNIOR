#pragma once
#include <String>
#include <vector>
#include "Attraction.h"


class Joueur
{
private:
	std::string name;
	int argent;
	int stand;
	std::vector <Case> AttractionJoueur;

public:
	Joueur(std::string name, int argent, int stand);

	void avancer(int nbCase);
	void allerA(int position);
	std::string getName();
	int getArgent();
	void Acheter(Attraction attraction);

};
