#include "libFunctions.h"

// Funkcja znajduj¹ca maksymalny numer wierzcho³ka w grafie na podstawie danych wczytanych z podanego strumienia odczytu.
int f_maxNrWierzcho³ka(ifstream& odczyt) {
	int iloscKrawedzi;
	int max = 0;
	int sprawdzana;
	odczyt >> iloscKrawedzi; // Odczytujemy liczbê krawêdzi
	odczyt >> max; // Pierwszy numer wierzcho³ka
	for (int i = 1; i < 2 * iloscKrawedzi; i++) {
		// Odczytujemy numer wierzcho³ka
		odczyt >> sprawdzana;
		// Jeœli numer wierzcho³ka jest wiêkszy ni¿ dotychczasowy maksymalny numer, aktualizujemy max
		if (sprawdzana > max) {
			max = sprawdzana;
		}
	}
	return max;
}

// Funkcja tworz¹ca macierz kierunkow¹ za pomoc¹ tablic dynamicznych na podstawie wczytanego pliku.
void f_utworzMacierzTablicami(ifstream& odczyt, int** tab, int iloscKrawedzi, int maxNrWierz) {
	string poczatek;
	string koniec;
	for (int i = 0; i < iloscKrawedzi; i++) {
		odczyt >> poczatek;
		odczyt >> koniec;
		tab[i][stoi(poczatek) - 1] = 1; // Ustawiamy 1 na odpowiedniej pozycji w tablicy dla pocz¹tku krawêdzi
		tab[i][stoi(koniec) - 1] = -1; // Ustawiamy -1 na odpowiedniej pozycji w tablicy dla koñca krawêdzi
	}
}

// Funkcja znajduj¹ca s¹siadów wierzcho³ków w grafie na podstawie macierzy kierunkowej.
void f_znajdzSasiada(int** tab, int** tabs, int iloscKrawedzi, int maxNrWierz) {
	for (int i = 0; i < maxNrWierz; i++) {
		for (int j = 0; j < maxNrWierz; j++) {
			for (int k = 0; k < iloscKrawedzi; k++) {
				if (tab[k][i] == 1 && tab[k][j] == -1) {
					// Dodajemy j jako s¹siada i-tego wierzcho³ka
					tabs[i][j] = j + 1;
					break;
				}
			}
		}
	}
}

// Funkcja wypisuj¹ca s¹siadów wierzcho³ków na podstawie macierzy s¹siedztwa.
void f_wypiszSasiada(int** tabs, int maxNrWierz) {
	for (int i = 0; i < maxNrWierz; i++) {
		cout << i + 1 << ": ";
		for (int j = 0; j < maxNrWierz; j++) {
			if (tabs[i][j] != 0) {
				cout << tabs[i][j] << ", "; // Wypisujemy s¹siada i-tego wierzcho³ka
			}
		}
		cout << endl;
	}
}

// Funkcja tworz¹ca macierz kierunkow¹ za pomoc¹ wektorów na podstawie wczytanego pliku.
void f_utworzMacierzWektorami(ifstream& odczyt, vector<vector<int>>& tab, int iloscKrawedzi, int maxNrWierz) {
	int wierzcholekStartowy, wierzcholekKoncowy;

	for (int i = 0; i < iloscKrawedzi; i++) {
		odczyt >> wierzcholekStartowy >> wierzcholekKoncowy;

		tab[i][wierzcholekStartowy - 1] = 1; // Ustawiamy 1 na odpowiedniej pozycji w tablicy dla pocz¹tku krawêdzi
		tab[i][wierzcholekKoncowy - 1] = -1; // Ustawiamy -1 na odpowiedniej pozycji w tablicy dla koñca krawêdzi
	}
}

// Funkcja znajduj¹ca s¹siadów wierzcho³ków w grafie na podstawie macierzy kierunkowej z wykorzystaniem wektorów.
void f_znajdzSasiadaWektor( vector<vector<int>>& tab, vector<vector<int>>& tabs, int iloscKrawedzi, int maxNrWierz) {
	// Przechodzimy przez wszystkie wierzcho³ki
	for (int i = 0; i < maxNrWierz; i++) {
		// Dla ka¿dego wierzcho³ka sprawdzamy s¹siadów
		for (int j = 0; j < maxNrWierz; j++) {
			// Przechodzimy przez wszystkie krawêdzie
			for (int k = 0; k < iloscKrawedzi; k++) {
				// Jeœli istnieje krawêdŸ od i do j
				if (tab[k][i] == 1 && tab[k][j] == -1) {
					tabs[i][j] = j + 1; // Dodajemy j jako s¹siada i-tego wierzcho³ka
					break;
				}
			}
		}
	}
}

// Funkcja wypisuj¹ca s¹siadów wierzcho³ków na podstawie macierzy s¹siedztwa z wykorzystaniem wektorów.
void f_wypiszSasiadaWektor( vector<vector<int>> tabs, int maxNrWierz) {
	for (int i = 0; i < maxNrWierz; i++) {
		cout << i + 1 << ": ";
		// Dla ka¿dego wierzcho³ka wypisujemy jego s¹siadów
		for (int j = 0; j < maxNrWierz; j++) {
			if (tabs[i][j] != 0) {
				cout << tabs[i][j] << ", "; // Wypisujemy s¹siada i-tego wierzcho³ka
			}
		}
		cout << endl;
	}
}

// Funkcja wypisuj¹ca zawartoœæ tablicy wektorów na standardowe wyjœcie.
void f_wypiszTabliceVector( vector<vector<int>> tablica) {
	for (int i = 0; i < tablica.size(); ++i) { // Przechodzimy przez wszystkie wektory w tablicy
		for (int j = 0; j < tablica[i].size(); ++j) { // Przechodzimy przez wszystkie elementy danego wektora
			cout << tablica[i][j] << " "; // Wypisujemy aktualny element tablicy wektorów
		}
		cout << endl; 
	}
}
