#ifndef CLETELEPORTATION_HPP_INCLUDED
#define CLETELEPORTATION_HPP_INCLUDED
#include "Objet.hpp"
class CleTeleportation : public Objet{
    public:
    CleTeleportation();
    void ajouter(Personnage * proprietaire);
    void retirer();
    void utiliser(Chateau * cha);
    void print(ostream& where,Objet * pe) const;
    
    private:


};


#endif // OBJET_HPP_INCLUDED