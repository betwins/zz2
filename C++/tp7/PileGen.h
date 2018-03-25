#ifndef PILEGEN
#define PILEGEN

#include <iostream>
using std::cout;

template <typename T>
class PileGen
{
  int taille;
  int capacite;
  T *tab;
  
 public:
  Pile(int);
  const T& top() const;
  bool isEmpty() const;
  void pop();
  void push(const T&);
  ~Pile();
};


#include "PileGen.cxx"
#endif
