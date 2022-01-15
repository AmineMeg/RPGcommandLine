#ifndef JEU_HPP_INCLUDED
#define JEU_HPP_INCLUDED

#include "Personnage.cpp"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Jeu {
    private:
        Personnage *joueur;

    public:
        Jeu();
        Personnage creationPersonnages();
        void creationJoueur();
        void setJoueur(Personnage *perso1);
        Personnage * getJoueur();
        void combat(Personnage * pers1, Personnage *perso2);
};



#endif // JEU_HPP_INCLUDED
