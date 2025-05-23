#pragma once
#include <string>

class Case
{
protected:
	int position;
	std::string caseName;

public : 
	int getPosition();
	std::string getName();
};

