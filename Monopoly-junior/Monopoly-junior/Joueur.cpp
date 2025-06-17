#include "Joueur.h"
#include "Attraction.h"
#include <iostream>

Joueur::Joueur(std::string name, int argent, int stand, int position) 
	:name(name), argent(argent), stand(stand), position(position)
{

}

Joueur::~Joueur() {
	for (Attraction* p : attractionsJoueur) {
		delete p;
	}
}

void Joueur::avancer(int nbCase) {
	position += nbCase; 
	if (position > 31) {
		position = position - 32;
	}
}

void Joueur::allerA(int newPosition) {
	position = newPosition; 
}

std::string Joueur::getName() const {
	return name;
}

int Joueur::getArgent() const {
	return argent; 
}

void Joueur::enleverArgent(int prix) {
	argent -= prix;
}

void Joueur::enleverStand() {
	stand--;
}

int Joueur::getStand() const {
	return stand; 
}


void Joueur::newAttraction(Attraction* attraction) {
	attractionsJoueur.push_back(attraction);
}

void Joueur::suppAttraction(Attraction* attraction) {
	attractionsJoueur.erase(std::remove(attractionsJoueur.begin(), attractionsJoueur.end(), attraction), attractionsJoueur.end());
}

void Joueur::afficherAttraction() const {
	std::cout << "Vous possedez : ";
	for (Attraction* p : attractionsJoueur) {
		std::cout << p->getName();
		std::cout << ", ";
	}
	std::cout << std::endl << std::endl;


}

void Joueur::gagnerArgent(int prix) {
	argent += prix; 
}

void Joueur::iniJoueur(int nbJoueur, int numJoueur) {
	std::cout << std::endl << "Veuillez rentrer le nom du joueur " << numJoueur << std::endl;
	std::cin >> name; 

	if (nbJoueur == 2) {
		stand = 15;
	}
	else {
		stand = 10;
	}
	argent = 31; 

	std::cout << std::endl;
}

int Joueur::getPosition() const {
	return position;
}