/**
* \mainpage
* \par Sklep samochodowy
* Program do obs³ugi listy klientów i towarów sklepu samochodowego
* \author Robert Cabaj
* \date 2022.06.30
* \version 1.0
* \par Kontakt:
* \a 01171814@pw.edu.pl
*/


#include <iostream>
#include<cstdlib>
#include "GUI.h"
#include "logika.h"

int main()
{
	bool CzyKlienciistnieja=0, CzyCzesciistnieja=0;
	Czesc* headC = NULL;
	Klient* headK = NULL;
	Czesc* tailC = headC;
	Klient* tailK = headK;
	wczytaj_baze("Asortyment.txt", headC);
	wczytaj_baze_klientów("Klienci.txt", headK);
	std::cout << "Witamy!\n";
	obsluga_uzytkownika (headC, headC, tailK, tailK, CzyCzesciistnieja, CzyKlienciistnieja);
	zapisz_baze("Asortyment.txt", headC);
	zapisz_baze_klientow("Klienci.txt", headK);
	return 0;
}