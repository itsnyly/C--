#include <iostream>

using namespace std;

int main()
{

    int numeros[] = {2, 4, 3, 1, 5}, valor = 1, i = 0;
    bool trobat = false;

    while ((!trobat) && (i < 5))
    {
        if (numeros[i] == valor)
        {
            trobat = true;
        }
        i++;
    }

    if (trobat)
    {
        cout << "El valor s'ha trobat a la posició " << i - 1;
    }
    else
    {
        cout << "El valor a buscar no existeix dins l'array";
    }

    return 0;
}