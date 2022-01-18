#ifndef JEU_HPP_INCLUDED
#define JEU_HPP_INCLUDED

#include "Personnage.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Jeu {
    private:
        Personnage *joueur;
        vector<Personnage*> listePerso;

    public:
        Jeu();
        void creationPersonnages();
        void creationJoueur();
        void setJoueur(Personnage *perso1);
        Personnage * getJoueur();
        vector<Personnage*> getListePerso();
        void combat(Personnage * pers1, Personnage *perso2);
        void mortPersonnage(Personnage * pe);
};



#endif // JEU_HPP_INCLUDED
