#pragma once
#include <String>
#include <vector>

class Joueur
{
private:
	std::string name;
	int argent;
	int stand;
	//std::vector <Case> AttractionJoueur;
	int position; 

public:
	Joueur(std::string name, int argent, int stand, int position );

	void avancer(int nbCase);
	void allerA(int position);
	std::string getName();
	int getArgent();

};