#include "StandGratuit.h"
#include "PlateauDeJeu.h"
#include "ListeCarte.h"
#include <iostream>




StandGratuit::StandGratuit(std::string couleur, std::string name, DefCarte* nextCarte, DefCarte* previousCarte)
	: DefCarte(nextCarte, previousCarte, name), couleur(couleur)
{
}

void StandGratuit::effetCarte(Joueur* joueurActif, PlateauDeJeu* plateau, int* argentCentre, ListeCarte* Cartes) {
	
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

	else if (couleur == "bleuFonce") {

		if (plateau->getCase(2)->getProprio() == nullptr && plateau->getCase(3)->getProprio() == nullptr) {
			std::cout << "Les 2 attraction Bleu Fonce sont libres ! Laquelle voulez-vous :" << std::endl << "1) Jeu de Ballons" << std::endl << "2) Barbe a Papa" << std::endl;
			while (reponse != 1 && reponse != 2) {
				std::cin >> reponse;
			}

			if (reponse == 1) {
				plateau->getCase(2)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire du Jeu de Ballons" << std::endl;
			}
			else if (reponse == 2) {
				plateau->getCase(3)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire de la Barbe a Papa" << std::endl;
			}
		}
		else if (plateau->getCase(2)->getProprio() == plateau->getCase(3)->getProprio()) {
			std::cout << "Les 2 attractions Bleu Fonce sont deja prise par le meme proprietaire !" << std::endl;
		}
		else if (plateau->getCase(2)->getProprio() == nullptr) {
			std::cout << "Seul le jeu de Ballons est libre en Bleu Fonce, il est maintenant a vous ! " << std::endl;
			plateau->getCase(2)->setProprio(joueurActif);
		}
		else if (plateau->getCase(3)->getProprio() == nullptr) {
			std::cout << "Seul la Barbe a papa est libre en Bleu Fonce, elle est maintenant a vous ! " << std::endl;
			plateau->getCase(3)->setProprio(joueurActif);
		}
		else {
			std::cout << "Les 2 attractions sont occupees par 2 proprietaires differents, vous pouvez en avoir une nouvelle !" << std::endl;
			if (plateau->getCase(2)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire du Jeu de Ballons, vous obtenez en plus la Barbe a Papa !" << std::endl;
				plateau->getCase(3)->changerProprietaire(joueurActif);
			}
			else if (plateau->getCase(3)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire de la Barbe a Papa, vous obtenez en plus le Jeu de Ballon !" << std::endl;
				plateau->getCase(2)->changerProprietaire(joueurActif);
			}
			else {
				std::cout << "Laquelle voulez-vous :" << std::endl << "1) Jeu de Ballons" << std::endl << "2) Barbe a Papa" << std::endl;
				while (reponse != 1 && reponse != 2) {
					std::cin >> reponse;
				}

				if (reponse == 1) {
					plateau->getCase(2)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire du Jeu de Ballon" << std::endl;
				}
				else if (reponse == 2) {
					plateau->getCase(3)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire de la Barbe a Papa" << std::endl;
				}
			}
		}
	}

	else if (couleur == "bleuClaire") {

		if (plateau->getCase(30)->getProprio() == nullptr && plateau->getCase(31)->getProprio() == nullptr) {
			std::cout << "Les 2 attraction Bleu Claire sont libres ! Laquelle voulez-vous :" << std::endl << "1) Grand Huit" << std::endl << "2) Montagne Russe" << std::endl;
			while (reponse != 1 && reponse != 2) {
				std::cin >> reponse;
			}

			if (reponse == 1) {
				plateau->getCase(30)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire du Grand Huit" << std::endl;
			}
			else if (reponse == 2) {
				plateau->getCase(31)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire de la Montagne Russe" << std::endl;
			}
		}
		else if (plateau->getCase(30)->getProprio() == plateau->getCase(31)->getProprio()) {
			std::cout << "Les 2 attractions Bleu Claire sont deja prise par le meme proprietaire !" << std::endl;
		}
		else if (plateau->getCase(30)->getProprio() == nullptr) {
			std::cout << "Seul le Grand Huit est libre en Bleu Claire, il est maintenant a vous ! " << std::endl;
			plateau->getCase(30)->setProprio(joueurActif);
		}
		else if (plateau->getCase(31)->getProprio() == nullptr) {
			std::cout << "Seul la Montagne Russe est libre en Bleu Claire, elle est maintenant a vous ! " << std::endl;
			plateau->getCase(31)->setProprio(joueurActif);
		}
		else {
			std::cout << "Les 2 attractions sont occupees par 2 proprietaires differents, vous pouvez en avoir une nouvelle !" << std::endl;
			if (plateau->getCase(30)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire du Grand Huit, vous obtenez en plus la Montagne Russe !" << std::endl;
				plateau->getCase(31)->changerProprietaire(joueurActif);
			}
			else if (plateau->getCase(31)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire de la Montagne Russe, vous obtenez en plus le Grand Huit !" << std::endl;
				plateau->getCase(30)->changerProprietaire(joueurActif);
			}
			else {
				std::cout << "Laquelle voulez-vous :" << std::endl << "1) Grand Huit" << std::endl << "2) Montagne Russe" << std::endl;
				while (reponse != 1 && reponse != 2) {
					std::cin >> reponse;
				}

				if (reponse == 1) {
					plateau->getCase(30)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire du Grand Huit" << std::endl;
				}
				else if (reponse == 2) {
					plateau->getCase(31)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire de la Montagne Russe" << std::endl;
				}
			}
		}
	}

	else if (couleur == "blanc") {

		if (plateau->getCase(6)->getProprio() == nullptr && plateau->getCase(7)->getProprio() == nullptr) {
			std::cout << "Les 2 attraction Blanche sont libres ! Laquelle voulez-vous :" << std::endl << "1) Theatre de Marionette" << std::endl << "2) Spectacle de Magie" << std::endl;
			while (reponse != 1 && reponse != 2) {
				std::cin >> reponse;
			}

			if (reponse == 1) {
				plateau->getCase(6)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire du Theatre de Marionette" << std::endl;
			}
			else if (reponse == 2) {
				plateau->getCase(7)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire du Spectacle de Magie" << std::endl;
			}
		}
		else if (plateau->getCase(6)->getProprio() == plateau->getCase(7)->getProprio()) {
			std::cout << "Les 2 attractions Blanche sont deja prise par le meme proprietaire !" << std::endl;
		}
		else if (plateau->getCase(6)->getProprio() == nullptr) {
			std::cout << "Seul le Theatre de Marionette est libre en Blanc, il est maintenant a vous ! " << std::endl;
			plateau->getCase(6)->setProprio(joueurActif);
		}
		else if (plateau->getCase(7)->getProprio() == nullptr) {
			std::cout << "Seul le Spectacle de Magie est libre en Blanc, il est maintenant a vous ! " << std::endl;
			plateau->getCase(7)->setProprio(joueurActif);
		}
		else {
			std::cout << "Les 2 attractions sont occupees par 2 proprietaires differents, vous pouvez en avoir une nouvelle !" << std::endl;
			if (plateau->getCase(6)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire du Theatre de Marionette, vous obtenez en plus le Spectacle de Magie !" << std::endl;
				plateau->getCase(7)->changerProprietaire(joueurActif);
			}
			else if (plateau->getCase(7)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire du Spectacle de Magie, vous obtenez en plus le Theatre de Marionette !" << std::endl;
				plateau->getCase(6)->changerProprietaire(joueurActif);
			}
			else {
				std::cout << "Laquelle voulez-vous :" << std::endl << "1) Theatre de Marionette" << std::endl << "2) Spectacle de Magie" << std::endl;
				while (reponse != 1 && reponse != 2) {
					std::cin >> reponse;
				}

				if (reponse == 1) {
					plateau->getCase(6)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire du Theatre de Marionette" << std::endl;
				}
				else if (reponse == 2) {
					plateau->getCase(7)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire du Spectacle de Magie" << std::endl;
				}
			}
		}
	}

	else if (couleur == "rose") {

		if (plateau->getCase(11)->getProprio() == nullptr && plateau->getCase(12)->getProprio() == nullptr) {
			std::cout << "Les 2 attraction Rose sont libres ! Laquelle voulez-vous :" << std::endl << "1) Manege" << std::endl << "2) Pedalos" << std::endl;
			while (reponse != 1 && reponse != 2) {
				std::cin >> reponse;
			}

			if (reponse == 1) {
				plateau->getCase(11)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire du Manege" << std::endl;
			}
			else if (reponse == 2) {
				plateau->getCase(12)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire des Pedalos" << std::endl;
			}
		}
		else if (plateau->getCase(11)->getProprio() == plateau->getCase(12)->getProprio()) {
			std::cout << "Les 2 attractions Rose sont deja prise par le meme proprietaire !" << std::endl;
		}
		else if (plateau->getCase(11)->getProprio() == nullptr) {
			std::cout << "Seul le Manege est libre en Rose, il est maintenant a vous ! " << std::endl;
			plateau->getCase(11)->setProprio(joueurActif);
		}
		else if (plateau->getCase(12)->getProprio() == nullptr) {
			std::cout << "Seul les Pedalos sont libres en Rose, ils sont maintenant a vous ! " << std::endl;
			plateau->getCase(12)->setProprio(joueurActif);
		}
		else {
			std::cout << "Les 2 attractions sont occupees par 2 proprietaires differents, vous pouvez en avoir une nouvelle !" << std::endl;
			if (plateau->getCase(11)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire du Manege, vous obtenez en plus les Pedalos !" << std::endl;
				plateau->getCase(12)->changerProprietaire(joueurActif);
			}
			else if (plateau->getCase(12)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire des Pedalos, vous obtenez en plus le Manege !" << std::endl;
				plateau->getCase(11)->changerProprietaire(joueurActif);
			}
			else {
				std::cout << "Laquelle voulez-vous :" << std::endl << "1) Manege" << std::endl << "2) Pedalos" << std::endl;
				while (reponse != 1 && reponse != 2) {
					std::cin >> reponse;
				}

				if (reponse == 1) {
					plateau->getCase(11)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire du Manege" << std::endl;
				}
				else if (reponse == 2) {
					plateau->getCase(12)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire des Pedalos" << std::endl;
				}
			}
		}
	}

	else if (couleur == "jaune") {

		if (plateau->getCase(22)->getProprio() == nullptr && plateau->getCase(23)->getProprio() == nullptr) {
			std::cout << "Les 2 attraction Jaune sont libres ! Laquelle voulez-vous :" << std::endl << "1) Promenade en Helico" << std::endl << "2) Promenade a Poney" << std::endl;
			while (reponse != 1 && reponse != 2) {
				std::cin >> reponse;
			}

			if (reponse == 1) {
				plateau->getCase(22)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire de la Promenade en Helico" << std::endl;
			}
			else if (reponse == 2) {
				plateau->getCase(23)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire de la Promenade a Poney" << std::endl;
			}
		}
		else if (plateau->getCase(22)->getProprio() == plateau->getCase(23)->getProprio()) {
			std::cout << "Les 2 attractions Jaune sont deja prise par le meme proprietaire !" << std::endl;
		}
		else if (plateau->getCase(22)->getProprio() == nullptr) {
			std::cout << "Seul la Promenade en Helico est libre en Jaune, elle est maintenant a vous ! " << std::endl;
			plateau->getCase(22)->setProprio(joueurActif);
		}
		else if (plateau->getCase(23)->getProprio() == nullptr) {
			std::cout << "Seul la Promenade a Poney est libre en Jaune, elle est maintenant a vous ! " << std::endl;
			plateau->getCase(23)->setProprio(joueurActif);
		}
		else {
			std::cout << "Les 2 attractions sont occupees par 2 proprietaires differents, vous pouvez en avoir une nouvelle !" << std::endl;
			if (plateau->getCase(22)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire de la Promenade en Helico, vous obtenez en plus la promenade a Poney !" << std::endl;
				plateau->getCase(23)->changerProprietaire(joueurActif);
			}
			else if (plateau->getCase(23)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire de la Promenade a Poney, vous obtenez en plus la Promenade en Helico !" << std::endl;
				plateau->getCase(22)->changerProprietaire(joueurActif);
			}
			else {
				std::cout << "Laquelle voulez-vous :" << std::endl << "1) Promenade en Helico" << std::endl << "2) Promenade a Poney" << std::endl;
				while (reponse != 1 && reponse != 2) {
					std::cin >> reponse;
				}

				if (reponse == 1) {
					plateau->getCase(22)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire de la Promenade en Helico" << std::endl;
				}
				else if (reponse == 2) {
					plateau->getCase(23)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire de la Promenade a Poney" << std::endl;
				}
			}
		}
	}

	else if (couleur == "vert") {

		if (plateau->getCase(27)->getProprio() == nullptr && plateau->getCase(28)->getProprio() == nullptr) {
			std::cout << "Les 2 attraction Verte sont libres ! Laquelle voulez-vous :" << std::endl << "1) Autos Tamponneuses" << std::endl << "2) Grande Roue" << std::endl;
			while (reponse != 1 && reponse != 2) {
				std::cin >> reponse;
			}

			if (reponse == 1) {
				plateau->getCase(27)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire des Autos Tamponneuses" << std::endl;
			}
			else if (reponse == 2) {
				plateau->getCase(28)->setProprio(joueurActif);
				std::cout << "Vous etes desormais proprietaire de la Grande Roue" << std::endl;
			}
		}
		else if (plateau->getCase(27)->getProprio() == plateau->getCase(28)->getProprio()) {
			std::cout << "Les 2 attractions Verte sont deja prise par le meme proprietaire !" << std::endl;
		}
		else if (plateau->getCase(27)->getProprio() == nullptr) {
			std::cout << "Seuls les Autos Tamponneuses sont libres en Vert, elles sont maintenant a vous ! " << std::endl;
			plateau->getCase(27)->setProprio(joueurActif);
		}
		else if (plateau->getCase(28)->getProprio() == nullptr) {
			std::cout << "Seul la Grande Roue est libre en Vert, elle est maintenant a vous ! " << std::endl;
			plateau->getCase(28)->setProprio(joueurActif);
		}
		else {
			std::cout << "Les 2 attractions sont occupees par 2 proprietaires differents, vous pouvez en avoir une nouvelle !" << std::endl;
			if (plateau->getCase(27)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire des Autos Tamponneuses, vous obtenez en plus la Grande Roue !" << std::endl;
				plateau->getCase(28)->changerProprietaire(joueurActif);
			}
			else if (plateau->getCase(28)->getProprio() == joueurActif) {
				std::cout << "Vous etes deja proprietaire de la Grande Roue, vous obtenez en plus les Autos Tamponneuses !" << std::endl;
				plateau->getCase(27)->changerProprietaire(joueurActif);
			}
			else {
				std::cout << "Laquelle voulez-vous :" << std::endl << "1) Autos Tamponneuses" << std::endl << "2) Grande Roue" << std::endl;
				while (reponse != 1 && reponse != 2) {
					std::cin >> reponse;
				}

				if (reponse == 1) {
					plateau->getCase(22)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire des Autos Tamponneuse" << std::endl;
				}
				else if (reponse == 2) {
					plateau->getCase(7)->changerProprietaire(joueurActif);
					std::cout << "Vous etes desormais proprietaire de la Grande Roue" << std::endl;
				}
			}
		}
	}


}