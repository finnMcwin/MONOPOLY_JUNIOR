#include "ListeCarte.h"

ListeCarte::ListeCarte() 
	:firstCarte(nullptr), lastCarte(nullptr)
{
}

ListeCarte:: ~ListeCarte() {
	DefCarte* carte = firstCarte;
	while (carte != nullptr) {
		DefCarte* inter = carte;
		carte = carte->getNextCarte();
		delete inter;
	}
}

int ListeCarte::size() {
	bool verrif = true;
	DefCarte* carte = firstCarte;
	int size = 0;
	if (carte == nullptr) {
		verrif = false;
	}
	else {
		size++;
	}
	while (verrif) {
		if (carte->getNextCarte() == nullptr) {
			verrif = false;
		}
		else {

			size++;
			carte = carte->getNextCarte();
		}
	}
	return size;
}


void ListeCarte::addCarte(DefCarte* newCarte) {
	
	

	if (firstCarte == nullptr) {
		firstCarte = newCarte;
		lastCarte = newCarte;
	}
	else
	{
		newCarte->setPreviousCarte(lastCarte);
		lastCarte->setNextCarte(newCarte);
		lastCarte = newCarte;
	}
	
}

DefCarte* ListeCarte::getCarte(int position) {
	DefCarte* interCarte = firstCarte;
	if (size() < position) {
		throw  std::exception();
	}
	else {


		for (int i = 1; i < position; i++) {
			interCarte = interCarte->getNextCarte();
		}
	}

	return interCarte;
}

void ListeCarte::piocher(Joueur* joueurActif, PlateauDeJeu* plateau, int* argentCentre) {
	DefCarte* cartePiochee = firstCarte; 

	firstCarte = cartePiochee->getNextCarte();
	firstCarte->setPreviousCarte(nullptr); 
	lastCarte->setNextCarte(cartePiochee); 
	cartePiochee->setNextCarte(nullptr);
	lastCarte = cartePiochee; 

	cartePiochee->effetCarte(joueurActif, plateau, argentCentre, this); 
}