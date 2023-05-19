#include <iostream>
using namespace std;

int main(){
    int x,y,aux; //utilitzarem una variable auxiliar per tal de guardar el valor de x i d'aquesta manera no perdre'l
    /*Exemple
        x = 9;
        y = 3;

    Resultat
        x = 3;
        y = 9;
    */
    cout<<"valor x: "; cin>>x;
    cout<<"valor y: "; cin>>y;
    aux = x;
    x = y;
    y = aux;
    cout<<"\nnou valor x: " << x <<endl;
    cout<<"nou valor y:" << y <<endl;
    return 0;
}