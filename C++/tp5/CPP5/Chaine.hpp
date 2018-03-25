#ifndef CPP5__CHAINE_HPP
#define CPP5__CHAINE_HPP

#include <iostream>
#include <fstream>

using std::stringstream;

class Chaine{
  int capa;
  char *tab;
public:
  // Constructeurs
  Chaine();
  ~Chaine();
  Chaine(int capacity);
  Chaine(const char *word);
  Chaine(const Chaine &essai);
  
  // Getters
  int getCapacite() const;
  const char* c_str() const; //getter de la chaine de caractère

  // Autres méthodes
  //Chaine remplacer(char *wordRepl);
  void afficher(stringstream &strm);
  const Chaine& operator=(const Chaine &);
  friend stringstream& operator<<(stringstream&, const Chaine&);
};

#endif
