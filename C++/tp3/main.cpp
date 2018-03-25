#include "A.hpp"
#include "B.hpp"

using std::cout;
using std::endl;

int main(int, char **)
{
    A *testA = new A(3);
    B *testB = new B(5);
    cout << testB->getJ()  << endl;
    testA->send(testB);
    cout << testB->getJ()  << endl;

    return 0;
}
