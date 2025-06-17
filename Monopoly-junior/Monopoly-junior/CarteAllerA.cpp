#include "CarteAllerA.h"
#include <iostream>


CarteAllerA::CarteAllerA(int position, std::string name, DefCarte* nextCarte)
	: DefCarte(nextCarte, name), position(position)
{
}

void CarteAllerA::effetCarte(Joueur* joueurActif, PlateauDeJeu* plateau, int* argentCentre)  {
	std::cout << "Vous avez piochez une carte " + name << std::endl;

	joueurActif->allerA(position);
	plateau->effetCase(position, joueurActif, argentCentre);
}