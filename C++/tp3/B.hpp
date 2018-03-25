#ifndef TPB
#define TPB

#include <iostream>


class A; // Déclaration anticipée

class B
{
    int j;
public:
    B(int n = 0);
    int getJ();
    void exec(int);
    void send(A*);
    ~B();
};

#endif
