#include "libFunctions.h"

// Funkcja znajduj�ca maksymalny numer wierzcho�ka w grafie na podstawie danych wczytanych z podanego strumienia odczytu.
int f_maxNrWierzcho�ka(ifstream& odczyt) {
	int iloscKrawedzi;
	int max = 0;
	int sprawdzana;
	odczyt >> iloscKrawedzi; // Odczytujemy liczb� kraw�dzi
	odczyt >> max; // Pierwszy numer wierzcho�ka
	for (int i = 1; i < 2 * iloscKrawedzi; i++) {
		// Odczytujemy numer wierzcho�ka
		odczyt >> sprawdzana;
		// Je�li numer wierzcho�ka jest wi�kszy ni� dotychczasowy maksymalny numer, aktualizujemy max
		if (sprawdzana > max) {
			max = sprawdzana;
		}
	}
	return max;
}

// Funkcja tworz�ca macierz kierunkow� za pomoc� tablic dynamicznych na podstawie wczytanego pliku.
void f_utworzMacierzTablicami(ifstream& odczyt, int** tab, int iloscKrawedzi, int maxNrWierz) {
	string poczatek;
	string koniec;
	for (int i = 0; i < iloscKrawedzi; i++) {
		odczyt >> poczatek;
		odczyt >> koniec;
		tab[i][stoi(poczatek) - 1] = 1; // Ustawiamy 1 na odpowiedniej pozycji w tablicy dla pocz�tku kraw�dzi
		tab[i][stoi(koniec) - 1] = -1; // Ustawiamy -1 na odpowiedniej pozycji w tablicy dla ko�ca kraw�dzi
	}
}

// Funkcja znajduj�ca s�siad�w wierzcho�k�w w grafie na podstawie macierzy kierunkowej.
void f_znajdzSasiada(int** tab, int** tabs, int iloscKrawedzi, int maxNrWierz) {
	for (int i = 0; i < maxNrWierz; i++) {
		for (int j = 0; j < maxNrWierz; j++) {
			for (int k = 0; k < iloscKrawedzi; k++) {
				if (tab[k][i] == 1 && tab[k][j] == -1) {
					// Dodajemy j jako s�siada i-tego wierzcho�ka
					tabs[i][j] = j + 1;
					break;
				}
			}
		}
	}
}

// Funkcja wypisuj�ca s�siad�w wierzcho�k�w na podstawie macierzy s�siedztwa.
void f_wypiszSasiada(int** tabs, int maxNrWierz) {
	for (int i = 0; i < maxNrWierz; i++) {
		cout << i + 1 << ": ";
		for (int j = 0; j < maxNrWierz; j++) {
			if (tabs[i][j] != 0) {
				cout << tabs[i][j] << ", "; // Wypisujemy s�siada i-tego wierzcho�ka
			}
		}
		cout << endl;
	}
}

// Funkcja tworz�ca macierz kierunkow� za pomoc� wektor�w na podstawie wczytanego pliku.
void f_utworzMacierzWektorami(ifstream& odczyt, vector<vector<int>>& tab, int iloscKrawedzi, int maxNrWierz) {
	int wierzcholekStartowy, wierzcholekKoncowy;

	for (int i = 0; i < iloscKrawedzi; i++) {
		odczyt >> wierzcholekStartowy >> wierzcholekKoncowy;

		tab[i][wierzcholekStartowy - 1] = 1; // Ustawiamy 1 na odpowiedniej pozycji w tablicy dla pocz�tku kraw�dzi
		tab[i][wierzcholekKoncowy - 1] = -1; // Ustawiamy -1 na odpowiedniej pozycji w tablicy dla ko�ca kraw�dzi
	}
}

// Funkcja znajduj�ca s�siad�w wierzcho�k�w w grafie na podstawie macierzy kierunkowej z wykorzystaniem wektor�w.
void f_znajdzSasiadaWektor( vector<vector<int>>& tab, vector<vector<int>>& tabs, int iloscKrawedzi, int maxNrWierz) {
	// Przechodzimy przez wszystkie wierzcho�ki
	for (int i = 0; i < maxNrWierz; i++) {
		// Dla ka�dego wierzcho�ka sprawdzamy s�siad�w
		for (int j = 0; j < maxNrWierz; j++) {
			// Przechodzimy przez wszystkie kraw�dzie
			for (int k = 0; k < iloscKrawedzi; k++) {
				// Je�li istnieje kraw�d� od i do j
				if (tab[k][i] == 1 && tab[k][j] == -1) {
					tabs[i][j] = j + 1; // Dodajemy j jako s�siada i-tego wierzcho�ka
					break;
				}
			}
		}
	}
}

// Funkcja wypisuj�ca s�siad�w wierzcho�k�w na podstawie macierzy s�siedztwa z wykorzystaniem wektor�w.
void f_wypiszSasiadaWektor( vector<vector<int>> tabs, int maxNrWierz) {
	for (int i = 0; i < maxNrWierz; i++) {
		cout << i + 1 << ": ";
		// Dla ka�dego wierzcho�ka wypisujemy jego s�siad�w
		for (int j = 0; j < maxNrWierz; j++) {
			if (tabs[i][j] != 0) {
				cout << tabs[i][j] << ", "; // Wypisujemy s�siada i-tego wierzcho�ka
			}
		}
		cout << endl;
	}
}

// Funkcja wypisuj�ca zawarto�� tablicy wektor�w na standardowe wyj�cie.
void f_wypiszTabliceVector( vector<vector<int>> tablica) {
	for (int i = 0; i < tablica.size(); ++i) { // Przechodzimy przez wszystkie wektory w tablicy
		for (int j = 0; j < tablica[i].size(); ++j) { // Przechodzimy przez wszystkie elementy danego wektora
			cout << tablica[i][j] << " "; // Wypisujemy aktualny element tablicy wektor�w
		}
		cout << endl; 
	}
}
