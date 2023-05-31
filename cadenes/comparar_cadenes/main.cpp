#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char paraula1[30], paraula2[30];

    cout << "Introdueix un text: ";
    cin.getline(paraula1, 30, '\n');
    cout << "Introdueix un altre text: ";
    cin.getline(paraula2, 30, '\n');

    if (strcmp(paraula1, paraula2) == 0)
    {
        cout << "Els textos són iguals";
    }
    else
    {
        cout << "Els textos són diferents";
    }

    return 0;
}