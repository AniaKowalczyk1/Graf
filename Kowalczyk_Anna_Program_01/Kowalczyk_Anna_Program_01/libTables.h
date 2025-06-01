#ifndef LIBTABLES_H
#define LIBTABLES_H
#include <iostream>

using namespace std;

/*
Funkcja tworz�ca tablic�
@param wymiarN - zmienna przechowuj�ca liczb� wierszy
@param wymiarM - zmienna przechowuj�ca liczb� kolumn
@return wska�nik do utoworzonej tablicy
*/
int** f_utworzTablice(int wymiarN, int wymiarM);

/*
Funkcja zwalniaj�ca pami�� i usuwaj�ca tablic�
@param wskTab - wska�nik do tablicy dwuwymiarowej
@param wymiarN - zmienna przechowuj�ca liczb� wierszy
*/
void f_zwolnijTablice(int** wskTab, int wymiarN);

/*
Funkcja wy�wietlaj�ca dwuwymiarow� tablic�
@param tab - wska�nik do tablicy dwuwymiarowej
@param wymiarN - zmienna przechowuj�ca liczb� wierszy
@param wymiarM- zmienna przechowuj�ca liczb� kolumn
*/
void f_wyswietlTablice(int** tab, int wymiarN, int wymiarM);

#endif

