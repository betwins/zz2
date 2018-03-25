#include "mere.hpp"

int Mere::compteur=0; // L'initialisation du compteur se fait toujours en global.

int main(int, char **)
{
    // Mere test = Mere(5);
    // Mere test2;
    // Constructeur par défaut, il n'y a pas de parenthèses à mettre !!
    fille testF2;
    cout << "compteur vaut " << testF2.getCompteur() << endl;
    cout << testF2.getPopo() << endl;
    cout << testF2.getI() << endl;
    cout << "compteur vaut " << testF2.getCompteur() << endl;
    cout << "z vaut " << testF2.getZ() << endl;
    return 0;
}
