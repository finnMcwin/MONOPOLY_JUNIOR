#pragma once

#include <iostream>
#include <string>
#include <functional>

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

        void initialiserCartes() {
            ajouterCarte("Avancez à la case départ", [&]() {
                *positionJoueur = 0;
                std::cout << "Vous retournez à la case départ." << std::endl;
                });

            ajouterCarte("Recevez 100€", [&]() {
                *argentJoueur += 100;
                std::cout << "Vous recevez 100€. Solde : " << *argentJoueur << "€" << std::endl;
                });

            ajouterCarte("Payez une amende de 50€", [&]() {
                *argentJoueur -= 50;
                std::cout << "Vous payez 50€. Solde : " << *argentJoueur << "€" << std::endl;
                });

            ajouterCarte("Allez en prison", [&]() {
                *positionJoueur = 10;
                std::cout << "Direction prison ! Position : " << *positionJoueur << std::endl;
                });
        }

    public:
        TasDeCartes(int* argent, int* position) : tete(nullptr), argentJoueur(argent), positionJoueur(position) {
            initialiserCartes(); // les cartes sont ajoutées ici
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
