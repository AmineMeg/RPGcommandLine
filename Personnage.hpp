#include <iostream>
#include <vector>
#include "Objet.hpp"
using namespace std;

class Personnage{
    private:
        string nom;
        int sante;
        int habilite;
        vector<Objet&> sac;  

    public:
        Personnage(int sante,int hab,string nom);
        void setSante(int s);
        string getNom();
        int getSante();
        int getHabilite();
        Objet getObjetAt(int i);
        vector<Objet&> getSac();
        void ajouterObjet(Objet obj);


};