#include <iostream>
#include <vector>
using namespace std;
class Personnage;
class Objet{
    private:
        Personnage * proprietaire;
    public:
        void setPersonnage(Personnage p);
        Personnage getProprietaire();
};