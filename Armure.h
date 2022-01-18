#ifndef ARMURE_H_INCLUDED
#define ARMURE_H_INCLUDED
#include "Objet.hpp" 
class Armure : public Objet{
private:
    int habilite;
    int resisatnce;
    int sante;
public:
    Armure(string nom,int res,int ha,int san);
    void ajouter(Personnage * proprietaire);
    void retirer();
};


#endif // ARMURE_H_INCLUDED
