#include"main.hpp"

int main() {
    int argentJoueur = 1500;
    int positionJoueur = 0;

    TasDeCartes tas;

    tas.melanger();

    // Tirer 3 cartes
    for (int i = 0; i < 3; ++i) {
        tas.tirerCarte();
        std::cout << "--------------------------\n";
    }

    return 0;
}
