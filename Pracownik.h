#pragma once
#include <iostream>
#include <string>
class Pracownik {
protected:
	std::string imie;
	int pozostalyUrlop;
	int staz;
	int pensja;
	int premia;
public:
	std::string getImie() { return imie; }
	int getUrlop() { return pozostalyUrlop; }
	int getStaz() { return staz; }
	int getPensja() { return pensja; }
	int getPremia() { return premia; }
	Pracownik();
	void setImie();
	void setStaz();
	virtual void wezPremie() = 0;
	bool operator>(Pracownik& drugi);
	bool operator==(Pracownik& drugi);
};