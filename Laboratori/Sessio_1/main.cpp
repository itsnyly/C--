#include <iostream>

using namespace std;
struct Data {
    int dia,mes,any;
};
struct Producte {
    string codi,nom,marca,categoria;
    int nombre_unitats;
    Data data_caducitat;
};
const int MAX_PRODUCTES=10000;
typedef Producte Vec_productes[MAX_PRODUCTES];
struct Vector_productes_n {
    Vec_productes vector;
    int mida_vector;
};
struct Categoria {
    string nom;
    int unitats_recollides;
};
const int MAX_CATEGORIES = 1000;
typedef Categoria Vec_categories[MAX_CATEGORIES];
struct Vector_categories_n {
    Vec_categories vector;
    int mida_vector, total_categories;
};

void cerca_dicotomica_categoria(const Vector_categories_n& categories, string nom_categoria, bool& trobat, int& pos) {
//Pre: categories.vector[0..categories.mida_vector-1] ordenat per categoria i 0<=categories.mida_vector<=MAX_CATEGORIES
//Post: trobat és true i 0<=pos<categories.mida_vector-1 si a categories.vector[pos] hi ha la categoria nom_categoria, si a categories.vector[0..categories.mida_vector-1] no hi ha la categoria nom_categoria, trobat és false i pos és la posició on s'hauria d'inserir perquè la taula estigués ordenada per categoria
    int esq=0, dreta=categories.mida_vector-1, mig;
    trobat=false;
    while (not trobat and esq<=dreta){
        mig=(esq+dreta)/2;
        if (categories.vector[mig].nom==nom_categoria) trobat=true;
        else if (categories.vector[mig].nom<nom_categoria) esq=mig+1;
        else dreta=mig-1;
    }
    if (trobat) pos=mig;
    else pos=esq;
}


int main (){
    Vector_productes_n productes_caducitat_llarga;
    Vector_productes_n productes_caducitat_curta;
    Vector_categories_n categories;
    return 0;
}