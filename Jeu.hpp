#include "Personnage.cpp"
#include <iostream>
#include <vector>
using namespace std;

class Jeu {
    private:
    Personnage *joueur;
    vector<Personnage*> bots;
    public:
        Jeu();
        void creationPersonnages();
        void creationJoueur();
        void setJoueur(Personnage *joueur);
        Personnage* getJoueur();
};

