#ifndef MERE
#define MERE

#include <iostream>
using std::cout;
using std::endl;

class Mere
{   
protected:
  int i;
  static int compteur;
public:
  int z;
  int getI() const;
  int getCompteur();
  Mere(int n = 0, int z = 12);
  ~Mere();
};

class fille : public Mere
{
  int popo;
public:
  fille(int k = 2);
  int getZ() const;
  int getPopo();
  ~fille();
};

#endif
