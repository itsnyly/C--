#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Llibre{
    string titol;
    string isbn;
    string editorial;
    string autor;
    int stock;
};

struct Inventari{
    Llibre llibre;
    int stock_1;
    int stock_2;
};

const int MAX_INVENTARI = 1000;
typedef Inventari Vec_inventari[MAX_INVENTARI];
struct Vector_inventari_n{
    Vec_inventari vec;
    int n;
};

Llibre llegir_llibre(ifstream &f_in){
    Llibre llibre;
    f_in >> llibre.titol;
    if(not f_in.eof())
        f_in >> llibre.isbn >>llibre.editorial >> llibre.autor >> llibre.stock;
    return llibre;
};

void mostrar_missatge_error(string missatge){
    cout<<"<< ERROR: "<<missatge<<" >>" <<endl;
};

void mostrar_titol(string titol){
    cout << titol;
}

void inserir_llibre(Vector_inventari_n& inventari, Llibre nou_llibre){
    int i= inventari.n-1;
    while(i>=0 and inventari.vec[i].llibre.titol>nou_llibre.titol){
        inventari.vec[i+1]=inventari.vec[i];
        i--;
    }
    inventari.vec[i+1].llibre=nou_llibre;
    inventari.n++;
};

void llegir_info_fitxer_inventari(Vector_inventari_n& inventari, ifstream& f_in){
    Llibre nou_llibre=llegir_llibre(f_in);
        while(not f_in.eof()){
            inserir_llibre(inventari, nou_llibre);
            nou_llibre=llegir_llibre(f_in);
        }
};
void omplir_de_fitxer_inventari(Vector_inventari_n& inventari){
    inventari.n=0;
    string nom;
    cout<<"ENTRA EL NOM DE FITXER DE L'INVENTARI DE LA LLIBRERIA 1: ";
    cin>>nom;
    ifstream f_in(nom.c_str());
    if(f_in.is_open()){
        llegir_info_fitxer_inventari(inventari,f_in);
    }
    else{
        mostrar_missatge_error("EL FITXER NO S'HA POGUT OBRIR");
        cout<<"INTRODUEIX UN ALTRE NOM DE FITXER: ";
        cin>>nom;
        ifstream f_in(nom.c_str());
        llegir_info_fitxer_inventari(inventari,f_in);
    }

};

void mostrar_inventari(Inventari inventari){
    cout << left << setfill(' ');
    cout << inventari.llibre.titol << " " << inventari.llibre.isbn << " " << inventari.llibre.autor <<  " " << inventari.llibre.editorial << " " << inventari.llibre.stock << endl; 
};

void mostrar_informacio_inventari(const Vector_inventari_n inventari){
    for (int i = 0; i < inventari.n; i++)
    {
        mostrar_inventari(inventari.vec[i]);
    }
};
int main(){
    Vector_inventari_n inventari;
    omplir_de_fitxer_inventari(inventari);
    mostrar_informacio_inventari(inventari);

    return 0;
}