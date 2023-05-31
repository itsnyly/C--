#include <iostream>
using namespace std;

int main(){
    float a, b, resultat = 0;
    cout<<"Valor de a: "; cin>>a; //Ho posem a la mateixa línia per estalviar espai
    cout<<"Valor de b: "; cin>>b;
    resultat = a / b + 1;
    cout.precision(2); //El resultat es mostrarà amb un màxim de 2 decimals
    cout<<"\nEl resultat és " <<resultat <<endl;
    return 0;

}