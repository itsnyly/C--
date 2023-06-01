#include <iostream>
#include <stdlib.h> //Llibreria la qual ens permetrà pausar l'execució del nostre programa
using namespace std;

int main()
{
    int i = 10;
    /**
     * Utilitzant el do while, el codi dins de do com a mínim s'executarà una vegada.
     * En canvi si utilitzem el while, comprovarà abans la condició i en cas que no la compleixi no executarà el codi.
     */
    do
    {
        cout << i << endl;
        i--;
    } while (i >= 1);

    system("pause");
    return 0;
}