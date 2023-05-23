#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int i;
    /**
     * Per utilitzar el for, primerament indiquem el valor amb el qual començarà el bucle.
     * Separat per ; indiquem fins on ha d'arribar.
     * Finalment indiquem si valor inicial augmentarà per cada volta que realitzi el bucle(i++) o disminuirà(i--)
     */
    for (i = 1; i <= 10; i++)
    {
        cout << i << endl;
    }

    system("pause");

    return 0;
}