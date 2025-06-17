#pragma once
#include <String>
#include <vector>

class Attraction;

class Joueur
{
private:
	std::string name;
	int argent;
	int stand;
	std::vector <Attraction*> attractionsJoueur;
	int position; 

public:
	Joueur(std::string name, int argent, int stand, int position );
	~Joueur();

	void avancer(int nbCase);
	void allerA(int newPosition);
	std::string getName() const;
	int getArgent() const;
	void enleverArgent(int prix); 
	void enleverStand(); 
	void recupStand() { stand++; };
	int getStand() const; 
	void newAttraction(Attraction* attraction); 
	void suppAttraction(Attraction* attraction);
	void afficherAttraction() const;
	void gagnerArgent(int prix);
	void iniJoueur(int nbJoueur, int numJoueur); 
	int getPosition() const; 

};