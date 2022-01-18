#include <iostream>
#include <string.h>
#include "Objet.cpp"
#include "Jeu.cpp"
#include "Arme.cpp"
#include "Armure.cpp"

using namespace std;
int main( int argc, char *argv[], char *envp[] )
{
    Jeu j{};
    j.creationJoueur();
    for(int i=0;i<j.getListePerso().size();i++){
        cout <<j.getListePerso().at(i)<<endl;
    }

  //  j.mortPersonnage(j.getListePerso().at(1));
    for(int i=0;i<j.getListePerso().size();i++){
        cout <<j.getListePerso().at(i)<<endl;
    }

    j.getJoueur()->getObjetAt(0);
    cout<<j.getJoueur()<<endl;

}
