#include <iostream>
using namespace std;

struct Persona
{
    char nom[20];
    int edat;
} persona1;

int main()
{
    cout << "Entra un nom per la persona 1: ";
    cin.getline(persona1.nom, 20, '\n');
    cout << "Entra l'edat per la persona 1: ";
    cin >> persona1.edat;

    cout << "Nom1: " << persona1.nom << endl;
    cout << "Edat1: " << persona1.edat << endl;

    return 0;
}
