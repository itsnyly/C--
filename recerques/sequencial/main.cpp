#include <iostream>

using namespace std;

int main()
{

    int numeros[] = {3, 4, 2, 1, 5}, valor, i;
    bool trobat = false;

    valor = 4;

    //Cerca sequencial
    i = 0;
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