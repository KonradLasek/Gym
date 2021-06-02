#pragma once
#include <iostream>
#include <string>
#include "Pracownik.h"
#include "Recepcjonistka.h"
#include "Trener.h"
#include <fstream>
#include <vector>
class Silownia {
	std::string nazwa;
	int iloscPracownikow;
	int iloscTrenerow;
	int iloscRecepcjonistek;
	Trener *Trenerzy;
	Recepcjonistka *Recepcjonistki;
	Pracownik** listaPracownikow;

public:
	Silownia(std::string _nazwa);
	~Silownia();
	std::string getNazwa() { return nazwa; }
	void setNazwa();
	int getIloscPracownikow() { return iloscPracownikow; }
	int getIloscTrenerow() { return iloscTrenerow; }
	int getIloscRecepcjonistek() { return iloscRecepcjonistek; }
	void dajPremie(int n);
	void zmienCene(int n);	//zmien trenerowi cene za 1 trening
	void zmienTrening(int n);	//zmien trenerowi liczbe treningow w tygodniu
	void zmienIloscOdzywek(int n);	//zmien ilosc odzywek sprzedanych przez recepcjonistke
	void dodajTrenera();
	void dodajRecepcjonistke();
	void zapiszPracownikow(); //tworzy/aktualizuje plik z wszystkimi pracownikami
	void maxZarobiek();	//wyswietla, ktory trener zarabia najwiecej
	void wyswietlPersonel(); //wypisuje imiona wszystkich pracownikow, wraz z ich miejscami w "listaPracownikow"
};