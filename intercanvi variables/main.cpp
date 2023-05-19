#include <iostream>
using namespace std;

int main(){
    int x,y,aux;
    cout<<"valor x: "; cin>>x;
    cout<<"valor y: "; cin>>y;
    aux = x;
    x = y;
    y = aux;
    cout<<"\nnou valor x: " << x <<endl;
    cout<<"nou valor y:" << y <<endl;
    return 0;
}