#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char paraula[] = "Programacio";
    char paraula2[] = {'P', 'r', 'o', 'g', 'r', 'a', 'm', 'a', 'c', 'i', 'o'};
    char nom[20];

    cout << "Entra el teu nom: ";

    /*Si guardem la cadena amb el cin, com feiem fins ara, quan aquest trobi un espai pararà de guardar caràcters.
      Si utilitzem la funció gets, guardarà tota la cadena sense tenir en compte la capacitat màxima de caràcters que volem guardar.
      Per aquest motiu la millor manera és utilitzar la funció cin.getline .
    */

    cin.getline(nom, 20, '\n');

    cout << nom << endl;
    return 0;
}