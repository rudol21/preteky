#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
class Bezec
{
	int startovneCislo;
	char pohlavie;
	string meno;
	string priezvisko;
	int dosiahnutyCas;
public:
	Bezec(int stC, char p, string m, string pr, int cas);
	~Bezec();
	int getStartovneCislo();
	char getPohlavie();
	string getMeno();
	string getPriezvisko();
	int getDosCas();
};

