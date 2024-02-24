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
const int MAX_PRODUCTES=1000;
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

void guardar_data_referencia(Data& data_referencia){
    //Pre: data
    //Post: guarda la data introduida per l'usuari
    cout << "Entra una data (any mes dia):" << endl;
    cin >> data_referencia.any >> data_referencia.mes >> data_referencia.dia;
}

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

void mostrar_producte(Producte producte) {
//Pre: cert
//Post: mostra la informació del producte per pantalla
    cout<<"c:"<<producte.codi<<" - "<<producte.nom<<" ("<<producte.marca<<") - n:"<<producte.nombre_unitats<<", cad:"<<producte.data_caducitat.dia<<"-"<<producte.data_caducitat.mes<<"-"<<producte.data_caducitat.any<<" ["<<producte.categoria<<"]"<<endl;
}

void mostrar_productes(const Vector_productes_n& productes) {
//Pre: cert
//Post: ha mostrat la informació guardada a productes.vector[0..productes.mida_vector-1] per pantalla
    cout<<"Llistat de productes de caducitat curta:"<<endl;
    for (int i=0; i<productes.mida_vector; i++)
        mostrar_producte(productes.vector[i]);
}

void cerca_dicotomica_producte(const Vector_productes_n& productes, string codi, bool& trobat, int& pos) {
//Pre: productes.vector[0..productes.mida_vector-1] ordenat per codi de producte i 0<=N<=MAX_PRODUCTES i 0<=categories.mida_vector<=MAX_CATEGORIES
//Post: trobat és true si a productes.vector[0..productes.mida_vector-1] hi ha un producte amb el codi donat i pos és la posició on es troba; si no hi ha cap producte amb aquest codi, trobat és false i pos és la posició on hauria de ser per mantenir l'ordre de la taula
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
//Pre: productes.mida_vector=N<MAX_PRODUCTES i productes.vector[0..N-1] ordenat per codi de producte
//Post: productes.mida_vector=N+1 i nou_producte s'ha inserit a productes.vector[0..N-1] mantenint l'ordre dels productes
    int i=productes.mida_vector-1;
    while (i>=0 and productes.vector[i].codi>nou_producte.codi){
        productes.vector[i+1]=productes.vector[i];
        i--;
    }
    productes.vector[i+1]=nou_producte;
    productes.mida_vector++;
}

void eliminar_producte(Vector_productes_n& productes,int pos){
    //Pre: productes.mida_vector=N<MAX_PRODUCTES i productes.vector[0..N-1] ordenat per codi de producte
    //Post: productes.mida_vector=N-1 i productes.vector[pos] s'ha eliminat a productes.vector[0..N-1] mantenint l'ordre dels productes
    for (int i=pos;i<productes.mida_vector-1; i++){
        productes.vector[i]=productes.vector[i+1];
    }
    productes.mida_vector--;
}

void alta_producte_categoria(Vector_categories_n& categories, string nova_categoria, int nombre_unitats_producte) {
//Pre: categories.mida_vector=N i 0<=N<=MAX_CATEGORIES i categories[0..N-1] ordenat per categoria
//Post: si nova_categoria no apareixia a categories.vector[0..N-1], la nova_categoria s'hi ha afegit respectant l'ordre alfabètic i categoreis.mida_vector=N+1; en cas contrari, es suma la quantitat de productes de nova_categoria a la categoria existent
    bool trobat;
    int pos;
    cerca_dicotomica_categoria(categories,nova_categoria,trobat,pos);
    if (!trobat) inserir_categoria(categories,nova_categoria,nombre_unitats_producte,pos);
    else categories.vector[pos].unitats_recollides+=nombre_unitats_producte;
}

void actualitzar_unitats_producte(Producte& producte, const Producte producte_repetit){
    //Pre: producte original i producte repetit
    //Post: es suma el nombre d'unitats del producte repetit al producte original
    producte.nombre_unitats+=producte_repetit.nombre_unitats;
}

bool es_caducitat_curta(const Producte producte, const Data data_referencia){
    //Pre: producte i una data de referencia
    //Post: retorna cert si la data del producte és inferior a la data de referencia, altrament retorna fals
    if(producte.data_caducitat.any < data_referencia.any) return true;
    else if(producte.data_caducitat.any == data_referencia.any && producte.data_caducitat.mes < data_referencia.mes) return true;
    else if (producte.data_caducitat.any == data_referencia.any && producte.data_caducitat.mes == data_referencia.mes && producte.data_caducitat.dia < data_referencia.dia) return true;
    return false;
}

bool es_data_diferent(const Producte producte_trobat, const Producte nou_producte ){
    //Pre: producte que es troba dins productes.vector[0...productes.mida_vector] i el nou producte que es vol inserir
    //Post: retorna fals si les dates dels dos productes són iguals, altrament retorna cert
    if(producte_trobat.data_caducitat.any == nou_producte.data_caducitat.any && producte_trobat.data_caducitat.mes == nou_producte.data_caducitat.mes && producte_trobat.data_caducitat.dia == nou_producte.data_caducitat.dia) return false;
    return true;
}

