#include <iostream>

using namespace std;

int main()
{
    int numeros[100][100], files, columnes;

    cout << "Introdueix el numero de files: ";
    cin >> files;
    cout << "Introdueix el numero de columnes: ";
    cin >> columnes;
    for (int i = 0; i < files; i++)
    {
        for (int j = 0; j < columnes; j++)
        {
            cout << "Entra un numero per la posició [" <<i<<"]["<<j<<"]";
            cin >> numeros[i][j];
        }
    }

    for (int i = 0; i < files; i++)
    {
        for (int j = 0; j < columnes; j++)
        {
            cout << numeros[i][j] << endl;
        }
    }

    return 0;
}