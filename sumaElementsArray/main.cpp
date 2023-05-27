/**
 * Explicació arrays :  https://www.youtube.com/watch?v=l-kOjxvgyDQ&ab_channel=Programaci%C3%B3nATS
 */

/**
 * En aquest programa tindrem un array de numeros i calcularem la suma total dels seus elements
 */
#include <iostream>

using namespace std;

int main()
{

    int numeros[5] = {1, 2, 3, 4, 5}; // Inicialitzem l'array
    int sumaTotal = 0;

    for (int i = 0; i < 5; i++)
    {
        sumaTotal += numeros[i]; // Recorrem l'array i anem sumant el valor de cada posició d'aquest
    }

    cout << "La suma dels elements és : " << sumaTotal;

    return 0;
}