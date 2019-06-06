
#include <stdlib.h>
#include <time.h>
#include <crtdbg.h>

#include "io.h"	
#include "algorithm.h"

#define doInbetweenSnaps 1

int main(int argc, char *argv[])
{

	srand(time(0) / 2);								// Inicjalizacja maszyny pseudolosowej
	char * pInput, *pOutput;						// Wska�niki na nazwy plik�w wej�ciowych
	unsigned int iterations = 0;					// Zmienna przechowywuj�ca maksymaln� liczb� iteracji
	unsigned int amountOfFocals = 0, amountOfDots = 0;		// Zmienne przechowywuj�ce ilo�� punkt�w na bitmapie i ilo�� punkt�w skupienia
	if (readArgs(argc, argv, &pInput, &pOutput, &iterations, &amountOfFocals)) return 0;	// Odczytanie argument�w podanych w wierszu polece�

	sfImage * handle = NULL;						// Uchwyt do bitmapy
	if (openFile(pInput, &handle)) return 0;		// Otwarcie bitmapy

	point * dots = NULL;							// Wska�nik na tablic� z czarnymi punktami na obrazie
	focal * focalPoints = NULL;						// Wska�nik na tablic� z punktami skupienia
	amountOfDots = getAmountOfPoints(handle);		// Zliczenie czarnych punkt�w na bitmapie

	if (allocatePointMemory(amountOfDots, &dots)) return 0;		// Pr�ba zaalokowania pami�ci na tablic� z czarnymi punktami
	if (allocateFocalMemory(amountOfFocals, &focalPoints))		// Pr�ba zaalokowania pami�ci na tablic� z punktami skupienia
	{
		freePixels(&dots);									// Zwolnienie miejsca tablicy z punktami w razie niepowodzenia
	}
	

	loadPointsToMem(&dots, handle);								// Wczytanie czarnych punkt�w z obrazka do tablicy
	loadFocals(&focalPoints, &dots, amountOfDots, amountOfFocals);	// Wczytanie i wylosowanie losowych punkt�w skupienia z po�r�d czarnych punkt�w na obrazie

	setFocals(focalPoints, &dots, amountOfDots, amountOfFocals, handle, iterations, doInbetweenSnaps); // Funkcja szukaj�ca stabilnych punkt�w skupienia dla bitmapy

	changeImage(dots, amountOfDots, handle);	// Naniesienie kolor�w na bitmap� wczytan� za pomoc� biblioteki 
	saveFile(pOutput, handle);								// Zapisanie bitmapy 

	free(focalPoints);										// Zwolnienie zaalkowanej pami�ci na tablic� z punktami skupienia 
	free(dots);												// Zwolnienie zaalkowanej pami�ci na tablic� z czarnymi punktami

	closeFile(&handle);										// Zwolnienie pami�ci u�ywanej przez bibliotek� na potrzeby wczytania obrazu z pliku
	free(pInput);			// Zwolnienie pami�ci na tablic� z nazw� pliku wejsciowego
	free(pOutput);			// Zwolnienie pami�ci na tablic� z nazw� pliku wyj�ciowego
	_CrtDumpMemoryLeaks();
	return 0;
}