#pragma once
#include "Cartes.h"

class ListeCarte
{
private: 
	Cartes* firstCarte; 
	Cartes* lastCarte; 
	Cartes* getCarte(int position); 

public : 
	ListeCarte();
	~ListeCarte();
	int size();
	void add(); 
	void insert(int position); 
	void remove(int position); 
	int operator[](int position);
};

