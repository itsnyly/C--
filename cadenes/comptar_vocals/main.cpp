#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char cadena[50];
    int vocal_a = 0, vocal_e = 0, vocal_i = 0, vocal_o = 0, vocal_u = 0;

    cout << "Introdueix un text: ";
    cin.getline(cadena, 50, '\n');
    strlwr(cadena);
    
    for (int i = 0; i < strlen(cadena); i++)
    {
        switch (cadena[i])
        {
            case 'a':
                vocal_a++;
                break;
            case 'e':
                vocal_e++;
                break;
            case 'i':
                vocal_i++;
                break;
            case 'o':
                vocal_o++;
                break;
            case 'u':
                vocal_u++;
                break;
            default:
                break;
        }
    }

    cout<<"a: " <<vocal_a <<endl;
    cout<<"e: " <<vocal_e <<endl;
    cout<<"i: " <<vocal_i <<endl;
    cout<<"o: " <<vocal_o <<endl;
    cout<<"u: " <<vocal_u;
    return 0;
}