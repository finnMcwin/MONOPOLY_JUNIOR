#include <ctime>
#include <cstdlib>

int rollDice(); 

int main() {

	return 0; 
}


int rollDice() {

	std::srand(std::time(0));
	int nombre = (std::rand() % 6) + 1;

	return nombre; 
}