void buscar_producte_repetit(const Vector_productes_n productes, const Producte nou_producte, bool& trobat, int& pos){
    //Pre: vector de productes ordenat alfabeticament, el producte a buscar
    //Post: Retorna cert si es troba el producte dins el vector i les seves dates de caducitat són diferents, altrament retorna fals
    cerca_dicotomica_producte(productes, nou_producte.codi, trobat, pos);
    if(trobat && es_data_diferent(productes.vector[pos], nou_producte)) trobat = false;
}

Producte llegir_producte(ifstream &f_in){
//Pre: f_in obert apunt de llegir
//Post: si després de la 1a lectura no s’activa f_in.eof, es llegix i retorna un producte de fin
  Producte producte;
  f_in>> producte.codi;
  if(not f_in.eof())
      f_in>>producte.nom>>producte.marca>>producte.nombre_unitats>> producte.data_caducitat.any >> producte.data_caducitat.mes >> producte.data_caducitat.dia>>producte.categoria;
  return producte;
}

void guardar_aliments_no_repetits(Vector_productes_n& productes_caducitat_curta, Vector_productes_n& productes_caducitat_llarga, Producte nou_producte, Data data_caducitat_referencia){
    //Pre: llistat dels productes de caducitat curta, llistat dels productes de caducitat llarga, el producte a guardar i la data de referencia
    //Post: insereix el nou producte en un llistat o l'altre depenent de la seva data de caducitat, si el producte no està repetit 
    bool trobat = false;
    int pos;
    if(es_caducitat_curta(nou_producte, data_caducitat_referencia))
    {
        buscar_producte_repetit(productes_caducitat_curta, nou_producte, trobat, pos);
        if(trobat) actualitzar_unitats_producte(productes_caducitat_curta.vector[pos],nou_producte);
        else inserir_producte(productes_caducitat_curta,nou_producte);
    }
    else 
    {
        buscar_producte_repetit(productes_caducitat_llarga, nou_producte, trobat, pos);
        if(trobat) actualitzar_unitats_producte(productes_caducitat_llarga.vector[pos], nou_producte);
        else inserir_producte(productes_caducitat_llarga,nou_producte);
    }
}

void omplir_de_fitxer(Vector_productes_n& productes_caducitat_curta,Vector_productes_n& productes_caducitat_llarga, Vector_categories_n& categories, Data data_caducitat_referencia, bool& fitxer_trobat) {
//Pre: cert
//Post: s'han omplert productes i categories amb les dades del fitxer indicat per teclat i productes.vector[0..productes.mida_vector-1] està ordenat per codi de producte i categories.vector[0..categories.mida_vector-1] està ordenat per categoria
    productes_caducitat_curta.mida_vector=0;
    productes_caducitat_llarga.mida_vector=0;
    categories.mida_vector=0;
    string nom;
    cout<<"Entra el nom del fitxer:" << endl;
    cin>>nom;
    ifstream f_in(nom.c_str());
    if (f_in.is_open()) {
        fitxer_trobat = true;
        Producte nou_producte=llegir_producte(f_in);
        while (not f_in.eof() and productes_caducitat_curta.mida_vector<MAX_PRODUCTES) {
            guardar_aliments_no_repetits(productes_caducitat_curta,productes_caducitat_llarga,nou_producte,data_caducitat_referencia);
            alta_producte_categoria(categories,nou_producte.categoria,nou_producte.nombre_unitats);
            nou_producte=llegir_producte(f_in);
        }
    }
    else cout<<"Fitxer no trobat";
}

void intercanvi_posicions_aliments(Producte& producte_1, Producte& producte_2){
    //Pre: producte_1 i producte_2
    //Post: guarda el valor de producte_1 a producte_2 i el de producte_2 a producte_1
    Producte aux = producte_1;
    producte_1 = producte_2;
    producte_2 = aux;
}

void ordenar_productes_per_nom(Vector_productes_n& productes){
    //Pre: llistat de productes ordenats per codi
    //Post: ordena el llistat alfabeticament per nom; si aquest és el mateix s'ordena per marca; i en cas que aquest també sigui el mateix s'ordenarà per data
    for (int i = 0; i < productes.mida_vector; i++)
    {
        for (int j = 1; j < productes.mida_vector; j++)
        {
            if(productes.vector[i].nom > productes.vector[j].nom) intercanvi_posicions_aliments(productes.vector[i], productes.vector[j]);
            else if (productes.vector[i].nom == productes.vector[j].nom && productes.vector[i].marca > productes.vector[j].marca) intercanvi_posicions_aliments(productes.vector[i], productes.vector[j]);
            else if (productes.vector[i].nom == productes.vector[j].nom && productes.vector[i].marca == productes.vector[j].marca && !es_caducitat_curta(productes.vector[i],productes.vector[j].data_caducitat)) intercanvi_posicions_aliments(productes.vector[i], productes.vector[j]);
        }
    }
}

