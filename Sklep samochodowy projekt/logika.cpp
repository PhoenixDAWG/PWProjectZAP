/**
* \file logika.cpp
* Plik implementacji modu³u logiki
*/
#include<fstream>
#include<iostream>
#include <string>
#include<cstdlib>
#include "logika.h"
using std::string;
using namespace std;
std::string Asortyment = "Asortyment.txt", listaklientow="ListaKlientow.txt";

void wczytaj_baze(std::string Asortyment, Czesc*&p)
{
	std::ifstream plik;
	plik.open(Asortyment, ios::in);

	if (!plik.good())
		return;

	Czesc* glowa = NULL;

	while (!(plik.eof()))
	{
		p = new Czesc;
		plik >>p->id;
		plik >> p->marka;
		plik >> p->nazwa;
		plik >> p->producent;
		plik >> p->cena;
		p->next = glowa;
		glowa = p;
	}
	p = glowa;
	plik.close();
}
void wczytaj_baze_klientów(std::string ListaKlientow, Klient*& p)
{
	std::ifstream plik;
	plik.open(ListaKlientow, ios::in);
	if (!plik.good())
		return;

	Klient* glowa = NULL;

	while (!(plik.eof()))
	{
		p = new Klient;
		plik >> p->imie;
		plik >> p->numer_nadwozia;
		plik >> p->markaCzesci;
		plik >> p->nazwaCzesci;
		plik >> p->DoZaplaty;
		p->next = glowa;
		glowa = p;
	}
	p = glowa;
	plik.close();
}
void zapisz_baze(std::string Asortyment, Czesc* p)
{
	std::fstream plik;
	plik.open(Asortyment, ios::out);
	while (p != 0) {
			plik << p->id << std::endl;
			plik << p->marka << std::endl;
			plik << p->nazwa<<std::endl;
			plik << p->producent<<std::endl;
			plik << p->cena<<std::endl;

			p = p->next;
	}
	plik.close();
}
void zapisz_baze_klientow(std::string ListaKlientow, Klient* p)
{
	std::ofstream plik(ListaKlientow, ios::out);

	while (p != 0) {
		
			plik << p->imie << std::endl;
			plik << p->numer_nadwozia << std::endl;
			plik << p->markaCzesci << std::endl;
			plik << p->nazwaCzesci << std::endl;
			plik << p->DoZaplaty << std::endl;

			p = p->next;
	}
		plik.close();
}
void stworzListe(Czesc*& p, string Marka, string NAZWA, string PRod, int CENA, bool Czesciistnieja) 
{
	if (p != NULL)
		return;
	p = new Czesc;
	p->id = 1;
	p->marka = Marka;
	p->nazwa = NAZWA;
	p->producent = PRod;
	p->cena = CENA;
	p->next = NULL;
	Czesciistnieja = 1;
}
void stworzListeklientow(Klient*& headK, string IMIE, int numerNADWOZIA, string MARKA, string NAZWA, int NALEZNOSC, bool Klienciistnieja)
{
	if (headK!= NULL)
		return;
	headK = new Klient;
	headK->imie = IMIE;
	headK->numer_nadwozia = numerNADWOZIA;
	headK->markaCzesci = MARKA;
	headK->nazwaCzesci = NAZWA;
	headK->DoZaplaty = NALEZNOSC;
	headK->next = NULL;
	Klienciistnieja = 1;
}
void dodaj_klienta(Klient* w, string imiE, int Nr_nadw, string MARKA, string NAZWAcz, int naleznosc )
{
	if (w == NULL)
		return;
	while (w->next != NULL)
		w = w->next;
	w->next = new Klient;
	w = w->next;
	w->imie = imiE;
	w->numer_nadwozia = Nr_nadw;
	w->markaCzesci = MARKA;
	w->nazwaCzesci = NAZWAcz;
	w->DoZaplaty = naleznosc;
	w->next = NULL;
}
void dodaj_czesc(Czesc* w, string MARKA, string NAZWA, string PRODUCENT, int CENA)
{
	if (w == NULL)
		return;
	while (w->next != NULL)
		w = w->next;
	int pom;
	pom = w->id;
	w->next = new Czesc;
	w = w->next;
	w->id=pom+1;
	w->marka = MARKA;
	w->nazwa = NAZWA;
	w->producent = PRODUCENT;
	w->cena = CENA;
	w->next = NULL;

}
void usun_czesc(Czesc*& g, int ID)
{		
	if (g == 0)
		return;
	while (g->next) {
		if(g->id=ID) {
		Czesc* del = g->next;
		g->next = del->next;
		delete del;
		}
		g = g->next;
	}
}
void usun_klienta(Klient*& g, string IMIE)
{
	if (g == 0)
		return;
	while (g->next) {
		if(g->imie!=IMIE)
			g = g->next;
		if(g->imie==IMIE) {
			Klient* del = g->next;
			g->next = del->next;
			delete del;
		}
	}
}