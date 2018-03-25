#include "mere.hpp"

int Mere::getI() const
{
    return i;
}

Mere::Mere(int n, int m):i(n),z(m)
{
    cout << "Mère initialisé à i = " << i << endl;
    ++compteur;
}

Mere::~Mere()
{
    cout << "J'ai détruit la mère" << endl;
    compteur--;
}

int fille::getZ() const
{
  return z;
}

fille::fille(int l):popo(l)
{
    cout << "la fille est initialisée à "  << popo  << endl;
    Mere(4,8);
}

int fille::getPopo()
{
    return popo;
}

fille::~fille()
{
    cout << "la fille est détruite"  << endl;
}

int Mere::getCompteur()
{
    return compteur;
}
