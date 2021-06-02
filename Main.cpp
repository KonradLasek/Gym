#include <iostream>
#include "Pracownik.h"
#include "Recepcjonistka.h"
#include "Trener.h"
#include "Silownia.h"
#include "Zabezpieczenie.h"	
int main() {
	Silownia s1("costam");
	std::cout << "Witaj w systemie zarzadzania silownia." << std::endl;
	std::cout << std::endl;
	s1.setNazwa();

	int ilu = zabezpieczenie<int>("Ilu trenerow chcesz zatrudnic?");
	for (int i = 0; i < ilu; ++i) {
		s1.dodajTrenera();
	}

	ilu = zabezpieczenie<int>("Ile recepcjonistek chcesz zatrudnic?");
	for (int i = 0; i < ilu; ++i) {
		s1.dodajRecepcjonistke();
	}
	while (1) {
		std::cout << "\t \t \t MENU GLOWNE" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Dodaj trenera" << std::endl;
		std::cout << "2. Dodaj recepcjonistke" << std::endl;
		std::cout << "3. Zmien ilosc treningow prowadzonych tygodniowo przez trenera" << std::endl;
		std::cout << "4. Zmien cene godziny treningu personalnego" << std::endl;
		std::cout << "5. Zmien ilosc odzywek sprzedanych przez recepcjonistke" << std::endl;
		std::cout << "6. Daj premie" << std::endl;
		std::cout << "7. Sprawdz ktory trener najwiecej zarobil" << std::endl;
		std::cout << "8. Zapisz" << std::endl;
		std::cout << "9. Wyswietl pracownikow" << std::endl;
		int wybor = zabezpieczenie<int>(" ");
		int ktory;
		switch (wybor) {
		case 1: 
			s1.dodajTrenera();
			break;
		case 2: 
			s1.dodajRecepcjonistke();
			break;
		case 3: 
			std::cout << "Ktoremu trenerowi chcesz zmienic ilosc treningow?" << std::endl;
			s1.wyswietlPersonel();
			std::cin >> ktory;
			if(ktory > 0 && ktory <= s1.getIloscTrenerow())
			s1.zmienTrening(ktory-1);
			else std::cout << "Nie ma takiego trenera" << std::endl;
			break;
		case 4:
			std::cout << "Ktoremu trenerowi chcesz zmienic cene godziny treningu?" << std::endl;
			s1.wyswietlPersonel();
			std::cin >> ktory;
			if (ktory > 0 && ktory <= s1.getIloscTrenerow())
				s1.zmienCene(ktory-1);
			else std::cout << "Nie ma takiego trenera" << std::endl;
			break;
		case 5:
			std::cout << "Ktorej recepcjonistce chcesz zmienic ilosc sprzedanych odzywek?" << std::endl;
			s1.wyswietlPersonel();
			std::cin >> ktory;
			if (ktory > s1.getIloscTrenerow() && ktory <= s1.getIloscPracownikow())
				s1.zmienIloscOdzywek(ktory-1);
			else std::cout << "Nie ma takiej recepcjonistki" << std::endl;
			break;
		case 6:
			std::cout << "Komu chcesz dac premie?" << std::endl;
			s1.wyswietlPersonel();
			std::cin >> ktory;
			if (ktory > 0 && ktory <= s1.getIloscPracownikow())
				s1.dajPremie(ktory-1);
			else std::cout << "Nie ma takiego pracownika" << std::endl;
			break;
		case 7:
			try {
				s1.maxZarobiek();
			}
			catch (...) {
				std::cout << "Conajmniej dwoch trenerow jest na pierwszym miejscu, nie chce mi sie tego problemu rozwiazywac, wiec rzucam wyjatek"<< std::endl;
				break;
			}
		case 8:
			std::cout << "Zapisano" << std::endl;
			s1.zapiszPracownikow();
			break;
		case 9:
			s1.wyswietlPersonel();
			break;
		
		}
		system("pause");
	}
	return 0;
}