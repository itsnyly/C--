#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char numeroEnter[] = "345", numeroDecimal[] = "322.45";
    int numEnter;
    float numDecimal;

    numEnter = atoi(numeroEnter);
    numDecimal = atof(numeroDecimal);

    cout << numEnter << endl;
    cout << numDecimal;
    return 0;
}