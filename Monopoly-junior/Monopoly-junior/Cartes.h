#pragma once

#include <iostream>
#include <string>
#include <functional>
#include "Case.h"
#include "joueur.h"
#include "PlateauDeJeu.h"
#include "Attraction.h"

class Carte {
public:
    std::string message;
    std::function<void(Joueur*, int*)> effet;
    Carte* suivant;

    Carte(const std::string& msg, std::function<void(Joueur*, int*)> effetAssocie)
        : message(msg), effet(effetAssocie), suivant(nullptr) {
    }

    void appliquerEffet(Joueur* joueurActif, int* argentCentre) const {
        std::cout << "Carte tirée : " << message << std::endl;
        effet(joueurActif, argentCentre); // on exécute l'action spécifique
    }
};

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class TasDeCartes {
private:
    Carte* tete;

    void initialiserCartes(Joueur* joueurActif, PlateauDeJeu* plateau, int* argentCentre, TasDeCartes* tasDeCartes) {
        ajouterCarte("Allez au grand huit", [&plateau, &tasDeCartes](Joueur* joueurActif, int* argentCentre) {
            joueurActif->allerA(30);
            plateau->effetCase(30, joueurActif, argentCentre, tasDeCartes);
            });

        ajouterCarte("Va sur la case Depart", [&plateau, &tasDeCartes](Joueur* joueurActif, int* argentCentre) {
            joueurActif->allerA(0);
            plateau->effetCase(0, joueurActif, argentCentre, tasDeCartes);
            });

        ajouterCarte("Va sur la case Ballet des Dauphins", [&plateau, &tasDeCartes](Joueur* joueurActif, int* argentCentre) {
            joueurActif->allerA(24);
            plateau->effetCase(24, joueurActif, argentCentre, tasDeCartes);
            });

        ajouterCarte("Va sur la case Aller au Cafe", [&plateau, &tasDeCartes](Joueur* joueurActif, int* argentCentre) {
            joueurActif->allerA(26);
            plateau->effetCase(26, joueurActif, argentCentre, tasDeCartes);
            });

        ajouterCarte("Va sur la case Feu d'Artifice", [&plateau, &tasDeCartes](Joueur* joueurActif, int* argentCentre) {
            joueurActif->allerA(8);
            plateau->effetCase(8, joueurActif, argentCentre, tasDeCartes);
            });

        ajouterCarte("Prend le Petit Train Jaune", [&plateau, &tasDeCartes](Joueur* joueurActif, int* argentCentre) {
            joueurActif->allerA(5);
            plateau->effetCase(5, joueurActif, argentCentre, tasDeCartes);
            });

        ajouterCarte("Prend le Petit Train Vert", [&plateau, &tasDeCartes](Joueur* joueurActif, int* argentCentre) {
            joueurActif->allerA(13);
            plateau->effetCase(13, joueurActif, argentCentre, tasDeCartes);
            });

        ajouterCarte("Prend le Petit Train Bleu", [&plateau, &tasDeCartes](Joueur* joueurActif, int* argentCentre) {
            joueurActif->allerA(21);
            plateau->effetCase(21, joueurActif, argentCentre, tasDeCartes);
            });

        ajouterCarte("Prend le Petit Train Rouge", [&plateau, &tasDeCartes](Joueur* joueurActif, int* argentCentre) {
            joueurActif->allerA(29);
            plateau->effetCase(29, joueurActif, argentCentre, tasDeCartes);
            });

        ajouterCarteStandGratuit("orange", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("rouge", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("rose", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("bleu clair", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("bleu foncé", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("jaune", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("vert", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("violet", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("orange", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("rouge", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("rose", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("bleu clair", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("bleu foncé", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("jaune", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("jaune", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("vert", plateau, joueurActif, argentCentre);
        ajouterCarteStandGratuit("violet", plateau, joueurActif, argentCentre);
    }

public:
    TasDeCartes(Joueur* joueurActif, PlateauDeJeu* plateau, int* argentCentre, TasDeCartes* cartes)
        : tete(nullptr)
    {
        initialiserCartes(joueurActif, plateau, argentCentre, cartes);
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

    void ajouterCarteStandGratuit(const std::string& couleur, PlateauDeJeu* plateau, Joueur* joueurActif, int* argentCentre) {
        ajouterCarte("Stand gratuit " + couleur, [&plateau, &couleur, this](Joueur* joueurActif, int* argentCentre) {
            this->tirerCarte(joueurActif,argentCentre);
            Case* case1 = new Case(0," ");
            Case* case2 = new Case(0, " ");
            bool Testcase1 = true;

            for (int i = 0; i < 32; ++i) {   
                if (plateau->getCase(i)->getCouleur() == couleur) {
                    if (Testcase1) {
                        case1 = plateau->getCase(i);
                        Testcase1 = false;
                    }
                    else {
                        case2 = plateau->getCase(i);
                        break;
                    }
                }
            }

            Joueur* proprio1 = case1->getProprio();
            Joueur* proprio2 = case2->getProprio();

            if (!proprio1) {
                case1->acheter(joueurActif);
                std::cout << "Stand gratuit posé sur " << case1->getName() << std::endl;
            }
            else if (!proprio2) {
                case2->acheter(joueurActif);
                std::cout << "Stand gratuit posé sur " << case2->getName() << std::endl;
            }
            else if (proprio1 != joueurActif && proprio2 != joueurActif && proprio1 != proprio2) {
                Joueur* aRemplacer = (proprio1->getArgent() >= proprio2->getArgent()) ? proprio1 : proprio2;
                Case* cible = (aRemplacer == proprio1) ? case1 : case2;
                cible->changerProprietaire(joueurActif);
                std::cout << "Stand adverse remplacé sur " << cible->getName() << std::endl;
            }
            else {
                std::cout << "Impossible de poser un stand " << couleur << ", nouvelle carte tirée." << std::endl;
                tirerCarte(joueurActif, argentCentre);
            }
            });
    }

    void ajouterCarte(const std::string& message, std::function<void(Joueur*, int*)> effet) {
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

    void tirerCarte(Joueur* joueurActif, int* argentCentre) {
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

        carteTiree->appliquerEffet(joueurActif, argentCentre);
    }
};