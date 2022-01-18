//
// Created by kreek on 13/01/2022.
//

#ifndef PROJETLOA_CHATEAU_HPP
#define PROJETLOA_CHATEAU_HPP

#include <iostream>
#include <cassert>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <random>

using namespace std;

struct Salle{
    string nom;
    Salle* droite;
    Salle* gauche;
    Salle* haut;
    Salle* bas;
    int nbPorteLibres = 3;
};


class Chateau {
private:
    vector<Salle*> listeSalle;
    int compteur;
    Salle* CreerNoeud ();

public:
    Chateau (int nbSalles);
    ~Chateau ();
    Salle* creerNoeud ();
    void supprimer ();
    void afficher ();
    int taille () const;
    void creerConnexions();
    void selectPorte(Salle *salle, Salle * nextSalle);
    void selectPorte2(Salle *salle, Salle *nextSalle);
};


#endif //PROJETLOA_CHATEAU_HPP
