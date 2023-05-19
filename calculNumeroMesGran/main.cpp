#include <iostream>
using namespace std;

int main(){
    int numero1,numero2;
    cout<<"Entra dos numeros "; cin>>numero1>>numero2;
    if(numero1 == numero2){
        cout<<"Els dos numeros son iguals";
    }
    else if(numero1 > numero2){
        cout<<"El numero més gran és: " <<numero1 <<endl;
    }
    else{
        cout<<"El numero més gran és: " <<numero2 <<endl;
    }
    return 0;
}