#include <iostream> // Paquet per poder llegir entrada i sortida de dades
using namespace std; // Permet utilitzar els noms de les funcions i objectes de la llibreria std sense el prefix std::

int main (){
    int number; // Variable numerica de tipus enter
    cout << "Put a number: "; // Demanem un número per pantalla
    cin >> number; // Llegim el número per teclat i el guardem a la variable number
    cout << "The number is: " << number << endl; // Mostrem el número per pantalla
    return 0; // Retornem un valor enter ja que el programa és de tipus int
}