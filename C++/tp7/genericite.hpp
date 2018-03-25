#ifndef GENER
#define GENER

#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <typename T> const T& maximum(const T&a, const T&b);
template <typename T1, typename T2> const T1& maximum(const T1&a, const T2&b);

#endif

// Si présence d'un .h, mettre un include "nom_fichier.cxx" dans le .h ! ==> déclaration générique.

// l'extension .cc permet d'effectuer une définition générique sans compiler en .o avant de compiler en exécutable.
