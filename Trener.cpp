#include "Trener.h"
Trener::Trener(): Pracownik(){
	pensja = 2500;
	cenaZaTrening = 50;
	iloscTreningowNaTydz = 0;
}
void Trener::wezPremie() {
	if (iloscTreningowNaTydz < 5) {
		std::cout << "Premia sie nie nalezy" << std::endl;
	}

	else if (iloscTreningowNaTydz >= 5 && iloscTreningowNaTydz < 10) {
		std::cout << "Przyznano 300zl premii" << std::endl;
		premia = 300;
	}
	else if (iloscTreningowNaTydz >= 10) {
		std::cout << "Przyznano 500zl premii" << std::endl;
		premia = 500;
	}
}
void Trener::setTreningi(int n) {
	iloscTreningowNaTydz = n;
}
void Trener::setCena(int n) {
	cenaZaTrening = n;
}