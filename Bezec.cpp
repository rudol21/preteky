#include "Bezec.h"






Bezec::Bezec(int stC, char p, string m, string pr, int cas)
{
	startovneCislo = stC;
	pohlavie= p;
	meno = m;
	priezvisko=pr;
	dosiahnutyCas=cas;
}

Bezec::~Bezec()
{
}

int Bezec::getStartovneCislo()
{
	return startovneCislo;
}

char Bezec::getPohlavie()
{
	return pohlavie;
}

string Bezec::getMeno()
{
	return 	meno;
}

string Bezec::getPriezvisko()
{
	return priezvisko;
}

int Bezec::getDosCas()
{
	return dosiahnutyCas;
}
