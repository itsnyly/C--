#include <iostream>
#include <math.h>
using namespace std;

int main(){
    float a,b,c, resultatPositiu = 0, resultatNegatiu = 0;
    cout<<"valor a: "; cin>>a;
    cout<<"valor b: "; cin>>b;
    cout<<"valor c: "; cin>>c;
    resultatPositiu = (-b + (sqrt((pow(b,2)) - (4 * a * c)))) / (2 * a);
    resultatNegatiu = (-b - (sqrt((pow(b,2)) - (4 * a * c)))) / (2 * a);
    cout<<"x = " <<resultatPositiu <<endl;
    cout<<"x = " <<resultatNegatiu <<endl;
    return 0;
}