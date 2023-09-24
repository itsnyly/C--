#include <iostream>

using namespace std;

int main(){
    int numeros[] = {1, 2, 3, 4, 5};
    int inf,sup,meitat,dada;
    bool trobat = false;

    dada = 4;

    //Cerca binaria

    while(inf <= sup){
        meitat = (inf + sup) / 2;

        if(numeros[meitat] == dada){
            trobat = true;
            break;
        }
        if(numeros[meitat] > dada){
            sup = meitat;
            meitat = (inf + sup) / 2;
        }
        if(numeros[meitat] < dada){
            inf = meitat;
            meitat = (inf + sup) / 2;
        }
    }

    if(trobat == true){
        cout << "Trobat a la posicio " << meitat << endl;
    }
    else{
        cout << "No trobat" << endl;
    }
    
    return 0;
}