#include "Preteky.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
Preteky::Preteky()
{
}


Preteky::~Preteky()
{
	for (auto &p : zoznamPretekarovM)
	{
		delete p;

	}
	zoznamPretekarovM.clear();
	for (auto &p : zoznamPretekarovZ)
	{
		delete p;
	}
	zoznamPretekarovZ.clear();
}

void Preteky::nacitajPretekarov(const char * menoSuboru)
{
	ifstream cin(menoSuboru);
	int startovneCislo;
	char pohlavie;
	string meno;
	string priezvisko;
	int dosiahnutyCas;
	int H=0;
	int M=0;
	int S=0;
	char pom;

	while (cin >> startovneCislo >> pohlavie >> meno>> priezvisko >> H >> pom >> M >> pom >> S)
	{
		dosiahnutyCas = S + (M * 60) + (H * 3600);
		if(pohlavie == 'M')
		zoznamPretekarovM.push_back(new Bezec(startovneCislo, pohlavie, meno, priezvisko, dosiahnutyCas));
		else
		zoznamPretekarovZ.push_back(new Bezec(startovneCislo, pohlavie, meno, priezvisko, dosiahnutyCas));
	}
}

bool wayToSort(Bezec *s1, Bezec *s2) { return s1->getDosCas() < s2->getDosCas(); };
void Preteky::utriedPodlaCasu()
{
	sort(zoznamPretekarovM.begin(), zoznamPretekarovM.end(), wayToSort);
	sort(zoznamPretekarovZ.begin(), zoznamPretekarovZ.end(), wayToSort);
}

void Preteky::vypisNaKonzolu()
{
	int startovneCislo;
	string meno;
	string priezvisko;
	int dosiahnutyCas;
	int H = 0;
	int M = 0;
	int S = 0;

	printf("Vsledky muzi \n -------------------\n");
	for (int i = 0; i < zoznamPretekarovM.size(); i++)
	{
		startovneCislo = zoznamPretekarovM[i]->getStartovneCislo();
		meno = zoznamPretekarovM[i]->getMeno();
		priezvisko = zoznamPretekarovM[i]->getPriezvisko();
		dosiahnutyCas = zoznamPretekarovM[i]->getDosCas();
		H = dosiahnutyCas / 3600;
		M = (dosiahnutyCas - (H * 3600)) / 60;
		S = dosiahnutyCas - (H * 3600 + M * 60);
		string pomM;
		string pomS;
		if (M < 10)
			pomM = "0";
		else
			pomM = "";
		if (S < 10)
			pomS = "0";
		else
			pomS = "";
		
		printf ("%i (%-2i) %-12s %-12s",i+1, startovneCislo, meno.c_str(), priezvisko.c_str());
		printf ("%i:%s%i:%s%i ",H,pomM.c_str(),M,pomS.c_str(),S);
		dosiahnutyCas = zoznamPretekarovM[i]->getDosCas()  - zoznamPretekarovM[0]->getDosCas();
		H = dosiahnutyCas / 3600;
		M = (dosiahnutyCas - (H * 3600)) / 60;
		S = dosiahnutyCas - (H * 3600 + M * 60);
		if (M < 10)
			pomM = "0";
		else
			pomM = "";
		if (S < 10)
			pomS = "0";
		else
			pomS = "";
		printf(" +%i:%s%i:%s%i ", H, pomM.c_str(), M, pomS.c_str(), S);
		printf("\n");
	}
	printf("Vsledky zeny \n -------------------\n");
	for (int i = 0; i < zoznamPretekarovZ.size(); i++)
	{
		startovneCislo = zoznamPretekarovZ[i]->getStartovneCislo();
		meno = zoznamPretekarovZ[i]->getMeno();
		priezvisko = zoznamPretekarovZ[i]->getPriezvisko();
		dosiahnutyCas = zoznamPretekarovZ[i]->getDosCas();
		H = dosiahnutyCas / 3600;
		M = (dosiahnutyCas - (H * 3600)) / 60;
		S = dosiahnutyCas - (H * 3600 + M * 60);
		string pomM;
		string pomS;
		if (M < 10)
			pomM = "0";
		else
			pomM = "";
		if (S < 10)
			pomS = "0";
		else
			pomS = "";
		
		printf("%i (%-2i) %-12s %-12s", i+1, startovneCislo, meno.c_str(), priezvisko.c_str());
		printf("%i:%s%i:%s%i ", H, pomM.c_str(), M, pomS.c_str(), S);
		dosiahnutyCas = zoznamPretekarovZ[i]->getDosCas() - zoznamPretekarovZ[0]->getDosCas();
		H = dosiahnutyCas / 3600;
		M = (dosiahnutyCas - (H * 3600)) / 60;
		S = dosiahnutyCas - (H * 3600 + M * 60);
		if (M < 10)
			pomM = "0";
		else
			pomM = "";
		if (S < 10)
			pomS = "0";
		else
			pomS = "";
		printf(" +%i:%s%i:%s%i ", H, pomM.c_str(), M, pomS.c_str(), S);
		printf("\n");
	}
	
}
