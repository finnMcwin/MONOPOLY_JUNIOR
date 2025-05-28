#include "Taxe.h"
#include <iostream>

Taxe::Taxe(int prix, int position) 
	:prix(prix)
{
	setPosition(position); 
}


int Taxe::getPrix() const {
	return prix; 
}

void Taxe::payer(Joueur joueur) {
	if (joueur.getArgent() < prix) {
		std::cout << "Vous etes trop pauvre" << std::endl; 
	}
	else {
		joueur.enleverArgent(prix); 
	}
}