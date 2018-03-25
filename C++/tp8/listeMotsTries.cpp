/*
plom: une seule surcharge possible de < utilisé par défaut dans plusieurs structures

foncteur: alternative flexible aux limitations intrinsèques des classes en c++
-> une instance qui se comporte comme s'il était une fonction en réagissant uniquement avec une liste d'arguments.

priority_queue<ZZ, vector<ZZ>, cmp> p;  cmp ==> type
sort(v.begin(), v.end(), cmp()); cmp ==> instance
cmp c;
sort(v.begin(), v.end, c); ==> instance PLUS COURANT */

#include "listeMotsTries.hpp"

listeMotsTries::listeMotsTries(){}
listeMotsTries::~listeMotsTries(){}

void listeMotsTries::afficherListe() const
{
  for(std::list<string>::iterator it = std::list::begin(); it!=std::list<string>.end(); it++)
    {
      cout << *it << endl;
    }
}
void listeMotsTries::ajouterMot(const std::string& inMot)
{
  l.push_back(inMot);
  l.sort();
  //std::sort(l.begin(),l.end());
}
void listeMotsTries::retirerMot(const std::string &inMot)
{
  l.remove(inMot);
}

int listeMotsTries::getNbMots() const{return l.size();}

const_iterator listeMotsTries::debut() const{this->begin();}

const_iterator listeMotsTries::fin() const{this->end();}
