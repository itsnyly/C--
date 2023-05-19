#include <iostream>
using namespace std;

int main(){
    char caracter;
    cout<<"Entra una lletra: "; cin>>caracter;
    switch (caracter)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout<<"És una vocal minúscula";
            break;
        default:
            cout<<"No és una vocal minúscula";
            break;
    }
    return 0;
}