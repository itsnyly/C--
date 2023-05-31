#include <iostream>

using namespace std;

int main()
{
    int numeros[2][2] = {{1, 2}, {3, 4}}, copiaNumeros[2][2];

    // Copiar el contingut de la primera matriu a la segona
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            copiaNumeros[i][j] = numeros[i][j];
        }
    }

    // Mostra el contingut de la segona matriu
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Valor de la posició [" << i << "][" << j << "] = " << copiaNumeros[i][j] << endl;
        }
    }

    return 0;
}