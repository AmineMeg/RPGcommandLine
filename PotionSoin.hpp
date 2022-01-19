#ifndef POTIONSOIN_HPP_INCLUDED
#define POTIONSOIN_HPP_INCLUDED
#include "Objet.hpp"
class PotionSoin : public Objet{
    public:
    PotionSoin();
    void ajouter(Personnage * proprietaire);
    void retirer();
    void utiliser();
    void print(ostream& where,Objet * pe) const;
    
    private:


};


#endif // POTIONSOIN_HPP_INCLUDED
