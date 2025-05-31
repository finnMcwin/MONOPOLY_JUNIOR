#include "Taxe.h"
#include <iostream>
#include "Joueur.h"

Taxe::Taxe(int prix, int position, std::string name) 
	:prix(prix)
{
	setPosition(position); 
	setName(name);
}


int Taxe::getPrix() const {
	return prix; 
}

void Taxe::payer(Joueur* joueur) {
	
	joueur->gagnerArgent(prix); 
	
}