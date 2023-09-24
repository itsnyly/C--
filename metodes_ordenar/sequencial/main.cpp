//Cerca Sequencial
//Programa que busca un número en un vector de números enteros

#include <iostream>

using namespace std;

int main(){
    int a[] = {3, 4, 2, 1, 5};
    int dada, i;
    bool trobat = false;
    dada = 4;
    //Cerca sequencial
    i=0;
    while ((trobat == false) && (i < 5))
    {
        if(a[i] == dada){
            trobat = true;
        }
        i++;
    }

    if(trobat == false){
        cout<<"No s'ha trobat la dada dins l'array";
    }
    else {
        cout<<"S'ha trobat la dada a la posició : "<<i-1<<endl;
    }
    
    return 0;
}