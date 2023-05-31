#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char cadena1[] = "hola,", cadena2[] = " bon dia!";
    strcat(cadena1, cadena2);
    cout << cadena1;
    return 0;
}