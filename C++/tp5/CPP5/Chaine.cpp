#include "Chaine.hpp"
#include <cstring>

using std::cout;
using std::endl;
using std::stringstream;

// Setters
Chaine::Chaine():capa(-1), tab(0){}
Chaine::~Chaine(){if (tab) delete[] tab;}
Chaine::Chaine(int capacity):capa(capacity>0 ? capacity : 0)
{
  if (capa)
    {
      tab = new char[capa];
      tab[0]=0;
    }
}
Chaine::Chaine(const char *word)
{
  if (word)
    {
      capa = strlen(word);
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
int Chaine::getCapacite() const{return capa;}
const char* Chaine::c_str() const{return tab;}

// Méthodes
stringstream& afficher(stringstream &strm, const Chaine &ch1) //ostream est un autre type
{
  strm << ch1.getCapacite() << " " << ch1.c_str();
  return strm;
}


// METHODE OPERATOR (redéfinition des opérateurs)

const Chaine& Chaine::operator=(const Chaine &c)
{
  if (this != &c)
    {
      if ((capa > -1) && (capa != c.capa)) delete[] tab;
      capa = c.capa;
      if (capa > -1)
	{
	  tab = new char[capa +1];
	  strcpy(tab, c.tab);
	}
      else
	{
	  tab = 0;
	}
    }
  return *this;
}

stringstream& operator<<(stringstream&o, const Chaine&c)
{
  o << c.tab;
  return o;
}

// faire classe pile et non pas un vecteur (push, pop, top, empty)
// 2 infos sur la pile: la capacité et le nb d'éléments
