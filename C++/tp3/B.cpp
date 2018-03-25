#include "B.hpp"
#include "A.hpp"

void B::exec(int x)
{
    j+=x;
}

void B::send(A* aptr)
{
    aptr->exec(j);
}

int B::getJ()
{
    return j;
}

B::B(int n)
{
    j = n;
}

B::~B()
{
}
