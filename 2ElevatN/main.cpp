#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int numeroBase = 2, numeroN, sumaTotal = 0;
    cout << "Introdueix un numero: ";
    cin >> numeroN;
    for (int i = 1; i <= numeroN; i++)
    {
        sumaTotal += pow(numeroBase, i);
    }

    cout << "El resultat és : " << sumaTotal;

    return 0;
}