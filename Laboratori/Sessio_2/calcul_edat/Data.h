#ifndef DATA_H
#define DATA_H

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
        void llegir();
        // Pre: data;
        // Post: llegeix dates en format AAAAMMDD,

    private:
        int a_dia;
        int a_mes;
        int a_any;
};

#endif // DATA_H