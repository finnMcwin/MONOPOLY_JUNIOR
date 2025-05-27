#pragma once
#include "DefCarte.h"

class Cartes
{
private: 
	Cartes* previousCarte;
	Cartes* nextCarte; 
	DefCarte carte; 
public : 
	Cartes(Cartes* previousCarte, Cartes* nextCarte);

	Cartes* getPreviousCarte() const;
	Cartes* getNextCarte() const; 
	void setPreviousCarte();
	void setNextCarte();

};

