#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "libFiles.h"
#include "libTables.h"
#include "libFunctions.h"
using namespace std;


int main() {
	ifstream odczyt;
	string nazwaPliku = "dane";
	f_odczytZpliku(odczyt, nazwaPliku);
	// Znajduje maksymalny numer wierzchołka na podstawie wczytanych danych
	int maxNrWierz = f_maxNrWierzchołka(odczyt); 
	odczyt.close();

	ifstream odczyt1;
	f_odczytZpliku(odczyt1, nazwaPliku);
	int iloscKrawedzi;
	odczyt1 >> iloscKrawedzi;
	// Tworzy tablicę dwuwymiarową na podstawie ilości krawędzi i maksymalnego numeru wierzchołka
	int** tablica = f_utworzTablice(iloscKrawedzi, maxNrWierz); 

	// Tworzy macierz kierunkową na podstawie wczytanych danych
	f_utworzMacierzTablicami(odczyt1, tablica, iloscKrawedzi, maxNrWierz);
	// Wyświetla zawartość tablicy dwuwymiarowej
	f_wyswietlTablice(tablica, iloscKrawedzi, maxNrWierz); 
	cout << endl;

	int** tablicaSasiad = f_utworzTablice(maxNrWierz, maxNrWierz); 

	// Znajduje sąsiadów wierzchołków na podstawie macierzy kierunkowej
	f_znajdzSasiada(tablica, tablicaSasiad, iloscKrawedzi, maxNrWierz); 
	f_wypiszSasiada(tablicaSasiad, maxNrWierz); 

	odczyt1.close();
	////////

	ifstream odczytW;
	f_odczytZpliku(odczytW, nazwaPliku);
	odczytW >> iloscKrawedzi;

	// Tworzy wektor wektorów na podstawie ilości krawędzi i maksymalnego numeru wierzchołka
	vector<vector<int>> tablicaWek(iloscKrawedzi, vector<int>(maxNrWierz)); 
	f_utworzMacierzWektorami(odczytW, tablicaWek, iloscKrawedzi, maxNrWierz); 
	cout << endl;

	f_wypiszTabliceVector(tablicaWek); // Wyświetla zawartość tablicy wektorów
	cout << endl;

	vector<vector<int>> tablicaSasiadWektor(maxNrWierz, vector<int>(maxNrWierz)); 

	f_znajdzSasiadaWektor(tablicaWek, tablicaSasiadWektor, iloscKrawedzi, maxNrWierz); 
	f_wypiszSasiadaWektor(tablicaSasiadWektor, maxNrWierz); 

	odczytW.close();

	return 0;
}
