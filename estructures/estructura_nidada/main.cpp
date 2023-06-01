// Concepte : https://www.youtube.com/watch?v=CXKNygkEpU8&list=PLWtYZ2ejMVJlUu1rEHLC0i_oibctkl0Vh&index=58&ab_channel=Programaci%C3%B3nATS
#include <iostream>

using namespace std;

struct info_direccio
{
    char direccio[30];
    char ciutat[20];
    char provincia[20];
};

struct treballador
{
    char nom[20];
    struct info_direccio dir_treballador;
    double salari;
} treballadors[2];

int main()
{
    // Obtenir informació dels treballadors
    for (int i = 0; i < 2; i++)
    {
        fflush(stdin); // Buidar el buffer i permetre obtenir els valors;
        cout << "Introdueix el teu nom: ";
        cin.getline(treballadors[i].nom, 20, '\n');
        cout << "Introdueix la teva direcció: ";
        cin.getline(treballadors[i].dir_treballador.direccio, 30, '\n');
        cout << "Introdueix la teva ciutat: ";
        cin.getline(treballadors[i].dir_treballador.ciutat, 20, '\n');
        cout << "Introdueix la teva provincia: ";
        cin.getline(treballadors[i].dir_treballador.provincia, 20, '\n');
        cout << "Introdueix el teu salari: ";
        cin >> treballadors[i].salari;
        cout << "\n";
    }

    // Mostrar informació
    for (int i = 0; i < 2; i++)
    {
        cout << "Treballador " << i + 1 << endl;
        cout << "-------------------" << endl;
        cout << "Nom: " << treballadors[i].nom << endl;
        cout << "Direcció: " << treballadors[i].dir_treballador.direccio << endl;
        cout << "Ciutat: " << treballadors[i].dir_treballador.ciutat << endl;
        cout << "Provincia: " << treballadors[i].dir_treballador.provincia << endl;
        cout << "Salari: " << treballadors[i].salari << endl;
        cout << "\n";
    }

    return 0;
}
