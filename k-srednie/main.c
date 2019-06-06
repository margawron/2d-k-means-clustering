
#include <stdlib.h>
#include <time.h>
#include <crtdbg.h>

#include "io.h"	
#include "algorithm.h"

#define doInbetweenSnaps 1

int main(int argc, char *argv[])
{

	srand(time(0) / 2);								// Inicjalizacja maszyny pseudolosowej
	char * pInput, *pOutput;						// WskaŸniki na nazwy plików wejœciowych
	unsigned int iterations = 0;					// Zmienna przechowywuj¹ca maksymaln¹ liczbê iteracji
	unsigned int amountOfFocals = 0, amountOfDots = 0;		// Zmienne przechowywuj¹ce iloœæ punktów na bitmapie i iloœæ punktów skupienia
	if (readArgs(argc, argv, &pInput, &pOutput, &iterations, &amountOfFocals)) return 0;	// Odczytanie argumentów podanych w wierszu poleceñ

	sfImage * handle = NULL;						// Uchwyt do bitmapy
	if (openFile(pInput, &handle)) return 0;		// Otwarcie bitmapy

	point * dots = NULL;							// WskaŸnik na tablicê z czarnymi punktami na obrazie
	focal * focalPoints = NULL;						// WskaŸnik na tablicê z punktami skupienia
	amountOfDots = getAmountOfPoints(handle);		// Zliczenie czarnych punktów na bitmapie

	if (allocatePointMemory(amountOfDots, &dots)) return 0;		// Próba zaalokowania pamiêci na tablicê z czarnymi punktami
	if (allocateFocalMemory(amountOfFocals, &focalPoints))		// Próba zaalokowania pamiêci na tablicê z punktami skupienia
	{
		freePixels(&dots);									// Zwolnienie miejsca tablicy z punktami w razie niepowodzenia
	}
	

	loadPointsToMem(&dots, handle);								// Wczytanie czarnych punktów z obrazka do tablicy
	loadFocals(&focalPoints, &dots, amountOfDots, amountOfFocals);	// Wczytanie i wylosowanie losowych punktów skupienia z poœród czarnych punktów na obrazie

	setFocals(focalPoints, &dots, amountOfDots, amountOfFocals, handle, iterations, doInbetweenSnaps); // Funkcja szukaj¹ca stabilnych punktów skupienia dla bitmapy

	changeImage(dots, amountOfDots, handle);	// Naniesienie kolorów na bitmapê wczytan¹ za pomoc¹ biblioteki 
	saveFile(pOutput, handle);								// Zapisanie bitmapy 

	free(focalPoints);										// Zwolnienie zaalkowanej pamiêci na tablicê z punktami skupienia 
	free(dots);												// Zwolnienie zaalkowanej pamiêci na tablicê z czarnymi punktami

	closeFile(&handle);										// Zwolnienie pamiêci u¿ywanej przez bibliotekê na potrzeby wczytania obrazu z pliku
	free(pInput);			// Zwolnienie pamiêci na tablicê z nazw¹ pliku wejsciowego
	free(pOutput);			// Zwolnienie pamiêci na tablicê z nazw¹ pliku wyjœciowego
	_CrtDumpMemoryLeaks();
	return 0;
}