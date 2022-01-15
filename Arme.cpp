#include "Arme.hpp"
#include "Personnage.hpp"
#include "Objet.cpp"
Arme::Arme(string nom,int fo,int ha,int att):Objet(nom){
    force=fo;
    habilite=ha;
    attaque=att;
}

void Arme::ajoutArme(Personnage* proprietaire){

    setProprietaire(proprietaire);
    if(getProprietaire()->ajouterObjet(this)){
        getProprietaire()->setAttaque(getProprietaire()->getAttaque()+attaque);
        getProprietaire()->setForce(getProprietaire()->getForce()+force);
        getProprietaire()->setHabilite(getProprietaire()->getHabilite()+habilite);
    }else{
        retirerProprietaire();
    }
}

void Arme::retirerArme(){

    getProprietaire()->setAttaque(getProprietaire()->getAttaque()-attaque);
    getProprietaire()->setForce(getProprietaire()->getForce()-force);
    getProprietaire()->setHabilite(getProprietaire()->getHabilite()-habilite);
    getProprietaire()->retirerObjet(this);
    retirerProprietaire();
}
