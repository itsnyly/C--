#include <iostream>
using namespace std;

int main()
{
    int numeros[100], n;

    cout << "Entra el nombre d'elements que tindrà l'array : ";
    cin >> n;

    // Guardarem els valors per cada posició de l'array
    for (int i = 0; i < n; i++)
    {
        cout << "Entra un valor: ";
        cin >> numeros[i];
    }

    // Mostrem la posició de l'array juntament amb el seu valor
    for (int i = 0; i < n; i++)
    {
        cout << "El valor de la posició " << i << " és: " << numeros[i] << endl;
    }
    
    return 0;
}