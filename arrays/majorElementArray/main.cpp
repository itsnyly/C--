#include <iostream>

using namespace std;

int main(){
    int numeros[100], n, max = 0;
    cout<<"Entra el nombre d'elements de l'array: "; cin>>n;

    // Guardem els valors del elements de l'array
    for (int i = 0; i < n; i++)
    {
        cout<<"Entra un valor: "; cin>>numeros[i];
        //Comparem els valors per trobar el més gran
        if(max < numeros[i]){
            max = numeros[i];
        }
    }

    cout<<"L'element més gran és : " <<max;
    
    return 0;
}

