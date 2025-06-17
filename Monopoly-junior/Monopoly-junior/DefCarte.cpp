#include "DefCarte.h"


DefCarte::DefCarte(DefCarte* nextCarte,DefCarte* previousCarte, std::string name) 
	:nextCarte(nextCarte),previousCarte(previousCarte), name(name)
{
}

DefCarte* DefCarte::getNextCarte() const {
	return nextCarte; 
}

DefCarte* DefCarte::getPreviousCarte() const {
	return previousCarte;
}


void DefCarte::setNextCarte(DefCarte* carte) {
	nextCarte = carte; 
}


void DefCarte::setPreviousCarte(DefCarte* carte) {
	previousCarte = carte;
}

void DefCarte::setName(std::string newName) {
	name = newName;
}