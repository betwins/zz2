#include "A.hpp"
#include "B.hpp"

void A::exec(int x)
{
    i+=x;
}

void A::send(B* bptr)
{
    bptr->exec(i);
}

int A::getI()
{
    return i;
}

A::A(int n)
{
    i = n;
}

A::~A()
{
}
