#include <iostream>
using namespace std;

int main(){
    int numero;
    cout<<"Entra un numero: "; cin>>numero;
    if(numero < 0){
        cout<<"El numero ha de ser més gran que 0";
    }
    else if(numero % 2 == 0){
        cout<<"El numero és parell";
    }
    else{
        cout<<"El numero és senar";
    }
    return 0;
}