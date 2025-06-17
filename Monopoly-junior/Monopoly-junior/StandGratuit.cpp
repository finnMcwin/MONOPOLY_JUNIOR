#include "StandGratuit.h"
#include <iostream>




StandGratuit::StandGratuit(std::string couleur, std::string name, DefCarte* nextCarte)
	: DefCarte(nextCarte, name), couleur(couleur)
{
}

void StandGratuit::effetCarte(Joueur* joueurActif, PlateauDeJeu* plateau, int* argentCentre) {
	
	std::cout << "Vous avez piochez une carte Stand Gratuit " + couleur << std::endl << std::endl; 
	int reponse = 0; 

	if (couleur == "orange") {

		if (plateau->getCase(14)->getProprio() == nullptr && plateau->getCase(15)->getProprio() == nullptr) {
			std::cout << "Les 2 attraction Oranges sont libres ! Laquelle voulez-vous :" << std::endl << "1) Tobboggan aquatique" << std::endl << "2) Mini-golf" << std::endl;
			while (reponse != 1 && reponse != 2) {
				std::cin >> reponse;
			}

			if (reponse == 1) {
				plateau->getCase(14)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire du Tobboggan Aquatique" << std::endl;
			}
			else if (reponse == 2) {
				plateau->getCase(15)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire du Mini-Golf" << std::endl;
			}
		}
		else if (plateau->getCase(15)->getProprio() == plateau->getCase(14)->getProprio()) {
			std::cout << "Les 2 attractions Oranges sont deja prise par le meme proprietaire !" << std::endl;
		}
		else if (plateau->getCase(14)->getProprio() == nullptr) {
			std::cout << "Seul le Tobboggan est libre en Orange, il est maintenant a vous ! " << std::endl;
			plateau->getCase(14)->setProprio(joueurActif);
		}
		else if (plateau->getCase(15)->getProprio() == nullptr) {
			std::cout << "Seul le Mini-Golf est libre en Orange, il est maintenant a vous ! " << std::endl;
			plateau->getCase(15)->setProprio(joueurActif);
		}
		else {
			std::cout << "Les 2 attractions sont occupees par 2 proprietaires differents, vous pouvez en avoir une nouvelle !" << std::endl;
			if (plateau->getCase(14)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire du Tobboggan, vous obtenez en plus le Mini-Golf !" << std::endl;
				plateau->getCase(15)->changerProprietaire(joueurActif);
			}
			else if (plateau->getCase(15)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire du Mini-Golf, vous obtenez en plus le Tobboggan Aquatique !" << std::endl;
				plateau->getCase(14)->changerProprietaire(joueurActif);
			}
			else {
				std::cout << "Laquelle voulez-vous :" << std::endl << "1) Tobboggan aquatique" << std::endl << "2) Mini-golf" << std::endl;
				while (reponse != 1 && reponse != 2) {
					std::cin >> reponse;
				}

				if (reponse == 1) {
					plateau->getCase(14)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire du Tobboggan Aquatique" << std::endl;
				}
				else if (reponse == 2) {
					plateau->getCase(15)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire du Mini-Golf" << std::endl;
				}
			}

		}
	}

	else if (couleur == "rouge") {

		if (plateau->getCase(18)->getProprio() == nullptr && plateau->getCase(19)->getProprio() == nullptr) {
			std::cout << "Les 2 attraction Rouges sont libres ! Laquelle voulez-vous :" << std::endl << "1) Jeu Video" << std::endl << "2) Maison Hantee" << std::endl;
			while (reponse != 1 && reponse != 2) {
				std::cin >> reponse;
			}

			if (reponse == 1) {
				plateau->getCase(18)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire des Jeux videos" << std::endl;
			}
			else if (reponse == 2) {
				plateau->getCase(19)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire de la Maison Hantee" << std::endl;
			}
		}
		else if (plateau->getCase(18)->getProprio() == plateau->getCase(19)->getProprio()) {
			std::cout << "Les 2 attractions Rouges sont deja prise par le meme proprietaire !" << std::endl;
		}
		else if (plateau->getCase(18)->getProprio() == nullptr) {
			std::cout << "Seul les Jeux Videos sont libres en Rouge, il est maintenant a vous ! " << std::endl;
			plateau->getCase(18)->setProprio(joueurActif);
		}
		else if (plateau->getCase(19)->getProprio() == nullptr) {
			std::cout << "Seul la Maison Hantee est libre en Rouge, elle est maintenant a vous ! " << std::endl;
			plateau->getCase(19)->setProprio(joueurActif);
		}
		else {
			std::cout << "Les 2 attractions sont occupees par 2 proprietaires differents, vous pouvez en avoir une nouvelle !" << std::endl;
			if (plateau->getCase(18)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire des Jeux Videos, vous obtenez en plus la Maison Hantee !" << std::endl;
				plateau->getCase(19)->changerProprietaire(joueurActif);
			}
			else if (plateau->getCase(19)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire de la Maison Hantee, vous obtenez en plus les Jeux Videos !" << std::endl;
				plateau->getCase(18)->changerProprietaire(joueurActif);
			}
			else {
				std::cout << "Laquelle voulez-vous :" << std::endl << "1) Jeux Videos" << std::endl << "2) Maison Hantee" << std::endl;
				while (reponse != 1 && reponse != 2) {
					std::cin >> reponse;
				}

				if (reponse == 1) {
					plateau->getCase(18)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire des Jeux Videos" << std::endl;
				}
				else if (reponse == 2) {
					plateau->getCase(19)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire de la Maison Hantee" << std::endl;
				}
			}

		}
	}

}