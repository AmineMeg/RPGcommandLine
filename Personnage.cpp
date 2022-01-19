#include "Personnage.hpp"

Personnage::Personnage(int sante,int hab,int fo,int res,int att,string nom){
    Personnage::sante=sante;
    habilite=hab;
    Personnage::nom=nom;
    force=fo;
    resistance=res;
    attaque=att;
}
void Personnage::setPosition(int pos){
    position=pos;
}
void Personnage::setAttaque(int att){
    attaque=att;
}
void Personnage::setForce(int fo){
    force=fo;
}
void Personnage::setHabilite(int ha){
    habilite=ha;
}
void Personnage::setResistance(int re){
    resistance=re;
}
void Personnage::setSante(int s){
    sante=s;
}
string Personnage::getNom(){
    return nom;
}
int Personnage::getPosition(){
    return position;
}
int Personnage::getSante(){
    return sante;
}
int Personnage::getHabilite(){
    return habilite;
}
int Personnage::getAttaque(){
    return attaque;
}
int Personnage::getForce(){
    return force;
}
int Personnage::getResistance(){
    return resistance;
}
Objet * Personnage::getObjetAt(int i){
    return sac.at(i);
}
vector<Objet*> Personnage::getSac(){
    return sac;
}
bool Personnage::ajouterObjet(Objet * obj){

    if(sac.size()<4){
        sac.push_back(obj);
        return true;
    }else{
        cout<<"Le sac est plein"<<endl;
        return false;
    }
}

void Personnage::retirerObjet(Objet * objet){
    for(int i=0;i<sac.size();i++){
        if(sac.at(i)==objet){
            cout<<"test"<<endl;
            sac.at(i)->retirer();
            sac.erase(sac.begin()+i);
            cout<<"test"<<endl;
            break;
        }
    }
}
