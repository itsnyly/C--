#include <iostream>
using namespace std;

int main()
{
    int matriu[100][100], files, columnes;

    cout << "Entra la quantitat de files: ";
    cin >> files;

    cout << "Entra la quantitat de columnes: ";
    cin >> columnes;

    // Inicialitzem els elements de la matriu
    for (int i = 0; i < files; i++)
    {
        for (int j = 0; j < columnes; j++)
        {
            cout << "Entra un valor per la posició [" << i << "][" << j << "] ";
            cin >> matriu[i][j];
        }
    }
    //Comprovem que sigui quadrada (és quadrada quan té el mateix nombre de files i de columnes)
    if (files == columnes)
    {
        // Comprovem si és simètrica (és simètrica si és quadrada i els seus valors coincideixen amb els valors de la seva forma trasposta)
        for (int i = 0; i < files; i++)
        {
            for (int j = 0; j < columnes; j++)
            {
                if (matriu[i][j] != matriu[j][i])
                {
                    cout << "La matriu no és simètrica";
                    return 0;
                }
            }
        }
        cout << "La matriu és simètrica";
    }
    else
    {
        cout << "La matriu no és quadrada";
    }

    return 0;
}