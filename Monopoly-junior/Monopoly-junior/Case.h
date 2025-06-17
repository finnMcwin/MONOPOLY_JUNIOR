#pragma once
#include <string>

class Joueur;

class Case
{
protected: 
	int position ;
	std::string name; 

public : 

	Case(int position, std::string name);
	Case();

	int getPosition() const;
	std::string getName() const; 
	void setName(std::string newName); 
	void setPosition(int newPostion);
	void toString() const; 
	
	virtual bool getOccupe() const { return false; };
	virtual void visite(Joueur* visiteur) {};
	virtual void changerProprietaire(Joueur* joueur) {};
	virtual int getPrix() const { return 0; };
	virtual void acheter(Joueur* joueur) {}; 
	virtual Joueur* getProprio() const { return nullptr; };
	virtual std::string getCouleur() const { return " "; };
	virtual void setProprio(Joueur* joueur) {};

	virtual void payer(Joueur* joueur) {};
};

