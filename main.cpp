#include <iostream>
#include <string.h>
#include "Jeu.cpp"
#include "Arme.cpp"
using namespace std;
int main( int argc, char *argv[], char *envp[] )
{
    Jeu j{};
    j.creationJoueur();
    cout<<"ouais"<<j.getJoueur()->getNom();
    Guerriers * p1 = new Guerriers("bot1");
    //j.combat(j.getJoueur(),p1);
    std:cout<<j.getJoueur()->getForce()<<endl;
    Arme * arme = new Arme ("lance de base",2,0,1);
    Arme * arme1 = new Arme ("lance de base",2,0,1);
    Arme * arme2 = new Arme ("lance de base",2,0,1);
    Arme * arme3 = new Arme ("lance de base",2,0,1);
    Arme * arme4 = new Arme ("lance de base",2,0,1);
    arme->ajoutArme(j.getJoueur());
    cout<<j.getJoueur()->getForce()<<endl;
    arme->retirerArme();
    cout<<j.getJoueur()->getForce()<<endl;
    cout<<"arme"<<arme->getProprietaire()<<endl;
    cout<<"joueur"<<j.getJoueur()<<endl;

    arme->ajoutArme(j.getJoueur());
    cout<<j.getJoueur()->getForce()<<endl;
    arme1->ajoutArme(j.getJoueur());
    cout<<j.getJoueur()->getForce()<<endl;
    arme2->ajoutArme(j.getJoueur());
    cout<<j.getJoueur()->getForce()<<endl;
    arme3->ajoutArme(j.getJoueur());
    cout<<j.getJoueur()->getForce()<<endl;
    arme4->ajoutArme(j.getJoueur());
    cout<<j.getJoueur()->getForce()<<endl;
}
