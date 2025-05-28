#include "Joueur.h"


Joueur::Joueur(std::string name, int argent, int stand, int position) 
	:name(name), argent(argent), stand(stand), position(position)
{

}

void Joueur::avancer(int nbCase) {
	position += nbCase; 
}