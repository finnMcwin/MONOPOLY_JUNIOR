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
	int nbCartes();
	void setPreviousCarte(Cartes carte); 
	void setNextCarte(Cartes carte); 
	void standGratuitOrange();
	void standGratuitRouge();
	void standGratuitRose();
	void standGratuitBleuClair();
	void standGratuitJaune();
	void standGratuitVert();
	void standGratuitViolet();
	void vaCaseTobogan();
	void vaGrandHuit();
	void vaCafe();
	void vaCaseDepart();
	void vaBallet();
	void vaFeuArtifice();
	void train();

};

