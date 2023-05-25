#include <iostream>
using namespace std;

int main(){
    int numeroN, sumaTotal = 0;

    cout<<"Introdueix un numero: "; cin>>numeroN;

    for (int i = 1; i <= numeroN; i++)
    {
        sumaTotal += i;
    }

    cout<<"La suma total és: " <<sumaTotal;
    
    return 0;
}