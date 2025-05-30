#include "Joueur.h"


Joueur::Joueur(std::string name, int argent, int stand, int position) 
	:name(name), argent(argent), stand(stand), position(position)
{

}

void Joueur::avancer(int nbCase) {
	position += nbCase; 
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

void Joueur::newAttraction(Attraction attraction) {
	attractionsJoueur.push_back(attraction);
}

void Joueur::gagnerArgent(int prix) {
	argent += prix; 
}