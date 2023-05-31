#include <iostream>
using namespace std;

int main(){
    int numeroBase;

    cout<<"Quina taula de multiplicar vols saber ? "; cin>>numeroBase;

    for (int i = 0; i <= 10; i++)
    {
        cout<<numeroBase<<" * "<< i << " = " << numeroBase*i <<endl;  
    }
    
    return 0;
}