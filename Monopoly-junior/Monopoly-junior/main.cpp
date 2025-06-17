#include <ctime>
#include <cstdlib>
#include "Case.h"
#include "Taxe.h"
#include "Attraction.h"
#include "PlateauDeJeu.h"
#include <iostream>
#include <limits> 
#include "ListeCarte.h"
#include "StandGratuit.h"
#include "CarteAllerA.h"
#include <vector>
#include <algorithm> 
#include <random>
#include <chrono> 
#include <thread>

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

	PlateauDeJeu* Plateau= new PlateauDeJeu;
	Plateau->setCase(Depart);
	Plateau->setCase(Chance1);
	Plateau->setCase(JeuDeBallons);
	Plateau->setCase(BarbePapa);
	Plateau->setCase(Chance2);
	Plateau->setCase(PetitTrainJaune);
	Plateau->setCase(TheatreMarionette);
	Plateau->setCase(SpectacleMagie);
	Plateau->setCase(FeuArtifice);
	Plateau->setCase(Chance3);
	Plateau->setCase(Cafe);
	Plateau->setCase(Manege);
	Plateau->setCase(Pedalos);
	Plateau->setCase(PetitTrainVert);
	Plateau->setCase(TobogganAquatique);
	Plateau->setCase(MiniGolf);
	Plateau->setCase(Fortune);
	Plateau->setCase(Chance4);
	Plateau->setCase(JeuVideo);
	Plateau->setCase(MaisonHantee);
	Plateau->setCase(Chance5);
	Plateau->setCase(PetitTrainBleu);
	Plateau->setCase(PromenadeHelico);
	Plateau->setCase(PromenadePoney);
	Plateau->setCase(BalletDauphin);
	Plateau->setCase(Chance6);
	Plateau->setCase(AllerCafe);
	Plateau->setCase(AutoToponneuse);
	Plateau->setCase(GrandeRoue);
	Plateau->setCase(PetitTrainRouge); 
	Plateau->setCase(GrandHuit);
	Plateau->setCase(MontagneRusse);


	StandGratuit* StandGratuitOrange1 = new StandGratuit("orange", "Stand Gratuit Orange", nullptr, nullptr);
	StandGratuit* StandGratuitOrange2 = new StandGratuit("orange", "Stand Gratuit Orange", nullptr, nullptr);
	StandGratuit* StandGratuitRouge1 = new StandGratuit("rouge", "Stand Gratuit Rouge", nullptr, nullptr);
	StandGratuit* StandGratuitRouge2 = new StandGratuit("rouge", "Stand Gratuit Rouge", nullptr, nullptr);
	StandGratuit* StandGratuitRose1 = new StandGratuit("rose", "Stand Gratuit Rose", nullptr, nullptr);
	StandGratuit* StandGratuitRose2 = new StandGratuit("rose", "Stand Gratuit Rose", nullptr, nullptr);
	StandGratuit* StandGratuitBlanc1 = new StandGratuit("blanc", "Stand Gratuit Blanc", nullptr, nullptr);
	StandGratuit* StandGratuitBlanc2 = new StandGratuit("blanc", "Stand Gratuit Blanc", nullptr, nullptr);
	StandGratuit* StandGratuitBleuClaire1 = new StandGratuit("bleuClaire", "Stand Gratuit Bleu Claire", nullptr, nullptr);
	StandGratuit* StandGratuitBleuClaire2 = new StandGratuit("bleuClaire", "Stand Gratuit Bleu Claire", nullptr, nullptr);
	StandGratuit* StandGratuitBleuFonce = new StandGratuit("bleuFonce", "Stand Gratuit Bleu Fonce", nullptr, nullptr);
	StandGratuit* StandGratuitJaune1 = new StandGratuit("jaune", "Stand Gratuit Jaune", nullptr, nullptr);
	StandGratuit* StandGratuitJaune2 = new StandGratuit("jaune", "Stand Gratuit Jaune", nullptr, nullptr);
	StandGratuit* StandGratuitVert1 = new StandGratuit("vert", "Stand Gratuit Vert", nullptr, nullptr);
	StandGratuit* StandGratuitVert2 = new StandGratuit("vert", "Stand Gratuit Vert", nullptr, nullptr);
	CarteAllerA* CarteTobboggan = new CarteAllerA(14, "Va sur le Tobboggan aquatique", nullptr, nullptr);
	CarteAllerA* CarteGrandHuit = new CarteAllerA(30, "Va sur le Grand Huit", nullptr, nullptr);
	CarteAllerA* CartePrendreBus = new CarteAllerA(26, "Va sur la case prendre le Bus ", nullptr, nullptr);
	CarteAllerA* CarteDepart = new CarteAllerA(0, "Va sur la case Depart ", nullptr, nullptr);
	CarteAllerA* CarteBalletDauphin = new CarteAllerA(24, "Va sur la case Ballet des Dauphins", nullptr, nullptr);
	CarteAllerA* CarteFeuArtifice = new CarteAllerA(8, "Va sur la case Feu d'Artifice", nullptr, nullptr);
	CarteAllerA* CartePetitTrainJaune = new CarteAllerA(5, "Va sur la case Petit Train Jaune", nullptr, nullptr);
	CarteAllerA* CartePetitTrainVert = new CarteAllerA(13, "Va sur la case Petit Train  Vert", nullptr, nullptr);
	CarteAllerA* CartePetitTrainBleu = new CarteAllerA(21, "Va sur la case Petit Train Bleu", nullptr, nullptr);
	CarteAllerA* CartePetitTrainRouge = new CarteAllerA(29, "Va sur la case Petit Train Rouge", nullptr, nullptr);


	std::vector <DefCarte*> listeProvisoire; 
	listeProvisoire.push_back(StandGratuitBlanc1);
	listeProvisoire.push_back(StandGratuitBlanc2);
	listeProvisoire.push_back(StandGratuitBleuClaire1);
	listeProvisoire.push_back(StandGratuitBleuClaire2);
	listeProvisoire.push_back(StandGratuitBleuFonce);
	listeProvisoire.push_back(StandGratuitJaune1);
	listeProvisoire.push_back(StandGratuitJaune2);
	listeProvisoire.push_back(StandGratuitOrange1);
	listeProvisoire.push_back(StandGratuitOrange2);
	listeProvisoire.push_back(StandGratuitRose1);
	listeProvisoire.push_back(StandGratuitRose2);
	listeProvisoire.push_back(StandGratuitRouge1);
	listeProvisoire.push_back(StandGratuitRouge2);
	listeProvisoire.push_back(StandGratuitVert1);
	listeProvisoire.push_back(StandGratuitVert2);
	listeProvisoire.push_back(CarteBalletDauphin); 
	listeProvisoire.push_back(CarteDepart);
	listeProvisoire.push_back(CarteFeuArtifice);
	listeProvisoire.push_back(CarteGrandHuit); 
	listeProvisoire.push_back(CartePetitTrainBleu);
	listeProvisoire.push_back(CartePetitTrainJaune);
	listeProvisoire.push_back(CartePetitTrainRouge);
	listeProvisoire.push_back(CartePetitTrainVert);
	listeProvisoire.push_back(CartePrendreBus);
	listeProvisoire.push_back(CarteTobboggan);

	// Melange des Cartes

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(listeProvisoire.begin(), listeProvisoire.end(), std::default_random_engine(seed));

	ListeCarte* piocheCarte = new ListeCarte(); 

	for (std::vector<DefCarte*>::iterator it = listeProvisoire.begin(); it < listeProvisoire.end(); ++it)
	{
		piocheCarte->addCarte(*it); 
	}


	Joueur* joueur1 = new Joueur(" ", 0, 0, 0);
	Joueur* joueur2 = new Joueur(" ", 0, 0, 0);
	Joueur* joueur3 = new Joueur(" ", 0, 0, 0);
	Joueur* joueur4 = new Joueur(" ", 0, 0, 0);
	int nbJoueur = 0; 

	std::cout << std::endl << "BIENVENUE DANS LE MONOPOLY JUNIOR ! " << std::endl << std::endl;
	
	while (nbJoueur < 2 || nbJoueur>4) {
		std::cout << "Merci d'indiquer le nombre de joueur souhaitant prendre part a l'aventure " << std::endl;
		std::cin >> nbJoueur;
		if (nbJoueur < 2) {
			std::cout << "Vous devez etre au minimum 2 joueurs" << std::endl;
		}
		else if (nbJoueur>4){
			std::cout << "Vous ne pouvez pas etre plus de 4 joueurs" << std::endl;
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

	std::cout << std::endl << "Vous etes maintenant pret pour commencer le monopoly !" << std::endl << "Vous possedez tous un total de 31 euros et ";
	if (nbJoueur == 2) {
		std::cout << "15 stands qui vous permettrons d'acquerir des attractions" << std::endl;
	}
	else {
		std::cout << "10 stands qui vous permettrons d'acquerir des attractions" << std::endl;
	}
	std::cout << std::endl << "Que le plus riche gagne !!" << std::endl << std::endl;
	
	std::this_thread::sleep_for(std::chrono::seconds(3));
	system("cls");

	bool jouer = true;
	char de = 'A'; 
	int jouerActif = 0; 
	int argentMilieu = 0;
	int* argentCentre = &argentMilieu;


	while (jouer) {

		if (jouerActif == nbJoueur) {
			jouerActif = 1; 
		}
		else {
			jouerActif++;
		}
		de = 'A';


		if (jouerActif == 1) {
			std::cout << std::endl << "------------ C'est a " << joueur1->getName() << " de jouer ! ------------" << std::endl << std::endl; 
			std::cout << std::endl << "-> Vous possedez actuellement " << joueur1->getArgent() << "euros et " << joueur1->getStand() << "stands" << std::endl;
			
			std::cout << std::endl << "Entre D pour lancer le de " << std::endl;			
			while (de != 'D') {
				std::cin >> de; 
			}

			joueur1->avancer(rollDice());
			std::cout << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			Plateau->effetCase(joueur1->getPosition(), joueur1, argentCentre, piocheCarte) ;

			if (joueur1->getArgent() <= 0) {
				std::cout << std::endl << "Vous etes fauche !" << std::endl;
				jouer = false;
			}
			std::cout << std::endl;
		}

		else if (jouerActif == 2) {
			std::cout << std::endl << "------------ C'est a " << joueur2->getName() << " de jouer ! ------------" << std::endl;
			std::cout << std::endl << "-> Vous possedez actuellement " << joueur2->getArgent() << "euros et " << joueur2->getStand() << "stands" << std::endl;

			std::cout << std::endl << "Entre D pour lancer le de " << std::endl;
			while (de != 'D') {
				std::cin >> de;
			}

			joueur2->avancer(rollDice());
			std::cout << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			Plateau->effetCase(joueur2->getPosition(), joueur2, argentCentre, piocheCarte);

			if (joueur2->getArgent() <= 0) {
				std::cout << std::endl << "Vous etes fauche !" << std::endl;
				jouer = false;
			}
			std::cout << std::endl;
		}

		else if (jouerActif == 3) {
			std::cout << std::endl << "------------ C'est a " << joueur3->getName() << " de jouer ! ------------" << std::endl;
			std::cout << std::endl <<  "-> Vous possedez actuellement " << joueur3->getArgent() << "euros et " << joueur3->getStand() << "stands" << std::endl;

			std::cout << std::endl << "Entre D pour lancer le de " << std::endl;
			while (de != 'D') {
				std::cin >> de;
			}


			joueur3->avancer(rollDice());
			std::cout << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			Plateau->effetCase(joueur3->getPosition(), joueur3, argentCentre, piocheCarte);

			if (joueur3->getArgent() <= 0) {
				std::cout << std::endl << "Vous etes fauche !" << std::endl;
				jouer = false;
			}
			std::cout << std::endl;
		}

		else if (jouerActif == 4) {
			std::cout << std::endl << "------------ C'est a " << joueur4->getName() << " de jouer ! ------------" << std::endl;
			std::cout << std::endl << "-> Vous possedez actuellement " << joueur4->getArgent() << "euros et " << joueur4->getStand() << "stands" << std::endl;

			std::cout << std::endl << "Entre D pour lancer le de " << std::endl;
			while (de != 'D') {
				std::cin >> de;
			}

			joueur4->avancer(rollDice());
			std::cout << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			Plateau->effetCase(joueur4->getPosition(), joueur4, argentCentre, piocheCarte);

			if (joueur4->getArgent() <= 0) {
				std::cout << std::endl << "Vous etes fauche !" << std::endl;
				jouer = false;
			}
			std::cout << std::endl;
		}

		std::this_thread::sleep_for(std::chrono::seconds(3));
		system("cls");
	}

	return 0; 
}


int rollDice() {

	std::srand(static_cast<unsigned int>(std::time(0)));
	int nombre = (std::rand() % 6) + 1;
	std::cout << "Vous avez obtenu " << nombre << std::endl;

	return nombre; 
}