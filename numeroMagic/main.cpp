#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int numeroIntroduit, intents = 0, numeroAdivinar = 0;

    srand(time(NULL));
    numeroAdivinar = 1 + rand() % (100);

    do
    {
        cout << "Pensa un numero entre 1 - 100 : ";
        cin >> numeroIntroduit;
        if (numeroIntroduit >= 1 && numeroIntroduit <= 100)
        {
            if (numeroIntroduit < numeroAdivinar)
            {
                cout << "El numero que has de trobar és més gran" << endl;
                intents++;
            }
            else
            {
                cout << "El numero que has de trobar és més petit" << endl;
                intents++;
            }
        }

    } while (numeroAdivinar != numeroIntroduit);
    cout << "ENHORABONA HAS TROBAT EL NÚMERO" << endl;
    cout << "Número d'intents : " << intents;

    return 0;
}