#include <ctime>
#include <cstdlib>
#include "Case.h"
#include "Taxe.h"
#include "Attraction.h"
#include "PlateauDeJeu.h"
#include <iostream>

int rollDice(); 

int main() {

	Taxe* Depart = new Taxe(2, 0, "Depart");
	Case* Chance1 = new Case(1, "Chance");
	Attraction* JeuDeBallons = new Attraction(1, false, nullptr, 2, "bleuFonce", "Jeu de Ballons");

	PlateauDeJeu Plateau;
	Plateau.setCase(Depart);
	Plateau.setCase(Chance1);
	Plateau.setCase(JeuDeBallons);

	Plateau.getCase(2)->toString();
	std::cout << Plateau.getCase(2)->getPrix() << std::endl;

	return 0; 
}


int rollDice() {

	std::srand(std::time(0));
	int nombre = (std::rand() % 6) + 1;

	return nombre; 
}