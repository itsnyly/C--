#include <iostream>
using namespace std;

int main(){
    float a,b,c,d,e,f, resultat = 0;
    cout<<"valor a: "; cin>>a;
    cout<<"valor b: "; cin>>b;
    cout<<"valor c: "; cin>>c;
    cout<<"valor d: "; cin>>d;
    cout<<"valor e: "; cin>>e;
    cout<<"valor f: "; cin>>f;
    cout.precision(2);
    resultat = (a + b/c) / (d + e/f);
    cout<<"\n El resultat és : " <<resultat;
    return 0;
}