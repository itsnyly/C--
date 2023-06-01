#include <iostream>

using namespace std;

int main()
{
    int numeros[] = {2, 6, 1, 8, 4}, aux, min;

    for (int i = 0; i < 5; i++)
    {
        min = i; // Guardem com a número més petit la primera posició
        for (int j = i + 1; j < 5; j++)
        {
            if (numeros[j] < numeros[min])
            {
                min = j; // Si trobem un número més petit guardem la posició a la variable min
            }
        }
        aux = numeros[i];          // Guardem el valor de la posició on estem a la variable aux
        numeros[i] = numeros[min]; // Assignem el número més petit a la posició de i
        numeros[min] = aux;        // El valor que tenia i el guardem a la posició del número més petit
    }

    // Mostrar array ordenat
    for (int i = 0; i < 5; i++)
    {
        cout << numeros[i] << " ";
    }

    return 0;
}