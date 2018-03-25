#include "stl.hpp"

int main(int, char**)
{
  vzz zz;
  zz.push_back(ZZ("pren", "nom", 10.1));
  zz.push_back(ZZ("abczar", "hey", 1));
  Cmp compa;
  std::priority_queue<ZZ, std::vector<ZZ>, compa> tri; /* les éléments de la priority_queue ne peuvent pas être changés */

  for(vzz::iterator it = zz.begin(); it!=zz.end(); ++it) tri.push(*it);
  tri.sort(compa);
  while(!tri.empty())
    {
      cout << tri.top() << endl;
      tri.pop();
    }
  return 0;
}
