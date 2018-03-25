#ifndef MOTSTRIES
#define MOTSTRIES

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <algorithm> //pour le sort
#include <iterator>

typedef std::map<string, string> mss;
typedef std::vector<ZZ> vzz;

using std::cout;
using std::endl;
using std::string;

class listeMotsTries
{
protected:
  std::list<std::string> l;

public:
  listeMotsTries();
  ~listeMotsTries();
  void afficherListe() const;
  void ajouterMot(const std::string&);
  void retirerMot(const std::string&);
  int getNbMots () const;
  const_iterator debut() const;
  const_iterator fin() const;
};
#endif
