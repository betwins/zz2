#ifndef TP2
#define TP2

#include <iostream>

class Bavarde
{
    int i;
public:
    Bavarde(int k = 0); //valeur par défaut uniquement dans le prototype !!
    int getI();
    ~Bavarde();
} bizarre(1);

class Couple{
    Bavarde a;
    Bavarde b;
public:
//    Couple(); Constructeur par défaut
    Couple(int rep1 = 0, int rep2 = 0); /* Constructeur par initialisation "direct", ajout d'initialisations par défaut */
    Couple(Bavarde &obj1, Bavarde &obj2); /* Constructeur par copie d'une variable de même type que la classe */
    Bavarde getA();
    Bavarde getB();
    ~Couple();
};

#endif
