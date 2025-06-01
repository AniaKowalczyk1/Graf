#ifndef LIBFUNCTIONS_H
#define LIBFUNCTIONS_H
#include <iostream>
#include <fstream>
#include <random>
#include <string>
using namespace std;

/*
Funkcja znajduj¹ca maksymalny numer wierzcho³ka w grafie na podstawie danych wczytanych z podanego strumienia odczytu.
@param odczyt - referencj¹ do obiektu strumienia wejœciowego
@return maksymalny numer wierzcho³ka w grafie
*/
int f_maxNrWierzcho³ka(ifstream& odczyt);

/*
Funkcja tworz¹ca macierz kierunkow¹ za pomoc¹ tablic dynamicznych na podstawie wczytanego pliku.
@param odczyt - referencj¹ do obiektu strumienia wejœciowego
@param tab - tablica incydencji
@param iloscKrawedzi - liczba krawedzi 
@param maxNrWierz -  maksymalny numer wierzcho³ka w grafie
*/
void f_utworzMacierzTablicami(ifstream& odczyt, int** tab, int iloscKrawedzi, int maxNrWierz);

/*
Funkcja znajduj¹ca s¹siadów wierzcho³ków w grafie na podstawie macierzy kierunkowej.
@param tab - tablica incydencji
@param tabs - tablica s¹siadów
@param iloscKrawedzi - liczba krawedzi
@param maxNrWierz -  maksymalny numer wierzcho³ka w grafie
*/
void f_znajdzSasiada(int** tab, int** tabs, int iloscKrawedzi, int maxNrWierz);

/*
Funkcja wypisuj¹ca s¹siadów wierzcho³ków na podstawie macierzy s¹siedztwa.
@param tabs - tablica s¹siadów
@param maxNrWierz -  maksymalny numer wierzcho³ka w grafie
*/
void f_wypiszSasiada(int** tabs, int maxNrWierz);


/*
Funkcja tworz¹ca macierz kierunkow¹ za pomoc¹ wektorów na podstawie wczytanego pliku.
@param odczyt - referencj¹ do obiektu strumienia wejœciowego
@param tab - tablica incydencji
@param iloscKrawedzi - liczba krawedzi
@param maxNrWierz -  maksymalny numer wierzcho³ka w grafie
*/
void f_utworzMacierzWektorami(ifstream& odczyt, vector<vector<int>>& tab, int iloscKrawedzi, int maxNrWierz);

/*
Funkcja znajduj¹ca s¹siadów wierzcho³ków w grafie na podstawie macierzy kierunkowej z wykorzystaniem wektorów.
@param tab - tablica incydencji
@param tabs - tablica s¹siadów
@param iloscKrawedzi - liczba krawedzi
@param maxNrWierz -  maksymalny numer wierzcho³ka w grafie
*/
void f_znajdzSasiadaWektor( vector<vector<int>>& tab, vector<vector<int>>& tabs, int iloscKrawedzi, int maxNrWierz);

/*
Funkcja wypisuj¹ca s¹siadów wierzcho³ków na podstawie macierzy s¹siedztwa z wykorzystaniem wektorów.
@param tabs - tablica s¹siadów
@param maxNrWierz -  maksymalny numer wierzcho³ka w grafie
*/
void f_wypiszSasiadaWektor( vector<vector<int>> tabs, int maxNrWierz);

/*
Funkcja wypisuj¹ca tablice incydencji
@param tablica - tablica s¹siadów
*/
void f_wypiszTabliceVector( vector<vector<int>> tablica);

#endif


