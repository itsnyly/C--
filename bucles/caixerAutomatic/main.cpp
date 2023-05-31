/**
 * La idea principal era fer ús del switch per controlar tres possibles opcions, 
 * però realitzarem un caixer automatic més realista utilitzant el while,
 * d'aquesta manera el procés s'anirà executant fins que l'usuari no seleccioni l'opció de sortir.
*/
#include <iostream>
using namespace std;

int main()
{
    int saldoInicial = 1000, operacio;
    float afegit, retirada;
    while (operacio != 3)
    {
        cout << "Selecciona una de les següents opcions: " << endl;
        cout << "1. Ingressar diners al teu compte" << endl;
        cout << "2. Treure diners del teu compte" << endl;
        cout << "3. Sortir" << endl;
        cin >> operacio;

        switch (operacio)
        {
        case 1:
            cout << "Quina quantitat vols ingressar ?" << endl;
            cin >> afegit;
            saldoInicial += afegit;
            cout << "Diners dels compte: " << saldoInicial << endl;
            break;
        case 2:
            cout << "Quina quantitat vols retirar ?" << endl;
            cin >> retirada;
            if (retirada > saldoInicial)
            {
                cout << "No disposes de suficients diners al compte" << endl;
            }
            else
            {
                saldoInicial -= retirada;
                cout << "Diners dels compte: " << saldoInicial << endl;
            }
            break;
        case 3:
            break;
        default:
            cout<<"Introdueix una operació vàlida" <<endl;
            break;
        }
    }

    return 0;
}