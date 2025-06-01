#ifndef LIBTABLES_H
#define LIBTABLES_H
#include <iostream>

using namespace std;

/*
Funkcja tworz¹ca tablicê
@param wymiarN - zmienna przechowuj¹ca liczbê wierszy
@param wymiarM - zmienna przechowuj¹ca liczbê kolumn
@return wskaŸnik do utoworzonej tablicy
*/
int** f_utworzTablice(int wymiarN, int wymiarM);

/*
Funkcja zwalniaj¹ca pamiêæ i usuwaj¹ca tablicê
@param wskTab - wskaŸnik do tablicy dwuwymiarowej
@param wymiarN - zmienna przechowuj¹ca liczbê wierszy
*/
void f_zwolnijTablice(int** wskTab, int wymiarN);

/*
Funkcja wyœwietlaj¹ca dwuwymiarow¹ tablicê
@param tab - wskaŸnik do tablicy dwuwymiarowej
@param wymiarN - zmienna przechowuj¹ca liczbê wierszy
@param wymiarM- zmienna przechowuj¹ca liczbê kolumn
*/
void f_wyswietlTablice(int** tab, int wymiarN, int wymiarM);

#endif

