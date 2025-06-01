#include "LibTables.h"

int** f_utworzTablice(int wymiarN, int wymiarM)
{
    int** wsk = nullptr; // Inicjalizuje wskaünik na nullptr
    try {
        wsk = new int* [wymiarN];   // Alokacja pamiÍci na wskaüniki do wierszy
        for (int i = 0; i < wymiarN; i++) {
            wsk[i] = new int[wymiarM] {};   // Alokacja pamiÍci dla kaødego wiersza
        }
    }
    catch (bad_alloc) {
        cerr << "Blad przy utworzeniu"; //komunikat o b≥Ídzie
        exit(0);
    }

    return wsk; //zwracany wskaünik do tablicy
}

void f_zwolnijTablice(int** wskTab, int wymiarN) {
    for (int i = 0; i < wymiarN; i++) {
        delete[] wskTab[i]; // Zwolnienie pamiÍci dla kaødego wiersza
    }
    delete[] wskTab; // Zwolnienie pamiÍci dla tablicy wskaünikÛw do wierszy
}

void f_wyswietlTablice(int** tab, int wymiarN, int wymiarM)
{
    for (int i = 0; i < wymiarN; i++) {
        for (int j = 0; j < wymiarM; j++) {
            cout << tab[i][j] << " ";  //wypisywanie elementÛw tablicy
        }
        cout << endl;
    }
}