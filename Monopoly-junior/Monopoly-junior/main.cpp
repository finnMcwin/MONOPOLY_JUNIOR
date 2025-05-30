#include <ctime>
#include <cstdlib>
#include "Case.h"
#include "Taxe.h"
#include "Attraction.h"
#include "PlateauDeJeu.h"

int rollDice(); 

int main() {

	Taxe Depart(2, 0);
	Case Chance1(1);
	Attraction JeuDeBallons(1, false, nullptr, 2, "bleuFonce");

	PlateauDeJeu Plateau;
	Plateau.setCase(Depart);
	Plateau.setCase(Chance1);
	Plateau.setCase(JeuDeBallons);



	return 0; 
}


int rollDice() {

	std::srand(std::time(0));
	int nombre = (std::rand() % 6) + 1;

	return nombre; 
}