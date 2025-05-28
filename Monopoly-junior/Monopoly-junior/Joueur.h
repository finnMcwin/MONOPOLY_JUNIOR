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
	std::vector <Attraction> AttractionJoueur;
	int position; 

public:
	Joueur(std::string name, int argent, int stand, int position );

	void avancer(int nbCase);
	void allerA(int position);
	std::string getName() const;
	int getArgent() const;
	void enleverArgent(int prix); 
	void enleverStand(); 

};