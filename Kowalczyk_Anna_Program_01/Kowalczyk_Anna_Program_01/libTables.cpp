#include "LibTables.h"

int** f_utworzTablice(int wymiarN, int wymiarM)
{
    int** wsk = nullptr; // Inicjalizuje wska�nik na nullptr
    try {
        wsk = new int* [wymiarN];   // Alokacja pami�ci na wska�niki do wierszy
        for (int i = 0; i < wymiarN; i++) {
            wsk[i] = new int[wymiarM] {};   // Alokacja pami�ci dla ka�dego wiersza
        }
    }
    catch (bad_alloc) {
        cerr << "Blad przy utworzeniu"; //komunikat o b��dzie
        exit(0);
    }

    return wsk; //zwracany wska�nik do tablicy
}

void f_zwolnijTablice(int** wskTab, int wymiarN) {
    for (int i = 0; i < wymiarN; i++) {
        delete[] wskTab[i]; // Zwolnienie pami�ci dla ka�dego wiersza
    }
    delete[] wskTab; // Zwolnienie pami�ci dla tablicy wska�nik�w do wierszy
}

void f_wyswietlTablice(int** tab, int wymiarN, int wymiarM)
{
    for (int i = 0; i < wymiarN; i++) {
        for (int j = 0; j < wymiarM; j++) {
            cout << tab[i][j] << " ";  //wypisywanie element�w tablicy
        }
        cout << endl;
    }
}