/**
 *!Per utilitzar la recerca binaria, l'array ha d'estar ordenat
 */

#include <iostream>

using namespace std;

int main()
{
    int numeros[] = {1, 2, 3, 4, 5};
    int inici, final, meitat, valor;
    bool trobat = false;

    valor = 4;

    //Cerca binaria
    inici = 0;
    final = 5;

    while (inici <= final)
    {
        meitat = (inici + final) / 2;

        if (numeros[meitat] == valor)
        {
            trobat = true;
            break;
        }
        else if (numeros[meitat] > valor)
        {
            final = meitat;
            meitat = (inici + final) / 2;
        }
        else
        {
            inici = meitat;
            meitat = (inici + final) / 2;
        }
    }

    if (trobat)
    {
        cout << "El valor s'ha trobat a la posició " << meitat;
    }
    else
    {
        cout << "El valor no existeix a l'array";
    }
    return 0;
}