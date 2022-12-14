#ifndef OBJET_HPP_INCLUDED
#define OBJET_HPP_INCLUDED
#include <iostream>
#include <vector>
class Chateau;
class Personnage;
using namespace std;
class Objet{
private:
    string nom;
    Personnage * proprietaire;
public:
    Objet(string nom);
    Personnage * getProprietaire();
    string getNom();
    void setProprietaire(Personnage * pro);
    void retirerProprietaire();
    virtual void ajouter(Personnage * proprietaire) {};
    virtual void retirer() = 0;
    virtual void utiliser(Chateau * cha) = 0;
    virtual void print(ostream& where,Objet * pe) const = 0;
    friend ostream& operator<<(ostream& os, Objet* ob) {
        ob->print(os,ob);
        return os;
    }
};



#endif // OBJET_HPP_INCLUDED
