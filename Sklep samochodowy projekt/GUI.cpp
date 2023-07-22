/**
* \file GUI.cpp
* Plik implementacji modu³u GUI
*/

#include<iostream>
#include"GUI.h"
#include "logika.h"
using std::cout;
using std::cin;
using std::string;
using std::endl;
string marka,imie,  nazwa, producent;
int cena, nrNAD, naleznosc;
int WPR;
string wprowadzenie;

void przegladaj_towar(Czesc* w)
{
	cout << "Lista towarow: \n";
	while (w!=0)
	{
		cout << "ID: " << w->id<<"\n Marka: "<<w->marka<<"\n Nazwa: "<<w->nazwa<<"\n Producent czesci: "<<w->producent<<"\n Cena: "<<w->cena<<"zl\n\n";
		w = w->next;
	}
}
void przegl¹daj_klientow(Klient* w)
{
	cout << "Lista klientow: \n";
	while (w!=0)
	{
		cout << "Imie klienta: " << w->imie << "\n Nr. Nadwozia: " << w->numer_nadwozia << "\n Marka pojazdu: " << w->markaCzesci << "\n Nazwa czesci: " << w->nazwaCzesci << "\n Naleznosc: " << w->DoZaplaty << "zl\n\n";
		w = w->next;
	}
}
void obsluga_uzytkownika(Czesc*& headC, Czesc*& tailC, Klient*& headK, Klient*& tailK, bool CzyCzesciistnieja, bool CzyKlienciistnieja)
{

	
	cout << "1.Otworz liste towarow\n2.Stworz liste towarow\n3.Dodaj element do asortymentu\n4.Usun element z asortymentu\n5.Otworz liste klientow\n6.Stworz liste klientow\n7.Dodaj klienta\n8.Usun klienta\n \n 0.Wyjdz z programu"<<endl;
	cin >> wprowadzenie;

	if (wprowadzenie == "1") {
		przegladaj_towar(headC);
		cout << "\n\n Nacisnij 0 zeby wrocic do menu glownego.\n";
		cin >> WPR;
		if (WPR == 0)
			obsluga_uzytkownika(headC, tailC, headK, tailK, CzyCzesciistnieja, CzyKlienciistnieja);
	}
	if (wprowadzenie == "2") {

		if (CzyCzesciistnieja == 1) {
			cout << "Lista zostala juz utworzona!\n\n";
			obsluga_uzytkownika(headC, tailC, headK, tailK, CzyCzesciistnieja, CzyKlienciistnieja);
		}
		cout << "Podaj dane:\n";
		cout << "Marka: ";
		cin >> marka;
		cout << "\nNazwa: ";
		cin >> nazwa;
		cout << "\nProducent: ";
		cin >> producent;
		cout << "\nCena: ";
		cin>> cena;
		stworzListe(headC, marka, nazwa, producent, cena, CzyCzesciistnieja);
		cout << "Lista czesci stworzona!\n\n";
		obsluga_uzytkownika(headC, tailC, headK, tailK, CzyCzesciistnieja, CzyKlienciistnieja);
	}
	if (wprowadzenie == "3") {

		cout << "Podaj dane:\n";
		cout << "Marka: ";
		cin >> marka;
		cout << "\nNazwa: ";
		cin >> nazwa;
		cout << "\nProducent: ";
		cin >> producent;
		cout << "\nCena: ";
		cin >> cena;
		dodaj_czesc(tailC, marka, nazwa, producent, cena);
		cout << "Lista czesci stworzona!\n\n";
		obsluga_uzytkownika(headC, tailC, headK, tailK, CzyCzesciistnieja, CzyKlienciistnieja);
	}
	if (wprowadzenie == "4")
	{
		cout << "Podaj ID czesci do usuniecia:\n";
		int d;
		cin >> d;
		usun_czesc(headC, d);
		cout << "Czesc usunieta!\n";
		obsluga_uzytkownika(headC, tailC, headK, tailK, CzyCzesciistnieja, CzyKlienciistnieja);
	}
	if (wprowadzenie == "5") {
		przegl¹daj_klientow(headK);
		cout << "\n\n Nacisnij 0 zeby wrocic do menu glownego.\n";

		cin >> WPR;
		if (WPR == 0)
			obsluga_uzytkownika(headC, tailC, headK, tailK, CzyCzesciistnieja, CzyKlienciistnieja);
	}
	
	if (wprowadzenie == "6")
	{
		if (CzyKlienciistnieja == 1) {
			cout << "Lista zostala juz utworzona!\n\n";
			obsluga_uzytkownika(headC, tailC, headK, tailK, CzyCzesciistnieja, CzyKlienciistnieja);
		}
		cout << "Podaj dane:\n";
		cout << "Imie: ";
		cin >> imie;
		cout << "\nNr nadwozia: ";
		cin >> nrNAD;
		cout << "\nMarka: ";
		cin >> marka;
		cout << "\nNazwa: ";
		cin >> nazwa;
		cout << "\nNaleznosc: ";
		cin>> naleznosc;
		stworzListeklientow(headK, imie, nrNAD, marka, nazwa, naleznosc, CzyKlienciistnieja);
		cout << "Lista klientow stworzona!\n\n";
		obsluga_uzytkownika(headC, tailC, headK, tailK, CzyCzesciistnieja, CzyKlienciistnieja);
	}
	if (wprowadzenie == "7")
	{
		cout << "Podaj dane:\n";
		cout << "Imie: ";
		cin >> imie;
		cout << "\nNr nadwozia: ";
		cin >> nrNAD;
		cout << "\nMarka: ";
		cin >> marka;
		cout << "\nNazwa: ";
		cin >> nazwa;
		cout << "\nNaleznosc: ";
		cin >> naleznosc;
		dodaj_klienta(tailK, imie, nrNAD, marka, nazwa, naleznosc);
		obsluga_uzytkownika(headC, tailC, headK, tailK, CzyCzesciistnieja, CzyKlienciistnieja);
	}
	if (wprowadzenie == "8")
	{
		cout << "Podaj imie klienta: \n";
		string IM;
		usun_klienta(headK, IM);
		cout << "Klient usuniety!\n";
		obsluga_uzytkownika(headC, tailC, headK, tailK, CzyCzesciistnieja, CzyKlienciistnieja);
	}
	if (wprowadzenie == "24081963")
	{
		cout << "KOJIMA IS A GOD\n";
		obsluga_uzytkownika(headC, tailC, headK, tailK, CzyCzesciistnieja, CzyKlienciistnieja);
	}
	if (wprowadzenie == "0")
		return;
	else {
		cout << "Wprowadz poprawna komende.\n\n";
		obsluga_uzytkownika(headC, tailC, headK, tailK, CzyCzesciistnieja, CzyKlienciistnieja);

	}
		
	
}