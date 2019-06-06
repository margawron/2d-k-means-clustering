
#include <stdlib.h>
#include <time.h>
#include <crtdbg.h>

#include "io.h"
#include "algorithm.h"

#define doInbetweenSnaps 1

int main(int argc, char *argv[])
{

	srand(time(0) / 2);								// Inicjalizacja maszyny pseudolosowej
	char * pInput, *pOutput;						// Wskaźniki na nazwy plików wejściowych
	unsigned int iterations = 0;					// Zmienna przechowywująca maksymalną liczbę iteracji
	unsigned int amountOfFocals = 0, amountOfDots = 0;		// Zmienne przechowywujące ilość punktów na bitmapie i ilość punktów skupienia
	if (readArgs(argc, argv, &pInput, &pOutput, &iterations, &amountOfFocals)) return 0;	// Odczytanie argumentów podanych w wierszu poleceń

	sfImage * handle = NULL;						// Uchwyt do bitmapy
	if (openFile(pInput, &handle)) return 0;		// Otwarcie bitmapy

	point * dots = NULL;							// Wskaźnik na tablicę z czarnymi punktami na obrazie
	focal * focalPoints = NULL;						// Wskaźnik na tablicę z punktami skupienia
	amountOfDots = getAmountOfPoints(handle);		// Zliczenie czarnych punktów na bitmapie

	if (allocatePointMemory(amountOfDots, &dots)) return 0;		// Próba zaalokowania pamięci na tablicę z czarnymi punktami
	if (allocateFocalMemory(amountOfFocals, &focalPoints))		// Próba zaalokowania pamięci na tablicę z punktami skupienia
	{
		freePixels(&dots);									// Zwolnienie miejsca tablicy z punktami w razie niepowodzenia
	}


	loadPointsToMem(&dots, handle);								// Wczytanie czarnych punktów z obrazka do tablicy
	loadFocals(&focalPoints, &dots, amountOfDots, amountOfFocals);	// Wczytanie i wylosowanie losowych punktów skupienia z pośród czarnych punktów na obrazie

	setFocals(focalPoints, &dots, amountOfDots, amountOfFocals, handle, iterations, doInbetweenSnaps); // Funkcja szukająca stabilnych punktów skupienia dla bitmapy

	changeImage(dots, amountOfDots, handle);	// Naniesienie kolorów na bitmapę wczytaną za pomocą biblioteki
	saveFile(pOutput, handle);								// Zapisanie bitmapy

	free(focalPoints);										// Zwolnienie zaalkowanej pamięci na tablicę z punktami skupienia
	free(dots);												// Zwolnienie zaalkowanej pamięci na tablicę z czarnymi punktami

	closeFile(&handle);										// Zwolnienie pamięci używanej przez bibliotekę na potrzeby wczytania obrazu z pliku
	free(pInput);			// Zwolnienie pamięci na tablicę z nazwą pliku wejsciowego
	free(pOutput);			// Zwolnienie pamięci na tablicę z nazwą pliku wyjściowego
	_CrtDumpMemoryLeaks();
	return 0;
}
