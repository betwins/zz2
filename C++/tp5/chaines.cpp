#include "chaines.hpp"

using std::cout;
using std::endl;

// Setters
Chaine::Chaine():capa(-1), tab(0){}
Chaine::~Chaine(){if (tab) delete[] tab;}
Chaine::Chaine(int capacity):capa(capacity), tab(0){}
Chaine::Chaine(const char* word)
{
  if (word)
    {
      capa = strlen(word) + 1;
      tab = new char[capa];
      strcpy(tab, word);
    }
  else
    {
      capa = 0;
      tab = 0;
    }
}
Chaine::Chaine(const Chaine &e):capa(e.capa), tab(0)
{
  if (capa > -1)
    {
      tab = new char[capa +1];
      strcpy(tab, e.tab);
    }
}


// Getters
int Chaine::getCapa(){return capa;}
char* Chaine::getTab(){return tab;}
// Méthodes
