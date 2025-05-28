#pragma once


class Cartes
{
private : 
	Cartes* previousCarte; 
	Cartes* nextCarte; 

public: 
	Cartes(Cartes* previousCarte, Cartes* nextCarte); 

	Cartes* getPreviousCarte() const; 
	Cartes* getNextCarte() const; 
	void setPreviousCarte(Cartes carte); 
	void setNextCarte(Cartes carte); 

};

