#ifndef PERSONNAGE_HPP_INCLUDED
#define PERSONNAGE_HPP_INCLUDED

#include <iostream>
#include <vector>
#include "Objet.hpp"
using namespace std;

class Personnage{
    private:
        string nom;
        string classe;
        int attaque;
        int force;
        int resistance;
        int sante;
        int habilite;
        vector<Objet*> sac;
        int position;
    public:
        Personnage(int sante,int hab,int fo,int res,int att,string nom);
        string getClasse();
        void setClasse(string newClasse);
        void setPosition(int pos);
        void setAttaque(int att);
        void setForce(int fo);
        void setHabilite(int ha);
        void setResistance(int re);
        void setSante(int s);
        int getPosition();
        string getNom();
        int getSante();
        int getHabilite();
        int getAttaque();
        int getForce();
        int getResistance();
        Objet * getObjetAt(int i);
        vector<Objet*> getSac();
        bool ajouterObjet(Objet * obj);
        void retirerObjet(Objet * obj);
        virtual void print(ostream& where,Personnage * pe) const = 0;
        friend ostream& operator<<(ostream& os, Personnage* pe) {
            pe->print(os,pe);
            return os;
        }


};


#endif // PERSONNAGE_HPP_INCLUDED
