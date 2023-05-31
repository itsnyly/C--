#include <iostream>
#include <string.h>

using namespace std;

int main()
{

    char paraula[] = "hola";
    int longitud = 0;

    longitud = strlen(paraula);

    cout << "Numero de caràcters de la cadena és: " << longitud;

    return 0;
}