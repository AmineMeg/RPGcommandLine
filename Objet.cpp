#include "Objet.hpp"

Objet::Objet(string nom){
    Objet::nom=nom;
}

string Objet::getNom(){
    return nom;
}

void Objet::setProprietaire(Personnage * pro){
    proprietaire = pro;
}

Personnage * Objet::getProprietaire(){
    return proprietaire;
}

void Objet::retirerProprietaire(){
    proprietaire=nullptr;
}
