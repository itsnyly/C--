#include <iostream>
using namespace std;

int main(){
    int numero;
    cout<<"Entre un numero de 1-5: "; cin>>numero;
    switch (numero) //Depèn del valor de la variable numero realitzarà una cosa o una altre
    {
    case 1:
        cout<<"És el numero 1";
        break;
    case 2:
        cout<<"És el numero 2";
        break;
    case 3:
        cout<<"És el numero 3";
        break;
    case 4:
        cout<<"És el numero 4";
        break;
    case 5:
        cout<<"És el numero 5";
        break;
    default: //Si el valor no és cap dels anteriors executarà el codi definit aquí
        break;
    }
    return 0;
}