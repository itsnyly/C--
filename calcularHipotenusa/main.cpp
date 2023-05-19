#include <iostream>
#include <math.h>
using namespace std;

int main(){
    float catet1,catet2, hipotenusa = 0;
    cout<<"valor catet 1: "; cin>>catet1;
    cout<<"valor catet 2: "; cin>>catet2;
    hipotenusa = sqrt(pow(catet1, 2) + pow(catet2,2));
    cout<<"hipotenusa : " <<hipotenusa <<endl;
    return 0;
}