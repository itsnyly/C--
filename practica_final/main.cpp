#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#pragma region StructActivitat
struct Activitat{
    string nom;
    double percentatge;
};
const int MAX_ACTIVITATS = 1000;
typedef Activitat Vec_act[MAX_ACTIVITATS];
struct Vector_activitats_n{
    Vec_act vec;
    int n;
};
#pragma endregion StructActivitat
#pragma region StructEstabliment
struct Establiment{
    string nif;
    string nom;
    string barri;
    double superficie;
    int dia;
    int mes;
    int any;
    string nom_activitat;
    char solvencia;
};
const int MAX_ESTABLIMENTS = 1000;
typedef Establiment Vec_est[MAX_ESTABLIMENTS];
struct Vector_establiments_n{
    Vec_est vec;
    int n;
};
#pragma endregion StructEstabliment
#pragma region Funcionaments
Activitat llegir_activitat(ifstream &f_in){
    Activitat act;
    f_in >> act.nom;
    if(not f_in.eof())
        f_in >> act.percentatge;
    return act;

};
Establiment llegir_establiment(ifstream &f_in){
    Establiment estab;
    bool solvencia;
    f_in >> estab.nif;
    if(not f_in.eof())
        f_in >> estab.nom >>estab.barri >> estab.superficie >> estab.dia >> 
        estab.mes >> estab.any >> estab.nom_activitat >> estab.solvencia;
    return estab;
};
void mostrar_missatge_error(string missatge){
    cout<<"<< ERROR: "<<missatge<<" >>" <<endl;
};
void inserir_activitat(Vector_activitats_n& activitats, Activitat nova_activitat){
    int i= activitats.n-1;
    while(i>=0 and activitats.vec[i].nom>nova_activitat.nom){
        activitats.vec[i+1]=activitats.vec[i];
        i--;
    }
    activitats.vec[i+1]=nova_activitat;
    activitats.n++;
};
void inserir_establiment(Vector_establiments_n& establiments, Establiment nou_estbliment){
    int i= establiments.n-1;
    while(i>=0 and establiments.vec[i].nif>nou_estbliment.nif){
        establiments.vec[i+1]=establiments.vec[i];
        i--;
    }
    establiments.vec[i+1]=nou_estbliment;
    establiments.n++;
};
void llegir_info_fitxer_activitat(Vector_activitats_n& activitats, ifstream& f_in){
    Activitat nova_activitat=llegir_activitat(f_in);
        while(not f_in.eof()){
            inserir_activitat(activitats, nova_activitat);
            nova_activitat=llegir_activitat(f_in);
        }
};
void llegir_info_fitxer_establiment(Vector_establiments_n& establiments, ifstream& f_in){
    Establiment nou_establiment=llegir_establiment(f_in);
        while(not f_in.eof()){
            inserir_establiment(establiments, nou_establiment);
            nou_establiment=llegir_establiment(f_in);
        }
};
void mostrar_titol(const string& titol){
    cout << setw(20) << setfill('_') << "_" << " "
         << setw(32) << setfill(' ') << left << titol << " "
         << setw(20) << setfill('_') << "_" << endl << endl;
};
void omplir_de_fitxer_activitats(Vector_activitats_n& activitats){
    activitats.n=0;
    string nom;
    cout<<"NOM DEL FITXER AMB ACTIVITATS EXISTENTS: ";
    cin>>nom;
    ifstream f_in(nom.c_str());
    if(f_in.is_open()){
        llegir_info_fitxer_activitat(activitats,f_in);
    }
    else{
        mostrar_missatge_error("EL FITXER NO S'HA POGUT OBRIR");
        cout<<"INTRODUEIX UN ALTRE NOM DE FITXER: ";
        cin>>nom;
        ifstream f_in(nom.c_str());
        llegir_info_fitxer_activitat(activitats,f_in);
    }
    mostrar_titol("FI PROCESSAMENT FITXER");

};
void omplir_de_fitxer_establiments(Vector_establiments_n& establiments){
    establiments.n=0;
    string nom;
    cout<<"NOM DEL FITXER AMB ESTABLIMENTS EXISTENTS: ";
    cin>>nom;
    ifstream f_in(nom.c_str());
    if(f_in.is_open()){
        llegir_info_fitxer_establiment(establiments,f_in);
    }
    else{
        mostrar_missatge_error("EL FITXER NO S'HA POGUT OBRIR");
        cout<<"INTRODUEIX UN ALTRE NOM DE FITXER: ";
        cin>>nom;
        ifstream f_in(nom.c_str());
        llegir_info_fitxer_establiment(establiments,f_in);
    }
    mostrar_titol("FI PROCESSAMENT FITXER");

};
void mostrar_activitat(Activitat activitat){
    cout << left << setfill(' ');
    cout << setw(20) << activitat.nom << " " << setw(6) <<right<< activitat.percentatge << " %  " << endl; 
};
void mostrar_establiment(Establiment establiment){
    cout << left << setfill(' ');
    cout << setw(10) << establiment.nif << " " << setw(20) << establiment.nom << " "
    << setw(15) << establiment.barri << " " <<setw(8) << right << establiment.superficie << " m2 " 
    << setw(2) << setfill('0') << establiment.dia <<"/" <<setw(2) <<establiment.mes << "/" << setw(4)
    << establiment.any <<"  " << setw(20) <<left << setfill(' ') << establiment.nom_activitat << " ";
    cout << establiment.solvencia;
    cout << endl;

};
void mostrar_informacio_activitats(const Vector_activitats_n activitats){
    mostrar_titol("ACTIVITATS");
    for (int i = 0; i < activitats.n; i++)
    {
        mostrar_activitat(activitats.vec[i]);
    }
    mostrar_titol("");
};
void mostrar_informacio_establiments(const Vector_establiments_n establiments){
    mostrar_titol("ESTABLIMENTS");
    for (int i = 0; i < establiments.n; i++)
    {
        mostrar_establiment(establiments.vec[i]);
    }
    mostrar_titol("");
};
void mostrar_menu_ajuda(){
    mostrar_titol("MENU");
    cout << "a: ALTA ESTABLIMENT O ACTIVITAT" << endl;
    cout << "b: BAIXA ESTABLIMENT" << endl;
    cout << "m: MODIFICAR ESTABLIMENT" << endl;
    cout << "c: CONSULTAR ESTABLIMENT" << endl;
    cout << "p: MOSTRAR ESTABLIMENTS O ACTIVITATS" << endl;
    cout << "o: MOSTRAR ESTABLIMENTS ORDENATS" << endl;
    cout << "n: NETEJAR ACTIVITATS" << endl;
    cout << "f: FILTRAR INSOLVENTS A FITXER" << endl;
    cout << "v: COMPROVAR SOLVENCIA PER BARRI I ACTIVITAT" << endl;
    cout << "i: TOP BARRIS IMPOSTOS" << endl;
    cout << "h: AJUDA" << endl;
    cout << "s: SORTIR" << endl;
    mostrar_titol("");
};
void mostrar_menu_modificar_establiment(){
    cout<<"CAMP A MODIFICAR (n: NOM, d: DATA D'OBERTURA, a: ACTIVITAT, s: SOLVENCIA): ";
};
void cerca_activitat(const Vector_activitats_n activitats, string nom_activitat, bool& trobat, int& pos){
    int esq=0, dret=activitats.n-1, mig;
    trobat = false;
    while (not trobat and esq<=dret)
    {
        mig=(esq+dret)/2;
        if(activitats.vec[mig].nom == nom_activitat) trobat = true;
        else if(activitats.vec[mig].nom<nom_activitat) esq=mig+1;
        else dret=mig-1;
    }
    if(trobat) pos=mig;
    else pos=esq; 
}
void cerca_establiment(const Vector_establiments_n establiments, string nif_establiment, bool& trobat, int& pos){
    int esq=0, dret=establiments.n-1, mig;
    trobat = false;
    while (not trobat and esq<=dret)
    {
        mig=(esq+dret)/2;
        if(establiments.vec[mig].nif == nif_establiment) trobat = true;
        else if(establiments.vec[mig].nif<nif_establiment) esq=mig+1;
        else dret=mig-1;
    }
    if(trobat) pos=mig;
    else pos=esq; 
}
void modificar_activitat(Vector_activitats_n& activitats, int& pos, double nou_percentatge){
    activitats.vec[pos].percentatge = nou_percentatge;
};
void donar_alta_activitat(Vector_activitats_n activitats){
    Activitat nova_activitat;
    bool trobat;
    int pos;
    cout << "NOM I PERCENTATGE APLICAT AL VALOR DELS ESTABLIMENTS:" << endl;
    cin >> nova_activitat.nom >> nova_activitat.percentatge;
    cerca_activitat(activitats,nova_activitat.nom,trobat,pos);
    if(trobat) modificar_activitat(activitats,pos,nova_activitat.percentatge);
    else inserir_activitat(activitats,nova_activitat);
    mostrar_titol("ACTIVITAT DONADA D'ALTA");
    mostrar_activitat(nova_activitat);
};
void donar_alta_establiment(Vector_establiments_n& establiments, Vector_activitats_n activitats){
    Establiment nou_establiment;
    bool trobat_establiment;
    int pos;
    cout << "NIF, NOM, BARRI, SUPERFICIE, DATA D'OBERTURA, ACTIVITAT I SOLVENCIA:" << endl;
    cin >> nou_establiment.nif >> nou_establiment.nom >> nou_establiment.barri >> nou_establiment.superficie >> nou_establiment.dia >> nou_establiment.mes
    >> nou_establiment.any >> nou_establiment.nom_activitat >> nou_establiment.solvencia;
    cerca_establiment(establiments,nou_establiment.nif,trobat_establiment,pos);
    if(trobat_establiment) mostrar_missatge_error("JA EXISTEIX UN ESTABLIMENT AMB AQUEST NIF");
    else {
        bool trobat_activitat;
        int pos_activitat;
        cerca_activitat(activitats,nou_establiment.nom_activitat,trobat_activitat, pos_activitat);
        if(trobat_activitat){
            inserir_establiment(establiments,nou_establiment);
            mostrar_titol("ESTABLIMENT DONAT D'ALTA");
            mostrar_establiment(nou_establiment);
            mostrar_informacio_establiments(establiments);
        }
        else mostrar_missatge_error("NO S'HA TROBAT L'ACTIVITAT D'AQUEST ESTABLIMENT");
    }
   
};
void donar_alta(Vector_activitats_n activitats, Vector_establiments_n& establiments){
    cout << "ESCOLLIR GRUP (e: ESTABLIMENTS, a: ACTIVITATS): ";
    char opcio;
    cin >> opcio;
    while (opcio != 'e' && opcio != 'a')
    {
        cout << "ESCOLLIR GRUP (e: ESTABLIMENTS, a: ACTIVITATS): ";
        cin >> opcio;
    };
    if(opcio == 'e') donar_alta_establiment(establiments,activitats);
    else donar_alta_activitat(activitats);
};
void eliminar_element_mantenint_ordre(Vector_establiments_n& establiments,int& n, int pos){
    for (int i = pos+1; i < n; i++)
    {
        establiments.vec[i-1] = establiments.vec[i];
    };
    n--;
};
void donar_baixa_establiment(Vector_establiments_n& establiments, Vector_activitats_n activitats, int pos ){
    Establiment establiment_baixa;
    establiment_baixa = establiments.vec[pos];
    eliminar_element_mantenint_ordre(establiments,establiments.n, pos-1);
    // TO-DO : Actualitzar vector activitats
    mostrar_titol("ESTABLIMENT DONAT DE BAIXA");
    mostrar_establiment(establiment_baixa);
    mostrar_informacio_establiments(establiments);
};
void donar_baixa(Vector_establiments_n& establiments, Vector_activitats_n activitats){
    string nif_establiment_baixa;
    cout <<"NIF DE L'ESTABLIMENT: ";
    cin >> nif_establiment_baixa;
    bool trobat;
    int pos;
    cerca_establiment(establiments,nif_establiment_baixa,trobat,pos);
    if(trobat) donar_baixa_establiment(establiments,activitats,pos);
    else mostrar_missatge_error("NO S'HA TROBAT L'ESTABLIMENT");
};
void modificar_camp_establiment(Vector_establiments_n& establiments, Vector_activitats_n activitats, int pos, char opcio){
    string nou_nom;
    int nou_dia;
    int nou_mes;
    int nou_any;
    string nova_activitat;
    bool trobat;
    int pos_activitat;
    switch (opcio)
    {
    case 'n':
        cout << "NOU NOM: ";
        cin>>nou_nom;
        establiments.vec[pos].nom = nou_nom;
        break;
    case 'd':
        cout << "NOVA DATA D'OBERTURA: ";
        cin>>nou_dia>>nou_mes>>nou_any;
        establiments.vec[pos].dia = nou_dia;
        establiments.vec[pos].mes = nou_mes;
        establiments.vec[pos].any = nou_any;
        break;
    case 'a':
        cout << "NOVA ACTIVITAT: ";
        cin>>nova_activitat;
        cerca_activitat(activitats,nova_activitat,trobat,pos_activitat);
        if(trobat) establiments.vec[pos].nom_activitat = nova_activitat;
        else mostrar_missatge_error("NO S'HA TROBAT L'ACTIVITAT");
        break;
    case 's':
        if (establiments.vec[pos].solvencia == 'S') establiments.vec[pos].solvencia= 'N';
        else establiments.vec[pos].solvencia = 'S';
        break;
    default:
        break;
    }
};
void modificar_establiment(Vector_establiments_n& establiments, Vector_activitats_n activitats, int pos){
    mostrar_titol("INFORMACIO DE L'ESTABLIMENT");
    Establiment establiment;
    establiment = establiments.vec[pos];
    mostrar_establiment(establiment);
    char opcio;
    mostrar_menu_modificar_establiment();
    cin>>opcio;
    while (opcio != 'n' && opcio != 'd' && opcio != 'a' && opcio !='s')
    {
        mostrar_menu_modificar_establiment();
        cin>>opcio;
    }
    modificar_camp_establiment(establiments,activitats,pos,opcio);
    mostrar_titol("ESTABLIMENT MODIFICAT");
    mostrar_establiment(establiments.vec[pos]);
};
void modificar(Vector_establiments_n& establiments, Vector_activitats_n activitats){
    string nif_establiment;
    cout <<"NIF DE L'ESTABLIMENT: ";
    cin >> nif_establiment;
    bool trobat;
    int pos;
    cerca_establiment(establiments,nif_establiment,trobat,pos);
    if(trobat) modificar_establiment(establiments,activitats,pos);
    else mostrar_missatge_error("NO S'HA TROBAT L'ESTABLIMENT");
};
void mostrar_establiments_activitats(Vector_establiments_n establiments, Vector_activitats_n activitats){
    cout << "ESCOLLIR GRUP (e: ESTABLIMENTS, a: ACTIVITATS): ";
    char opcio;
    cin >> opcio;
    while (opcio != 'e' && opcio != 'a')
    {
        cout<< "ESCOLLIR GRUP (e: ESTABLIMENTS, a: ACTIVITATS): ";
        cin>> opcio;
    }
    if(opcio == 'e') mostrar_informacio_establiments(establiments);
    else mostrar_establiments_activitats(establiments,activitats);
    
};

