#include <iostream>
#include "Data.h"

using namespace std;

Data::Data()
{
// Pre: cert; Post: és la data 1/1/2001
    a_dia = 1;
    a_mes = 1;
    a_any = 2001;
}

bool Data::es_aniversari(const Data& d) const {
// Pre: cert; // Post: cert si d.dia i d.mes són iguals a la data actual, fals altrament
    return (a_dia == d.a_dia && a_mes == d.a_mes);
}

int Data::edat(const Data& d) const {
    int anys = 0;
    anys = a_any - d.a_any;
    if((a_mes < d.a_mes) || (a_mes == d.a_mes && a_dia < d.a_dia ) ) anys--;
    return anys;
}

void Data::llegir() {
// Pre: cert;
// Post: llegeix dates en format AAAAMMDD
    int any, mes, dia;
    // llegir AAAAMMDD i separar-ho en any, mes i dia
    cin >> any;
    dia = any % 100;
    any = any / 100;
    mes = any % 100;
    any = any / 100;
    // es guarda dia, mes i any en els atributs
    a_any = any;
    a_mes = mes;
    a_dia = dia;
}