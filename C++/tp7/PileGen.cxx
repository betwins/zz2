//tous les templates de pile

// La classe Pile

template<typename T>
PileGen::PileGen(int capa):taille(0), capacite(capa)
{
  tab = new T[capacite];
}

template<typename T>
const T& PileGen::top() const
{
  return tab[taille-1];
}

bool PileGen::isEmpty() const
{
  return taille == 0;
}

void PileGen::pop()
{
  --taille;
}

template<typename T>
void PileGen::push(const T &el)
{
  tab[taille] = el;
  ++taille;
}

template<typename T>
PileGen::~PileGen()
{
  if (tab)
    {
      delete [] tab;
// Crochets nécessaires si on a mis un nombre de cellules en allouant (après le "new")
      cout << "Pile détruite !" << endl;
    }
}
