#pragma once
#include "DefCarte.h"
#include <string>
#include "Attraction.h"

class StandGratuit: private DefCarte
{
private: 
	std::string couleur;

public: 
	StandGratuit(int nombre, std::string couleur);


};

