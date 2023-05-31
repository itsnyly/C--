#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int sumaQuadrats = 0;

    for (int i = 1; i <= 10; i++)
    {
        sumaQuadrats += pow(i, 2);
    }

    cout << "La suma dels quadrats és : " << sumaQuadrats;
    return 0;
}