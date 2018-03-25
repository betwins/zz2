#ifndef TPA
#define TPA

#include <iostream>

class B; // Déclaration anticipée

class A
{
    int i;
public:
    A(int n = 0);
    int getI();
    void exec(int);
    void send(B*);
    ~A();
};

#endif
