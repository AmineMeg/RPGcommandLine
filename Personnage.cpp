#include "Personnage.hpp"

Personnage::Personnage(int sante,int hab,string nom){
    sante=sante;
    habilite=hab;
    nom=nom;
}

void Personnage::setSante(int s){
    sante+=s;
}
string Personnage::getNom(){
    return nom;
}
int Personnage::getSante(){
    return sante;
}
int Personnage::getHabilite(){
    return habilite;
}
Objet Personnage::getObjetAt(int i){
    return sac.at(i);
}
vector<Objet&> Personnage::getSac(){
    return sac;
}
void Personnage::ajouterObjet(Objet obj){
    sac.push_back(obj);
}
