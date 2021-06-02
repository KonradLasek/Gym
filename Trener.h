#pragma once
#include "Pracownik.h"
class Trener : public Pracownik {
	int iloscTreningowNaTydz;
	int cenaZaTrening;
public: 
	Trener();
	void wezPremie();
	void setTreningi(int n);
	void setCena(int n);
};