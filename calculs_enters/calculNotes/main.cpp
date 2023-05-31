/**
 * La qualificació final d'un estudiant és la mitjana de tres notes:
 * La nota de pràctiques repercuta en un 30% del total
 * La nota teòrica repercuta en un 60% del total
 * I la nota de participació repercuta en el 10 % restant
 ** El programa ha de llegir les tres notes i mostrar la nota final
*/

#include <iostream>
using namespace std;

int main(){
    float notaPractiques, notaTeorica, notaParticipacio, notaMitjana = 0;
    cout<<"Nota de pràctiques: "; cin>>notaPractiques;
    cout<<"Nota teòrica: "; cin>>notaTeorica;
    cout<<"Nota participació: "; cin>>notaParticipacio;
    notaMitjana = ((notaPractiques * 30) / 100) + ((notaTeorica * 60) / 100) + ((notaParticipacio * 10) / 100);
    cout<<"Nota mitjana: " <<notaMitjana <<endl;
    return 0;
}