#include "CleTeleportation.hpp"
#include "Personnage.hpp"
#include "Chateau.hpp"
#include <stdlib.h>
#include <time.h>

CleTeleportation::CleTeleportation():Objet("clé de TP"){
    
}

void CleTeleportation::ajouter(Personnage * proprietaire){
     setProprietaire(proprietaire);
    if(getProprietaire()->ajouterObjet(this)){
        
    }else{
        retirerProprietaire();
    }
}

void CleTeleportation::retirer(){
    retirerProprietaire();
}

void CleTeleportation::utiliser(Chateau * cha ){
    cout<<"Utilisation cle Teleportation"<<endl;
    cout<<"choisir une salle où se TP"<<endl;
    int res;
    cin>>res;
    while(res<0 || res>cha->getListeSalle().size() ){
        cout<<"choisir une salle valide"<<endl;
        cin >>res;
    }

    for (int i = 0;i < cha->getListeSalle()[getProprietaire()->getPosition()]->personnagesPresent.size();i++){
        if (getProprietaire() == cha->getListeSalle()[getProprietaire()->getPosition()]->personnagesPresent[i]){
            cha->getListeSalle()[getProprietaire()->getPosition()]->personnagesPresent.erase(
                    cha->getListeSalle()[getProprietaire()->getPosition()]->personnagesPresent.begin()+i);
            getProprietaire()->setPosition(res);
            cha->getListeSalle()[getProprietaire()->getPosition()]->personnagesPresent.push_back(getProprietaire());
        }
    }

    getProprietaire()->retirerObjet(this);
    retirer();
}

void CleTeleportation::print(ostream& where,Objet * pe) const {
    where<<"Une potion de soin"<<endl;

}
