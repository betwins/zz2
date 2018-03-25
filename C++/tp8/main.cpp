#include "stl.hpp"

int main (int, char **) {
  // ******** VECTOR ********

  // std::vector<int> v;
  // int input;

  // while (std::cin >> input)
  //   v.push_back (input);

  // std::sort(v.begin(), v.end());

  // std::copy (v.begin(), v.end(),
  // 	     std::ostream_iterator<int> (std::cout, "\n"));

  // QUEUE méthodes: {push_back,back,push_front,front}
  // ******** PILES méthodes: {push,pop,top} ********
  
  // std::stack<int> is;
  // std::stack<double, std::vector<double> > ds;

  // for (int i = 0; i < 100; ++i)
  //   is.push(i);

  // while (!is.empty()) {
  //    std::cout << is.top() << std::endl;
  //    ds.push((double)is.top()*is.top());
  //    is.pop();
  // }


  // ******** FILE A PRIORITE  méthodes: {push,pop,top} ********
  ZZ moi("Baptiste","Martinez",10), toi("Clement","Serre",12);
  // std::cout << moi << std::endl;
  // std::cout << toi << std::endl;
  // if (moi<toi)
  //   {
  //     std::cout << "Clement est superieur" << std::endl;
  //   }
  // else if (moi<toi)
  //   {
  //     std::cout << "Baptiste est superieur" << std::endl;
  //   }

  typedef std::vector<ZZ>  vzz;
  // OU en C++ 2011
  // using vzz = std::vector<ZZ> ;

  // ******* Partie 1.3 *******
  
  // vzz zz;

  // zz.push_back(ZZ("Baptiste","Martinez",14));

  // // il faut mettre des elements
  // // zz.push_back(ZZ(...));
  
  // std::priority_queue<ZZ> tri;

  // for (ZZ& i:zz)
  //   {
  //     tri.push(i);
  //   }
  
  // for(vzz::iterator it = zz.begin(); it!=zz.end(); ++it)
  //   tri.push(*it);

  // while(!tri.empty()) {
  //   std::cout << tri.top() << " ";
  //   tri.pop();
  // }

  // ******* Partie 1.4 *******
  typedef std::vector<ZZ*> vz;
  ZZ *el1=&moi, *el2=&toi;
  vz vectzz;
  vectzz.push_back(el1);
  vectzz.push_back(el2);
  vectzz.clear();
  return 0;
  
}


// Pour erreurs liées à la STL, lire les premières lignes, les autres ne sont pas pertinentes.


//voir photos pour inversion des const en fonction si c'est un operateur interne ou externe

// Ne pas utiliser [] en lecture avec les maps: obj: map[clé]
