#ifndef DICO
#define DICO

#include <iostream>
#include <string>

class Dictionnaire
{
public:
  typedef listeMotsTries valeur;
  typedef char           clé;

protected:
  std::map<cle,valeur> dico;
};

#endif
