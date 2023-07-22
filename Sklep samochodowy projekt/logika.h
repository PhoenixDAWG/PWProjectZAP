/**
* \file logika.h
* Plik nag³owkowy modu³u logiki
*/
#ifndef LOGIKA_H
#define LOGIKA_H
#include <string>

/*
* \brief struktura tworzaca elementy listy czesci sklepu
* \param id numer identyfikacyjny czesci, marka nazwa marki samochodu danej czesci, nazwa to nazwa czesci, producent to nazwa producenta czesci, cena to cena czesci
*/
struct Czesc {
	int id;
	std::string marka ;
	std::string nazwa;
	std::string producent;
	int cena;
	Czesc* next;
};
/*
* \brief struktura tworzaca elementy listy klientow sklepu
* \param imie to imie klienta, numer_nadwozia, markaCzesci to nazwa marki czesci zamowionej, nazwaCzesci to nazwa zamowionej czesci, DoZaplaty to wartosc jaka klient musi zaplacic za zamowiony towar
*/
struct Klient {
	std::string imie;
	int numer_nadwozia;
	std::string markaCzesci;
	std::string nazwaCzesci;
	int DoZaplaty;
	Klient* next;
};

/*
* \brief funkcja wczytuje liste czesci z pliku
* \param p wskaznik na glowe listy, Asortyment to nazwa pliku z lista
*/
void wczytaj_baze(std::string Asortyment, Czesc*&p);
/*
* \brief funkcja wczytuje liste klientow z pliku
* \param p wskaznik na glowe listy, ListaKlientow to nazwa pliku z lista
*/
void wczytaj_baze_klientów(std::string ListaKlientow, Klient *&p);
/*
* \brief funkcja zapisuje liste czesci do pliku
* \param p wskaznik na glowe listy, Asortyment to nazwa pliku z lista
*/
void zapisz_baze(std::string Asortyment, Czesc *p);
/*
* \brief funkcja zapisuje liste klientow do pliku
* \param p wskaznik na glowe listy, ListaKlientow to nazwa pliku z lista
*/
void zapisz_baze_klientow(std::string ListaKlientow, Klient* p);
/*
* \brief funkcja tworzy liste czesci
* \param p wskaznik na glowe listy, marka nazwa marki samochodu danej czesci, nazwa to nazwa czesci, producent to nazwa producenta czesci, cena to cena czesci
*/
void stworzListe(Czesc*& p, std::string Marka, std::string NAZWA, std::string PRod, int CENA, bool Czesciistnieja);
/*
* \brief funkcja tworzaca liste klientow sklepu
* \param p to wskaznik na glowe listy, IMIE to imie klienta, numer_nadwozia, markaCzesci to nazwa marki czesci zamowionej, nazwaCzesci to nazwa zamowionej czesci, DoZaplaty to wartosc jaka klient musi zaplacic za zamowiony towar
*/
void stworzListeklientow(Klient*& p, std::string IMIE, int numerNADWOZIA, std::string MARKA, std::string NAZWA, int NALEZNOSC, bool Klienciistnieja);
/*
* \brief funkcja dodajaca klienta do listy klientow
* \param w to wskaznik na glowe listy, imiE to imie klienta, Nr_nadw to numer nadwozia pojazdu klienta, MARKA to marka pojazdu klienta, NAZWAcz to nazwa zamowionej czesci, naleznosc to wartosc jaka klient musi zaplacic za zamowiony towar
*/
void dodaj_klienta(Klient* w, std::string imiE, int Nr_nadw, std::string MARKA, std::string NAZWAcz, int naleznosc);
/*
* \brief funkcja dodajaca nowa czesc do listy czesci
* \param w to wskaznik na glowe listy, MARKA to nazwa marki pojazdu czesci, NAZWA to nazwa czesci, PRODUCENT to nazwa producenta czesci, CENA to cena czesci
*/
void dodaj_czesc(Czesc* w, std::string MARKA, std::string NAZWA, std::string PRODUCENT, int CENA);
/*
* \brief funkcja usuwajaca dana czesc z listy
* \param g to wskaznik na adres glowy listy, ID to numer identyfikacyjny czesci do usuniecia z listy
*/
void usun_czesc(Czesc*& g, int ID);
/*
* \brief funkcja usuwajaca danego klienta sklepu
* \param g to wskaznik na adres glowy listy, IMIE to imie klienta, ktory ma byc usuniety z listy
*/
void usun_klienta(Klient*& g, std::string IMIE);

#endif // !LOGIKA_H

