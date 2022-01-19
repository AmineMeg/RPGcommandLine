#include "Armure.h"
#include "Personnage.hpp"
Armure::Armure(string nom,int res,int ha,int san):Objet(nom){
    sante=san;
    habilite=ha;
    resistance=res;
}

void Armure::ajouter(Personnage* proprietaire){

    setProprietaire(proprietaire);
    if(getProprietaire()->ajouterObjet(this)){
        getProprietaire()->setResistance(getProprietaire()->getResistance()+resistance);
        getProprietaire()->setSante(getProprietaire()->getSante()+sante);
        getProprietaire()->setHabilite(getProprietaire()->getHabilite()+habilite);
    }else{
        retirerProprietaire();
    }
}

void Armure::retirer(){
    cout<<"retirer depuis armure"<<endl;
    getProprietaire()->setResistance(getProprietaire()->getResistance()-resistance);
    getProprietaire()->setSante(getProprietaire()->getSante()-sante);
    getProprietaire()->setHabilite(getProprietaire()->getHabilite()-habilite);
    retirerProprietaire();
}

void Armure::print(ostream& where,Objet * pe){
    where<<pe->getNom()<<endl;
    where<<"Modifiant les statistiques"<<endl;
    where<<"+"<<resistance<<" resistances"<<endl;
    where<<"+"<<sante<<" en sante"<<endl;
    where<<"+"<<habilite<<" en habilite"<<endl;

}

