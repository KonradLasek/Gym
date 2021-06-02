#pragma once
#include "Pracownik.h"
class Recepcjonistka : public Pracownik {
	int sprzedaneOdzywki;
public:
	Recepcjonistka();
	void wezPremie();
	void setOdzywki(int n);
	int getOdzywki() { return sprzedaneOdzywki; }
};