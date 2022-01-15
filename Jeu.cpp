#include "Jeu.hpp"
#include "Amazones.cpp"
#include "Guerriers.cpp"
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
         joueur=am;
         Personnage p1 {5,5,5,5,5,"bot1"};
         Personnage p2 {5,5,5,5,5,"bot2"};
         Personnage p3 {5,5,5,5,5,"bot3"};


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

