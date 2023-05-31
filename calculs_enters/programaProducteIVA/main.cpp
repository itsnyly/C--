#include <iostream>
using namespace std;

int main(){
    float preu, preuFinal;
    int iva = 21;
    cout << "Introdueix el preu del producte: ";
    cin >> preu;
    preuFinal = preu + (preu * iva / 100);
    cout << "El preu final es: " << preuFinal << endl;
    return 0;
}