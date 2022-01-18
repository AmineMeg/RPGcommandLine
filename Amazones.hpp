#ifndef AMAZONES_HPP_INCLUDED
#define AMAZONES_HPP_INCLUDED
#include <iostream>
#include <vector>
#include "Personnage.hpp"
class Amazones : public Personnage{
    private:
    public:
        Amazones(string nom);
        void print(ostream& where,Personnage * pe) const;


};


#endif // AMAZONES_HPP_INCLUDED
