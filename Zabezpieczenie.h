#pragma once
#include <iostream>
#include <string>
template <typename T>
int zabezpieczenie(std::string napis) {
	T ilosc;
	while (1) {
		std::cout << napis << std::endl;
		std::cin >> ilosc;
		if (std::cin.fail() == true) {
			std::cout << "wykryto blad" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else return ilosc;
	}
}