void ordenar_productes_per_data(Vector_productes_n& productes){
    //Pre: llistat de productes ordenats per codi
    //Post: ordena el llistat alfabeticament per data; si aquest és el mateix s'ordena per nom; i en cas que aquest també sigui el mateix s'ordenarà per marca
    for (int i = 0; i < productes.mida_vector; i++)
    {
        for (int j = 1; j < productes.mida_vector; j++)
        {
            if(!es_caducitat_curta(productes.vector[i], productes.vector[j].data_caducitat)) intercanvi_posicions_aliments(productes.vector[i], productes.vector[j]);
            else if (!es_data_diferent(productes.vector[i],productes.vector[j]) && productes.vector[i].nom > productes.vector[j].nom) intercanvi_posicions_aliments(productes.vector[i], productes.vector[j]);
            else if (!es_data_diferent(productes.vector[i],productes.vector[j]) && productes.vector[i].nom == productes.vector[j].nom && productes.vector[i].marca > productes.vector[j].marca) intercanvi_posicions_aliments(productes.vector[i], productes.vector[j]);
        }
    }
}

void comprovar_comanda(Vector_categories_n categories, string nom_categoria, int quantitat_comanda){
    //Pre: llistat de categories i comanda a realitzar
    //Post: si la categoria de la comanda es troba dins del llistat i la quanitat de la comanda es < que el nombre d'unitats d'aquella categoria, es pot satisfer la comanda, altrament no es podrà satisfer
    bool trobat = false;
    int pos;
    cerca_dicotomica_categoria(categories,nom_categoria,trobat,pos);
    if(trobat)
    {
        if(categories.vector[pos].unitats_recollides >= quantitat_comanda) cout << "-- Es pot satisfer --"<<endl;
        else cout << "-- No es pot satisfer --"<<endl;
    }
}

void actualitzar_llistes_aliments(Vector_productes_n& productes_caducitat_curta, Vector_productes_n& productes_caducitat_llarga, const Data nova_data_referencia){
    //Pre: llistat de productes de caducitat llarga, llistat de productes de caducitat curta i la nova data de caducitat
    //Post: els productes de caducitat llarga que tinguin una data < que nova_data_referencia es guardaran al llistat de productes de caducitat curta i s'elimina de l'anterior
    for (int i = 0; i < productes_caducitat_llarga.mida_vector; i++)
    {
        if(es_caducitat_curta(productes_caducitat_llarga.vector[i],nova_data_referencia)) 
        {
            inserir_producte(productes_caducitat_curta,productes_caducitat_llarga.vector[i]);
            eliminar_producte(productes_caducitat_llarga,i);
        }
    }
}

void menu() {
//Pre: cert
//Post: mostra les opcions que té l'usuari
    cout<<"OPCIONS:"<<endl;
    cout<<"N -> Ordenar per nom"<<endl;
    cout<<"D -> Ordenar per data"<<endl;
    cout<<"A -> Actualitzar"<<endl;
    cout<<"C -> Comanda"<<endl;
    cout<<"M -> Menu"<<endl;
    cout<<"S -> Sortir"<<endl;
}

char llegir_opcio() {
//Pre: cert
//Post: retorna el caràcter llegit de teclat
    char opcio;
    cout<<"Opcio:"<<endl;
    cin>>opcio;
    return opcio;
}

int main (){
    Data data_referencia;
    Vector_productes_n productes_caducitat_llarga;
    Vector_productes_n productes_caducitat_curta;
    Vector_categories_n categories;
    guardar_data_referencia(data_referencia);
    bool fitxer_trobat = false;
    omplir_de_fitxer(productes_caducitat_curta,productes_caducitat_llarga,categories,data_referencia, fitxer_trobat);
    if(fitxer_trobat){
        menu();
        char opcio=llegir_opcio();
        while(opcio!='S') {
            if(opcio=='N') 
            {
                ordenar_productes_per_nom(productes_caducitat_curta);
                mostrar_productes(productes_caducitat_curta);
            }
            else if (opcio=='D')
            {
                ordenar_productes_per_data(productes_caducitat_curta);
                mostrar_productes(productes_caducitat_curta);
            }
            else if (opcio=='A') 
            {
                cout << "Entra la nova data (any mes dia)"<<endl;
                Data nova_data_referencia;
                cin >> nova_data_referencia.any >> nova_data_referencia.mes >> nova_data_referencia.dia;
                actualitzar_llistes_aliments(productes_caducitat_curta, productes_caducitat_llarga, nova_data_referencia);
            }
            else if (opcio=='C')
            {
                cout << "Categoria:" << endl;
                string nom_categoria;
                cin >> nom_categoria;
                cout << "Quantitat:" <<endl;
                int quantitat_comanda;
                cin >> quantitat_comanda;
                comprovar_comanda(categories,nom_categoria,quantitat_comanda);
            }
            else if (opcio=='M') menu();
            opcio=llegir_opcio();
        }
    }
    else cout << "Fitxer no trobat";
    return 0;
}