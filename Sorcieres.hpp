#ifndef SORCIERES_HPP_INCLUDED
#define SORCIERES_HPP_INCLUDED
#include <iostream>
#include <vector>
#include "Personnage.hpp"
class Sorcieres : public Personnage{
    private:
    public:
        Sorcieres(string nom);
        void print(ostream& where,Personnage * pe) const;

};




#endif // SORCIERES_HPP_INCLUDED
