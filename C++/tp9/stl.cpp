#include "stl.hpp"

ZZ::ZZ():prenom("p"),nom("n"),note(0){}

ZZ::ZZ(string firstN, string name, double grade):prenom(firstN), nom(name), note(grade){}

ZZ::~ZZ(){std::cout << "destruction" << std::endl;}

const string& ZZ::getPrenom() const{return prenom;}

const string& ZZ::getNom() const{return nom;}

const double& ZZ::getNote() const{return note;}

std::ostream& operator<<(std::ostream& o, const ZZ& eleve)
{
  o << eleve.getPrenom() << " " << eleve.getNom() << " " << eleve.getNote();
  return o;
}

bool Cmp::operator<(const ZZ& eleve2) const //opérateur interne
{
  return ((this->getNom()).compare(eleve2.getNom())<0);
  //this est le premier élément "elt1" dans la comparaison "elt1 < elt2", eleve2 est l'élément elt2
}
