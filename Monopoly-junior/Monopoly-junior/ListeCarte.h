#pragma once
#include "DefCarte.h"


class ListeCarte
{
private : 
	DefCarte* firstCarte; 
	
	DefCarte* getCarte(int position); 

public: 
	ListeCarte();
	~ListeCarte();

	void addCarte(DefCarte* carte);
	DefCarte* piocher();

};

