/**
 * Calcular la funció f(x,y) = √x / (y^2 - 1)
*/
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    float x,y,resultat = 0;
    cout<<"Valor x: "; cin>> x;
    cout<<"Valor y: "; cin>> y;
    resultat = (sqrt(x))/(pow(y,2) - 1);
    cout<<"Resultat funció : " <<resultat <<endl;
    return 0;
}