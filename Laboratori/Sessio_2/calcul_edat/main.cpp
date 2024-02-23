#include <iostream>
#include "Data.h"

using namespace std;

int main()
{
    Data data1, data2;
    cout << "ENTRA LA DATA ACTUAL:" << endl;
    data1.llegir();
    cout << "ENTRA LA DATA DE NAIXEMENT:" << endl;
    data2.llegir();
    int edat = data1.edat(data2);
    if(data1.es_aniversari(data2)) cout << "AVUI ES L'ANIVERSARI! FA " << edat << " ANYS";
    else cout << "TE " << edat << " ANYS";
    return 0;
}