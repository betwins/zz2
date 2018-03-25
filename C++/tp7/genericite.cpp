#include "genericite.hpp"

// Les templates

template <typename T> const T& maximum(const T&a, const T&b)
{
  return ((a > b) ? a : b);
}

template <typename T1, typename T2> const T1& maximum(const T1&a, const T2&b)
{
  try
    {
      throw string("Erreur sur les types!");
      return ((a > b) ? a : b);
    }
  catch (string const& chaine)
    {
      cout << chaine << endl;
    }
}

