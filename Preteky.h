#pragma once
#include "Bezec.h"

class Preteky
{
	vector <Bezec*> zoznamPretekarovM;
	vector <Bezec*> zoznamPretekarovZ;
public:
	Preteky();
	~Preteky();
	void nacitajPretekarov(const char * menoSuboru);
	void utriedPodlaCasu();
	void vypisNaKonzolu();
};

