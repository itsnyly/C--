#include <iostream>
using namespace std;

int main()
{
    int valor, sumaTotal = 0;

    do
    {
        cout << "Introdueix un valor : ";
        cin >> valor;

        if (valor > 0)
        {
            sumaTotal += valor;
        }
    } while (((valor < 20) || (valor > 30)) && (valor != 0));

    cout << "La suma total és: " << sumaTotal;

    return 0;
}