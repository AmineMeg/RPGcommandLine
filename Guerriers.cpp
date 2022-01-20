#include "Guerriers.hpp"
#include "Armure.h"


Guerriers::Guerriers(string nom) : Personnage(6,2,7,5,3,nom){
    setClasse("Guerriers");
    Armure * armure = new Armure ("armure de base",2,-1,3);
    armure->ajouter(this);
}

void Guerriers::print(ostream& where,Personnage * pe) const {
    where << "Je suis le Guerrier " <<pe->getNom()<<"\n";
    where<<"mes statistique actuelles sont :\n";
    where<<"attaque : "<<pe->getAttaque()<<endl;
    where<<"force : "<<pe->getForce()<<endl;
    where<<"resistance : "<<pe->getResistance()<<endl;
    where<<"habilite : "<<pe->getHabilite()<<endl;
    where<<"sante : "<<pe->getSante()<<endl;
    where<<"possedant les objets :"<<endl;
    for(int i=0;i<pe->getSac().size();i++){
        where<<pe->getObjetAt(i)->getNom()<<endl;
    }
}
