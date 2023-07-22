/**
* \file GUI.h
* Plik nag³owkowy modu³u GUI 
*
*/

#ifndef GUI_H
#define GUI_H
#include "logika.h"
/*
* \brief  funkcja drukuje liste towarow
* \param w zmienna wskaznikowa do glowy listy towarow
*/
void przegladaj_towar(Czesc* w);
/*
* \brief funkcja drukuje liste klientow
* \param w zmienna wskaznikowa do glowy listy klientow
*/
void przegl¹daj_klientow(Klient* w);
/*
* \brief funkcja odpowiedzialna za komunikacje program-uzytkownik
* \param headC,tailC,headK,tailK to odpowiednio zmienne wskaznikowe do glowy listy towarow, ogona listy towarow, glowy listy klientow, ogona listy klientow, zmienne bool CzyCzesciistnieja i CzyKlienciistnieja zawieraja informacje, czy listy zostaly juz stworzone(zabezpieczenie przed utrata pamieci)
*/
void obsluga_uzytkownika(Czesc*& headC, Czesc*& tailC, Klient *&headK, Klient *&tailK, bool CzyCzesciistnieja, bool CzyKlienciistnieja);
#endif