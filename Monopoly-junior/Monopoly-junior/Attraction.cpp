#include "Attraction.h"
#include <iostream>
#include "Joueur.h"

Attraction::Attraction(int prix, bool occupe, Joueur* proprietaire, int position, std::string couleur, std::string name) 
	:prix(prix), occupe(occupe), proprietaire(proprietaire), couleur(couleur)
{
	setPosition(position); 
	setName(name);
}

int Attraction::getPrix() const {
	return prix;
}

bool Attraction::getOccupe() const {
	return occupe;
}


void Attraction::acheter(Joueur* joueur) {
	if (joueur->getArgent() < prix) {
		std::cout << "Vous etes trop pauvre pour cette attraction" << std::endl;
	}
	else if (joueur->getStand() <= 0) {
		std::cout << "Vous avez trop d'attractions" << std::endl; 
	}
	else {
		proprietaire = joueur;
		occupe = true;
		joueur->enleverArgent(prix);
		joueur->enleverStand();
		std::cout << "Transaction effectuée avec succes ! " << std::endl;
	}
}

void Attraction::changerProprietaire(Joueur* joueur) {
	proprietaire = joueur;
}

void Attraction::visite(Joueur* visiteur) {
	std::cout << std::endl << "Cette attraction est deja occupe par " << proprietaire->getName() << std::endl << "Vous lui devez : " << prix << " euros" << std::endl;
	visiteur->enleverArgent(prix);
	proprietaire->gagnerArgent(prix);
}
