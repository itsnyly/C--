#ifndef DATA_H
#define DATA_H
#include <string>

using namespace std;

class Data
{
    public:
        Data();
        // Pre: cert;
        // Post: és la data 1/1/2001
        bool es_aniversari(const Data& d) const;
        // Pre: cert;
        // Post: cert si d.mes i d.dia són iguals a la data actual, fals altrament;
        int edat(const Data& d) const;
        // Pre: data naixement vàlida;
        // Post: retorna l'edat tinguent en compte la data actual i la data de naixement ;
        void llegir();
        // Pre: cert;
        // Post: llegeix dates en format AAAAMMDD,

    private:
        int a_dia;
        int a_mes;
        int a_any;
        // CONSTANTS DE CLASSE
        static const int MESOS_ANY = 12;
        static const int DIES_MES[];
        static const string NOM_MES[];
        // FUNCIONS DE CLASSE
        static bool es_data_valida(int dia, int mes, int any);
        // Pre: cert;
        // Post: retorna cert si dia/mes/any formen una data vàlida
        // en el calendari gregorià (entre els anys 1600 i 4000)
};

#endif // DATA_H