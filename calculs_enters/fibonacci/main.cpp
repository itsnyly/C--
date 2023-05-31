#include <iostream>
using namespace std;

int main(){
    int numeroN, numeroAnterior = 1, sumaNumeros = 0, primerNumero = 0;

    cout<<"Entra un numero: "; cin>>numeroN;
    cout<<"1 ";
    for (int i = 1; i < numeroN; i++)
    {  
        sumaNumeros = primerNumero + numeroAnterior;
        primerNumero = numeroAnterior;
        numeroAnterior = sumaNumeros;
        cout<<sumaNumeros<<" ";
    }
    
    return 0;
}