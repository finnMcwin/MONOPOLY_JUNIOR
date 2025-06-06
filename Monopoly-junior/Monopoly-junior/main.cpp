#include <ctime>
#include <cstdlib>
#include "Case.h"
#include "Taxe.h"
#include "Attraction.h"
#include "PlateauDeJeu.h"
#include <iostream>

int rollDice(); 

int main() {

	Taxe* Depart = new Taxe(2, 0, "Depart");
	Case* Chance1 = new Case(1, "Chance");
	Attraction* JeuDeBallons = new Attraction(1, false, nullptr, 2, "bleuFonce", "Jeu de Ballons");
	Attraction* BarbePapa = new Attraction(1, false, nullptr, 3, "bleuFonce", "Barbe a Papa");
	Case* Chance2 = new Case(4, "Chance"); 
	Case* PetitTrainJaune = new Case(5, "Petit Train Jaune"); 
	Attraction* TheatreMarionette = new Attraction(2, false, nullptr, 6, "blanc", "Theatre de Marionette");
	Attraction* SpectacleMagie = new Attraction(2, false, nullptr, 7, "blanc", "Spectacle de Magie");
	Taxe* FeuArtifice = new Taxe(-2, 8, "Feu d'Artifice");
	Case* Chance3 = new Case(9, "Chance");
	Case* Cafe = new Case(10, "Cafe");
	Attraction* Manege = new Attraction(2, false, nullptr, 11, "rose", "Manege");
	Attraction* Pedalose = new Attraction(2, false, nullptr, 12, "rose", "Pedalos");
	Case* PetitTrainVert = new Case(13, "Petit Train Vert"); 
	Attraction* TobogganAquatique = new Attraction(3, false, nullptr, 14, "orange", "Toboggan Aquatique");
	Attraction* MiniGolf = new Attraction(3, false, nullptr, 15, "orange", "Mini golf");
	Case* Fortune = new Case(16, "Fortune"); 
	Case* Chance4 = new Case(17, "Chance");
	Attraction* JeuVideo = new Attraction(3, false, nullptr, 18, "rouge", "Jeux Video");
	Attraction* MaisonHantee = new Attraction(3, false, nullptr, 19, "rouge", "Maison Hantee");
	Case* Chance5 = new Case(20, "Chance");
	Case* PetitTrainBleu = new Case(21, "Petit Train Bleu");
	Attraction* PromenadeHelico = new Attraction(4, false, nullptr,22, "jaune", "Promenade en Helicoptere");
	Attraction* PromenadePoney = new Attraction(4, false, nullptr, 23, "jaune", "Promenade a Poney");
	Taxe* BalletDauphin = new Taxe(-2, 24, "Ballet des Dauphins"); 
	Case* Chance6 = new Case(25, "Chance");
	Case* AllerCafe = new Case(26, "Prendre le bus pour aller au Cafe"); 
	Attraction* AutoToponneuse = new Attraction(4, false, nullptr, 27, "vert", "Autos Tamponneuses");
	Attraction* GrandeRoue = new Attraction(4, false, nullptr, 28, "jaune", "Grande Roue");
	Case* PetitTrainRouge = new Case(29, "Petit Train Rouge");
	Attraction* GrandHuit = new Attraction(5, false, nullptr, 30, "bleuClaire", "Grand Huit");
	Attraction* MontagneRusse = new Attraction(5, false, nullptr, 31, "bleuClaire", "Montagne Russe");

	PlateauDeJeu Plateau;
	Plateau.setCase(Depart);
	Plateau.setCase(Chance1);
	Plateau.setCase(JeuDeBallons);

	Plateau.getCase(2)->toString();
	std::cout << Plateau.getCase(2)->getPrix() << std::endl;

	return 0; 
}


int rollDice() {

	std::srand(std::time(0));
	int nombre = (std::rand() % 6) + 1;

	return nombre; 
}