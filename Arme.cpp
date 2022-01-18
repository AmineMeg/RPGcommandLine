#include "Arme.hpp"
#include "Personnage.hpp"

Arme::Arme(string nom,int fo,int ha,int att):Objet(nom){
    force=fo;
    habilite=ha;
    attaque=att;
}

void Arme::ajouter(Personnage* proprietaire){

    setProprietaire(proprietaire);
    if(getProprietaire()->ajouterObjet(this)){
        getProprietaire()->setAttaque(getProprietaire()->getAttaque()+attaque);
        getProprietaire()->setForce(getProprietaire()->getForce()+force);
        getProprietaire()->setHabilite(getProprietaire()->getHabilite()+habilite);
    }else{
        retirerProprietaire();
    }
}

void Arme::retirer(){
    cout<<"retirer depuis arme"<<endl;
    getProprietaire()->setAttaque(getProprietaire()->getAttaque()-attaque);
    getProprietaire()->setForce(getProprietaire()->getForce()-force);
    getProprietaire()->setHabilite(getProprietaire()->getHabilite()-habilite);
    retirerProprietaire();
}
