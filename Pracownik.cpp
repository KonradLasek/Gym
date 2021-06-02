#include "Pracownik.h"
#include "Zabezpieczenie.h"
Pracownik::Pracownik() {
	pozostalyUrlop = 20;
	staz = 0;
	premia = 0;
}
void Pracownik::setImie() {
	std::cout << "Podaj imie pracownika" << std::endl;
	std::cin >> imie;
}
bool Pracownik::operator>(Pracownik& drugi) {
	if (premia > drugi.premia)
		return true;
	else return false;
}
bool Pracownik::operator==(Pracownik& drugi) {
	if (pensja + premia == drugi.pensja + drugi.premia)
		return true;
	else return false;
}
void Pracownik::setStaz() {
	staz = zabezpieczenie<int>("Jaki jest staz pracownika?");
}
