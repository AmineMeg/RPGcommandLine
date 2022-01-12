#include <iostream>
#include <string.h>
#include "Jeu.cpp"
using namespace std;
int main( int argc, char *argv[], char *envp[] )
{
    Jeu j{};
    j.creationJoueur();
    cout<<"ouais"<<j.getJoueur()->getNom();

}
