#ifndef JEU_HPP_INCLUDED
#define JEU_HPP_INCLUDED

#include "Personnage.cpp"
#include <iostream>
#include <vector>
using namespace std;

class Jeu {
    private:
        Personnage *joueur;

    public:
        Jeu();
        Personnage creationPersonnages();
        void creationJoueur();
        void setJoueur(Personnage *joueur);
        Personnage* getJoueur();
};



#endif // JEU_HPP_INCLUDED
