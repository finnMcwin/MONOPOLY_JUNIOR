#include "Case.h"

Case::Case(int position)
{
	this->position = position;
}

Case::Case() {
}

int Case::getPosition() const {
	return position; 
}

void Case::setPosition(int newPosition) {
	position = newPosition; 
}