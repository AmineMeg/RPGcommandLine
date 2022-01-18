#ifndef MOINES_HPP_INCLUDED
#define MOINES_HPP_INCLUDED
#include "Personnage.hpp"
class Moines : public Personnage{
    private:
    public:
        Moines(string nom);
        void print(ostream& where,Personnage * pe) const;

};


#endif // MOINES_HPP_INCLUDED
