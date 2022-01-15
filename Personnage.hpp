#ifndef PERSONNAGE_HPP_INCLUDED
#define PERSONNAGE_HPP_INCLUDED

#include <iostream>
#include <vector>
class Objet;
using namespace std;

class Personnage{
    private:
        string nom;
        int attaque;
        int force;
        int resistance;
        int sante;
        int habilite;
        vector<Objet*> sac;

    public:
        Personnage(int sante,int hab,int fo,int res,int att,string nom);
        void setAttaque(int att);
        void setForce(int fo);
        void setHabilite(int ha);
        void setResistance(int re);
        void setSante(int s);
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


};


#endif // PERSONNAGE_HPP_INCLUDED
