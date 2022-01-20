#include "Amazones.hpp"
#include "Arme.hpp"
#include "PotionSoin.cpp"
#include "CleTeleportation.cpp"
Amazones::Amazones(string nom) : Personnage(4,6,6,3,2,nom){

    Arme * arme = new Arme ("lance de base",2,0,1);
    PotionSoin * potion = new PotionSoin();
    CleTeleportation * cle = new CleTeleportation();
    arme->ajouter(this);
    potion->ajouter(this);
    cle->ajouter(this);
}

void Amazones::print(ostream& where,Personnage * pe) const {
    where << "Je suis l'Amazone " <<pe->getNom()<<"\n";
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
