#ifndef GUERRIERS_HPP_INCLUDED
#define GUERRIERS_HPP_INCLUDED
#include <iostream>
#include <vector>
#include "Personnage.hpp"
class Guerriers : public Personnage{
    private:
    public:
        Guerriers(string nom);
        void print(ostream& where,Personnage * pe) const;

};




#endif // GUERRIERS_HPP_INCLUDED
