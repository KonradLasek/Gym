#include "Recepcjonistka.h"
Recepcjonistka::Recepcjonistka() : Pracownik() {
	pensja = 2300;
	sprzedaneOdzywki = 0;
}
void Recepcjonistka::wezPremie(){
	if (sprzedaneOdzywki < 50)
		std::cout << "Premia sie nie nalezy" << std::endl;
	else if (sprzedaneOdzywki >= 50 && sprzedaneOdzywki < 100) {
		std::cout << "Przyznano 300zl premii" << std::endl;
		premia = 300;
	}
	else if(sprzedaneOdzywki >=100){
		std::cout << "Przyznano 500zl premii" << std::endl;
		premia = 500;
	}
}
void Recepcjonistka::setOdzywki(int n) {
	sprzedaneOdzywki = n;
}