#ifndef LIBFUNCTIONS_H
#define LIBFUNCTIONS_H
#include <iostream>
#include <fstream>
#include <random>
#include <string>
using namespace std;

/*
Funkcja znajduj�ca maksymalny numer wierzcho�ka w grafie na podstawie danych wczytanych z podanego strumienia odczytu.
@param odczyt - referencj� do obiektu strumienia wej�ciowego
@return maksymalny numer wierzcho�ka w grafie
*/
int f_maxNrWierzcho�ka(ifstream& odczyt);

/*
Funkcja tworz�ca macierz kierunkow� za pomoc� tablic dynamicznych na podstawie wczytanego pliku.
@param odczyt - referencj� do obiektu strumienia wej�ciowego
@param tab - tablica incydencji
@param iloscKrawedzi - liczba krawedzi 
@param maxNrWierz -  maksymalny numer wierzcho�ka w grafie
*/
void f_utworzMacierzTablicami(ifstream& odczyt, int** tab, int iloscKrawedzi, int maxNrWierz);

/*
Funkcja znajduj�ca s�siad�w wierzcho�k�w w grafie na podstawie macierzy kierunkowej.
@param tab - tablica incydencji
@param tabs - tablica s�siad�w
@param iloscKrawedzi - liczba krawedzi
@param maxNrWierz -  maksymalny numer wierzcho�ka w grafie
*/
void f_znajdzSasiada(int** tab, int** tabs, int iloscKrawedzi, int maxNrWierz);

/*
Funkcja wypisuj�ca s�siad�w wierzcho�k�w na podstawie macierzy s�siedztwa.
@param tabs - tablica s�siad�w
@param maxNrWierz -  maksymalny numer wierzcho�ka w grafie
*/
void f_wypiszSasiada(int** tabs, int maxNrWierz);


/*
Funkcja tworz�ca macierz kierunkow� za pomoc� wektor�w na podstawie wczytanego pliku.
@param odczyt - referencj� do obiektu strumienia wej�ciowego
@param tab - tablica incydencji
@param iloscKrawedzi - liczba krawedzi
@param maxNrWierz -  maksymalny numer wierzcho�ka w grafie
*/
void f_utworzMacierzWektorami(ifstream& odczyt, vector<vector<int>>& tab, int iloscKrawedzi, int maxNrWierz);

/*
Funkcja znajduj�ca s�siad�w wierzcho�k�w w grafie na podstawie macierzy kierunkowej z wykorzystaniem wektor�w.
@param tab - tablica incydencji
@param tabs - tablica s�siad�w
@param iloscKrawedzi - liczba krawedzi
@param maxNrWierz -  maksymalny numer wierzcho�ka w grafie
*/
void f_znajdzSasiadaWektor( vector<vector<int>>& tab, vector<vector<int>>& tabs, int iloscKrawedzi, int maxNrWierz);

/*
Funkcja wypisuj�ca s�siad�w wierzcho�k�w na podstawie macierzy s�siedztwa z wykorzystaniem wektor�w.
@param tabs - tablica s�siad�w
@param maxNrWierz -  maksymalny numer wierzcho�ka w grafie
*/
void f_wypiszSasiadaWektor( vector<vector<int>> tabs, int maxNrWierz);

/*
Funkcja wypisuj�ca tablice incydencji
@param tablica - tablica s�siad�w
*/
void f_wypiszTabliceVector( vector<vector<int>> tablica);

#endif


