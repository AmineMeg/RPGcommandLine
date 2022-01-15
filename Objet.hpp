#ifndef OBJET_HPP_INCLUDED
#define OBJET_HPP_INCLUDED
#include <iostream>
#include <vector>
#include "Personnage.hpp"
using namespace std;
class Objet{
private:
    string nom;
    Personnage * proprietaire;
public:
    Objet(string nom);
    Personnage * getProprietaire();
    void setProprietaire(Personnage * pro);
    void retirerProprietaire();
};



#endif // OBJET_HPP_INCLUDED
