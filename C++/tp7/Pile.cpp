#include "Pile.hpp"

// La classe Pile

Pile::Pile(int capa):taille(0), capacite(capa)
{
  tab = new int[capacite];
}

const int& Pile::top() const
{
  return tab[taille-1];
}

bool Pile::isEmpty() const
{
  return taille == 0;
}

void Pile::pop()
{
  --taille;
}

void Pile::push(const int &nb)
{
  tab[taille] = nb;
  ++taille;
}

Pile::~Pile()
{
  if (tab)
    {
      delete [] tab;
// Crochets nécessaires si on a mis un nombre de cellules en allouant (après le "new")
      cout << "Pile détruite !" << endl;
    }
}
