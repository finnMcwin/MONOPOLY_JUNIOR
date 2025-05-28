#include "Attraction.h"
#include <iostream>

Attraction::Attraction(int prix, bool occupe, Joueur proprietaire, int position, std::string couleur) 
	:prix(prix), occupe(occupe), proprietaire(proprietaire), couleur(couleur)
{
	setPosition(position); 
}

int Attraction::getPrix() const {
	return prix;
}

bool Attraction::getOccupe() const {
	return occupe;
}


void Attraction::acheter(Joueur joueur) {
	if (joueur.getArgent() < prix) {
		std::cout << "Vous etes trop pauvre pour cette attraction" << std::endl;
	}
	else {
		proprietaire = joueur;
		occupe = true;
		joueur.enleverArgent(prix);
		joueur.enleverStand();
	}
}

void Attraction::changerProprietaire(Joueur joueur) {
	proprietaire = joueur;
}