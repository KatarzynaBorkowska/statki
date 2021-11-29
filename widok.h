#ifndef WIDOK_H
#define WIDOK_H
#include <string>

class widok
{
	public:
	int dwa,trzy,cztery,piec; // statki
	
	void plansza(int);
	void plansza_tworzenie(int);
	void uzupelnianie(int);
	void statki();
	void statki_u(int,int,std::string);
	void z_kalawiatury(int,int,std::string,int,int);
};

#endif
