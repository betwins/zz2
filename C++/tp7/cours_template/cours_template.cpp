//exemples de templates (métaprogrammation):


// fonction de base
int factorielle (int N)
{
  if (!N) return 1;
  return N* factorielle(N-1);
}

// terme général
template <int N>
struct Factorielle
{
  static const int valeur = N*factorielle<N-1>::valeur;
};

// spécialisation
template <>
struct factorielle<0>
{
  static const int valeur = 1;
};

/*

  Abstraction de données: -> Structurelle  -> SDD abstraite
                          -> Fonctionnelle -> algo abstraite
			  ADA, C++, Java ==> Métaprogrammation 

  C++: template -> 1 paramètre générique
  
  template <typename T>
  T somme(const T&a, const T&b)
  {
    return a+b;
  }

  Lorsqu'on tape:
  int i1, i2, i3;
  on trouve en fin de compte: i3 = somme<int>(i1, i2);
  ou bien de manière implicite: i3 = somme(i1, i2);
