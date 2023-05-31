#include <iostream>
using namespace std;

int main()
{
    int numeroN, factorial = 1;

    cout << "Introdueix un numero: ";
    cin >> numeroN;

    for (int i = 1; i <= numeroN; i++)
    {
        factorial *= i;
    }

    cout << "El factorial del numero " << numeroN << " és: " << factorial;

    return 0;
}