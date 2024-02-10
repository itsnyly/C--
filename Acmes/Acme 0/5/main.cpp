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

void inserir_llibre(Vector_inventari_n& inventari, Llibre nou_llibre, int num_inventari){
    int i= inventari.n-1;
    while(i>=0 and inventari.vec[i].llibre.titol>nou_llibre.titol){
        inventari.vec[i+1]=inventari.vec[i];
        i--;
    }
    if(inventari.vec[i].llibre.titol == nou_llibre.titol) inventari.vec[i].stock_2 = nou_llibre.stock;
    else{
        inventari.vec[i+1].llibre=nou_llibre;
        if(num_inventari == 1) inventari.vec[i+1].stock_1 = nou_llibre.stock;
        else inventari.vec[i+1].stock_2 = nou_llibre.stock;
    }
    
    inventari.n++;
};

void llegir_info_fitxer_inventari(Vector_inventari_n& inventari, ifstream& f_in, int num_inventari){
    Llibre nou_llibre=llegir_llibre(f_in);
        while(not f_in.eof()){
            inserir_llibre(inventari, nou_llibre, num_inventari);
            nou_llibre=llegir_llibre(f_in);
        }
};

void comprovar_fitxers(Vector_inventari_n& inventari,string fitxer, int num_inventari){
    ifstream f_in(fitxer.c_str());
    if(f_in.is_open()){
        llegir_info_fitxer_inventari(inventari,f_in,num_inventari);
    }
    else{
        mostrar_missatge_error("EL FITXER NO S'HA POGUT OBRIR");
        cout<<"INTRODUEIX UN ALTRE NOM DE FITXER: ";
        cin>>fitxer;
        ifstream f_in(fitxer.c_str());
        llegir_info_fitxer_inventari(inventari,f_in, num_inventari);
    }
};

void omplir_de_fitxer_inventari(Vector_inventari_n& inventari){
    inventari.n=0;
    string fitxer1;
    cout<<"ENTRA EL NOM DE FITXER DE L'INVENTARI DE LA LLIBRERIA 1: " << endl;
    cin>>fitxer1;
    comprovar_fitxers(inventari, fitxer1, 1);
    string fitxer2;
    cout<<"ENTRA EL NOM DE FITXER DE L'INVENTARI DE LA LLIBRERIA 2: " << endl;
    cin>>fitxer2;
    comprovar_fitxers(inventari, fitxer2, 2);
};

void ordenar_inventari_isbn(Vector_inventari_n& inventari_original){
    for (int i = 0; i < inventari_original.n; i++)
    {
        for (int j = 0; j < inventari_original.n; j++)
        {
            if(inventari_original.vec[j].llibre.isbn > inventari_original.vec[i].llibre.isbn){
                Inventari aux = inventari_original.vec[i];
                inventari_original.vec[i] = inventari_original.vec[j];
                inventari_original.vec[j] = aux;
            }
        }
    }
};

void mostrar_inventari(Inventari inventari){
    cout << inventari.stock_1 << " - " << inventari.stock_2 << " " << inventari.llibre.titol << ", " << inventari.llibre.autor << " Ed. " << inventari.llibre.editorial <<  " - " << inventari.llibre.isbn << endl; 
};

void mostrar_informacio_inventari(const Vector_inventari_n inventari){
    cout << "Estocs Titol, Autor Editorial - ISBN" << endl;
    for (int i = 0; i < inventari.n; i++)
    {
        mostrar_inventari(inventari.vec[i]);
    }
    cout << endl;
};
int main(){
    Vector_inventari_n inventari;
    omplir_de_fitxer_inventari(inventari);
    cout << "INVENTARI PER ORDRE ALFABETIC" << endl;
    mostrar_informacio_inventari(inventari);
    cout << "INVENTARI PER ORDRE D'ISBN" << endl;
    ordenar_inventari_isbn(inventari);
    mostrar_informacio_inventari(inventari);
    return 0;
}