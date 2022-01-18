#include "Armure.h"
#include "Personnage.hpp"
Armure::Armure(string nom,int res,int ha,int san):Objet(nom){
    sante=san;
    habilite=ha;
    resisatnce=res;
}

void Armure::ajouter(Personnage* proprietaire){

    setProprietaire(proprietaire);
    if(getProprietaire()->ajouterObjet(this)){
        getProprietaire()->setResistance(getProprietaire()->getResistance()+resisatnce);
        getProprietaire()->setSante(getProprietaire()->getSante()+sante);
        getProprietaire()->setHabilite(getProprietaire()->getHabilite()+habilite);
    }else{
        retirerProprietaire();
    }
}

void Armure::retirer(){
    cout<<"retirer depuis armure"<<endl;
    getProprietaire()->setResistance(getProprietaire()->getResistance()-resisatnce);
    getProprietaire()->setSante(getProprietaire()->getSante()-sante);
    getProprietaire()->setHabilite(getProprietaire()->getHabilite()-habilite);
    retirerProprietaire();
}

