#ifndef JEU_HPP_INCLUDED
#define JEU_HPP_INCLUDED
#include "Chateau.hpp"
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
        bool enCours = true;

    public:
        Jeu();
        void creationPersonnages();
        void creationJoueur();
        void partie ();
        void deposerObjet(Chateau * cha);
        void ramasserObjet(Chateau * cha);
        void utiliserObjet();
        void changerDeSalleJoueur(Chateau * chateau);
        void changerSalleBot(Chateau * chateau,Personnage * bot);
        void checkCombat(Chateau * cha);
        void checkMort(Chateau * cha);
        void setJoueur(Personnage *perso1);
        Personnage * getJoueur();
        vector<Personnage*> getListePerso();
        void combat(Personnage * pers1, Personnage *perso2);
        void mortPersonnage(Personnage * pe,Chateau * chateau);
};



#endif // JEU_HPP_INCLUDED
