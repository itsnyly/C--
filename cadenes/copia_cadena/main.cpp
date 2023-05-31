#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char paraula[] = "Programant amb en Nil";
    char paraulaCopiada[50];
    strcpy(paraulaCopiada, paraula);

    cout << "Cadena Original : " << paraula << endl;
    cout << "Cadena Copiada : " << paraulaCopiada;

    return 0;
}