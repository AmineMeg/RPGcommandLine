#ifndef ARMURE_H_INCLUDED
#define ARMURE_H_INCLUDED
#include "Objet.hpp" 
class Armure : public Objet{
private:
    int habilite;
    int resistance;
    int sante;
public:
    Armure(string nom,int res,int ha,int san);
    void ajouter(Personnage * proprietaire);
    void retirer();
    void utiliser(){cout<<"ca ne fait rien "<<endl;}
    void print(ostream& where,Objet * pe) const;
};


#endif // ARMURE_H_INCLUDED
