#ifndef ARME_HPP_INCLUDED
#define ARME_HPP_INCLUDED
#include "Objet.hpp"

class Arme : public Objet{
private:
    int habilite;
    int force;
    int attaque;
public:
    Arme(string nom,int fo,int ha,int att);
    void ajouter(Personnage * proprietaire);
    void retirer();
};



#endif // ARME_HPP_INCLUDED
