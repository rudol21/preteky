#include "Bezec.h"
#include "Preteky.h"



int main(int argc, char * argv[])
{
	Preteky *pretek = new Preteky();
	pretek->nacitajPretekarov("suborNaCitanie.txt");
	pretek->utriedPodlaCasu();
	pretek->vypisNaKonzolu();
	delete pretek;
	return 0;
}