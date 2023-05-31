#include <iostream>
using namespace std;

int main(){
    int numero, dada = 5;
    cout<<"Introdueix un numero: "; cin>>numero;
    /**
     *! Un igual assigna un valor a una variable, dos iguals comprova la igualtat entre dos valors
    */
    if(numero == dada){ //Si es compleix la condició de que numero és igual al valor de dada, executarà el codi del seu interior
        cout<<"El numero és 5";
    }
    else{ //En cas contrari executarà aquest codi
        cout<<"El numero és diferent de 5";
    }
    return 0;
}