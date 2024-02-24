#include <iostream>
#include "Data.h"

using namespace std;

// CONSTANTS DE CLASSE
const int Data::DIES_MES[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string Data::NOM_MES[] = {"CAP", "GENER", "FEBRER", "MARC", "ABRIL",
"MAIG", "JUNY", "JULIOL", "AGOST", "SETEMBRE", "OCTUBRE", "NOVEMBRE",
"DESEMBRE"};

// CONSTRUCTORS
// CONSTRUCTOR PER DEFECTE
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
    // Pre: data naixement vàlida; // Post: retorna l'edat tinguent en compte la data actual i la data de naixement ;
    int anys = 0;
    anys = a_any - d.a_any;
    if((a_mes < d.a_mes) || (a_mes == d.a_mes && a_dia < d.a_dia ) ) anys--;
    return anys;
}

void Data::llegir() {
    // Pre: cert; // Post: llegeix dates en format AAAAMMDD
    int any, mes, dia;
    do { // llegir AAAAMMDD i separar-ho en any, mes i dia
        cin >> any;
        dia = any % 100;
        any = any / 100;
        mes = any % 100;
        any = any / 100;
    } while (!es_data_valida(dia, mes, any));
    // es guarda dia, mes i any en els atributs
    a_any = any;
    a_mes = mes;
    a_dia = dia;
}

// FUNCIONS DE CLASSE
bool Data::es_data_valida(int dia, int mes, int any) {
    // Pre: cert; // Post: cert si dia/mes/any seria una data vàlida en el calendari gregorià (entre anys 1600 i 4000), fals altrament
    bool correcte = true;
    bool es_de_traspas = (any % 4 == 0) and (any % 100 != 0 or any % 400 == 0);
    if (any > 3999 or any < 1600 or mes > MESOS_ANY or mes < 1 or dia < 1)
        correcte = false;
    else {
        int dies_mes;
        if (es_de_traspas and mes == 2) dies_mes = 29;
        else dies_mes = DIES_MES[mes];
        if (dia > dies_mes) correcte = false;
    }
    return correcte;
}
