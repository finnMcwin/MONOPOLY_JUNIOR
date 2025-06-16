#pragma once

#include <iostream>
#include <string>
#include <functional>
#include "Case.h"
#include "joueur.h"
#include "PlateauDeJeu.h"

class Carte {
public:
    std::string message;
    std::function<void()> effet;
    Carte* suivant;

    Carte(const std::string& msg, std::function<void()> effetAssocie)
        : message(msg), effet(effetAssocie), suivant(nullptr) {
    }

    void appliquerEffet() const {
        std::cout << "Carte tirée : " << message << std::endl;
        effet(); // on exécute l'action spécifique
    }
};

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class TasDeCartes {
private:
    Carte* tete;
    int* argentJoueur; // pointeur vers l'argent du joueur
    int* positionJoueur;

    void initialiserCartes(Joueur* joueurActif, PlateauDeJeu* plateau, int* argentCentre) {
        ajouterCarte("Allez au grand huit", [&]() {
                joueurActif->allerA(30);
                plateau->effetCase(30, joueurActif, argentCentre);
            });

        ajouterCarte("Va sur la case Depart", [&]() {
            joueurActif->allerA(0);
            plateau->effetCase(0, joueurActif, argentCentre);
            });

        ajouterCarte("Va sur la case Ballet des Dauphins", [&]() {
            joueurActif->allerA(24);
            plateau->effetCase(24, joueurActif, argentCentre);
            });

        ajouterCarte("Va sur la case Aller au Cafe", [&]() {
            joueurActif->allerA(26);
            plateau->effetCase(26, joueurActif, argentCentre);
            });

        ajouterCarte("Va sur la case Feu d'Artifice", [&]() {
            joueurActif->allerA(8);
            plateau->effetCase(8, joueurActif, argentCentre);
            });

        ajouterCarte("Prend le Petit Train Jaune", [&]() {
            joueurActif->allerA(5);
            plateau->effetCase(5, joueurActif, argentCentre);
            });

        ajouterCarte("Prend le Petit Train Vert", [&]() {
            joueurActif->allerA(13);
            plateau->effetCase(13, joueurActif, argentCentre);
            });

        ajouterCarte("Prend le Petit Train Bleu", [&]() {
            joueurActif->allerA(21);
            plateau->effetCase(21, joueurActif, argentCentre);
            });

        ajouterCarte("Prend le Petit Train Rouge", [&]() {
            joueurActif->allerA(29);
            plateau->effetCase(29, joueurActif, argentCentre);
            });


    }

public:
    TasDeCartes(Joueur* joueurActif, PlateauDeJeu* plateau, int* argentCentre, int* argent, int* position)
        : tete(nullptr), argentJoueur(argent), positionJoueur(position)
    {
        initialiserCartes(joueurActif, plateau, argentCentre);
    }


    ~TasDeCartes() {
        if (!tete) return;
        Carte* courant = tete->suivant;
        while (courant != tete) {
            Carte* aSupprimer = courant;
            courant = courant->suivant;
            delete aSupprimer;
        }
        delete tete;
    }

    void ajouterCarte(const std::string& message, std::function<void()> effet) {
        Carte* nouvelle = new Carte(message, effet);
        if (!tete) {
            tete = nouvelle;
            tete->suivant = tete;
        }
        else {
            Carte* temp = tete;
            while (temp->suivant != tete)
                temp = temp->suivant;
            temp->suivant = nouvelle;
            nouvelle->suivant = tete;
        }
    }

    void melanger() {
        if (!tete || tete->suivant == tete) return;

        std::vector<Carte*> cartes;
        Carte* courant = tete;
        do {
            cartes.push_back(courant);
            courant = courant->suivant;
        } while (courant != tete);

        std::srand(std::time(nullptr));
        std::random_shuffle(cartes.begin(), cartes.end());

        for (size_t i = 0; i < cartes.size(); ++i)
            cartes[i]->suivant = cartes[(i + 1) % cartes.size()];

        tete = cartes[0];
    }

    void tirerCarte() {
        if (!tete) {
            std::cout << "Le tas est vide." << std::endl;
            return;
        }

        Carte* carteTiree = tete;

        Carte* courant = tete;
        while (courant->suivant != tete)
            courant = courant->suivant;

        courant->suivant = tete->suivant;
        tete = tete->suivant;
        carteTiree->suivant = tete;
        courant->suivant = carteTiree;

        carteTiree->appliquerEffet();
    }
};
