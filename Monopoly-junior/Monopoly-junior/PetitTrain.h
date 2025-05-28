#pragma once 
#include "Case.h"
#include <string>

class PetitTrain : public Case
{
private: 
	std::string couleur; 

public : 
	PetitTrain(int position, std::string couleur); 


};