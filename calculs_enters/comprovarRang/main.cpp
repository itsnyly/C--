#include <iostream>
using namespace std;

int main(){
    int numero;

    cout<<"Entra un numero: "; cin>>numero;
    if(numero >= 18 && numero <=25){
        cout<<"El numero està dins del rang [18-25]";
    }
    else{
        cout<<"El numero no es troba dins el rang [18-25]";
    }
    return 0;
}