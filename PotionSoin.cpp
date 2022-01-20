#include "PotionSoin.hpp"
#include "Personnage.hpp"
#include <stdlib.h>
#include <time.h>

PotionSoin::PotionSoin():Objet("Potion de soin"){

}

void PotionSoin::ajouter(Personnage * proprietaire){
     setProprietaire(proprietaire);
    if(getProprietaire()->ajouterObjet(this)){
        
    }else{
        retirerProprietaire();
    }
}

void PotionSoin::retirer(){
    retirerProprietaire();
}

void PotionSoin::utiliser(Chateau * cha){
    cout<<"Utilisation Potion de soin"<<endl;
    srand((unsigned int)time(0));
    int jetDes = (rand() % 4 + 1);
    getProprietaire()->setSante(getProprietaire()->getSante()+jetDes);
    getProprietaire()->retirerObjet(this);
    retirer();
}

void PotionSoin::print(ostream& where,Objet * pe) const {
    where<<"Une potion de soin"<<endl;

}
