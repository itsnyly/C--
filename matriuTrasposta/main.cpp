#include <iostream>

using namespace std;

int main()
{
    int matriu[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, matriuTrasposta[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriuTrasposta[i][j] = matriu[j][i];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matriuTrasposta[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}