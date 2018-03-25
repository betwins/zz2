#ifndef PILE
#define PILE

#include <iostream>
using std::cout;
using std::endl;

class Pile
{
  int taille;
  int capacite;
  int *tab;
  
 public:
  Pile(int capacite);
  const int& top() const;
  bool isEmpty() const;
  void pop();
  void push(const int&);
  ~Pile();
};

#endif
