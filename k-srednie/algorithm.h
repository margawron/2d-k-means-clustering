#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "SFML\Graphics.h"




//
// Struktura focal
// struktura opisująca punkt skupienia danych
//
typedef struct {
	float x, y;					// koordynaty punktu skupienia
	sfColor color;				// kolor przypisany do punktu skupienia danych
}focal;

//
// Struktura point
// struktura przechowywuje koordynaty punktu i przynależność punktu na płaszczyźnie
//
typedef struct {
	unsigned int x, y;	//koordynaty punktu z danymi
	focal * affil;		//wskaźnik na element typu focal opisujący punkt skupienia danych
}point;

//
// Funkcja getPoints
// funkcja zlicza czarne punkty na bitmapie i zwraca ich ilość
// sfImage * handle - uchwyt do pliku z bitmapie
// return - zwraca liczbę czarnych punktów
//
unsigned int getAmountOfPoints(sfImage * handle);

//
// Funkcja allocatePointMemory
// funkcja alokuje pamięć dla danych typu point
// unsigned int amount - ilość pikseli dla których potrzebna jest pamięć
// point ** dataPointer - wskaźnik na pamięć która zostanie zaalokowana przez funkcję
// return - funkcja zwraca 1 jeżeli alokacja pamięci się udała, 0 jeżeli alokacja się nie udała
//
int allocatePointMemory(unsigned int amount, point ** dataPointer);

//
// Funkcja allocateFocalMemory
// funkcja alokuje pamięć dla danych typu point
// unsigned int amount - ilość pikseli dla których potrzebna jest pamięć
// point ** dataPointer - wskaźnik na pamięć która zostanie zaalokowana przez funkcję
// return - funkcja zwraca 1 jeżeli alokacja pamięci się udała, 0 jeżeli alokacja się nie udała
//
int allocateFocalMemory(unsigned int amount, focal ** dataPointer);

//
// Funkcja loadPointsToMem
// funkcja zapisuje punkty ze struktury sfImage do tablicy wskazanej przez dataPointer
// point ** dataPointer - wskaźnik na tablicę z punktami
// sfImage * handle - uchwyt do struktury przechowywującej piksele
//
void loadPointsToMem(point ** dataPointer, sfImage * handle);

//
// Funkcja loadFocals
// funkcja ustawia podaną, losową ilość punktów
// focal ** dataFocals - wskaźnik na wskaźnik na blok pamięci do którego należy załadować punkty
// point ** dataPoints - wskażnik na wskaźnik na block pamięci zawierący punkty z którego należy wylosować punkty skupienia
// unsigned int amountOfDots - ilość punktów w bloku pamięci
// unsigned int amountOfFocals - ilość punktów skupienia w bloku pamięci (ilość punktów skupienia do wylosowania)
//
void loadFocals(focal ** dataFocals, point ** dataPoints, unsigned int amountOfDots, unsigned int amountOfFocals);

//
// Funkcja setFocals
// funkcja ustala stacjonarne punkty skupienia (tk. takie które po kolejnych iteracjach się nie przemieszczą) bądź przerywa po określonej liczbie iteracji
// focal * focalPoints - adres blok pamięci z punktami skupienia
// point ** dataPointer - wskaźnik na adres do bloku pamięci który przechowuje czarne punkty (punkty danych) z bitmapy
// unsigned int amountOfPoints - ilość (wielkość bloku pamięci) punktów danych
// unsigned int amountOfFocals - ilość (wielkość bloku pamięci) punktów skupienia
// sfImage * handle - uchwyt do danych wczytanych z bitmapy
// unsigned int iterations - maksymalna ilośc iteracji jaką może wykonać program po czym ma zakończyć wyznaczanie punktów skupień
// short doInbetween - przełącznik decydujący czy funkcja ma robić zrzuty położenia danych do bitmapy co iterację
//
void setFocals(focal * focalPoints, point ** dataPointer, unsigned int amountOfPoints, unsigned int amountOfFocals, sfImage * handle, unsigned int iterations, short doInbetween);

//
// Funkcja changeImage
// funkcja nanosi kolor na piksele z danymi na bitmapie
// point * points - adres bloku pamięci przychowywującego punkty danych
// sfImage * handle - uchwyt do danych wczytanch z bitmapy
//
void changeImage(point * points, unsigned int amountOfPoints, sfImage * handle);



#endif // !_ALGORITHM_H_
