#include <iostream>

using namespace std;

int main(){
    int numeros [] = {2,4,8,3,1};
    int i, j, aux;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if(numeros[j] > numeros[j+1]){
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
        
    }

    cout<<"Array Ordenat" <<endl;

    for (i = 0; i < 5; i++)
    {
        cout<<numeros[i]<<" ";
    }
    
    

    return 0;
}