#include "Silownia.h"
#include "Zabezpieczenie.h"
Silownia::Silownia(std::string _nazwa) {
	nazwa = _nazwa;
	listaPracownikow = new Pracownik*[10];
	iloscPracownikow = 0;
	iloscRecepcjonistek = 0;
	iloscTrenerow = 0;
}
Silownia::~Silownia() {
	delete[] listaPracownikow;
}
void Silownia::setNazwa() {
	std::cout << "Podaj nazwe silowni:" << std::endl;
	std::cin >> nazwa;
}
void Silownia::dodajTrenera() {
	if (iloscPracownikow == 0) {
		iloscPracownikow = 1;
		iloscTrenerow = 1;
		Trenerzy = new Trener[iloscTrenerow];
		Trenerzy[0].setImie();
		listaPracownikow[iloscTrenerow - 1] = &Trenerzy[0];
	}
	else if(iloscPracownikow > 0 && iloscPracownikow < 10) {
		Trener *temp = nullptr;
		Recepcjonistka *tempr = nullptr;
		iloscPracownikow++;
		iloscTrenerow++;
		temp = new Trener[iloscTrenerow];
		for (int i = 0; i < iloscTrenerow-1; ++i) {
			temp[i] = Trenerzy[i];
		}
		temp[iloscTrenerow - 1].setImie();
		delete[] Trenerzy;
		Trenerzy = new Trener[iloscTrenerow];
		for (int i = 0; i < iloscTrenerow; ++i) {
			Trenerzy[i] = temp[i];
			listaPracownikow[i] = &Trenerzy[i];
			listaPracownikow[i + iloscTrenerow] = &Recepcjonistki[i];
		}
	}
	else std::cout << "Nie mozemy zatrudnic wiecej niz 10 pracownikow" << std::endl;
	
}
void Silownia::dodajRecepcjonistke() {
	if (iloscPracownikow == 0) {
		iloscPracownikow = 1;
		iloscRecepcjonistek = 1;
		Recepcjonistki = new Recepcjonistka[iloscRecepcjonistek];
		Recepcjonistki[0].setImie();
		listaPracownikow[iloscRecepcjonistek - 1] = &Recepcjonistki[0];
	}
	else if(iloscPracownikow > 0 && iloscPracownikow <10) {
		Recepcjonistka *temp = nullptr;
		iloscPracownikow++;
		iloscRecepcjonistek++;
		temp = new Recepcjonistka[iloscRecepcjonistek];
		for (int i = 0; i < iloscRecepcjonistek - 1; ++i) {
			temp[i] = Recepcjonistki[i];
		}
		temp[iloscRecepcjonistek - 1].setImie();
		delete[] Recepcjonistki;
		Recepcjonistki = new Recepcjonistka[iloscRecepcjonistek];
		for (int i = 0; i < iloscRecepcjonistek; ++i) {
			Recepcjonistki[i] = temp[i];
			listaPracownikow[iloscTrenerow + i] = &Recepcjonistki[i];
		}
	}
	else std::cout << "Nie mozemy zatrudnic wiecej niz 10 pracownikow" << std::endl;
}
void Silownia::dajPremie(int n){
	listaPracownikow[n]->wezPremie();
}
void Silownia::zmienCene(int n) {
	std::cout<< "Trener: " << listaPracownikow[n]->getImie() << std::endl;
	int cena = zabezpieczenie<int>("Jaka ma byc nowa cena za 1h treningu?");
	Trenerzy[n].setCena(cena);
}
void Silownia::zmienTrening(int n) {
	std::cout << "Trener: " << listaPracownikow[n]->getImie() << std::endl;
	int trening = zabezpieczenie<int>("Ile treningow tygodniowo chcesz dodac?");
	Trenerzy[n].setTreningi(trening);
}
void Silownia::zmienIloscOdzywek(int n) {
	std::cout << "Recepcjonistka: " << listaPracownikow[n]->getImie() << std::endl;
	int odzywki = zabezpieczenie<int>("Ile odzywek sprzedala recepcjonistka?");
	Recepcjonistki[n].setOdzywki(odzywki);
}
void Silownia::zapiszPracownikow() {
	std::ofstream plik;
	plik.open("Lista_Pracownikow.txt", std::ifstream::out);
	for(int i=0; i< iloscPracownikow; ++i){
		plik << "Imie: " << listaPracownikow[i]->getImie() << " \t Pensja " << listaPracownikow[i]->getPensja() << " \t Premia: " << listaPracownikow[i]->getPremia() << std::endl;
}
	plik.close();
}
void Silownia::maxZarobiek() {
	int ileRazy = 0;
	Trener temp;
	temp = Trenerzy[0];
		for (int i = 1; i < iloscTrenerow; ++i) {
			if (Trenerzy[i] > temp) {
				temp = Trenerzy[i];
			}
	}
		for (int i = 0; i < iloscTrenerow; ++i) {
			if (Trenerzy[i] == temp) {
				ileRazy++;
				if (ileRazy == 2) throw(1);
			}
		}
	std::cout << "Najwiecej zarabia trener: " << temp.getImie() << std::endl;
}
void Silownia::wyswietlPersonel() {
	std::cout << "Trenerzy:" << std::endl;
	for (int i = 0; i < iloscTrenerow; ++i) {
		std::cout << i + 1 << ". ";
		std::cout << listaPracownikow[i]->getImie() << std::endl;
	}
	std::cout << "Recepcjonistki:" << std::endl;
	for (int i = 0; i < iloscRecepcjonistek; ++i) {
		std::cout << i + iloscTrenerow + 1 << ". ";
		std::cout << listaPracownikow[iloscTrenerow + i]->getImie() << std::endl;
	}
}