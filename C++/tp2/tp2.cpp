#include "tp2.hpp"

/* évite de faire rechercher au pré-processeur, dans toute la
 * librairie, une fonction qu'il ne reconnaît pas tout de suite 
 */
using std::cout; 
using std::endl;

Bavarde globale(2); // bizarre et globale sont des variables globales

int main(int, char**)
{
    // Bavarde b;                                                                PARTIE 1.1 cycle de vie variable
    // Bavarde *p = new Bavarde(10);
    // cout << "valeur du i de b: " << b.getI() << endl;
    // cout << "valeur du i de p: " << p->getI() << endl;
    // cout << Bavarde(40).getI() << endl; // une variable anonyme a une durée de vie très courte
    // delete p;

    // const int TAILLE = 4;                                                     PARTIE 1.2 test tableaux
    // Bavarde tab1[TAILLE];
    // Bavarde *tab2 = new Bavarde[TAILLE];
    
    // for (int i = 0; i<TAILLE; ++i)
    // {
    // 	cout << "valeur dans le tableau 1: " << tab1[i].getI() << endl;
    // 	cout << "valeur dans le tableau 2: " << tab2[i].getI() << endl;
    // }
    // delete tab2;

    Bavarde v1;
    Bavarde v2 = Bavarde(12);
    Couple var1;
    Couple *var2 = new Couple;
    Couple var3 = Couple(v2, v1);
    Couple var4 = Couple(45, 50);
    cout << "valeur du i de var1" << var1.getA().getI() << endl;
    cout << "valeur du i de var2" << var2->getB().getI() << endl;
    cout << "valeur du i de var3" << var3.getA().getI() << endl;
    cout << "valeur du i de var4" << var4.getA().getI() << " " << var4.getB().getI() << endl;

    delete var2;
    return 0;
}

// ************** CLASSE BAVARDE **************

// Constructeur
Bavarde::Bavarde(int k)
{
    i = k;
}

// Getter
int Bavarde::getI()
{
    return i;
}

// Destructeur
Bavarde::~Bavarde()
{
    cout << "Tais-toi " << i << endl;
}

//   DIFFERENCES ENTRE L'AGREGATION ET LA COMPOSITION
// Dans l'agrégation, la durée de vie n'est pas corrélée, si on détruit l'objet agrégeant on ne détruit pas forcément l'objet agrégé.
// Dans la composition, la durée de vie est corrélée, donc si on détruit l'objet agrégeant, on détruit aussi l'objet agrégé.

// ************** CLASSE COUPLE **************

// Getter
Bavarde Couple::getA()
{
    return a;
}
Bavarde Couple::getB()
{
    return b;
}


// Constructeur
Couple::Couple(int rep1, int rep2):a(rep1), b(rep2)
{
}

Couple::Couple(Bavarde &obj1, Bavarde &obj2):a(obj1), b(obj2)
{
}

// Destructeur
Couple::~Couple()
{
    cout << "Avada Kedavra " << a.getI() << " " << b.getI() << endl;
}
