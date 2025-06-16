#include <ctime>
#include <cstdlib>
#include "Case.h"
#include "Taxe.h"
#include "Attraction.h"
#include "PlateauDeJeu.h"
#include <iostream>
#include <limits> 

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
	Attraction* Pedalos = new Attraction(2, false, nullptr, 12, "rose", "Pedalos");
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
	Plateau.setCase(BarbePapa);
	Plateau.setCase(Chance2);
	Plateau.setCase(PetitTrainJaune);
	Plateau.setCase(TheatreMarionette);
	Plateau.setCase(SpectacleMagie);
	Plateau.setCase(FeuArtifice);
	Plateau.setCase(Chance3);
	Plateau.setCase(Cafe);
	Plateau.setCase(Manege);
	Plateau.setCase(Pedalos);
	Plateau.setCase(PetitTrainVert);
	Plateau.setCase(TobogganAquatique);
	Plateau.setCase(MiniGolf);
	Plateau.setCase(Fortune);
	Plateau.setCase(Chance4);
	Plateau.setCase(JeuVideo);
	Plateau.setCase(MaisonHantee);
	Plateau.setCase(Chance5);
	Plateau.setCase(PetitTrainBleu);
	Plateau.setCase(PromenadeHelico);
	Plateau.setCase(PromenadePoney);
	Plateau.setCase(BalletDauphin);
	Plateau.setCase(Chance6);
	Plateau.setCase(AllerCafe);
	Plateau.setCase(AutoToponneuse);
	Plateau.setCase(GrandeRoue);
	Plateau.setCase(PetitTrainRouge); 
	Plateau.setCase(GrandHuit);
	Plateau.setCase(MontagneRusse);

	Joueur* joueur1 = new Joueur(" ", 0, 0, 0);
	Joueur* joueur2 = new Joueur(" ", 0, 0, 0);
	Joueur* joueur3 = new Joueur(" ", 0, 0, 0);
	Joueur* joueur4 = new Joueur(" ", 0, 0, 0);
	int nbJoueur = 0; 

	std::cout << "Bienvenue dans le Monopoly Junior ! " << std::endl;
	
	while (nbJoueur < 2 || nbJoueur>4) {
		std::cout << "Merci d'indiquer le nombre de joueur souhaitant prendre part à l'aventure " << std::endl;
		std::cin >> nbJoueur;
		if (nbJoueur < 2) {
			std::cout << "Vous devez etre au minimum 2 joueurs" << std::endl;
		}
		else if (nbJoueur>4){
			std::cout << "Vous ne pouvez pas être plus de 4 joueurs" << std::endl;
		}
	}

	for (int iniJoueur = 1; iniJoueur <= nbJoueur; iniJoueur++) {
		if (iniJoueur == 1) {
			joueur1->iniJoueur(nbJoueur, iniJoueur);
		}
		else if (iniJoueur == 2) {
			joueur2->iniJoueur(nbJoueur, iniJoueur);
		}
		else if (iniJoueur == 3) {
			joueur3->iniJoueur(nbJoueur, iniJoueur);
		}
		else if (iniJoueur == 4) {
			joueur4->iniJoueur(nbJoueur, iniJoueur);
		}
	}

	std::cout << "Vous etes maintenant pret pour commencer le monopoly !" << std::endl << "Vous possedez tous un total de 31 euros et ";
	if (nbJoueur == 2) {
		std::cout << "15 stands qui vous permettrons d'acquerir des attractions" << std::endl;
	}
	else {
		std::cout << "10 stands qui vous permettrons d'acquerir des attractions" << std::endl;
	}
	std::cout << "Que le plus riche gagne !!" << std::endl << std::endl;

	bool jouer = true;
	int jouerActif = 0; 
	int argentMilieu = 0;
	int* argentCentre = &argentMilieu;

	while (jouer) {

		if (jouerActif == 4) {
			jouerActif = 1; 
		}
		else {
			jouerActif++;
		}

		if (jouerActif == 1) {
			std::cout << "C'est a " << joueur1->getName() << " de jouer !" << std::endl; 
			std::cout << "vous possedez actuellement " << joueur1->getArgent() << "euros et " << joueur1->getStand() << "stands" << std::endl;
			
			std::cout << "Appuyer sur Entrée pour lancer le dee" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
			

			joueur1->avancer(rollDice());
			Plateau.effetCase(joueur1->getPosition(), joueur1, argentCentre) ;

			if (joueur1->getArgent() <= 0) {
				std::cout << std::endl << "Vous etes fauche !" << std::endl;
				jouer = false;
			}
			std::cout << std::endl;
		}

		else if (jouerActif == 2) {
			std::cout << "C'est a " << joueur2->getName() << " de jouer !" << std::endl;
			std::cout << "vous possedez actuellement " << joueur2->getArgent() << "euros et " << joueur2->getStand() << "stands" << std::endl;

			std::cout << "Appuyer sur Entrée pour lancer le dee" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();


			joueur2->avancer(rollDice());
			Plateau.effetCase(joueur2->getPosition(), joueur2, argentCentre);

			if (joueur2->getArgent() <= 0) {
				std::cout << std::endl << "Vous etes fauche !" << std::endl;
				jouer = false;
			}
			std::cout << std::endl;
		}

		else if (jouerActif == 3) {
			std::cout << "C'est a " << joueur3->getName() << " de jouer !" << std::endl;
			std::cout << "vous possedez actuellement " << joueur3->getArgent() << "euros et " << joueur3->getStand() << "stands" << std::endl;

			std::cout << "Appuyer sur Entrée pour lancer le dee" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();


			joueur3->avancer(rollDice());
			Plateau.effetCase(joueur3->getPosition(), joueur3, argentCentre);

			if (joueur3->getArgent() <= 0) {
				std::cout << std::endl << "Vous etes fauche !" << std::endl;
				jouer = false;
			}
			std::cout << std::endl;
		}

		else if (jouerActif == 4) {
			std::cout << "C'est a " << joueur4->getName() << " de jouer !" << std::endl;
			std::cout << "vous possedez actuellement " << joueur4->getArgent() << "euros et " << joueur4->getStand() << "stands" << std::endl;

			std::cout << "Appuyer sur Entrée pour lancer le dee" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();


			joueur4->avancer(rollDice());
			Plateau.effetCase(joueur4->getPosition(), joueur4, argentCentre);

			if (joueur4->getArgent() <= 0) {
				std::cout << std::endl << "Vous etes fauche !" << std::endl;
				jouer = false;
			}
			std::cout << std::endl;
		}
	}

	return 0; 
}


int rollDice() {

	std::srand(static_cast<unsigned int>(std::time(0)));
	int nombre = (std::rand() % 6) + 1;
	std::cout << "Vous avez obtenu " << nombre << std::endl;

	return nombre; 
}