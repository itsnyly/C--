#include <iostream>

using namespace std;

int main()
{
    char primerArray[] = {'a', 'b', 'c', 'd', 'e'}, segonArray[] = {'f', 'g', 'h', 'i', 'j'}, arrayFinal[10];

    for (int i = 0; i < 5; i++)
    {
        arrayFinal[i] = primerArray[i];
    }

    for (int i = 5; i < 10; i++)
    {
        arrayFinal[i] = segonArray[i - 5];
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arrayFinal[i] << endl;
    }

    return 0;
}