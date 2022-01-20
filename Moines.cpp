#include "Moines.hpp"
#include "Arme.hpp"


Moines::Moines(string nom) : Personnage(6,2,7,5,3,nom){
    setClasse("Moines");
    Arme * arme = new Arme ("baton de base",2,-1,3);
    arme->ajouter(this);
}


void Moines::print(ostream& where,Personnage * pe) const {
    where << "Je suis le moine " <<pe->getNom()<<"\n";
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
