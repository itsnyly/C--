#include <iostream>
#include <fstream>

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

void inserir_categoria(Vector_categories_n& categories, string nova_categoria, int unitats_producte, int pos) {
//Pre: categories.mida_vector=mida_vector<MAX_CATEGORIES i categories.vector[0..mida_vector-1] ordenat alfabèticament per categoria i 0<=pos<=mida_vector indica on cal afegir nova_categoria perquè la taula es mantingui ordenada
//Post: categories.mida_vector=mida_vector+1 i la nova categoria s'ha inserit a la posició pos de categories.vector
    for (int i=categories.mida_vector; i>pos; i--)
        categories.vector[i]=categories.vector[i-1];
    categories.vector[pos].nom=nova_categoria;
    categories.vector[pos].unitats_recollides=unitats_producte;
    categories.mida_vector++;
}

void actualitzar_unitats_categoria(Vector_categories_n categories, int unitats_producte, int pos) {

}

void mostrar_producte(Producte producte) {
//Pre: cert
//Post: mostra la informació de la jugadora a per pantalla
    cout<<producte.codi<<" - "<<producte.nom<<" "<<producte.marca<<" "<<producte.nombre_unitats<<" "<<producte.data_caducitat.dia <<"-"<<producte.data_caducitat.mes<<"-"<<producte.data_caducitat.any<<" "<<producte.categoria<<endl;
}

void mostra_categoria(Categoria categoria) {
//Pre: cert
//Post: mostra informació del país a per pantalla
    cout<<categoria.nom<< " - " <<categoria.unitats_recollides<<endl;
}

void mostrar_productes(const Vector_productes_n& productes) {
//Pre: cert
//Post: ha mostrat la informació guardada a jugadores.vec[0..jugadores.n-1] per pantalla
    cout<<"PRODUCTES ACTUALS: "<<endl;
    for (int i=0; i<productes.mida_vector; i++)
        mostrar_producte(productes.vector[i]);
}

void cerca_dicotomica_producte(const Vector_productes_n& productes, string codi, bool& trobat, int& pos) {
//Pre: jugadores.vec[0..jugadores.n-1] ordenat per codi de jugadora i 0<=N<=MAX_J i 0<=paisos.n<=MAX_P
//Post: trobat és true si a jugadores.vec[0..jugadores.n-1] hi ha una jugadora amb el codi donat i pos és la posició on es troba; si no hi ha cap jugadora amb aquest codi, trobat és false i pos és la posició on hauria de ser per mantenir l'ordre de la taula
    int esq=0, dret=productes.mida_vector-1, mig=0;
    trobat=false;
    while (not trobat and esq<=dret) {
        mig=(esq+dret)/2;
        if (productes.vector[mig].codi==codi) trobat=true;
        else if (productes.vector[mig].codi<codi) esq=mig+1;
        else dret=mig-1;
    }
    if (trobat) pos=mig;
    else pos=esq;
}

void inserir_producte(Vector_productes_n& productes, Producte nou_producte) {
//Pre: jugadores.n=N<MAX_J i jugadores.vec[0..N-1] ordenat per codi de jugadora
//Post: jugadores.n=N+1 i nova s'ha inserit a jugadores.vec[0..N-1] mantenint l'ordre de les jugadores
    int i=productes.mida_vector-1;
    while (i>=0 and productes.vector[i].codi>nou_producte.codi){
        productes.vector[i+1]=productes.vector[i];
        i--;
    }
    productes.vector[i+1]=nou_producte;
    productes.mida_vector++;
}

void alta_producte_categoria(Vector_categories_n& categories, string nova_categoria, int nombre_unitats_producte) {
//Pre: paisos.n=N i 0<=N<=MAX_P i paisos[0..N-1] ordenat per nom de país
//Post: si nou_pais no apareixia a paisos.vec[0..N-1], el nou_pais s'hi ha afegit respectant l'ordre alfabètic i paisos.n=N+1; en cas contrari, s'ha incrementat una jugadora al país corresponent
    bool trobat;
    int pos;
    cerca_dicotomica_categoria(categories,nova_categoria,trobat,pos);
    if (not trobat) inserir_categoria(categories,nova_categoria,nombre_unitats_producte,pos);
    //else categories.vector[pos].++;
}

Producte llegir_producte(ifstream &f_in){
//Pre: f_in obert apunt de llegir
//Post: si després de la 1a lectura no s’activa f_in.eof, es llegix i retorna una jugadora de fin
  Producte producte;
  f_in>> producte.codi;
  if(not f_in.eof())
      f_in>>producte.nom>>producte.marca>>producte.nombre_unitats>> producte.data_caducitat.any >> producte.data_caducitat.mes >> producte.data_caducitat.dia>>producte.categoria;
  return producte;
}

void omplir_de_fitxer(Vector_productes_n& productes, Vector_categories_n& categories) {
//Pre: cert
//Post: s'han omplert jugadores i paisos amb les dades del fitxer indicat per teclat i jugadores.vec[0..jugadores.n-1] està ordenat per codi de jugadora i paisos.vec[0..paisos.n-1] està ordenat per nom de país
    productes.mida_vector=0;
    categories.mida_vector=0;
    string nom;
    cout<<"NOM DEL FITXER: ";
    cin>>nom;
    ifstream f_in(nom.c_str());
    if (f_in.is_open()) {
        Producte nou_producte=llegir_producte(f_in);
        while (not f_in.eof() and productes.mida_vector<MAX_PRODUCTES) {
            inserir_producte(productes,nou_producte);
            alta_producte_categoria(categories,nou_producte.categoria,nou_producte.nombre_unitats);
            nou_producte=llegir_producte(f_in);
        }
    }
    else cout<<"FITXER NO OBERT"<<endl;
}




int main (){
    Vector_productes_n productes_caducitat_llarga;
    //Vector_productes_n productes_caducitat_curta;
    Vector_categories_n categories;
    omplir_de_fitxer(productes_caducitat_llarga,categories);
    mostrar_productes(productes_caducitat_llarga);
    return 0;
}