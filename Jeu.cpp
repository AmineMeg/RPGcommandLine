#include "Jeu.hpp"
#include "Amazones.cpp"
#include "Guerriers.cpp"
#include "Moines.cpp"
#include "Sorcieres.cpp"
Jeu::Jeu(){

}

void Jeu::creationJoueur(){
    cout<<"Vous avec le choix entre 4 classes :\n 1- Le Guerrier \n 2- Le Mage \n 3- La Sorciere\n 4- L'Amazone"<<endl;
    int rep;
    cin>>rep;

    while(rep!=1 && rep!=2 & rep!=3 && rep!=4 ){
        cout<<"choisissez un personnage valable !"<<endl;
        cin>>rep;
    }
    if(rep==4){
         Amazones * am = new Amazones("dsdeds");
         cout<<"sante "<<am->getSante();
         joueur=am;
         listePerso.push_back(am);
         Guerriers * gu = new Guerriers("bot1");
         Moines * mo = new Moines("bot2");
         Sorcieres * so = new Sorcieres("bot3");
         listePerso.push_back(gu);
         listePerso.push_back(mo);
         listePerso.push_back(so);
    }else if(rep == 3){
        Sorcieres * so = new Sorcieres("dsdeds");
        joueur=so;
        listePerso.push_back(so);
        Guerriers * gu = new Guerriers("bot1");
        Moines * mo = new Moines("bot2");
        Amazones * am = new Amazones("bot3");
        listePerso.push_back(gu);
        listePerso.push_back(mo);
        listePerso.push_back(am);
    }else if(rep==2){
        Moines * mo = new Moines("dsdeds");
        joueur=mo;
        listePerso.push_back(mo);
        Guerriers * gu = new Guerriers("bot1");
        Sorcieres * so = new Sorcieres("bot2");
        Amazones * am = new Amazones("bot3");
        listePerso.push_back(gu);
        listePerso.push_back(so);
        listePerso.push_back(am);
    }else{
        Guerriers * gu = new Guerriers("dsdeds");
        joueur=gu;
        listePerso.push_back(gu);
        Moines * mo = new Moines("bot1");
        Sorcieres * so = new Sorcieres("bot2");
        Amazones * am = new Amazones("bot3");
        listePerso.push_back(mo);
        listePerso.push_back(so);
        listePerso.push_back(am);
    }

}

void Jeu::combat(Personnage * pers1, Personnage * perso2){

    srand((unsigned int)time(0));
    for (int i=0;i<pers1->getAttaque();i++){
        int resAttendu;
        if(pers1->getForce()<perso2->getResistance()){
            resAttendu = 5;
        }else if(pers1->getForce()==perso2->getResistance()){
            resAttendu = 4;
        }else{
            resAttendu=3;
        }

        int jetDes = (rand() % 6 + 1);
        cout<<"resattendu "<<resAttendu<<endl;
        cout<<"jet des "<<jetDes<<endl;
        if(jetDes>=resAttendu){
            perso2->setSante(perso2->getSante()-1);
            cout<<"attaque"<<endl;
        }else{
            cout<<"esquive"<<endl;
        }

    }


}



Personnage * Jeu::getJoueur(){
    return joueur;
}

vector<Personnage*> Jeu::getListePerso(){
    return listePerso;
}

void Jeu::mortPersonnage(Personnage * pe){
    for(int i=0;i<listePerso.size();i++){
        if(pe == listePerso.at(i)){
            delete listePerso.at(i);
            listePerso.erase(listePerso.begin()+i);
        }
    }
    //Ajouter drop item perso dans la piece !!!
}

