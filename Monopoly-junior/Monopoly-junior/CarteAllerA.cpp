#include "CarteAllerA.h"
#include <iostream>
#include "PlateauDeJeu.h"



CarteAllerA::CarteAllerA(int position, std::string name, DefCarte* nextCarte, DefCarte* previousCarte)
	: DefCarte(nextCarte,previousCarte, name), position(position)
{
}

void CarteAllerA::effetCarte(Joueur* joueurActif, PlateauDeJeu* plateau, int* argentCentre,ListeCarte* cartes )  {
	std::cout << "Vous avez piochez une carte " + name << std::endl;

	joueurActif->allerA(position);
	plateau->effetCase(position, joueurActif, argentCentre, cartes);
}