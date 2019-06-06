#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "SFML\Graphics.h"




//
// Struktura focal
// struktura opisuj¹ca punkt skupienia danych
//
typedef struct {
	float x, y;					// koordynaty punktu skupienia
	sfColor color;				// kolor przypisany do punktu skupienia danych
}focal;

//
// Struktura point
// struktura przechowywuje koordynaty punktu i przynale¿noœæ punktu na p³aszczyŸnie
//
typedef struct {
	unsigned int x, y;	//koordynaty punktu z danymi
	focal * affil;		//wskaŸnik na element typu focal opisuj¹cy punkt skupienia danych
}point;

//
// Funkcja getPoints
// funkcja zlicza czarne punkty na bitmapie i zwraca ich iloœæ
// sfImage * handle - uchwyt do pliku z bitmapie
// return - zwraca liczbê czarnych punktów
//
unsigned int getAmountOfPoints(sfImage * handle);

//
// Funkcja allocatePointMemory
// funkcja alokuje pamiêæ dla danych typu point
// unsigned int amount - iloœæ pikseli dla których potrzebna jest pamiêæ
// point ** dataPointer - wskaŸnik na pamiêæ która zostanie zaalokowana przez funkcjê
// return - funkcja zwraca 1 je¿eli alokacja pamiêci siê uda³a, 0 je¿eli alokacja siê nie uda³a
//
int allocatePointMemory(unsigned int amount, point ** dataPointer);

//
// Funkcja allocateFocalMemory
// funkcja alokuje pamiêæ dla danych typu point
// unsigned int amount - iloœæ pikseli dla których potrzebna jest pamiêæ
// point ** dataPointer - wskaŸnik na pamiêæ która zostanie zaalokowana przez funkcjê
// return - funkcja zwraca 1 je¿eli alokacja pamiêci siê uda³a, 0 je¿eli alokacja siê nie uda³a
//
int allocateFocalMemory(unsigned int amount, focal ** dataPointer);

//
// Funkcja loadPointsToMem
// funkcja zapisuje punkty ze struktury sfImage do tablicy wskazanej przez dataPointer 
// point ** dataPointer - wskaŸnik na tablicê z punktami
// sfImage * handle - uchwyt do struktury przechowywuj¹cej piksele
//
void loadPointsToMem(point ** dataPointer, sfImage * handle);

//
// Funkcja loadFocals
// funkcja ustawia podan¹, losow¹ iloœæ punktów
// focal ** dataFocals - wskaŸnik na wskaŸnik na blok pamiêci do którego nale¿y za³adowaæ punkty
// point ** dataPoints - wska¿nik na wskaŸnik na block pamiêci zawier¹cy punkty z którego nale¿y wylosowaæ punkty skupienia
// unsigned int amountOfDots - iloœæ punktów w bloku pamiêci
// unsigned int amountOfFocals - iloœæ punktów skupienia w bloku pamiêci (iloœæ punktów skupienia do wylosowania)
//
void loadFocals(focal ** dataFocals, point ** dataPoints, unsigned int amountOfDots, unsigned int amountOfFocals);

//
// Funkcja setFocals
// funkcja ustala stacjonarne punkty skupienia (tk. takie które po kolejnych iteracjach siê nie przemieszcz¹) b¹dŸ przerywa po okreœlonej liczbie iteracji
// focal * focalPoints - adres blok pamiêci z punktami skupienia
// point ** dataPointer - wskaŸnik na adres do bloku pamiêci który przechowuje czarne punkty (punkty danych) z bitmapy
// unsigned int amountOfPoints - iloœæ (wielkoœæ bloku pamiêci) punktów danych
// unsigned int amountOfFocals - iloœæ (wielkoœæ bloku pamiêci) punktów skupienia 
// sfImage * handle - uchwyt do danych wczytanych z bitmapy
// unsigned int iterations - maksymalna iloœc iteracji jak¹ mo¿e wykonaæ program po czym ma zakoñczyæ wyznaczanie punktów skupieñ
// short doInbetween - prze³¹cznik decyduj¹cy czy funkcja ma robiæ zrzuty po³o¿enia danych do bitmapy co iteracjê
//
void setFocals(focal * focalPoints, point ** dataPointer, unsigned int amountOfPoints, unsigned int amountOfFocals, sfImage * handle, unsigned int iterations, short doInbetween);

//
// Funkcja changeImage
// funkcja nanosi kolor na piksele z danymi na bitmapie
// point * points - adres bloku pamiêci przychowywuj¹cego punkty danych
// sfImage * handle - uchwyt do danych wczytanch z bitmapy
// 
void changeImage(point * points, unsigned int amountOfPoints, sfImage * handle);



#endif // !_ALGORITHM_H_
