#include "Jeu.hpp"
#include "Amazone.cpp"

Jeu::Jeu(){

}

void Jeu::creationJoueur(){
    cout<<"Vous avec le choix entre 4 classes :\n 1- Le Guerrier \n 2- Le Mage \n 3- La Sorciere\n 4- L'Amazone"<<endl;
    int rep;
    cin>>rep;

    if(rep!=1 || rep!=2 || rep!=3 || rep!=4 ){
        cout<<"choisissez un personnage valable !"<<endl;
    }
    if(rep==4){
         Amazone am{"test"}
    }




}
