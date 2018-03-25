#ifndef TPCHAINES
#define TPCHAINES

#include <iostream>
#include <cstring>

class Chaine{
  int capa;
  char *tab;
public:
  Chaine();
  ~Chaine();
  Chaine(int capacity);
  Chaine(const char *word);
  Chaine(const Chaine &);
  int getCapa();
  char* getTab();
  //Chaine remplacer(char *wordRepl);
  //void afficher();
};

#endif
