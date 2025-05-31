#include "Case.h"
#include <iostream>

Case::Case(int position, std::string name)
{
	this->position = position;
	this->name = name;
}

Case::Case() 
	:position(0)
{
	
}

int Case::getPosition() const {
	return position; 
}

void Case::setPosition(int newPosition) {
	position = newPosition; 
}

std::string Case::getName() const {
	return name;
}

void Case::setName(std::string newName) {
	name = newName;
}

void Case::toString() const {
	std::cout << "Vous etes sur la case " << name << std::endl;
}