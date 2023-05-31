#include <iostream>

using namespace std;

int main(){

    int numeros [] = {4,2,3,1,5};
    int i, pos, aux;

    for (i = 0; i < 5; i++)
    {
        pos = i; //Es guarda la posició actual
        aux = numeros[i]; //Es guarda el valor de la posició actual
        while ((pos > 0) && (numeros[pos-1] > aux)) //Mentres la posició actual sigui major a 0 i el valor de la posició anterior sigui més gran que el valor de la posició actual
        {
            numeros[pos] = numeros[pos-1]; //Guardarem el valor de la posició anterior a la posició actual
            pos--; //Retrocedim posicions
        }

        numeros[pos] = aux; //Asignem a la posició actual (on abans hi havia un numero major) el valor guardar a aux.
        
    }
    
    return 0;
}