void consultar_establiment(Vector_establiments_n establiments){
    cout << "NIF DE L'ESTABLIMENT: ";
    string nif;
    cin >> nif;
    bool trobat;
    int pos;
    cerca_establiment(establiments,nif, trobat, pos);
    if(trobat) {
        mostrar_titol("ESTABLIMENT");
        mostrar_establiment(establiments.vec[pos]);
        mostrar_titol("");
    }
    else mostrar_missatge_error("NO S'HA TROBAT L'ESTABLIMENT");
};

void menu(Vector_activitats_n activitats, Vector_establiments_n establiments){
    cout << "OPCIO (h: AJUDA): ";
    char opcio;
    cin >> opcio;
    while (opcio!='s')
    {
        switch (opcio)
        {
        case 'a':
            donar_alta(activitats, establiments);
            break;
        case 'b':
            donar_baixa(establiments,activitats);
            break;
        case 'm':
            modificar(establiments,activitats);
            break;
        case 'c':
            consultar_establiment(establiments);
            break;
        case 'p':
            mostrar_establiments_activitats(establiments, activitats);
            break;
        case 'o':
            mostrar_menu_ajuda();
            break;
        case 'n':
            mostrar_menu_ajuda();
            break;
        case 'f':
            mostrar_menu_ajuda();
            break;
        case 'v':
            mostrar_menu_ajuda();
            break;
        case 'i':
            mostrar_menu_ajuda();
            break;
        case 'h':
            mostrar_menu_ajuda();
            break;
        default:
            cout << "OPCIÓ NO VÀLIDA" << endl;
            break;
        }
        cout << "OPCIO (h: AJUDA): ";
        cin >> opcio;
    }
    
};

#pragma endregion Funcionaments
int main(){
    Vector_activitats_n activitats;
    Vector_establiments_n establiments;
    omplir_de_fitxer_activitats(activitats);
    mostrar_informacio_activitats(activitats);
    omplir_de_fitxer_establiments(establiments);
    mostrar_informacio_establiments(establiments);
    menu(activitats,establiments);
    return 0;
}